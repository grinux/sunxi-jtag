#include "sunxi_jtag.h"

struct gd _gd = { .baudrate = CFG_SYS_BAUDRATE };

#pragma location = "DRAM_INIT_DONE"
void dram_init_done(void)
{
        while(1);
}

void main(void)
{
        gd = &_gd;
        
        board_init_f(0);

        printf("Init done\n");  
        
        __asm volatile ("mov r12, %0 \n"
                        "mov r11, %1 \n"
                        "mov r10, %2"
                                ::"r"(CONFIG_SYS_CLK_FREQ / 1000000),
                                  "r" (CONFIG_DRAM_CLK),
                                  "r"(gd->ram_size >> 20));
        dram_init_done();
}
