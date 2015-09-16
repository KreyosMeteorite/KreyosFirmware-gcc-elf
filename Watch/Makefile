DEFCCPATH = "/opt/ti/gcc"
CCPATHFILE = ccpath.local
CCPATH ="$$(cat $(CCPATHFILE) 2>/dev/null || echo $(DEFCCPATH))"

CCINCLUDES = ${CCPATH}/include
WINE    =
CC      = $(CCPATH)/bin/msp430-elf-gcc
LINK    = $(CCPATH)/bin/msp430-elf-gcc
OBJCOPY = $(CCPATH)/bin/msp430-elf-objcopy
ECHO	= echo
OBJDIR  = objs.msp430

BUILDNUM = buildnum
FWVERSION ="1.1.0.$$(cat $(BUILDNUM))"

LSCRIPT = build/iwatch-msp430f5438a.ld

CFLAGS  = -g -std=c99 --debug -mlarge -ffunction-sections -fdata-sections -fno-builtin -I${CCPATH}/include -D__MSP430F5438A__ -mmcu=MSP430F5438A -DFWVERSION=\"$(FWVERSION)\"
CFLAGS2 = -Os -MMD
LDFLAGS = ${CFLAGS} -Wl,-m,msp430X -L${CCPATH}/include/ -T${LSCRIPT} -Wl,--gc-sections -Wl,-Map=$(OBJDIR)/watch.map

ALL_DEFINES = RELEASE_VERSION AUTOSTART_ENABLE=1 HAVE_BLE=0 AMX_ANSIONLY=1 BYTE_ORDER=LITTLE_ENDIAN PAWN_CELL_SIZE=16 HAVE_ALLOCA_H=0 PRODUCT_W001=1 AMX_NATIVETABLE=window_natives
ALL_INCLUDEDIRS = \
	. \
	core \
	core/lib \
	platform/common \
	platform/iwatch \

#######################################
# source files
CORE   = \
	core/cfs/cfs-coffee.c \
	core/sys/ctimer.c \
	core/sys/etimer.c \
	core/sys/energest.c \
	core/sys/process.c \
	core/sys/rtimer.c \
	core/sys/stimer.c \
	core/sys/timer.c \
	core/lib/assert.c \
	core/lib/list.c

COMMON = \
	platform/common/memlcd.c

PLATFORM = \
	platform/iwatch/tornout.c \
	platform/iwatch/backlight.c \
	platform/iwatch/battery.c \
	platform/iwatch/button.c \
	platform/iwatch/clock.c \
	platform/iwatch/flash.c \
	platform/iwatch/i2c.c \
	platform/iwatch/isr.c \
	platform/iwatch/msp430.c \
	platform/iwatch/contiki-exp5438-main.c \
	platform/iwatch/rtc.c \
	platform/iwatch/spiflash.c \
	platform/iwatch/printf.c \
	platform/iwatch/system.c \
	platform/iwatch/rtimer-arch.c \
	platform/iwatch/uart1-putchar.c \
	platform/iwatch/watchdog.c \
	platform/iwatch/Template_Driver.c \

#platform/iwatch/progam.c \

GRLIB0 = \
	circle.c \
	charmap.c \
	context.c \
	image.c \
	line.c \
	rectangle.c \
	triagle.c \
	string.c

GRLIB_FONTS = \
	fontgothic14.c \
	fontgothic18.c \
	fontgothic18b.c \
	fontgothic24b.c \
	fontgothic28.c \
	fontgothic28b.c \
	fontnimbus30.c \
	fontnimbus38.c \
	fontnimbus46.c \
	fontnimbus52.c \
	fontnimbus34.c \
	fontnimbus40.c \
	fontnimbus50.c \
	fontnimbus91.c \
	fonticon16.c \
	fonticon32.c \
	fonticon48.c \
	fontunicode.c \
	logoimg.c

GRLIB = $(addprefix grlib/, $(GRLIB0)) $(addprefix grlib/fonts/, $(GRLIB_FONTS))

AMX0 = amx.c amxwindow.c amxstring.c amxcons.c
AMX = $(addprefix pawnscript/, $(AMX0))

WATCH = \
	watch/analog-watch.c \
	watch/configtime.c \
	watch/countdown.c \
	watch/controls.c \
	watch/charging.c \
	watch/digit-watch.c \
	watch/window.c \
	watch/stopwatch.c \
	watch/names.c \
	watch/cordic.c \
	watch/calendar.c \
	watch/stopwatch.c \
	watch/worldclock.c \
	watch/host.c \
	watch/reset.c \
	watch/status.c \
	watch/welcome.c \
	watch/menu.c \

SRCS = $(CORE) $(WATCH) $(PLATFORM) $(GRLIB) $(AMX) $(COMMON)
OBJS0 = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR)/, $(OBJS0))

ifeq ($(WINE), )
DEPFILES = $(OBJS:.o=.d)
endif

#####################
# rules to build the object files
$(OBJDIR)/%.o: %.c
	@$(ECHO) "Compiling $<"
	@test -d $(OBJDIR) || mkdir -pm 775 $(OBJDIR)
	@test -d $(@D) || mkdir -pm 775 $(@D)
	@-$(RM) $@
	$(CC) $< -c $(CFLAGS) $(CFLAGS2) $(ALL_DEFINES:%=-D%) $(ALL_INCLUDEDIRS:%=-I%) -o $@

# create firmware image from common objects and example source file

all: buildnum $(OBJS) $(OBJDIR)/watch.elf

$(OBJDIR)/watch.elf: ${OBJS}
	@echo "============================================================"
	@echo "Link $@"
	${LINK} $^ $(LIBS) ${LDFLAGS} -o$@
	@echo "Convert to verilog format"
	${OBJCOPY} -O verilog $@ $(OBJDIR)/watch.txt
# compatibility with Kreyos' BSL.exe
	@${ECHO} q >>$(OBJDIR)/watch.txt

buildnum: $(OBJS)
	@echo "Build Number: $$(cat buildnum)"
ifeq ($(OFFICIAL), 1)
	@echo $$(($$(cat buildnum) + 1)) > buildnum
#	git commit buildnum -m "pump version to $$(cat buildnum)" 
#	git push
endif

ifeq ($(WINE), )
ifneq ($(MAKECMDGOALS), clean)
-include $(DEPFILES)
endif
endif

.SILENT:
.PHONY:	clean
clean:
	rm -Rf $(OBJDIR)/
