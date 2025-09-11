/******************************************************************************
* File Name:   main.c
*
* Description: This code example demonstrates the implementation of PMSM sensorless
* field-oriented control (FOC) for 2 motors using the Infineon's MCUs.
*
* Related Document: See README.md
*
*******************************************************************************
* Copyright 2024-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "HardwareIface.h"
#include "cybsp.h"
#include "Controller.h"
#include "MotorCtrlHWConfig.h"

/*******************************************************************************
* Global variable
********************************************************************************/
/* XMC7x - GCC_ARM: EEPROM storage */
#if defined(COMPONENT_CAT1C)
uint8_t Em_Eeprom_Storage[srss_0_eeprom_0_PHYSICAL_SIZE] __attribute__ ((section(".cy_em_eeprom")));
#endif
/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* This is the main function.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;
    
    #if defined(COMPONENT_CAT1C)// Disabled the D-CACHE for XMC7200 device. 
    SCB_DisableDCache();
    #endif
    result = cybsp_init();                 /* Initialize the device and board peripherals */
    CY_ASSERT(result == CY_RSLT_SUCCESS);  /* Board init failed. Stop program execution   */

    // Initialize controller
    HW_IFACE_ConnectFcnPointers();         /* must be called before STATE_MACHINE_Init()  */
    STATE_MACHINE_Init();

    // Enable global interrupts
    __enable_irq();

    (void) (result);
    for (;;)
    {

    }
}
