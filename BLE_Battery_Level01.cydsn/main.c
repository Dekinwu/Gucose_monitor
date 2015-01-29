 /*******************************************************************************
* File: main.c
*
* Version : 1.1
*
* Description: 
*   This is source code for the PSoC4 Opamp example project. 
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>
#include <stdio.h>
#include "config_cmd.h"


void UartRX_Interrupt(void)
{
    
    switch(g_config_cmd.sta)
    {
        case HEADER1_STA:
             if(UART_DEB_UartGetByte()==CMD_HEADER1) g_config_cmd.sta=HEADER2_STA;
             break;
        case HEADER2_STA:
             if(UART_DEB_UartGetByte()==CMD_HEADER2) g_config_cmd.sta=LEDTYPE_STA;
             break;
        case LEDTYPE_STA:
             g_config_cmd.ledtype=UART_DEB_UartGetByte();
             g_config_cmd.sta=PWMDUTY_STA;
            break;
        case PWMDUTY_STA:
             g_config_cmd.pwm_duty=UART_DEB_UartGetByte();
             g_config_cmd.sta=CRC_STA;
            break;
        case CRC_STA:
             g_config_cmd.crc=UART_DEB_UartGetByte();
             g_config_cmd.sta=HEADER1_STA;
             g_config_cmd.flag=1;
            break;
       default: break;
    }
    UART_DEB_ClearRxInterruptSource( UART_DEB_GetRxInterruptSource());
}

void main()
{
    unsigned char i=0;
    CyGlobalIntEnable;  
    
    g_config_cmd.sta=HEADER1_STA;
    
    UART_DEB_Start(); 
    UART_DEB_SCB_IRQ_Start();
    UART_DEB_SCB_IRQ_StartEx(UartRX_Interrupt);
    printf("please input led type and pwm duty: \r\n");
    
    PWM_IR_AND_RED_Start();
    PWM_NIR1_Start();
    PWM_GREEN_Start();
    
    
    
    /* Start Opamp component */
  //  Opamp_Start();

    /* Sets Opamp power mode to High power */
   // Opamp_SetPower(Opamp_HIGH_POWER);

    for(;;)
    {
         //  UART_DEB_UartPutChar(0x55);
         if(g_config_cmd.flag==1)
        {
             g_config_cmd.flag=0;
            if(g_config_cmd.ledtype==LED_GREEN)  PWM_GREEN_WriteCompare((uint8)((g_config_cmd.duty<<8)/100));
            if(g_config_cmd.ledtype==LED_IR)  PWM_IR_AND_RED_WriteCompare2((uint8)((g_config_cmd.duty<<8)/100));
            if(g_config_cmd.ledtype==LED_NIR)  PWM_NIR1_WriteCompare2((uint8)((g_config_cmd.duty<<8)/100));
            printf("pwm duty setted! \r\n");
        }
           //printf("please input led type and pwm duty: \r\n");
    }
}


/* [] END OF FILE */
