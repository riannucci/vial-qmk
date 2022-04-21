# MCU name
MCU_FAMILY = PICO
MCU_SERIES = RP2040
BOOTLOADER = RP2040
MCU = cortex-m0plus

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

LAYOUTS = planck_mit ortho_4x12
LAYOUTS_HAS_RGB = no

# Disable unsupported hardware
RGBLIGHT_SUPPORTED = no
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
