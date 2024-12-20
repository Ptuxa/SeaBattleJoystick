#include "display.h"
#include "main.h"

#include <math.h>

void write_to_segment(uint8_t segment, uint8_t data);
void shift_out(uint8_t value);

uint8_t digits[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint8_t segments[] = {0xF1, 0xF2, 0xF4, 0xF8};
	
void display_update_integer(int value) {
	int segments_size = sizeof(segments) / sizeof(segments[0]);
	if (value >= pow(10, segments_size) || value < 0) 
	{
		return;
	}
	int devider = pow(10, segments_size - 1);
	for (int i = 0; i < segments_size; i++) {
		int store_value = value / devider;
		value -= devider * store_value;
		devider /= 10;
		write_to_segment(segments[i], digits[store_value]);
	}	
}

void write_to_segment(uint8_t segment, uint8_t data) {
	HAL_GPIO_WritePin(LATCH_CLK_GPIO_Port, LATCH_CLK_Pin, GPIO_PIN_RESET);
  shift_out(data);
  shift_out(segment);
  HAL_GPIO_WritePin(LATCH_CLK_GPIO_Port, LATCH_CLK_Pin, GPIO_PIN_SET);
}

void shift_out(uint8_t value) {
  for (int i = 7; i >= 0; i--) {
		HAL_GPIO_WritePin(SDI_GPIO_Port, SDI_Pin, (value >> i & 1));
    HAL_GPIO_WritePin(SHIFT_CLK_GPIO_Port, SHIFT_CLK_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SHIFT_CLK_GPIO_Port, SHIFT_CLK_Pin, GPIO_PIN_RESET);
  }
}