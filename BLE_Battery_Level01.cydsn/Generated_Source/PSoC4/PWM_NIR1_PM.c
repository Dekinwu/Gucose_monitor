/*******************************************************************************
* File Name: PWM_NIR1_PM.c
* Version 3.10
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_NIR1.h"

static PWM_NIR1_backupStruct PWM_NIR1_backup;


/*******************************************************************************
* Function Name: PWM_NIR1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NIR1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_NIR1_SaveConfig(void) 
{

    #if(!PWM_NIR1_UsingFixedFunction)
        #if(!PWM_NIR1_PWMModeIsCenterAligned)
            PWM_NIR1_backup.PWMPeriod = PWM_NIR1_ReadPeriod();
        #endif /* (!PWM_NIR1_PWMModeIsCenterAligned) */
        PWM_NIR1_backup.PWMUdb = PWM_NIR1_ReadCounter();
        #if (PWM_NIR1_UseStatus)
            PWM_NIR1_backup.InterruptMaskValue = PWM_NIR1_STATUS_MASK;
        #endif /* (PWM_NIR1_UseStatus) */

        #if(PWM_NIR1_DeadBandMode == PWM_NIR1__B_PWM__DBM_256_CLOCKS || \
            PWM_NIR1_DeadBandMode == PWM_NIR1__B_PWM__DBM_2_4_CLOCKS)
            PWM_NIR1_backup.PWMdeadBandValue = PWM_NIR1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_NIR1_KillModeMinTime)
             PWM_NIR1_backup.PWMKillCounterPeriod = PWM_NIR1_ReadKillTime();
        #endif /* (PWM_NIR1_KillModeMinTime) */

        #if(PWM_NIR1_UseControl)
            PWM_NIR1_backup.PWMControlRegister = PWM_NIR1_ReadControlRegister();
        #endif /* (PWM_NIR1_UseControl) */
    #endif  /* (!PWM_NIR1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_NIR1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NIR1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_NIR1_RestoreConfig(void) 
{
        #if(!PWM_NIR1_UsingFixedFunction)
            #if(!PWM_NIR1_PWMModeIsCenterAligned)
                PWM_NIR1_WritePeriod(PWM_NIR1_backup.PWMPeriod);
            #endif /* (!PWM_NIR1_PWMModeIsCenterAligned) */

            PWM_NIR1_WriteCounter(PWM_NIR1_backup.PWMUdb);

            #if (PWM_NIR1_UseStatus)
                PWM_NIR1_STATUS_MASK = PWM_NIR1_backup.InterruptMaskValue;
            #endif /* (PWM_NIR1_UseStatus) */

            #if(PWM_NIR1_DeadBandMode == PWM_NIR1__B_PWM__DBM_256_CLOCKS || \
                PWM_NIR1_DeadBandMode == PWM_NIR1__B_PWM__DBM_2_4_CLOCKS)
                PWM_NIR1_WriteDeadTime(PWM_NIR1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_NIR1_KillModeMinTime)
                PWM_NIR1_WriteKillTime(PWM_NIR1_backup.PWMKillCounterPeriod);
            #endif /* (PWM_NIR1_KillModeMinTime) */

            #if(PWM_NIR1_UseControl)
                PWM_NIR1_WriteControlRegister(PWM_NIR1_backup.PWMControlRegister);
            #endif /* (PWM_NIR1_UseControl) */
        #endif  /* (!PWM_NIR1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_NIR1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NIR1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_NIR1_Sleep(void) 
{
    #if(PWM_NIR1_UseControl)
        if(PWM_NIR1_CTRL_ENABLE == (PWM_NIR1_CONTROL & PWM_NIR1_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_NIR1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_NIR1_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_NIR1_UseControl) */

    /* Stop component */
    PWM_NIR1_Stop();

    /* Save registers configuration */
    PWM_NIR1_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_NIR1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NIR1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_NIR1_Wakeup(void) 
{
     /* Restore registers values */
    PWM_NIR1_RestoreConfig();

    if(PWM_NIR1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_NIR1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
