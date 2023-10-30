#include "../u-boot/include/sunxi_gpio.h"
#if !_SUNXI_GPIO_C_ && !CFG_SYS_INIT_DEBUG && !DRAM_APP
/* disable GPIO for INIT */
#define sunxi_gpio_set_cfgbank(...)
#define sunxi_gpio_set_cfgpin(...)
#define sunxi_gpio_get_cfgbank(...) (0)
#define sunxi_gpio_get_cfgpin(...) (0)
#define sunxi_gpio_set_drv(...)
#define sunxi_gpio_set_drv_bank(...)
#define sunxi_gpio_set_pull(...)
#define sunxi_gpio_set_pull_bank(...)
#define sunxi_name_to_gpio(...) (0)
#endif
