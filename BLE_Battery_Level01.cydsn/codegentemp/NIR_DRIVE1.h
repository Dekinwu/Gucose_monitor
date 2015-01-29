/*******************************************************************************
* File Name: NIR_DRIVE1.h  
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

#if !defined(CY_PINS_NIR_DRIVE1_H) /* Pins NIR_DRIVE1_H */
#define CY_PINS_NIR_DRIVE1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NIR_DRIVE1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NIR_DRIVE1_Write(uint8 value) ;
void    NIR_DRIVE1_SetDriveMode(uint8 mode) ;
uint8   NIR_DRIVE1_ReadDataReg(void) ;
uint8   NIR_DRIVE1_Read(void) ;
uint8   NIR_DRIVE1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NIR_DRIVE1_DRIVE_MODE_BITS        (3)
#define NIR_DRIVE1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NIR_DRIVE1_DRIVE_MODE_BITS))

#define NIR_DRIVE1_DM_ALG_HIZ         (0x00u)
#define NIR_DRIVE1_DM_DIG_HIZ         (0x01u)
#define NIR_DRIVE1_DM_RES_UP          (0x02u)
#define NIR_DRIVE1_DM_RES_DWN         (0x03u)
#define NIR_DRIVE1_DM_OD_LO           (0x04u)
#define NIR_DRIVE1_DM_OD_HI           (0x05u)
#define NIR_DRIVE1_DM_STRONG          (0x06u)
#define NIR_DRIVE1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NIR_DRIVE1_MASK               NIR_DRIVE1__MASK
#define NIR_DRIVE1_SHIFT              NIR_DRIVE1__SHIFT
#define NIR_DRIVE1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NIR_DRIVE1_PS                     (* (reg32 *) NIR_DRIVE1__PS)
/* Port Configuration */
#define NIR_DRIVE1_PC                     (* (reg32 *) NIR_DRIVE1__PC)
/* Data Register */
#define NIR_DRIVE1_DR                     (* (reg32 *) NIR_DRIVE1__DR)
/* Input Buffer Disable Override */
#define NIR_DRIVE1_INP_DIS                (* (reg32 *) NIR_DRIVE1__PC2)


#if defined(NIR_DRIVE1__INTSTAT)  /* Interrupt Registers */

    #define NIR_DRIVE1_INTSTAT                (* (reg32 *) NIR_DRIVE1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NIR_DRIVE1_DRIVE_MODE_SHIFT       (0x00u)
#define NIR_DRIVE1_DRIVE_MODE_MASK        (0x07u << NIR_DRIVE1_DRIVE_MODE_SHIFT)


#endif /* End Pins NIR_DRIVE1_H */


/* [] END OF FILE */
