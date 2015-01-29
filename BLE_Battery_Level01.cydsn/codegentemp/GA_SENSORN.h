/*******************************************************************************
* File Name: GA_SENSORN.h  
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

#if !defined(CY_PINS_GA_SENSORN_H) /* Pins GA_SENSORN_H */
#define CY_PINS_GA_SENSORN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GA_SENSORN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GA_SENSORN_Write(uint8 value) ;
void    GA_SENSORN_SetDriveMode(uint8 mode) ;
uint8   GA_SENSORN_ReadDataReg(void) ;
uint8   GA_SENSORN_Read(void) ;
uint8   GA_SENSORN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GA_SENSORN_DRIVE_MODE_BITS        (3)
#define GA_SENSORN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GA_SENSORN_DRIVE_MODE_BITS))

#define GA_SENSORN_DM_ALG_HIZ         (0x00u)
#define GA_SENSORN_DM_DIG_HIZ         (0x01u)
#define GA_SENSORN_DM_RES_UP          (0x02u)
#define GA_SENSORN_DM_RES_DWN         (0x03u)
#define GA_SENSORN_DM_OD_LO           (0x04u)
#define GA_SENSORN_DM_OD_HI           (0x05u)
#define GA_SENSORN_DM_STRONG          (0x06u)
#define GA_SENSORN_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GA_SENSORN_MASK               GA_SENSORN__MASK
#define GA_SENSORN_SHIFT              GA_SENSORN__SHIFT
#define GA_SENSORN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GA_SENSORN_PS                     (* (reg32 *) GA_SENSORN__PS)
/* Port Configuration */
#define GA_SENSORN_PC                     (* (reg32 *) GA_SENSORN__PC)
/* Data Register */
#define GA_SENSORN_DR                     (* (reg32 *) GA_SENSORN__DR)
/* Input Buffer Disable Override */
#define GA_SENSORN_INP_DIS                (* (reg32 *) GA_SENSORN__PC2)


#if defined(GA_SENSORN__INTSTAT)  /* Interrupt Registers */

    #define GA_SENSORN_INTSTAT                (* (reg32 *) GA_SENSORN__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GA_SENSORN_DRIVE_MODE_SHIFT       (0x00u)
#define GA_SENSORN_DRIVE_MODE_MASK        (0x07u << GA_SENSORN_DRIVE_MODE_SHIFT)


#endif /* End Pins GA_SENSORN_H */


/* [] END OF FILE */
