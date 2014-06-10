
#include "MDR32Fx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

typedef struct {
	uint16_t read_index;
	uint16_t size;
	uint16_t *data;
} uart_dma_rx_buffer_t;


//---------------------------------------------//
// Buffer settings
#define RX_BUFFER_SIZE			200		// Filled by DMA in cyclical way
#define EMPTY_DATA				0xFFFF

// Parser settings
#define RX_MESSAGE_MAX_LENGTH	80		// Maximum message length
#define MAX_WORDS_IN_MESSAGE	20		// Maximum words separated by SPACING_SYMBOL in message
#define MAX_FUNCTION_ARGUMENTS   5		// Maximum arguments for a command


typedef struct {
	uint8_t type;
	uint8_t enable;
	uint32_t brate;
	uint8_t parity;
} uart_receiver_msg_t;

typedef struct {
	uint8_t enable;
	uint8_t parity;
	uint32_t brate;
} uart_param_request_t;


// Task command interface
enum {
	UART_INITIAL_START = 1,
	UART_APPLY_NEW_SETTINGS,
	UART_RX_TICK
};


extern uart_receiver_msg_t uart_rx_tick_msg;
extern xQueueHandle xQueueUART1RX, xQueueUART2RX;
extern xSemaphoreHandle hwUART1_mutex;
extern xSemaphoreHandle hwUART2_mutex;

void UART_Get_comm_params(uint8_t uart_num, uart_param_request_t *r);

void vTaskUARTReceiver(void *pvParameters);




