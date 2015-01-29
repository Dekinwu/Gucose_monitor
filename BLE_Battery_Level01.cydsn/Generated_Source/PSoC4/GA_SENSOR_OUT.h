/*******************************************************************************
* File Name: GA_SENSOR_OUT.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_GA_SENSOR_OUT_H) /* Pins GA_SENSOR_OUT_H */
#define CY_PINS_GA_SENSOR_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GA_SENSOR_OUT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GA_SENSOR_OUT_Write(uint8 value) ;
void    GA_SENSOR_OUT_SetDriveMode(uint8 mode) ;
uint8   GA_SENSOR_OUT_ReadDataReg(void) ;
uint8   GA_SENSOR_OUT_Read(void) ;
uint8   GA_SENSOR_OUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GA_SENSOR_OUT_DRIVE_MODE_BITS        (3)
#define GA_SENSOR_OUT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GA_SENSOR_OUT_DRIVE_MODE_BITS))

#define GA_SENSOR_OUT_DM_ALG_HIZ         (0x00u)
#define GA_SENSOR_OUT_DM_DIG_HIZ         (0x01u)
#define GA_SENSOR_OUT_DM_RES_UP          (0x02u)
#define GA_SENSOR_OUT_DM_RES_DWN         (0x03u)
#define GA_SENSOR_OUT_DM_OD_LO           (0x04u)
#define GA_SENSOR_OUT_DM_OD_HI           (0x05u)
#define GA_SENSOR_OUT_DM_STRONG          (0x06u)
#define GA_SENSOR_OUT_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GA_SENSOR_OUT_MASK               GA_SENSOR_OUT__MASK
#define GA_SENSOR_OUT_SHIFT              GA_SENSOR_OUT__SHIFT
#define GA_SENSOR_OUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GA_SENSOR_OUT_PS                     (* (reg32 *) GA_SENSOR_OUT__PS)
/* Port Configuration */
#define GA_SENSOR_OUT_PC                     (* (reg32 *) GA_SENSOR_OUT__PC)
/* Data Register */
#define GA_SENSOR_OUT_DR                     (* (reg32 *) GA_SENSOR_OUT__DR)
/* Input Buffer Disable Override */
#define GA_SENSOR_OUT_INP_DIS                (* (reg32 *) GA_SENSOR_OUT__PC2)


#if defined(GA_SENSOR_OUT__INTSTAT)  /* Interrupt Registers */

    #define GA_SENSOR_OUT_INTSTAT                (* (reg32 *) GA_SENSOR_OUT__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GA_SENSOR_OUT_DRIVE_MODE_SHIFT       (0x00u)
#define GA_SENSOR_OUT_DRIVE_MODE_MASK        (0x07u << GA_SENSOR_OUT_DRIVE_MODE_SHIFT)


#endif /* End Pins GA_SENSOR_OUT_H */


/* [] END OF FILE */
