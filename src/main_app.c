#include "sunxi_dram_app.h"

struct gd _gd = { .baudrate = CFG_SYS_BAUDRATE };

void main(void)
{
        /* store uart bauddrate */
        gd = &_gd;

        /* set desired cpu clock in hz */
        /* clock_set_pll1(408000000); */
        
        /* enable uart clock */    
        clock_init_uart();      

        /* 
         * set uart gpio
         * init uart 
         */
        board_init_f(0);
        
        printf("Hello from DRAM\n");  
        
        while(1);
}
