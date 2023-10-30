# sunxi-jtag
IAR Embedded Workbench JTAG support for Allwinner SoCs.

IAR allows to loading and running of applications out-of-the-box in SUNXI SRAM by selecting the proper core and using a compatible linker configuration.  
To run the app in DRAM we need to initialize it previously.  

And this is why this side project was born.  

It allows us to link, load, run and step-by-step debug in DRAM by using J-Link or a compatible JTAG emulator.  
It was done by porting the U-Boot clock and DRAM initialization code into an IAR macro called sunxi.mac.  

Steps:  
1. Setup IAR, J-Link, board, USB dongle(optional)
2. Clone repo.
3. Clone U-Boot from sunxi-jtag dir: git clone --depth=1 https://github.com/u-boot/u-boot.git 
4. Open sunxi-jtag.ewp.
5. In sunxi_jtag.h change CFG_SYS_UART to desired console UART.
6. Build dram-app target.
7. Start debugging.
8. If USB dongle is connected you will see "Hello from DRAM" output.
9. Edit linker configuration sunxi-dram-app.icf to set desired code area size.
10. Enjoy running application from DRAM without unwanted tricks.

As a side effect of this work, the project allows to run the original U-Boot initialization code, and therefore sunxi.mac has two working modes:

1. macro initialization(default). All registers are accessed by JTAG then the main debugee is loaded.
2. binary initialization.  Initialization executable loaded by JTAG then run it->evaluate results->load main debugee.

Performance between them is not noticeable. 
But if you want to use binary mode or just want to play with SUNXI-related U-Boot code under IAR there is additional steps:

11. Open sunxi-jtag.ewp and select dram-init target.
12. In sunxi-jtag.h set CFG_SYS_INIT_DEBUG to 1 to enable console output for dram-init target.
13. Build. File sunXX-YYY-dram-init.hex will be generated.
14. Debug if you want.
15. Change the target back to dram-app.
16. In Options->Debugger->Extra Options change --macro_param init_mode="mac" to --macro_param init_mode="bin". 
This tells sunxi.mac to go into bin mode and load and run the generated hex file before main debugee.
17. Start debugging.
18. Check the debug log to see hex file loaded and executed properly.
19. Enjoy.

Based on U-Boot 29427e6 and if you have any build issues remove u-boot folder and:
1. git clone https://github.com/u-boot/u-boot.git 
2. cd u-boot
3. git reset --hard 29427e6 
4. try to rebuild

If you still have any troubles write few words here https://github.com/grinux/sunxi-jtag/issues

GPL-2.0 license inherited from U-Boot
