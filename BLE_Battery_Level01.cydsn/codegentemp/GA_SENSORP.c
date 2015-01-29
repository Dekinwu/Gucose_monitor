/*******************************************************************************
* File Name: GA_SENSORP.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "GA_SENSORP.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        GA_SENSORP_PC =   (GA_SENSORP_PC & \
                                (uint32)(~(uint32)(GA_SENSORP_DRIVE_MODE_IND_MASK << (GA_SENSORP_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (GA_SENSORP_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: GA_SENSORP_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void GA_SENSORP_Write(uint8 value) 
{
    uint8 drVal = (uint8)(GA_SENSORP_DR & (uint8)(~GA_SENSORP_MASK));
    drVal = (drVal | ((uint8)(value << GA_SENSORP_SHIFT) & GA_SENSORP_MASK));
    GA_SENSORP_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: GA_SENSORP_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  GA_SENSORP_DM_STRONG     Strong Drive 
*  GA_SENSORP_DM_OD_HI      Open Drain, Drives High 
*  GA_SENSORP_DM_OD_LO      Open Drain, Drives Low 
*  GA_SENSORP_DM_RES_UP     Resistive Pull Up 
*  GA_SENSORP_DM_RES_DWN    Resistive Pull Down 
*  GA_SENSORP_DM_RES_UPDWN  Resistive Pull Up/Down 
*  GA_SENSORP_DM_DIG_HIZ    High Impedance Digital 
*  GA_SENSORP_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void GA_SENSORP_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(GA_SENSORP__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: GA_SENSORP_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro GA_SENSORP_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GA_SENSORP_Read(void) 
{
    return (uint8)((GA_SENSORP_PS & GA_SENSORP_MASK) >> GA_SENSORP_SHIFT);
}


/*******************************************************************************
* Function Name: GA_SENSORP_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 GA_SENSORP_ReadDataReg(void) 
{
    return (uint8)((GA_SENSORP_DR & GA_SENSORP_MASK) >> GA_SENSORP_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GA_SENSORP_INTSTAT) 

    /*******************************************************************************
    * Function Name: GA_SENSORP_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 GA_SENSORP_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(GA_SENSORP_INTSTAT & GA_SENSORP_MASK);
		GA_SENSORP_INTSTAT = maskedStatus;
        return maskedStatus >> GA_SENSORP_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
