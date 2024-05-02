## IAR Embedded Workbench JTAG support for Allwinner SoCs. 

#### Currently tested using uSD to JTAG breakout board on: 
- [x] V3s (Lichee Pi Zero)
- [x] H3 (Orange Pi PC)
- [x] H5 (Orange Pi PC2)
- [x] H616 (Orange Pi Zero2)
- [x] H6 (Orange Pi One Plus)
- [x] R40/A40/V40 (Banana Pi BPI-M2 Berry)
- [x] T113-S3 (MangoPi MQ-R)

IAR allows out-of-the-box to run debugee in SUNXI SRAM by selecting the proper core and using a compatible linker configuration.  
To run the code in DRAM it needs to be initialized previously.  

This package allows step-by-step debugging in DRAM by using J-Link or a compatible JTAG emulator.  
It was done by porting the U-Boot clock and DRAM initialization code into an IAR macro called sunxi.mac. 
Initialization by executing precompiled binary is also supported.  

Steps:  
1. Setup IAR 9.40 for only Cortex-A7, 9.50 and later for both A7 and A53, J-Link, board, USB dongle(optional)
2. Clone repo git clone --recurse-submodules https://github.com/grinux/sunxi-jtag.git  
3. Open sunxi-jtag.ewp or sunxi-jtag-94.ewp for EWARM 9.40
4. In sunxi_jtag.h change CFG_SYS_UART to desired console UART.
5. Build XX-dram-app target.
6. For Cortex-A53 core (H5 etc) run J-Link GDB server GUI and select Cortex-A53 core, JTAG interface, and GDB port 2331
or run console version with params: -select USB=0 -device Cortex-A53 -endian little -if JTAG -speed auto -noir -LocalhostOnly -nologtofile -port 2331
7. Start debugging. If IAR asks for memory configuration. Hit "Use factory" button.
8. If message box popups select desired initialization mode and set it permanently in project options later following message box instructions.
9. Run.
10. If the USB dongle is connected "Hello from DRAM" output appears.
11. Edit linker configuration sunxi.icf to set desired code/dram area size.
12. Enjoy running applications from DRAM without unwanted tricks.

The project allows the running of the original U-Boot initialization code, and therefore sunxi.mac has two working modes available to select while first loading:

1. Macro initialization(supports only V3s, H3, R40). Initialization is made by JTAG directly accessing necessary registers then the main debugee is loaded.
2. Binary initialization. Initialization executable loaded by JTAG then run it -> evaluate results -> load main debugee.

Performance between them is not noticeable. 
To use binary mode there are additional steps:

13. Select a suitable XX-dram-init target (V3s-dram-init, H3-dram-init, etc)
14. In sunxi_jtag.h set CFG_SYS_INIT_DEBUG to 1 to enable console output for dram-init target.
15. Build. File sunXX-YY-dram-init.hex will be generated.
16. Debug if it is needed.
17. Change the target back to XX-dram-app.
18. In Options->Debugger->Extra Options add or change --macro_param init_mode="bin". 
This tells sunxi.mac to go into binary mode and load and run the generated hex file before main debuggee.
19. Start debugging.
20. Check the debug log to see hex file loaded and executed properly.
21. Enjoy.

If you have any trouble write a few words [here](https://github.com/grinux/sunxi-jtag/issues) or make PR


GPL-2.0 license inherited from U-Boot. Checkout [this](https://github.com/ARM-software/u-boot/blob/402465214395ed26d6fa72d9b6097c7adbf6a966/Licenses/README#L11) statement about using in proprietary projects.
