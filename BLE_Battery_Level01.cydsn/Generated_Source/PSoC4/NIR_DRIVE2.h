/*******************************************************************************
* File Name: NIR_DRIVE2.h  
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

#if !defined(CY_PINS_NIR_DRIVE2_H) /* Pins NIR_DRIVE2_H */
#define CY_PINS_NIR_DRIVE2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NIR_DRIVE2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NIR_DRIVE2_Write(uint8 value) ;
void    NIR_DRIVE2_SetDriveMode(uint8 mode) ;
uint8   NIR_DRIVE2_ReadDataReg(void) ;
uint8   NIR_DRIVE2_Read(void) ;
uint8   NIR_DRIVE2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NIR_DRIVE2_DRIVE_MODE_BITS        (3)
#define NIR_DRIVE2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NIR_DRIVE2_DRIVE_MODE_BITS))

#define NIR_DRIVE2_DM_ALG_HIZ         (0x00u)
#define NIR_DRIVE2_DM_DIG_HIZ         (0x01u)
#define NIR_DRIVE2_DM_RES_UP          (0x02u)
#define NIR_DRIVE2_DM_RES_DWN         (0x03u)
#define NIR_DRIVE2_DM_OD_LO           (0x04u)
#define NIR_DRIVE2_DM_OD_HI           (0x05u)
#define NIR_DRIVE2_DM_STRONG          (0x06u)
#define NIR_DRIVE2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NIR_DRIVE2_MASK               NIR_DRIVE2__MASK
#define NIR_DRIVE2_SHIFT              NIR_DRIVE2__SHIFT
#define NIR_DRIVE2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NIR_DRIVE2_PS                     (* (reg32 *) NIR_DRIVE2__PS)
/* Port Configuration */
#define NIR_DRIVE2_PC                     (* (reg32 *) NIR_DRIVE2__PC)
/* Data Register */
#define NIR_DRIVE2_DR                     (* (reg32 *) NIR_DRIVE2__DR)
/* Input Buffer Disable Override */
#define NIR_DRIVE2_INP_DIS                (* (reg32 *) NIR_DRIVE2__PC2)


#if defined(NIR_DRIVE2__INTSTAT)  /* Interrupt Registers */

    #define NIR_DRIVE2_INTSTAT                (* (reg32 *) NIR_DRIVE2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NIR_DRIVE2_DRIVE_MODE_SHIFT       (0x00u)
#define NIR_DRIVE2_DRIVE_MODE_MASK        (0x07u << NIR_DRIVE2_DRIVE_MODE_SHIFT)


#endif /* End Pins NIR_DRIVE2_H */


/* [] END OF FILE */
