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

#define ADC_IN_CHANNEL         (0x00u)
uint16  g_adcResult;


void Data_Acquire_and_Print(void)
{
    do
    {
       ADC_SAR_StartConvert();
       ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT);
       g_adcResult = ADC_SAR_GetResult16(ADC_IN_CHANNEL);
       printf("%d",g_adcResult);
     }while(g_config_cmd.flag==0);
}


void UartRX_Interrupt(void)
{
    
    switch(g_pconf_cmd->sta)
    {
        case HEADER1_STA:
             if(UART_DEB_SpiUartReadRxData()==CMD_HEADER1) g_pconf_cmd->sta=HEADER2_STA;
             break;
        case HEADER2_STA:
             if(UART_DEB_SpiUartReadRxData()==CMD_HEADER2) g_pconf_cmd->sta=DATAREV_STA;
             break;
        case DATAREV_STA:
             *((char *)(g_pconf_cmd+g_pconf_cmd->datanum) )=UART_DEB_SpiUartReadRxData();
             if(g_pconf_cmd->datanum++ == CMD_DATA_NUM) g_pconf_cmd->sta=CRC_STA; 
            break;
        case CRC_STA:
             g_pconf_cmd->crc=UART_DEB_SpiUartReadRxData();
             g_pconf_cmd->sta=HEADER1_STA;
             g_pconf_cmd->flag=1;
            break;
       default: break;
    }
    UART_DEB_ClearRxInterruptSource( UART_DEB_GetRxInterruptSource());
}

void main()
{
    unsigned char i=0;
    uint16 j;
    CyGlobalIntEnable;  
    
    g_pconf_cmd->sta=HEADER1_STA;
    
    /*config uart*/
    UART_DEB_Start(); 
    UART_DEB_SCB_IRQ_Start();
    UART_DEB_SCB_IRQ_StartEx(UartRX_Interrupt);
    printf("uart inited! you can config led type and pwm duty. \r\n");
    
    /*config PWM*/
    PWM_IR_AND_RED_Start();
    PWM_NIR1_Start();
    PWM_GREEN_Start();
    
         
    /* Start Opamp component */
    Opamp_Start();
    /* Sets Opamp power mode to High power */
    Opamp_SetPower(Opamp_HIGH_POWER);
    
    /*ADC init*/
    ADC_SAR_Start();
    
     //ADC_StartConvert();
    //ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT);
    //g_adcResult = ADC_SAR_GetResult16(ADC_IN_CHANNEL );

    for(;;)
    {
         //  UART_DEB_UartPutChar(0x55);
         if(g_pconf_cmd->flag==1)
        {
            g_config_cmd.flag=0;
            i=0;
            if(g_pconf_cmd->cmd==CMD_GREEN)  
            {
                 PWM_IR_AND_RED_Stop();// 
                 PWM_NIR1_Stop();
                 while((g_pconf_cmd->pwm[i]!=0) && (i<8))
                  {
                    PWM_GREEN_WriteCompare((uint8)((g_pconf_cmd->pwm[i]<<8)/100));
                    PWM_GREEN_Enable();
                    printf("GREEN led pwm duty is: %d \r\n",(uint8)((g_pconf_cmd->pwm[i]<<8)/100));
                    j=(g_pconf_cmd->acqnum_h<<8) + g_pconf_cmd->acqnum_l;
                    while(j--)  Data_Acquire_and_Print();
                    i++;
                  }
            }
            
            if(g_pconf_cmd->cmd==CMD_REDANDIR)  
            {
                PWM_GREEN_Stop();//  
                PWM_NIR1_Stop();
                while((g_pconf_cmd->pwm[i]!=0) && (i<8))
                {
                    PWM_IR_AND_RED_WriteCompare1((uint8)((g_pconf_cmd->pwm[i]<<8)/100));  //RED LED PWM set
                    PWM_IR_AND_RED_WriteCompare2(0);
                    PWM_IR_AND_RED_Enable();
                    printf("RED led pwm duty is: %d \r\n",(uint8)g_pconf_cmd->pwm[i]);
                    j=(g_pconf_cmd->acqnum_h<<8) + g_pconf_cmd->acqnum_l;
                    while(j--)  Data_Acquire_and_Print();
                    PWM_IR_AND_RED_WriteCompare2((uint8)((g_pconf_cmd->pwm[i]<<8)/100)); //IR LED
                    PWM_IR_AND_RED_WriteCompare1(0);
                    PWM_IR_AND_RED_Enable();
                    printf("IR led pwm duty is: %d \r\n",(uint8)g_pconf_cmd->pwm[i]);
                    j=(g_pconf_cmd->acqnum_h<<8) + g_pconf_cmd->acqnum_l;
                    while(j--)  Data_Acquire_and_Print();
                    i++;
               }
            }
            if(g_pconf_cmd->cmd==CMD_NIR)
            {
                PWM_GREEN_Stop();//  
                PWM_IR_AND_RED_Stop();
                while((g_pconf_cmd->pwm[i]!=0) && (i<8))
                {
                    PWM_NIR1_WriteCompare2((uint8)((g_pconf_cmd->pwm[i]<<8)/100));  //two NIR LED driving with same pwm duty
                    PWM_NIR1_WriteCompare1((uint8)((g_pconf_cmd->pwm[i]<<8)/100));
                 
                    PWM_NIR1_Enable();
                    printf("NIR led pwm duty is: %d \r\n",(uint8)g_pconf_cmd->pwm[i]);
                    j=(g_pconf_cmd->acqnum_h<<8) + g_pconf_cmd->acqnum_l;
                    while(j--)  Data_Acquire_and_Print();
                    i++;
                }  
            /*LED kaiguan配置完成后，开始不断采集，直至g_config_cmd.flag==1*/
            //Data_Acquire_and_Print();
          }
        
        }    
     }
}


/* [] END OF FILE */
