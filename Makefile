.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home 2>/dev/null | cut -d= -f2 | sed -e 's@^None$$@@g')

.PHONY: help setup build flash clean

help:
	@echo "Targets:"
	@echo "  make setup            one-time: install qmk_firmware + register this dir as the userspace overlay"
	@echo "  make build            compile every target listed in qmk.json (qmk userspace-compile)"
	@echo "  make flash            compile and flash ergodox_ez:dinosaur (put keyboard in bootloader first)"
	@echo "  make clean            remove build artifacts"
	@echo ""
	@echo "Or use any qmk_firmware make target directly, e.g.:"
	@echo "  make ergodox_ez:dinosaur          # compile"
	@echo "  make ergodox_ez:dinosaur:flash    # compile + flash"

setup:
	@command -v qmk >/dev/null 2>&1 || { \
		echo "qmk CLI not found. Install with one of:"; \
		echo "  brew install qmk/qmk/qmk        # macOS"; \
		echo "  pipx install qmk                # Linux/macOS"; \
		echo "  python3 -m pip install --user qmk"; \
		exit 1; }
	@test -n "$(QMK_FIRMWARE_ROOT)" -a -d "$(QMK_FIRMWARE_ROOT)" || qmk setup -y
	qmk config user.overlay_dir="$(QMK_USERSPACE)"
	@echo "Setup complete. Try 'make build'."

build:
	qmk userspace-compile

flash:
	qmk flash -kb ergodox_ez -km dinosaur

clean:
	qmk clean

# Catch-all: forward everything else (e.g. `ergodox_ez:dinosaur`) to qmk_firmware's Makefile.
%:
	@test -n "$(QMK_FIRMWARE_ROOT)" -a -d "$(QMK_FIRMWARE_ROOT)" || { \
		echo "qmk_firmware not found. Run 'make setup' first."; exit 1; }
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
