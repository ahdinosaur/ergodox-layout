KEYBOARD := ergodox_ez
KEYMAP   := dinosaur

QMK_HOME      ?= $(HOME)/qmk_firmware
KEYMAP_TARGET := $(QMK_HOME)/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

.PHONY: help build flash clean setup link

help:
	@echo "Targets:"
	@echo "  make setup  - one-time: install qmk + clone qmk_firmware + symlink this keymap"
	@echo "  make build  - compile firmware (.hex / .bin)"
	@echo "  make flash  - compile and flash (put keyboard in bootloader first)"
	@echo "  make clean  - remove build artifacts"

build: link
	qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

flash: link
	qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

clean:
	qmk clean

setup:
	@command -v qmk >/dev/null 2>&1 || { \
		echo "qmk CLI not found. Install with one of:"; \
		echo "  brew install qmk/qmk/qmk        # macOS"; \
		echo "  pipx install qmk                # Linux/macOS"; \
		echo "  python3 -m pip install --user qmk"; \
		exit 1; }
	@test -d "$(QMK_HOME)" || qmk setup -y -H "$(QMK_HOME)"
	@$(MAKE) link
	@echo "Setup complete. Try 'make build'."

link: $(KEYMAP_TARGET)

$(KEYMAP_TARGET):
	@test -d "$(QMK_HOME)" || { echo "QMK_HOME not found at $(QMK_HOME). Run 'make setup' first."; exit 1; }
	ln -sfn "$(CURDIR)" "$(KEYMAP_TARGET)"
