/*******************************************************************************
* File Name: pin_button.h  
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

#if !defined(CY_PINS_pin_button_H) /* Pins pin_button_H */
#define CY_PINS_pin_button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pin_button_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pin_button_Write(uint8 value) ;
void    pin_button_SetDriveMode(uint8 mode) ;
uint8   pin_button_ReadDataReg(void) ;
uint8   pin_button_Read(void) ;
uint8   pin_button_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pin_button_DRIVE_MODE_BITS        (3)
#define pin_button_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pin_button_DRIVE_MODE_BITS))

#define pin_button_DM_ALG_HIZ         (0x00u)
#define pin_button_DM_DIG_HIZ         (0x01u)
#define pin_button_DM_RES_UP          (0x02u)
#define pin_button_DM_RES_DWN         (0x03u)
#define pin_button_DM_OD_LO           (0x04u)
#define pin_button_DM_OD_HI           (0x05u)
#define pin_button_DM_STRONG          (0x06u)
#define pin_button_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define pin_button_MASK               pin_button__MASK
#define pin_button_SHIFT              pin_button__SHIFT
#define pin_button_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pin_button_PS                     (* (reg32 *) pin_button__PS)
/* Port Configuration */
#define pin_button_PC                     (* (reg32 *) pin_button__PC)
/* Data Register */
#define pin_button_DR                     (* (reg32 *) pin_button__DR)
/* Input Buffer Disable Override */
#define pin_button_INP_DIS                (* (reg32 *) pin_button__PC2)


#if defined(pin_button__INTSTAT)  /* Interrupt Registers */

    #define pin_button_INTSTAT                (* (reg32 *) pin_button__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define pin_button_DRIVE_MODE_SHIFT       (0x00u)
#define pin_button_DRIVE_MODE_MASK        (0x07u << pin_button_DRIVE_MODE_SHIFT)


#endif /* End Pins pin_button_H */


/* [] END OF FILE */
