#include "lcd.h"
#include "main.h"

#define LCD_BASE ((uint32_t)(0x68000000 | 0x0003FFFE))
#define LCD      ((LCD_CONTROLLER_TYPEDEF *)LCD_BASE)

static void LCD_WR_REG(uint8_t u8_REG)
{
    LCD->u8_REG = u8_REG;
}

static void LCD_WR_RAM_8(uint8_t u8_RAM)
{
    LCD->u8_RAM = u8_RAM;
}

// static void LCD_WR_RAM_16(uint16_t u16_RAM)
// {
//     LCD->u16_RAM = u16_RAM;
// }
// static void LCD_WriteReg(uint8_t u8_REG, uint16_t u16_Data)
// {
//     LCD_WR_REG(u8_REG);
//     LCD_WR_RAM_16(u16_Data);
// }
static uint8_t LCD_RD_RAM_8(void)
{
    return LCD->u8_RAM;
}
// static uint8_t LCD_ReadReg(uint8_t u8_REG)
// {
//     LCD_WR_REG(u8_REG);
//     return LCD_RD_RAM_8();
// }
// static void LCD_WriteRam_Prepare(void)
// {
//     LCD->u8_REG = lcd_dev.wramcmd;
// }

_lcd_dev lcd_dev;

void lcd_clear(void)
{
    uint16_t i, j;
    for (i = 0; i < 240; i++) {
        for (j = 0; j < 240; j++) {
            drv_lcd_draw_pixel(i, j, 0xef00);
        }
    }
}
void drv_lcd_init(void)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_Delay(100);

    LCD_WR_REG(0x04);
    lcd_dev.id = LCD_RD_RAM_8();
    lcd_dev.id = LCD_RD_RAM_8();
    lcd_dev.id = LCD_RD_RAM_8();
    lcd_dev.id <<= 8;
    lcd_dev.id |= LCD_RD_RAM_8();

    LCD_WR_REG(0x36);
    LCD_WR_RAM_8(0x00);

    LCD_WR_REG(0x3A);
    LCD_WR_RAM_8(0x05);

    LCD_WR_REG(0xB2);
    LCD_WR_RAM_8(0x0C);
    LCD_WR_RAM_8(0x0C);
    LCD_WR_RAM_8(0x00);
    LCD_WR_RAM_8(0x33);
    LCD_WR_RAM_8(0x33);

    LCD_WR_REG(0xB7);
    LCD_WR_RAM_8(0x35);

    LCD_WR_REG(0xBB);
    LCD_WR_RAM_8(0x37);

    LCD_WR_REG(0xC0);
    LCD_WR_RAM_8(0x2C);

    LCD_WR_REG(0xC2);
    LCD_WR_RAM_8(0x01);

    LCD_WR_REG(0xC3);
    LCD_WR_RAM_8(0x12);

    LCD_WR_REG(0xC4);
    LCD_WR_RAM_8(0x20);

    LCD_WR_REG(0xC6);
    LCD_WR_RAM_8(0x0F);

    LCD_WR_REG(0xD0);
    LCD_WR_RAM_8(0xA4);
    LCD_WR_RAM_8(0xA1);

    LCD_WR_REG(0xE0);
    LCD_WR_RAM_8(0xD0);
    LCD_WR_RAM_8(0x04);
    LCD_WR_RAM_8(0x0D);
    LCD_WR_RAM_8(0x11);
    LCD_WR_RAM_8(0x13);
    LCD_WR_RAM_8(0x2B);
    LCD_WR_RAM_8(0x3F);
    LCD_WR_RAM_8(0x54);
    LCD_WR_RAM_8(0x4C);
    LCD_WR_RAM_8(0x18);
    LCD_WR_RAM_8(0x0D);
    LCD_WR_RAM_8(0x0B);
    LCD_WR_RAM_8(0x1F);
    LCD_WR_RAM_8(0x23);

    LCD_WR_REG(0xE1);
    LCD_WR_RAM_8(0xD0);
    LCD_WR_RAM_8(0x04);
    LCD_WR_RAM_8(0x0C);
    LCD_WR_RAM_8(0x11);
    LCD_WR_RAM_8(0x13);
    LCD_WR_RAM_8(0x2C);
    LCD_WR_RAM_8(0x3F);
    LCD_WR_RAM_8(0x44);
    LCD_WR_RAM_8(0x51);
    LCD_WR_RAM_8(0x2F);
    LCD_WR_RAM_8(0x1F);
    LCD_WR_RAM_8(0x1F);
    LCD_WR_RAM_8(0x20);
    LCD_WR_RAM_8(0x23);

    // LCD_WR_REG(0x21);

    LCD_WR_REG(0x11);
    HAL_Delay(120);

    LCD_WR_REG(0x29);
    lcd_clear();
}
void drv_lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    if (x >= 240 || y >= 240)
        return;

    LCD_WR_REG(0x2A);
    LCD_WR_RAM_8((x >> 8) & 0xff);
    LCD_WR_RAM_8(x & 0xff);
    LCD_WR_RAM_8((x >> 8) & 0xff);
    LCD_WR_RAM_8(x & 0xff);

    LCD_WR_REG(0x2B);
    LCD_WR_RAM_8((y >> 8) & 0xff);
    LCD_WR_RAM_8(y & 0xff);
    LCD_WR_RAM_8((y >> 8) & 0xff);
    LCD_WR_RAM_8(y & 0xff);

    LCD_WR_REG(0x2C);

    uint16_t data = (color >> 8) & 0xff;
    LCD_WR_RAM_8(data);
    data = color & 0xff;
    LCD_WR_RAM_8(data);
}