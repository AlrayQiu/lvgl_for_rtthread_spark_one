#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>

typedef struct {
    uint16_t width;
    uint16_t height;
    uint16_t id;
    uint16_t dir;     // 0横屏 1竖屏
    uint16_t wramcmd; // 写ram命令
    uint16_t setxcmd; // 设置x坐标命令
    uint16_t setycmd; // 设置y坐标命令
} _lcd_dev;

extern _lcd_dev lcd_dev;

typedef struct {
    volatile uint8_t u8_REG;
    volatile uint8_t RESERVED;
    volatile uint8_t u8_RAM;
    volatile uint16_t u16_RAM;
} LCD_CONTROLLER_TYPEDEF;

void drv_lcd_init();
void drv_lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
#endif