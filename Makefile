.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)

# The above checks needs the setup to be done first. These targets are kind of just for documentation
setup:
	@qmk setup -H $(HOME)/repos/qmk_firmware

configure: setup
	@qmk config user.overlay_dir="$(HOME)/repos/qmk_userspace"

all:
	@qmk userspace-compile

kyria:
	# Yes, rev4 is the correct revision
	@qmk compile -kb splitkb/halcyon/kyria/rev4 -km default_hlc -e HLC_TFT_DISPLAY=1
	# Flash it by pressing the reset button on the _connected_ half, the copy the
	# splitkb_halcyon_kyria_rev4_default_hlc.uf2 file into the mounted directory.
	# Connect the other half and repeat the process.
