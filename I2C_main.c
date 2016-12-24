#include<stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "i2c.h"
#include "PLL.h"
#include "UART.h"

int main()
{
	uint8_t data;
	PLL_Init();
	UART_Init();
	i2c_slave_init(0x0A);
	data=0X00;
	while((I2C0_SCSR_R & I2C_SCSR_OAR2SEL) == 0);
	UART_OutString("\r\nAddress matched\r\n");
	while((I2C0_SCSR_R & I2C_SCSR_FBR) == 0);
	data=I2C0_SDR_R	;
	if(data != 0X00)
	{
		UART_OutString("\r\nData recieved \r");
		UART_OutChar(data);
		UART_OutString("\r\n");
	}
		
	
	return 0;
}
