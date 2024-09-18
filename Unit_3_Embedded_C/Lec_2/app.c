
#include "uart.h"

unsigned char string_buffer[100]= "learn-in-depth:Hossam_zohir";
unsigned char const string_buffer1[100]= "learn-in-depth:Hossam_zohir";

void main(void)
{
	Uart_send_string(string_buffer);
}