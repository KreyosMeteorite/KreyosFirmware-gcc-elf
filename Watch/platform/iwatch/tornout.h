#ifndef _TORNOUT_H
#define _TORNOUT_H

typedef enum {
  MODE_PAIR = 0,
  MODE_HRM = 1,
  MODE_CBSC = 2
}ModeEnum;

void ant_init(ModeEnum mode);
void ant_shutdown(void);
extern void codec_init();
extern void codec_bypass(int enable);
extern void codec_shutdown();
extern void bluetooth_init();
extern void bluetooth_start();
extern void bluetooth_shutdown();
extern void bluetooth_discoverable(uint8_t onoff);
extern void mpu6050_init();
extern const char* bluetooth_address();
#define count_elem(arr) (sizeof(arr)/sizeof(arr[0]))
#endif
