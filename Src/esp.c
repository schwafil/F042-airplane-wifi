#include "esp.h"
#include "stdio.h"

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif /* __GNUC__ */
UART_HandleTypeDef * esp_uart;
void esp_init(void){
	esp_uart = &huart1;
	MX_USART1_UART_Init();
}



PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART3 and Loop until the end of transmission */
  HAL_UART_Transmit(esp_uart, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

GETCHAR_PROTOTYPE{
	uint8_t c;
	if(HAL_UART_Receive(esp_uart, (uint8_t *)&c, 1, 1000) == HAL_TIMEOUT){
		return EOF;
	}
	return c;
}

