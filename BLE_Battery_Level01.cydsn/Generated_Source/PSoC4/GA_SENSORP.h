/*******************************************************************************
* File Name: GA_SENSORP.h  
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

#if !defined(CY_PINS_GA_SENSORP_H) /* Pins GA_SENSORP_H */
#define CY_PINS_GA_SENSORP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GA_SENSORP_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GA_SENSORP_Write(uint8 value) ;
void    GA_SENSORP_SetDriveMode(uint8 mode) ;
uint8   GA_SENSORP_ReadDataReg(void) ;
uint8   GA_SENSORP_Read(void) ;
uint8   GA_SENSORP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GA_SENSORP_DRIVE_MODE_BITS        (3)
#define GA_SENSORP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GA_SENSORP_DRIVE_MODE_BITS))

#define GA_SENSORP_DM_ALG_HIZ         (0x00u)
#define GA_SENSORP_DM_DIG_HIZ         (0x01u)
#define GA_SENSORP_DM_RES_UP          (0x02u)
#define GA_SENSORP_DM_RES_DWN         (0x03u)
#define GA_SENSORP_DM_OD_LO           (0x04u)
#define GA_SENSORP_DM_OD_HI           (0x05u)
#define GA_SENSORP_DM_STRONG          (0x06u)
#define GA_SENSORP_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GA_SENSORP_MASK               GA_SENSORP__MASK
#define GA_SENSORP_SHIFT              GA_SENSORP__SHIFT
#define GA_SENSORP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GA_SENSORP_PS                     (* (reg32 *) GA_SENSORP__PS)
/* Port Configuration */
#define GA_SENSORP_PC                     (* (reg32 *) GA_SENSORP__PC)
/* Data Register */
#define GA_SENSORP_DR                     (* (reg32 *) GA_SENSORP__DR)
/* Input Buffer Disable Override */
#define GA_SENSORP_INP_DIS                (* (reg32 *) GA_SENSORP__PC2)


#if defined(GA_SENSORP__INTSTAT)  /* Interrupt Registers */

    #define GA_SENSORP_INTSTAT                (* (reg32 *) GA_SENSORP__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GA_SENSORP_DRIVE_MODE_SHIFT       (0x00u)
#define GA_SENSORP_DRIVE_MODE_MASK        (0x07u << GA_SENSORP_DRIVE_MODE_SHIFT)


#endif /* End Pins GA_SENSORP_H */


/* [] END OF FILE */
