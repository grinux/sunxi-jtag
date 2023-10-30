#ifndef _SUNXI_JTAG_H_
#define _SUNXI_JTAG_H_

#define CFG_SYS_BAUDRATE 115200    /* br */
#define CFG_SYS_CPU_CLK_CUSTOM 0   /* place desired CPU clk here */
#define CFG_SYS_UART 0             /* uart to use */
#define CFG_SYS_INIT_DEBUG 0       /* 1 to enable uart console in dram-init */

#include <mock.h>

/* u-boot/generated/autoconf.h
 * have to edit some symbols below
 */
#if V3s 
/*
 *
 * Automatically generated file; DO NOT EDIT.
 * U-Boot 2024.01-rc1 Configuration
 *
 */
#define CONFIG_ENV_SUPPORT 1
#define CONFIG_SUNXI_DRAM_DDR2_V3S 1
#define CONFIG_DISPLAY_BOARDINFO 1
#define CONFIG_CRC32 1
#define CONFIG_CMD_BOOTM 1
#define CONFIG_ENV_FAT_FILE "uboot.env"
#define CONFIG_CMD_EXT4 1
#define CONFIG_SMBIOS 1
#define CONFIG_TOOLS_FIT_PRINT 1
#define CONFIG_SYS_ARM_MMU 1
#define CONFIG_SYS_THUMB_BUILD 1
#define CONFIG_SYS_MAXARGS 16
#define CONFIG_MULTI_DTB_FIT_UNCOMPRESS_SZ 0x8000
#define CONFIG_SYS_MEM_TOP_HIDE 0x0
#define CONFIG_LOGLEVEL 4
#define CONFIG_SYS_MALLOC_LEN 0x220000
#define CONFIG_OF_BOARD_SETUP 1
#define CONFIG_ZLIB 1
#define CONFIG_SPL_SIZE_LIMIT 0x0
#define CONFIG_EFI_DT_FIXUP 1
#define CONFIG_LIB_ELF 1
#define CONFIG_OF_LIBFDT 1
#define CONFIG_CMD_EDITENV 1
#define CONFIG_SPL_USE_ARCH_MEMSET 1
#define CONFIG_PINCONF_RECURSIVE 1
#define CONFIG_PREBOOT ""
#define CONFIG_SYSRESET_CMD_RESET 1
#define CONFIG_SPL_FRAMEWORK 1
#define CONFIG_LMB_USE_MAX_REGIONS 1
#define CONFIG_BOOTMETH_VBE_SIMPLE 1
#define CONFIG_USE_ARCH_MEMCPY 1
#define CONFIG_BLK 1
#define CONFIG_SYS_SRAM_SIZE 0x0
#define CONFIG_USB 1
#define CONFIG_ARM_ASM_UNIFIED 1
#define CONFIG_OF_LIBFDT_OVERLAY 1
#define CONFIG_BOOTMETH_VBE_SIMPLE_OS 1
#define CONFIG_OF_SEPARATE 1
#define CONFIG_GENERATE_SMBIOS_TABLE 1
#define CONFIG_SYS_ARM_CACHE_WRITEBACK 1
#define CONFIG_GZIP 1
#define CONFIG_NR_DRAM_BANKS 1
#define CONFIG_SHA1 1
#define CONFIG_SUNXI_SRAM_ADDRESS 0x0
#define CONFIG_DM_REGULATOR 1
#define CONFIG_SPL_IMAGE "spl/u-boot-spl.bin"
#define CONFIG_WDT_SUNXI 1
#define CONFIG_ARMV7_SECURE_MAX_SIZE 0xbc00
#define CONFIG_HASH 1
#define CONFIG_CMD_CONSOLE 1
#define CONFIG_CMD_BOOTD 1
#define CONFIG_EFI_UNICODE_CAPITALIZATION 1
#define CONFIG_SYS_NS16550 1
#define CONFIG_MMC_SUNXI 1
#define CONFIG_SYS_CLK_FREQ 1008000000
#define CONFIG_SDP_LOADADDR 0x0
#define CONFIG_DEFAULT_FDT_FILE ""
#define CONFIG_SPL_SYS_MALLOC_F 1
#define CONFIG_OF_TRANSLATE 1
#define CONFIG_USB1_VBUS_PIN ""
#define CONFIG_SYS_MONITOR_LEN 786432
#define CONFIG_USB0_VBUS_DET ""
#define CONFIG_BOOTSTAGE_STASH_ADDR 0x0
#define CONFIG_SPL_STACK_R_MALLOC_SIMPLE_LEN 0x100000
#define CONFIG_USB2_VBUS_PIN ""
#define CONFIG_USE_PREBOOT 1
#define CONFIG_SPL_SPRINTF 1
#define CONFIG_HAVE_PRIVATE_LIBGCC 1
#define CONFIG_BOOTM_PLAN9 1
#define CONFIG_SYS_MMC_ENV_PART 0
#define CONFIG_CMD_BDI 1
#define CONFIG_ARMV7_PSCI_NR_CPUS 4
#define CONFIG_ARM 1
#define CONFIG_CREATE_ARCH_SYMLINK 1
#define CONFIG_SPL_STACK_R_ADDR 0x4fe00000
#define CONFIG_SPL_SYS_THUMB_BUILD 1
#define CONFIG_DM_SEQ_ALIAS 1
#define CONFIG_SYS_RX_ETH_BUFFER 4
#define CONFIG_PRE_CONSOLE_BUFFER 1
#define CONFIG_GMAC_TX_DELAY 0
#define CONFIG_OF_REAL 1
#define CONFIG_SPECIFY_CONSOLE_INDEX 1
#define CONFIG_CMD_BOOTEFI_HELLO_COMPILE 1
#define CONFIG_CMD_SLEEP 1
#define CONFIG_EFI_LOADER 1
#define CONFIG_USB_GADGET_VENDOR_NUM 0x1f3a
#define CONFIG_FIT_EXTERNAL_OFFSET 0x0
#define CONFIG_PRE_CON_BUF_SZ 4096
#define CONFIG_OF_LIST "sun8i-v3s-licheepi-zero"
#define CONFIG_CMD_SAVEENV 1
#define CONFIG_ARCH_SUPPORTS_LTO 1
#define CONFIG_SYSRESET 1
#define CONFIG_CLK 1
#define CONFIG_EFI_LOAD_FILE2_INITRD 1
#define CONFIG_SPL_BSS_START_ADDR 0x4ff80000
#define CONFIG_BINMAN 1
#define CONFIG_SPL_MAX_SIZE 0x5fa0
#define CONFIG_DM_REGULATOR_FIXED 1
#define CONFIG_SYS_CPU "armv7"
#define CONFIG_FIT_FULL_CHECK 1
#define CONFIG_PHY_RESET_DELAY 0
#define CONFIG_SPL_POWER 1
#define CONFIG_TOOLS_FIT 1
#define CONFIG_USB_GADGET_PRODUCT_NUM 0x1010
#define CONFIG_CC_OPTIMIZE_FOR_SIZE 1
#define CONFIG_CMD_BOOTFLOW 1
#define CONFIG_POWER 1
#define CONFIG_DM_MMC 1
#define CONFIG_CC_HAS_ASM_INLINE 1
#define CONFIG_USE_PRIVATE_LIBGCC 1
#define CONFIG_ARCH_FIXUP_FDT_MEMORY 1
#define CONFIG_BUILD_TARGET ""
#define CONFIG_SUNXI_DRAM_DW 1
#define CONFIG_EFI_LOADER_HII 1
#define CONFIG_DM_SERIAL 1
#define CONFIG_ETH 1
#define CONFIG_DM_I2C 1
#define CONFIG_PXE_UTILS 1
#define CONFIG_TOOLS_FIT_RSASSA_PSS 1
#define CONFIG_USB0_ID_DET ""
#define CONFIG_SPL_BINMAN_UBOOT_SYMBOLS 1
#define CONFIG_USB_GADGET_MANUFACTURER "Allwinner Technology"
#define CONFIG_REGEX 1
#define CONFIG_EFI_PARTITION_ENTRIES_NUMBERS 56
#define CONFIG_CMD_BOOTEFI_BOOTMGR 1
#define CONFIG_DOS_PARTITION 1
#define CONFIG_PINCONF 1
#define CONFIG_SPL_SYS_MALLOC_SIMPLE 1
#define CONFIG_CMD_ENV_EXISTS 1
#define CONFIG_SUNXI_NO_PMIC 1
#define CONFIG_IMX_DCD_ADDR 0x00910000
#define CONFIG_ENV_FAT_INTERFACE "mmc"
#define CONFIG_BOOT_DEFAULTS 1
#define CONFIG_SPL_STACK 0x8000
#define CONFIG_EFI_PLATFORM_LANG_CODES "en-US"
#define CONFIG_TEXT_BASE 0x42e00000
#define CONFIG_ENV_SIZE 0x10000
#define CONFIG_STACK_SIZE 0x1000000
#define CONFIG_FIT_PRINT 1
#define CONFIG_IDENT_STRING " Allwinner Technology"
#define CONFIG_SYS_MMC_ENV_DEV 0
#define CONFIG_CMDLINE_EDITING 1
#define CONFIG_TOOLS_FIT_SIGNATURE_MAX_SIZE 0x10000000
#define CONFIG_CMD_SETEXPR 1
#define CONFIG_BOOTM_EFI 1
#define CONFIG_BOOTMETH_EFILOADER 1
#define CONFIG_DM_DEVICE_REMOVE 1
#define CONFIG_SYS_UBOOT_START 0x42e00000
#define CONFIG_SUNXI_DRAM_DDR2 1
#define CONFIG_PLATFORM_ELFENTRY "_start"
#define CONFIG_TOOLS_MD5 1
#define CONFIG_CLK_SUNXI 1
#define CONFIG_MACH_SUN8I_V3S 1
#define CONFIG_TOOLS_SHA1 1
#define CONFIG_SYS_LOAD_ADDR 0x42000000
#define CONFIG_SYS_CACHELINE_SIZE 64
#define CONFIG_SPL_IMAGE_TYPE_SUNXI_EGON 1
#define CONFIG_CMD_EXPORTENV 1
#define CONFIG_CMD_MMC 1
#define CONFIG_DM_EVENT 1
#define CONFIG_DM_DEV_READ_INLINE 1
#define CONFIG_PINCTRL 1
#define CONFIG_REQUIRE_SERIAL_CONSOLE 1
#define CONFIG_CMD_RANDOM 1
#define CONFIG_WDT 1
#define CONFIG_USB_GADGET 1
#define CONFIG_SYS_BOOTM_LEN 0x800000
#define CONFIG_ARCH_SUNXI 1
#define CONFIG_BOOTM_VXWORKS 1
#define CONFIG_BOOTM_LINUX 1
#define CONFIG_DM_REGULATOR_COMMON 1
#define CONFIG_SUNXI_MINIMUM_DRAM_MB 64
#define CONFIG_FS_FAT 1
#define CONFIG_BLUETOOTH_DT_DEVICE_FIXUP ""
#define CONFIG_BINMAN_FDT 1
#define CONFIG_EFI_PARTITION 1
#define CONFIG_CMD_PART 1
#define CONFIG_AUTO_COMPLETE 1
#define CONFIG_TOOLS_FIT_FULL_CHECK 1
#define CONFIG_SPL_SERIAL_PRESENT 1
#define CONFIG_SIMPLE_BUS 1
#define CONFIG_PINCTRL_SUNXI 1
#define CONFIG_CLANG_VERSION 0
#define CONFIG_SYS_NS16550_REG_SIZE -4
#define CONFIG_CMD_CYCLIC 1
#define CONFIG_CMD_CRC32 1
#define CONFIG_SPL_GPIO 1
#define CONFIG_SPL_SYS_MALLOC_CLEAR_ON_INIT 1
#define CONFIG_PRINTF 1
#define CONFIG_USB_GADGET_VBUS_DRAW 2
#define CONFIG_I2C 1
#define CONFIG_SYS_BOARD "sunxi"
#define CONFIG_BOOTM_NETBSD 1
#define CONFIG_RESET_SUNXI 1
#define CONFIG_TOOLS_CRC32 1
#define CONFIG_SYS_MMCSD_FS_BOOT 1
#define CONFIG_LEGACY_IMAGE_FORMAT 1
#define CONFIG_SYS_CONFIG_NAME "sun8i"
#define CONFIG_FWU_NUM_IMAGES_PER_BANK 2
#define CONFIG_SUN6I_PRCM 1
#define CONFIG_EFI_DEVICE_PATH_TO_TEXT 1
#define CONFIG_CRC8 1
#define CONFIG_SPL_OF_LIBFDT_ASSUME_MASK 0xff
#define CONFIG_OF_LIBFDT_ASSUME_MASK 0x0
#define CONFIG_PRE_CON_BUF_ADDR 0x4f000000
#define CONFIG_DM_GPIO 1
#define CONFIG_WATCHDOG 1
#define CONFIG_MMC_QUIRKS 1
#define CONFIG_ARMV7_VIRT 1
#define CONFIG_TOOLS_SHA256 1
#define CONFIG_USE_ARCH_MEMSET 1
#define CONFIG_PINCTRL_SUN8I_V3S 1
#define CONFIG_SHA256 1
#define CONFIG_PINMUX 1
#define CONFIG_DM_RESET 1
#define CONFIG_DM_WARN 1
#define CONFIG_SPL_USE_TINY_PRINTF 1
#define CONFIG_CMD_LOADXY_TIMEOUT 90
#define CONFIG_SUNXI_GPIO 1
#define CONFIG_SYS_CBSIZE 1024
#define CONFIG_USB0_VBUS_PIN ""
#define CONFIG_PARTITION_UUIDS 1
#define CONFIG_ENV_VARS_UBOOT_CONFIG 1
#define CONFIG_WATCHDOG_TIMEOUT_MSECS 16000
#define CONFIG_SYS_ARM_CACHE_CP15 1
#define CONFIG_CMD_GO 1
#define CONFIG_SPL_SYS_NS16550_SERIAL 1
#define CONFIG_EFI_CAPSULE_MAX 15
#define CONFIG_ENV_SOURCE_FILE ""
#define CONFIG_ISO_PARTITION 1
#define CONFIG_CONSOLE_FLUSH_SUPPORT 1
#define CONFIG_EFI_DEVICE_PATH_UTIL 1
#define CONFIG_CPU_V7_HAS_VIRT 1
#define CONFIG_SYS_MALLOC_CLEAR_ON_INIT 1
#define CONFIG_EVENT_DYNAMIC 1
#define CONFIG_BOOTDELAY 2
#define CONFIG_EFI_EBBR_2_1_CONFORMANCE 1
#define CONFIG_CMD_IMI 1
#define CONFIG_SPL_BSS_MAX_SIZE 0x80000
#define CONFIG_GPIO 1
#define CONFIG_SYS_HZ 1000
#define CONFIG_CYCLIC_MAX_CPU_TIME_US 1000
#define CONFIG_DEVICE_TREE_INCLUDES ""
#define CONFIG_EFI_UNICODE_COLLATION_PROTOCOL2 1
#define CONFIG_CMD_FS_GENERIC 1
#define CONFIG_SPL_LEGACY_BLOCK 1
#define CONFIG_SPRINTF 1
#define CONFIG_SUPPORT_OF_CONTROL 1
#define CONFIG_CMD_BLOCK_CACHE 1
#define CONFIG_SPL_ARMV7_SET_CORTEX_SMPEN 1
#define CONFIG_DISTRO_DEFAULTS 1
#define CONFIG_SYS_LONGHELP 1
#define CONFIG_BOOTMETH_VBE 1
#define CONFIG_ENV_MIN_ENTRIES 64
#define CONFIG_CMD_EXT2 1
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_DATA_PART_OFFSET 0x10
#define CONFIG_ARMV7_PSCI_0_1 1
#define CONFIG_CLK_SUN6I_A31_R 1
#define CONFIG_LAST_STAGE_INIT 1
#define CONFIG_DM_STDIO 1
#define CONFIG_SYS_PROMPT_HUSH_PS2 "> "
#define CONFIG_LOCALVERSION ""
#define CONFIG_SERIAL 1
#define CONFIG_SPL_STRTO 1
#define CONFIG_SUPPORT_SPL 1
#define CONFIG_CMDLINE 1
#define CONFIG_DTOC 1
#define CONFIG_SPL_LIBCOMMON_SUPPORT 1
#define CONFIG_SPL_BANNER_PRINT 1
#define CONFIG_BOOTCOMMAND "run distro_bootcmd"
#define CONFIG_CMD_LOADB 1
#define CONFIG_CMD_RUN 1
#define CONFIG_CMD_PINMUX 1
#define CONFIG_FS_FAT_MAX_CLUSTSIZE 65536
#define CONFIG_SYS_PROMPT "=> "
#define CONFIG_LINKER_LIST_ALIGN 4
#define CONFIG_CMD_MEMORY 1
#define CONFIG_HUSH_PARSER 1
#define CONFIG_CMD_BOOTZ 1
#define CONFIG_SPL_IMAGE_TYPE "sunxi_egon"
#define CONFIG_SPL_MMC 1
#define CONFIG_BOARD_LATE_INIT 1
#define CONFIG_CMD_XIMG 1
#define CONFIG_CMD_ECHO 1
#define CONFIG_SPL_HAS_BSS_LINKER_SECTION 1
#define CONFIG_SPL 1
#define CONFIG_TOOLS_FIT_VERBOSE 1
#define CONFIG_MMC_WRITE 1
#define CONFIG_LOCALVERSION_AUTO 1
#define CONFIG_COUNTER_FREQUENCY 24000000
#define CONFIG_DRAM_CLK 360
#define CONFIG_ARMV7_PSCI 1
#define CONFIG_SYS_SRAM_BASE 0x0
#define CONFIG_SPL_SYS_STACK_F_CHECK_BYTE 0xaa
#define CONFIG_SPL_LEGACY_IMAGE_FORMAT 1
#define CONFIG_SYS_BOOT_RAMDISK_HIGH 1
#define CONFIG_MMC_HW_PARTITIONING 1
#define CONFIG_SPL_SYS_MALLOC_F_LEN 0x2000
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_USE_SECTOR 1
#define CONFIG_SYS_ARCH "arm"
#define CONFIG_CYCLIC 1
#define CONFIG_MD5 1
#define CONFIG_CMD_DM 1
#define CONFIG_SPL_BSS_LIMIT 1
#define CONFIG_LIB_UUID 1
#define CONFIG_ARMV7_LPAE 1
#define CONFIG_SYS_CACHE_SHIFT_6 1
#define CONFIG_SUPPORT_ACPI 1
#define CONFIG_HAS_VBAR 1
#define CONFIG_SPL_SERIAL 1
#define CONFIG_SPL_BINMAN_SYMBOLS 1
#define CONFIG_USE_BOOTCOMMAND 1
#define CONFIG_CPU_V7A 1
#define CONFIG_LMB 1
#define CONFIG_EXPERT 1
#define CONFIG_CMD_EFICONFIG 1
#define CONFIG_BOOTMETH_EXTLINUX 1
#define CONFIG_MMC_VERBOSE 1
#define CONFIG_SYS_SOC "sunxi"
#define CONFIG_BOOTMETH_GLOBAL 1
#define CONFIG_MMC 1
#define CONFIG_BAUDRATE 115200
#define CONFIG_CHARSET 1
#define CONFIG_EVENT 1
#define CONFIG_ARMV7_NONSEC 1
#define CONFIG_SPL_SEPARATE_BSS 1
#define CONFIG_ARCH_SUPPORT_PSCI 1
#define CONFIG_CC_IS_GCC 1
#define CONFIG_MISC_INIT_R 1
#define CONFIG_SPL_TARGET ""
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR 0x40
#define CONFIG_ENV_FAT_DEVICE_AND_PART ":auto"
#define CONFIG_SPL_SHA1 1
#define CONFIG_FAT_WRITE 1
#define CONFIG_PARTITIONS 1
#define CONFIG_CMD_ITEST 1
#define CONFIG_LMB_MAX_REGIONS 16
#define CONFIG_CLK_SUN8I_V3S 1
#define CONFIG_DISPLAY_CPUINFO 1
#define CONFIG_CMD_GPIO 1
#define CONFIG_SYS_RELOC_GD_ENV_ADDR 1
#define CONFIG_DM_USB 1
#define CONFIG_BOOTSTAGE_STASH_SIZE 0x1000
#define CONFIG_SERIAL_PRESENT 1
#define CONFIG_OF_CONTROL 1
#define CONFIG_SYS_MMC_MAX_BLK_COUNT 65535
#define CONFIG_FS_EXT4 1
#define CONFIG_SPL_LDSCRIPT "arch/arm/cpu/armv7/sunxi/u-boot-spl.lds"
#define CONFIG_CMD_FDT 1
#define CONFIG_TOOLS_FIT_SIGNATURE 1
#define CONFIG_CMD_LOADS 1
#define CONFIG_CMD_FAT 1
#define CONFIG_TOOLS_LIBCRYPTO 1
#define CONFIG_MKIMAGE_DTC_PATH "dtc"
#define CONFIG_EFI_VAR_BUF_SIZE 65536
#define CONFIG_BLOCK_CACHE 1
#define CONFIG_SPL_SHA256 1
#define CONFIG_PYLIBFDT 1
#define CONFIG_CPU_V7_HAS_NONSEC 1
#define CONFIG_TOOLS_OF_LIBFDT 1
#define CONFIG_MMC_SUNXI_SLOT_EXTRA -1
#define CONFIG_SUNXI_DRAM_DW_16BIT 1
#define CONFIG_EFI_PARTITION_ENTRIES_OFF 0
#define CONFIG_SYS_XTRACE 1
#define CONFIG_GCC_VERSION 90400
#define CONFIG_HAVE_TEXT_BASE 1
#define CONFIG_SPL_RAW_IMAGE_SUPPORT 1
#define CONFIG_MENU 1
#define CONFIG_LIB_RAND 1
#define CONFIG_BOOTSTD 1
#define CONFIG_CONS_INDEX 1
#define CONFIG_DEFAULT_DEVICE_TREE "sun8i-v3s-licheepi-zero"
#define CONFIG_SPL_TEXT_BASE 0x00060
#define CONFIG_SYSRESET_WATCHDOG_AUTO 1
#define CONFIG_SPL_LOGLEVEL 4
#define CONFIG_CMD_BOOTEFI 1
#define CONFIG_FIT 1
#define CONFIG_AUTOBOOT 1
#define CONFIG_ENV_MAX_ENTRIES 512
#define CONFIG_FWU_NUM_BANKS 2
#define CONFIG_SPL_PAD_TO 0x8000
#define CONFIG_PINCTRL_FULL 1
#define CONFIG_TOOLS_SHA384 1
#define CONFIG_DM 1
#define CONFIG_CMD_GPT 1
#define CONFIG_DM_KEYBOARD 1
#define CONFIG_HAS_THUMB2 1
#define CONFIG_BOOTM_RTEMS 1
#define CONFIG_SYSRESET_WATCHDOG 1
#define CONFIG_SYS_MALLOC_F 1
#define CONFIG_ERR_PTR_OFFSET 0x0
#define CONFIG_SPL_PRINTF 1
#define CONFIG_SUPPORT_RAW_INITRD 1
#define CONFIG_SPL_USE_ARCH_MEMCPY 1
#define CONFIG_SPL_PAYLOAD "u-boot.bin"
#define CONFIG_CMD_IMPORTENV 1
#define CONFIG_SYS_FDT_PAD 0x3000
#define CONFIG_DRAM_ZQ 14779
#define CONFIG_STRTO 1
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION 1
#define CONFIG_PINCTRL_GENERIC 1
#define CONFIG_SYS_MALLOC_F_LEN 0x2000
#define CONFIG_SUNXI_GEN_SUN6I 1
#define CONFIG_CMD_ELF 1
#define CONFIG_MACH_SUN8I 1
#define CONFIG_SUNXI_DRAM_MAX_SIZE 0x80000000
#define CONFIG_SYS_PBSIZE 1024
#define CONFIG_USB3_VBUS_PIN ""
#define CONFIG_SPL_LIBGENERIC_SUPPORT 1
#define CONFIG_TOOLS_SHA512 1
#define CONFIG_RANDOM_UUID 1
#define CONFIG_BOOTMETH_VBE_REQUEST 1
#define CONFIG_OF_TAG_MIGRATE 1
#define CONFIG_SAVEENV 1
#define CONFIG_ENV_IS_IN_FAT 1
#define CONFIG_SYS_ARM_ARCH 7
#define CONFIG_CMD_SOURCE 1
#define CONFIG_EFI_VARIABLE_FILE_STORE 1
#define CONFIG_CMD_SYSBOOT 1
#define CONFIG_INPUT 1
#define CONFIG_EFI_ECPT 1
#define CONFIG_SPL_STACK_R 1

#undef CONFIG_DM_SERIAL /* don't use driver model */
#include <configs/sun8i.h>

#elif H3

#undef CONFIG_DM_SERIAL
#include <configs/sun8i.h>

#elif H5

#undef CONFIG_DM_SERIAL
#include <configs/sun8i.h>

#elif R40

#elif A64

#endif

/* mods of u-boot/generated/autoconf.h */
#undef CONFIG_SPL_BANNER_PRINT                  /* don't print U-Boot banner */
#undef CONFIG_CONS_INDEX
#define CONFIG_CONS_INDEX (CFG_SYS_UART + 1)    /* redefine UART */
#undef CONFIG_BAUDRATE
#define CONFIG_BAUDRATE CFG_SYS_BAUDRATE        /* redefine UART baud */        

#if CFG_SYS_CPU_CLK_CUSTOM > 0 
#undef CONFIG_SYS_CLK_FREQ
#define CONFIG_SYS_CLK_FREQ CFG_SYS_CPU_CLK_CUSTOM
#endif

/* prototypes */
void board_init_f(ulong dummy);

#endif
 