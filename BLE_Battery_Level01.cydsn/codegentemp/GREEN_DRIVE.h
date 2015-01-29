/*******************************************************************************
* File Name: GREEN_DRIVE.h  
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

#if !defined(CY_PINS_GREEN_DRIVE_H) /* Pins GREEN_DRIVE_H */
#define CY_PINS_GREEN_DRIVE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GREEN_DRIVE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GREEN_DRIVE_Write(uint8 value) ;
void    GREEN_DRIVE_SetDriveMode(uint8 mode) ;
uint8   GREEN_DRIVE_ReadDataReg(void) ;
uint8   GREEN_DRIVE_Read(void) ;
uint8   GREEN_DRIVE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GREEN_DRIVE_DRIVE_MODE_BITS        (3)
#define GREEN_DRIVE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GREEN_DRIVE_DRIVE_MODE_BITS))

#define GREEN_DRIVE_DM_ALG_HIZ         (0x00u)
#define GREEN_DRIVE_DM_DIG_HIZ         (0x01u)
#define GREEN_DRIVE_DM_RES_UP          (0x02u)
#define GREEN_DRIVE_DM_RES_DWN         (0x03u)
#define GREEN_DRIVE_DM_OD_LO           (0x04u)
#define GREEN_DRIVE_DM_OD_HI           (0x05u)
#define GREEN_DRIVE_DM_STRONG          (0x06u)
#define GREEN_DRIVE_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GREEN_DRIVE_MASK               GREEN_DRIVE__MASK
#define GREEN_DRIVE_SHIFT              GREEN_DRIVE__SHIFT
#define GREEN_DRIVE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GREEN_DRIVE_PS                     (* (reg32 *) GREEN_DRIVE__PS)
/* Port Configuration */
#define GREEN_DRIVE_PC                     (* (reg32 *) GREEN_DRIVE__PC)
/* Data Register */
#define GREEN_DRIVE_DR                     (* (reg32 *) GREEN_DRIVE__DR)
/* Input Buffer Disable Override */
#define GREEN_DRIVE_INP_DIS                (* (reg32 *) GREEN_DRIVE__PC2)


#if defined(GREEN_DRIVE__INTSTAT)  /* Interrupt Registers */

    #define GREEN_DRIVE_INTSTAT                (* (reg32 *) GREEN_DRIVE__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GREEN_DRIVE_DRIVE_MODE_SHIFT       (0x00u)
#define GREEN_DRIVE_DRIVE_MODE_MASK        (0x07u << GREEN_DRIVE_DRIVE_MODE_SHIFT)


#endif /* End Pins GREEN_DRIVE_H */


/* [] END OF FILE */
