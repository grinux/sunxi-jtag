#ifndef _SUNXI_DRAM_APP_H_
#define _SUNXI_DRAM_APP_H_

#include "sunxi_jtag.h"

void clock_init_uart(void);

/* mock for unused functions in board_init_f() */
__weak int clock_init(void) { return 0; } /* clock and */
__weak int timer_init(void) { return 0; } /* timer already initialized by dram-init */
__weak void sunxi_board_init(void) {}

#endif
 