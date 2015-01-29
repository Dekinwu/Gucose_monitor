/*******************************************************************************
* File Name: RED_DRIVE.c  
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
#include "RED_DRIVE.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        RED_DRIVE_PC =   (RED_DRIVE_PC & \
                                (uint32)(~(uint32)(RED_DRIVE_DRIVE_MODE_IND_MASK << (RED_DRIVE_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (RED_DRIVE_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: RED_DRIVE_Write
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
void RED_DRIVE_Write(uint8 value) 
{
    uint8 drVal = (uint8)(RED_DRIVE_DR & (uint8)(~RED_DRIVE_MASK));
    drVal = (drVal | ((uint8)(value << RED_DRIVE_SHIFT) & RED_DRIVE_MASK));
    RED_DRIVE_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: RED_DRIVE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  RED_DRIVE_DM_STRONG     Strong Drive 
*  RED_DRIVE_DM_OD_HI      Open Drain, Drives High 
*  RED_DRIVE_DM_OD_LO      Open Drain, Drives Low 
*  RED_DRIVE_DM_RES_UP     Resistive Pull Up 
*  RED_DRIVE_DM_RES_DWN    Resistive Pull Down 
*  RED_DRIVE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  RED_DRIVE_DM_DIG_HIZ    High Impedance Digital 
*  RED_DRIVE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void RED_DRIVE_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(RED_DRIVE__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: RED_DRIVE_Read
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
*  Macro RED_DRIVE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RED_DRIVE_Read(void) 
{
    return (uint8)((RED_DRIVE_PS & RED_DRIVE_MASK) >> RED_DRIVE_SHIFT);
}


/*******************************************************************************
* Function Name: RED_DRIVE_ReadDataReg
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
uint8 RED_DRIVE_ReadDataReg(void) 
{
    return (uint8)((RED_DRIVE_DR & RED_DRIVE_MASK) >> RED_DRIVE_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RED_DRIVE_INTSTAT) 

    /*******************************************************************************
    * Function Name: RED_DRIVE_ClearInterrupt
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
    uint8 RED_DRIVE_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(RED_DRIVE_INTSTAT & RED_DRIVE_MASK);
		RED_DRIVE_INTSTAT = maskedStatus;
        return maskedStatus >> RED_DRIVE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
