/**
 * @file main.c
 * @author Konrad Sikora
 * @date Jan 2021
 */

#include "MKL05Z4.h"
#include "../inc/keyboard.h"
#include "../inc/lcd1602.h"
#include "../inc/pit.h"
#include "../inc/calculate.h"
#include "../inc/rtc.h"
#include "../inc/buttons.h"
#include "../inc/dma.h"
#include "../inc/adc.h"
#include "../inc/uart.h"
#include "../inc/mode.h"
#include "../inc//led.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_all();

int main(void)
{
  init_all();
  LCD1602_PrintXY("Time:\0", 0, 1);

  while (1)
  {
    RTC_choose_mode();
    choose_mode();
    uart_mode();
    RTC_alarm_mode();
    __wfi(); // save energy and wait for interrupt
  }
}

void init_all()
{
  LCD1602_Init(); // initialize LCD
  LCD1602_Backlight(TRUE);
  KB_init();       // initialize Keyboard
  LEDs_init();     // initialize LEDs
  PIT_init();      // initialize PIT
  RTC_init();      // initialize RTC
  BUTTOONS_init(); // initialize buttons
  ADC_init();      // initialize ADC
  DMA_init();      // initialize DMA
  UART0_init();    // initialize USART
}
