KreyosFirmware-IAR7
===================

Build Instruction:  
1. Install IAR MSP-430 7.x, the 30-day evaluation version works fine  
https://www.iar.com/iar-embedded-workbench/texas-instruments/msp430/  

2. Install and configure MinGW and msys  
http://www.mingw.org/Welcome_to_MinGW_org  
http://www.mingw.org/wiki/Getting_Started

3. Using the MinGW Shell, run make -f Makefile.msp430 to create watch.txt in the objs.msp430 directory.  

4. Copy watch.txt to the KreyosFirmware directory

5. Connect the watch to the charger cradle, and the cradle to a USB port. Press all four buttons on the watch, until it reboots  

6. For a few seconds, the watch will accept being programmed via BSL. Run run.bat  

7. Provided that the COM port autodetection worked, the watch should be programmed and reboot without further user intervention  
