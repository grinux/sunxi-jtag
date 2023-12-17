#include "sunxi_jtag.h"

struct gd _gd = { .baudrate = CFG_SYS_BAUDRATE };

#pragma location = "DRAM_INIT_RESULTS"
struct {
        unsigned int sys_clk;
        unsigned int dram_clk;
        unsigned int dram_size;
        unsigned short magic;
} init_results;

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
        
        init_results.sys_clk = CONFIG_SYS_CLK_FREQ / 1000000;
        init_results.dram_clk = CONFIG_DRAM_CLK;
        init_results.dram_size = gd->ram_size >> 20;
        init_results.magic = 0xBABE;

        dram_init_done();
}
