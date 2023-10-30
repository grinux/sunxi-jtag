#ifndef _MOCK_H_
#define _MOCK_H_

/* mock unused and redirect/redefine some other u-boot entities 
 * define some macroses that can't be imported from u-boot headers due to 
 * GCC and ICCARM incompatibility 
 */


#define __printf(a,b)

#include <stdio.h>
#include <c/string.h>
#include <intrinsics.h>
#include <linux/kconfig.h>
#include <asm/barriers.h>

#define CONFIG_SPL_BUILD

#define CFG_SYS_BAUDRATE_TABLE {CFG_SYS_BAUDRATE}

#define _COUNT_TO_USEC(x)	((x) / 24)
#define timer_get_us() _COUNT_TO_USEC(get_ticks())

#define BIT(nr)			(1UL << (nr))
#define ALIGN(x,a)		__ALIGN_MASK((x),(typeof(x))(a)-1)
#define ALIGN_DOWN(x, a)	ALIGN((x) - ((a) - 1), (a))
#define __ALIGN_MASK(x,mask)	(((x)+(mask))&~(mask))
#define PTR_ALIGN(p, a)		((typeof(p))ALIGN((unsigned long)(p), (a)))
#define IS_ALIGNED(x, a)	(((x) & ((typeof(x))(a) - 1)) == 0)
#define REPEAT_BYTE(x)	        ((~0ul / 0xff) * (x))

#define unlikely(x) (x)
#define likely(x) (x)

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

/* disable unsupported and redefine other attrubutes */
#define __asm__ asm
#define __always_inline inline
#define __packed 
#define __maybe_unused
#define __section(a) 
#define __attribute_const__
#define __must_check
#define __aligned(...)
#define __attribute__(...)

/* types */
#define IO volatile

#define __le32 unsigned int
#define size_t unsigned int
#define __kernel_size_t unsigned int
#define ssize_t u32
#define uintptr_t unsigned int *
#define phys_addr_t unsigned int
#define phys_size_t unsigned int
#define dma_addr_t unsigned int

#define u8 unsigned char
#define u16 unsigned short int
#define u32 unsigned int
#define u64 unsigned long long

#define s8 signed char
#define s16 signed short int
#define s32 signed int
#define s64 signed long long

#define uint8_t u8
#define uint16_t u16
#define uint32_t u32
#define uint64_t u64

#define uchar u8
#define ulong u32
#define uint u32

#define __u8 u8
#define __u16 u16
#define __u32 u32
#define __u64 u64

#define __be32 unsigned int

#if !defined bool
#define bool unsigned char
#endif
#define false 0
#define true 1

/* used marco */
#define BITS_PER_BYTE 8
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

#define cpu_to_le32(x) ((u32)(x))
#define le32_to_cpu(x) ((u32)(x))

#define uswap_32(x) \
	((((x) & 0xff000000) >> 24) | \
	 (((x) & 0x00ff0000) >>  8) | \
	 (((x) & 0x0000ff00) <<  8) | \
	 (((x) & 0x000000ff) << 24))
#define be32_to_cpu(x)		uswap_32(x)

#define mb()		dsb()
#define __iormb()	dmb()
#define __iowmb()	dmb()

#define __arch_getb(a)			(*(volatile unsigned char *)(a))
#define __arch_getw(a)			(*(volatile unsigned short *)(a))
#define __arch_getl(a)			(*(volatile unsigned int *)(a))

#define __arch_putb(v,a)		(*(volatile unsigned char *)(a) = (v))
#define __arch_putw(v,a)		(*(volatile unsigned short *)(a) = (v))
#define __arch_putl(v,a)		(*(volatile unsigned int *)(a) = (v))

/* CFG_SYS_DEBUG_IO is preincluded for certain file */
#if CFG_SYS_INIT_DEBUG && CFG_SYS_DEBUG_IO 
                                
#define __raw_writeb(v,a)	({ u8 __v = v; printf ("W08: %x=%x\n", a, __v); __arch_putb(__v,a); __v; })
#define __raw_writew(v,a)	({ u16 __v = v; printf ("W16: %x=%x\n", a, __v); __arch_putw(__v,a); __v; })
#define __raw_writel(v,a)	({ u32 __v = v; printf ("W32: %x=%x\n", a, __v); __arch_putl(__v,a); __v;})

#define __raw_readb(a)		({ u8 __v = __arch_getb(a); printf ("R08: %x=%x\n", a, __v); __v; })
#define __raw_readw(a)		({ u16 __v = __arch_getw(a); printf ("R16: %x=%x\n", a, __v); __v; })
#define __raw_readl(a)		({ u32 __v = __arch_getl(a); printf ("R32: %x=%x\n", a, __v); __v; })

#define writeb(v,c)	({ printf ("W08: %x=%x\n", c, v); u8  __v = v; __iowmb(); __arch_putb(__v,c); __v; })
#define writew(v,c)	({ printf ("W16: %x=%x\n", c, v);u16 __v = v; __iowmb(); __arch_putw(__v,c); __v; })
#define writel(v,c)	({ printf ("W32: %x=%x\n", c, v);u32 __v = v; __iowmb(); __arch_putl(__v,c); __v; })

#define readb(c)	({ u8  __v = __arch_getb(c); __iormb(); printf ("R08: %x=%x\n", c, __v); __v; })
#define readw(c)	({ u16 __v = __arch_getw(c); __iormb(); printf ("R16: %x=%x\n", c, __v); __v; })
#define readl(c)	({ u32 __v = __arch_getl(c); __iormb(); printf ("R32: %x=%x\n", c, __v); __v; })
#define readlw(c)	({ u32 __v = __arch_getl(c); __iormb();/* printf ("WAI: %x=%x\n", c, __v);*/ __v; })
     
#else                
#define __raw_writeb(v,a)	__arch_putb(v,a)
#define __raw_writew(v,a)	__arch_putw(v,a)
#define __raw_writel(v,a)	__arch_putl(v,a)

#define __raw_readb(a)		__arch_getb(a)
#define __raw_readw(a)		__arch_getw(a)
#define __raw_readl(a)		__arch_getl(a)

#define writeb(v,c)	({ u8  __v = v; __iowmb(); __arch_putb(__v,c); __v; })
#define writew(v,c)	({ u16 __v = v; __iowmb(); __arch_putw(__v,c); __v; })
#define writel(v,c)	({ u32 __v = v; __iowmb(); __arch_putl(__v,c); __v; })

#define readb(c)	({ u8  __v = __arch_getb(c); __iormb(); __v; })
#define readw(c)	({ u16 __v = __arch_getw(c); __iormb(); __v; })
#define readl(c)	({ u32 __v = __arch_getl(c); __iormb(); __v; })

#endif /* _DEBUG_H_ */                
                
#define out_arch(type,endian,a,v)	__raw_write##type(cpu_to_##endian(v),a)
#define in_arch(type,endian,a)		endian##_to_cpu(__raw_read##type(a))

#define out_le32(a,v)	out_arch(l,le32,a,v)
#define out_le16(a,v)	out_arch(w,le16,a,v)

#define in_le32(a)	in_arch(l,le32,a)
#define in_le16(a)	in_arch(w,le16,a)

#define out_8(a,v)	__raw_writeb(v,a)
#define in_8(a)		__raw_readb(a)

#define clrbits(type, addr, clear) \
	out_##type((addr), in_##type(addr) & ~(clear))

#define setbits(type, addr, set) \
	out_##type((addr), in_##type(addr) | (set))

#define clrsetbits(type, addr, clear, set) \
	out_##type((addr), (in_##type(addr) & ~(clear)) | (set))

#define clrbits_le32(addr, clear) clrbits(le32, addr, clear)
#define setbits_le32(addr, set) setbits(le32, addr, set)
#define clrsetbits_le32(addr, clear, set) clrsetbits(le32, addr, clear, set)

#define clrbits_le16(addr, clear) clrbits(le16, addr, clear)
#define setbits_le16(addr, set) setbits(le16, addr, set)
#define clrsetbits_le16(addr, clear, set) clrsetbits(le16, addr, clear, set)

#define clrbits_8(addr, clear) clrbits(8, addr, clear)
#define setbits_8(addr, set) setbits(8, addr, set)
#define clrsetbits_8(addr, clear, set) clrsetbits(8, addr, clear, set)


#define min(x, y) ({				\
	typeof(x) _min1 = (x);			\
	typeof(y) _min2 = (y);			\
	(void) (&_min1 == &_min2);		\
	_min1 < _min2 ? _min1 : _min2; })

#define max(x, y) ({				\
	typeof(x) _max1 = (x);			\
	typeof(y) _max2 = (y);			\
	(void) (&_max1 == &_max2);		\
	_max1 > _max2 ? _max1 : _max2; })

#define clamp(val, lo, hi) min((typeof(val))max(val, lo), hi)

#define DIV_ROUND_CLOSEST(x, divisor)(			\
{							\
	typeof(x) __x = x;				\
	typeof(divisor) __d = divisor;			\
	(((typeof(x))-1) > 0 ||				\
	 ((typeof(divisor))-1) > 0 || (__x) > 0) ?	\
		(((__x) + ((__d) / 2)) / (__d)) :	\
		(((__x) - ((__d) / 2)) / (__d));	\
}							\
)

/* mock for unused macro */
#define EXT_CSD_EXTRACT_BOOT_PART(...)  (0)
#define EXT_CSD_EXTRACT_BOOT_ACK(...)   (0)
#define IS_SD(...)                      (0)
#define U_BOOT_ENV_CALLBACK(...)
#define SPL_LOAD_IMAGE_METHOD(...)

/* mock for unused constants */
#define EXT_CSD_BOOT_BUS_WIDTH          (0)
#define MMCSD_MODE_RAW                  (0)
#define MMCSD_MODE_EMMCBOOT             (0)
#define H_NOCLEAR                       (0) 
#define ETH_ALEN                        (1)
#define H_FORCE                         (0)
#define H_INTERACTIVE                   (0)
#define GD_FLG_RELOC                    (0)
#define GD_FLG_SERIAL_READY             (0x100)
#define GD_FLG_RECORD_OVF               (0x2000)

/* mock for unused strcuts */
struct spl_image_info;
struct spl_boot_device;
struct phy { u8 dummy; };
struct mmc {u8 ext_csd[2]; };
struct cmd_tbl;
enum env_operation { env_operation_DUMMY = 0 };
enum env_op { env_op_create, env_op_overwrite, env_op_delete };
enum boot_dev { BOOT_DEVICE_BOARD,BOOT_DEVICE_MMC1, BOOT_DEVICE_NAND,
BOOT_DEVICE_MMC2, BOOT_DEVICE_SPI };
enum env_location { ENVL_UNKNOWN, ENVL_NOWHERE, ENVL_FAT, ENVL_MMC, ENVL_UBI, 
ENVL_NAND, ENVL_SPI_FLASH};

/* mock for unused functions */
#define return_to_fel(...)              __no_operation()
#define eth_init_board()                __no_operation()
#define spl_init(...)                   __no_operation()
#define dcache_enable(...)              __no_operation()
#define himport_r(...)                  __no_operation()
#define env_set_hex(...)                __no_operation()
#define sprintf(...)                    __no_operation()
#define snprintf(...)                   __no_operation()
#define eth_env_set_enetaddr(...)       __no_operation()
#define env_set(...)                    __no_operation()
#define do_fixup_by_compat(...)         __no_operation()
#define fdt_fixup_ethernet(...)         __no_operation()
#define schedule(...)                   __no_operation()
#define debug(...)                      __no_operation()
#define pr_debug(...)                   __no_operation()
#define pr_err(...)                     __no_operation()
#define mmc_switch_part(...)            (0)
#define gd_of_root(...)                 (0)
#define sunxi_mmc_init(...)             (0)
#define sun4i_usb_phy_vbus_detect(...) (-1)    
#define blk_dread(...)                  (0)
#define generic_phy_get_by_name(...)    (1)
#define generic_phy_init(...)           (1)
#define crc32(...)                      (0)
#define env_get(...)                    (0)
#define eth_env_get_enetaddr(...)       (0)
#define dectoul(...)                    (0)
#define spl_in_proper()                 (0)
#define mmc_get_blk_desc(...)           ((struct blk_desc *)0)
#if V3s
#define clock_set_pll11(...)            __no_operation()
#endif            

/* redefines/redirects */
#if CFG_SYS_INIT_DEBUG || DRAM_APP 
#define preloader_console_init(...)     serial_init()
#else
#define preloader_console_init(...)     __no_operation()
#define printf(...)                     __no_operation()
#endif

#define panic(...)                      printf(__VA_ARGS__)
#define hang(...)                       while(1)
#define udelay(usec)                    __udelay(usec) 

/* mock for main global u-boot structure with somme additional fields */
__weak struct gd {
        u32 flags;
        u32 baudrate;
        u8 have_console;
        u8 cb[0x1000];
        u32 cb_size;        
        u32 ram_size;
        void const * fdt_blob;
        struct {
                u32 bi_boot_params;
        }*bd;
        struct {
                u32 lastinc;
                u32 tbl;
        } arch;
} *gd;
#define DECLARE_GLOBAL_DATA_PTR

/* prototypes */
void sdelay(unsigned long loops);
void __udelay(unsigned long usec);
unsigned long long get_ticks(void);
int timer_init(void);

#endif