#include "receive_UART_callback.h"


#include <stdio.h>
#include <string.h>
#include "stm32f1xx_it.h"


uint8_t received_byte = 0;
int index_received_btn_buffer = 0;
char buffer_received_btn[RX_BUFFER_SIZE];


void receive_btn_byte_callback(UART_HandleTypeDef *huart) {
  if (received_byte != BTN_ID_DELIMETER && 
	index_received_btn_buffer < sizeof(buffer_received_btn) / sizeof(buffer_received_btn[0])) {
	  buffer_received_btn[index_received_btn_buffer] = received_byte;
		index_received_btn_buffer++;
	} else {
			int destroyed_ship_size;
			if (sscanf(buffer_received_btn, DESTROYED_SHIP_SIZE_PATTERN, &destroyed_ship_size) >= 1) {
				destroyed_ship_summary += destroyed_ship_size;
			}
			index_received_btn_buffer = 0;
	}
	
	HAL_UART_Receive_DMA(huart, &received_byte, sizeof(received_byte));
}