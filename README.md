KreyosFirmware-gcc-elf
======================

Key differences from KreyosFirmware-IAR7:
- Does not build with IAR7
- Has no bluetooth or motion sensing support, as those were binary blobs
- All unused Contiki files are removed
- Builds with TI's gcc-elf
  http://www.ti.com/tool/msp430-gcc-opensource
  https://copr.fedoraproject.org/coprs/nielsenb/msp430-development-tools/

Build Instruction:
1. Run make in the Watch directory
2. In objs.msp430 two files will be created; watch.elf and watch.txt
3. watch.txt is in the appropriate format for flashing the Kreyos, using Kreyos' BSL.exe through Windows or Wine.
4. Enjoy your smart watch, now even dumber than before!
