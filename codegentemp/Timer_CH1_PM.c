/*******************************************************************************
* File Name: Timer_CH1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Timer_CH1.h"

static Timer_CH1_BACKUP_STRUCT Timer_CH1_backup;


/*******************************************************************************
* Function Name: Timer_CH1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_CH1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_CH1_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_CH1_Sleep(void)
{
    if(0u != (Timer_CH1_BLOCK_CONTROL_REG & Timer_CH1_MASK))
    {
        Timer_CH1_backup.enableState = 1u;
    }
    else
    {
        Timer_CH1_backup.enableState = 0u;
    }

    Timer_CH1_Stop();
    Timer_CH1_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_CH1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_CH1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_CH1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_CH1_Wakeup(void)
{
    Timer_CH1_RestoreConfig();

    if(0u != Timer_CH1_backup.enableState)
    {
        Timer_CH1_Enable();
    }
}


/* [] END OF FILE */
