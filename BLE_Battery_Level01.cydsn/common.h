/*******************************************************************************
* File Name: common.h
*
* Version 1.0
*
* Description:
*  Contains the function prototypes and constants available to the example
*  project.
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <project.h>
#include <stdio.h>

#define ENABLED                     (1u)
#define DISABLED                    (0u)

#define LED_ON                      (0u)
#define LED_OFF                     (1u)

#define ADC_BATTERY_CHANNEL         (0x00u)
#define ADC_TEMPERATURE_CHANNEL     (0x01u)
#define ADC_DEF_TEMP_REF            (1024u)

/***************************************
*        External Function Prototypes
***************************************/
//void ShowValue(CYBLE_GATT_VALUE_T *value);
void Set32ByPtr(uint8 ptr[], uint32 value);
void ShowError(void);


/***************************************
* External data references
***************************************/
//extern CYBLE_CONN_HANDLE_T connHandle;
extern volatile uint32 mainTimer;

/* [] END OF FILE */
