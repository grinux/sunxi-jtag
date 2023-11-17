## IAR Embedded Workbench JTAG support for Allwinner SoCs. 

#### Currently tested using uSD to JTAG breakout board on: 
- [x] V3s (Lichee Pi Zero)
- [x] H3 (Orange Pi PC)
- [ ] H5 (Orange Pi PC2)
- [ ] T113-S3 (MangoPi MQ-R)

IAR allows out-of-the-box to run debugee in SUNXI SRAM by selecting the proper core and using a compatible linker configuration.  
To run the app in DRAM we need to initialize it previously.  

And this is why this side project was born.  

It allows us to link, load, run, and step-by-step debug in DRAM by using J-Link or a compatible JTAG emulator.  
It was done by porting the U-Boot clock and DRAM initialization code into an IAR macro called sunxi.mac.  

Steps:  
1. Setup IAR, J-Link, board, USB dongle(optional)
2. Clone repo git clone --recurse-submodules https://github.com/grinux/sunxi-jtag.git  
3. Open sunxi-jtag.ewp.
4. In sunxi_jtag.h change CFG_SYS_UART to desired console UART.
5. Build dram-app target.
6. Start debugging.
7. If USB dongle is connected you will see "Hello from DRAM" output.
8. Edit linker configuration sunxi-dram-app.icf to set desired code area size.
9. Enjoy running applications from DRAM without unwanted tricks.

As a side effect of this work, the project allows run the original U-Boot initialization code, and therefore sunxi.mac has two working modes:

1. macro initialization(default). All registers are accessed by JTAG then the main debugee is loaded.
2. binary initialization. Initialization executable loaded by JTAG then run it->evaluate results->load main debugee.

Performance between them is not noticeable. 
But if you want to use binary mode or just want to play with SUNXI-related U-Boot code under IAR there are additional steps:

10. Open sunxi-jtag.ewp and select a suitable dram-init target (V3s-dram-init, H3-dram-init, etc)
11. In sunxi_jtag.h set CFG_SYS_INIT_DEBUG to 1 to enable console output for dram-init target.
12. Build. File sunXX-YYY-dram-init.hex will be generated.
13. Debug if you want.
14. Change the target back to dram-app.
15. In Options->Debugger->Extra Options change --macro_param init_mode="mac" to --macro_param init_mode="bin". 
This tells sunxi.mac to go into binary mode and load and run generated hex file before main debugee.
16. Start debugging.
17. Check the debug log to see hex file loaded and executed properly.
18. Enjoy.

If you have any trouble write few words [here](https://github.com/grinux/sunxi-jtag/issues) or make PR


GPL-2.0 license inherited from U-Boot. Checkout [this](https://github.com/ARM-software/u-boot/blob/402465214395ed26d6fa72d9b6097c7adbf6a966/Licenses/README#L11) statement about using in proprietary projects. 
