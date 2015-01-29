/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>


#ifndef _CONFIG_CMD_H
#define _CONFIG_CMD_H

#define CMD_HEADER1 0XAA
#define CMD_HEADER2  0XEE
    
#define CMD_LEN  5
#define CMD_END  NULL
    
#define HEADER1_STA  0X01
#define HEADER2_STA  0X02
#define LEDTYPE_STA 0x03
#define PWMDUTY_STA 0x04
#define CRC_STA 0x05
    
#define LED_GREEN 0X01
#define LED_RED 0X02
#define LED_IR 0X03
#define LED_NIR 0X04
    
typedef struct
    {
         uint8 sta;
         uint8 ledtype;
         uint8 pwm_duty;
         uint8 duty;
         uint8 crc;
         uint8 flag;
    }config_cmd,*pconfig_cmd;
    
config_cmd g_config_cmd;
    

    
    
    
#endif


/* [] END OF FILE */
