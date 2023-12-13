#ifndef _SUNXI_JTAG_H_
#define _SUNXI_JTAG_H_

#define CFG_SYS_BAUDRATE 115200    /* br */
#define CFG_SYS_CPU_CLK_CUSTOM 0   /* place desired CPU clk here */
#define CFG_SYS_UART 0             /* uart to use */
#define CFG_SYS_INIT_DEBUG 0       /* 1 to enable uart console in dram-init */

#if SOC_ID_V3S
#include <configs\V3s.h>

#elif SOC_ID_H3
#include <configs\H3.h>

#elif SOC_ID_H5
#include <configs\H5.h>

#elif SOC_ID_H616
#include <configs\H616.h>

#elif SOC_ID_R40

#elif SOC_ID_A64

#endif

/* mods configs\xxx.h */
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
 