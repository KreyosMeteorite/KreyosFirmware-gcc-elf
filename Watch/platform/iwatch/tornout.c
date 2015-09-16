#include "contiki.h"
#include "window.h"
#include "rtc.h"
#include "grlib/grlib.h"
//#include "cordic.h"
#include <stdio.h>
#include <string.h>
//#include "memory.h"
#include "memlcd.h"
#include "tornout.h"

//uint8_t disable_key;

#define count_elem(arr) (sizeof(arr)/sizeof(arr[0]))

void hfp_battery(int x) {
}

int CheckUpgrade(void)
{
  return 0;
}

void Upgrade()
{
}

void codec_init() {
}

void codec_bypass(int x) {
}

void codec_shutdown() {
}

void bluetooth_init() {
}

void bluetooth_discoverable(uint8_t x) {
}

const char* bluetooth_address()
{
  return (const char*)"AA";
}

void mpu6050_init() {
}

void ant_init(ModeEnum x) {
}

void ant_shutdown() {
}

void ped_reset() {
}
