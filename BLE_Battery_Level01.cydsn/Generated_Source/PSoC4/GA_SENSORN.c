/*******************************************************************************
* File Name: GA_SENSORN.c  
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
#include "GA_SENSORN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        GA_SENSORN_PC =   (GA_SENSORN_PC & \
                                (uint32)(~(uint32)(GA_SENSORN_DRIVE_MODE_IND_MASK << (GA_SENSORN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (GA_SENSORN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: GA_SENSORN_Write
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
void GA_SENSORN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(GA_SENSORN_DR & (uint8)(~GA_SENSORN_MASK));
    drVal = (drVal | ((uint8)(value << GA_SENSORN_SHIFT) & GA_SENSORN_MASK));
    GA_SENSORN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: GA_SENSORN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  GA_SENSORN_DM_STRONG     Strong Drive 
*  GA_SENSORN_DM_OD_HI      Open Drain, Drives High 
*  GA_SENSORN_DM_OD_LO      Open Drain, Drives Low 
*  GA_SENSORN_DM_RES_UP     Resistive Pull Up 
*  GA_SENSORN_DM_RES_DWN    Resistive Pull Down 
*  GA_SENSORN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  GA_SENSORN_DM_DIG_HIZ    High Impedance Digital 
*  GA_SENSORN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void GA_SENSORN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(GA_SENSORN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: GA_SENSORN_Read
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
*  Macro GA_SENSORN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GA_SENSORN_Read(void) 
{
    return (uint8)((GA_SENSORN_PS & GA_SENSORN_MASK) >> GA_SENSORN_SHIFT);
}


/*******************************************************************************
* Function Name: GA_SENSORN_ReadDataReg
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
uint8 GA_SENSORN_ReadDataReg(void) 
{
    return (uint8)((GA_SENSORN_DR & GA_SENSORN_MASK) >> GA_SENSORN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GA_SENSORN_INTSTAT) 

    /*******************************************************************************
    * Function Name: GA_SENSORN_ClearInterrupt
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
    uint8 GA_SENSORN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(GA_SENSORN_INTSTAT & GA_SENSORN_MASK);
		GA_SENSORN_INTSTAT = maskedStatus;
        return maskedStatus >> GA_SENSORN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
