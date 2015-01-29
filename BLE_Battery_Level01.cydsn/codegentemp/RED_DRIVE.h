/*******************************************************************************
* File Name: RED_DRIVE.h  
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

#if !defined(CY_PINS_RED_DRIVE_H) /* Pins RED_DRIVE_H */
#define CY_PINS_RED_DRIVE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RED_DRIVE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RED_DRIVE_Write(uint8 value) ;
void    RED_DRIVE_SetDriveMode(uint8 mode) ;
uint8   RED_DRIVE_ReadDataReg(void) ;
uint8   RED_DRIVE_Read(void) ;
uint8   RED_DRIVE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RED_DRIVE_DRIVE_MODE_BITS        (3)
#define RED_DRIVE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RED_DRIVE_DRIVE_MODE_BITS))

#define RED_DRIVE_DM_ALG_HIZ         (0x00u)
#define RED_DRIVE_DM_DIG_HIZ         (0x01u)
#define RED_DRIVE_DM_RES_UP          (0x02u)
#define RED_DRIVE_DM_RES_DWN         (0x03u)
#define RED_DRIVE_DM_OD_LO           (0x04u)
#define RED_DRIVE_DM_OD_HI           (0x05u)
#define RED_DRIVE_DM_STRONG          (0x06u)
#define RED_DRIVE_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RED_DRIVE_MASK               RED_DRIVE__MASK
#define RED_DRIVE_SHIFT              RED_DRIVE__SHIFT
#define RED_DRIVE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RED_DRIVE_PS                     (* (reg32 *) RED_DRIVE__PS)
/* Port Configuration */
#define RED_DRIVE_PC                     (* (reg32 *) RED_DRIVE__PC)
/* Data Register */
#define RED_DRIVE_DR                     (* (reg32 *) RED_DRIVE__DR)
/* Input Buffer Disable Override */
#define RED_DRIVE_INP_DIS                (* (reg32 *) RED_DRIVE__PC2)


#if defined(RED_DRIVE__INTSTAT)  /* Interrupt Registers */

    #define RED_DRIVE_INTSTAT                (* (reg32 *) RED_DRIVE__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RED_DRIVE_DRIVE_MODE_SHIFT       (0x00u)
#define RED_DRIVE_DRIVE_MODE_MASK        (0x07u << RED_DRIVE_DRIVE_MODE_SHIFT)


#endif /* End Pins RED_DRIVE_H */


/* [] END OF FILE */
