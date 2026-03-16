/*******************************************************************************
* Copyright 2024, Cypress Semiconductor Corporation (an Infineon company) or
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

#pragma once

#include "cybsp.h"
#include "General.h"


#if defined(COMPONENT_CAT1B)

/* Temperature sensor configurations */
#define ACTIVE_TEMP_SENSOR  true        // Active IC (e.g. MCP9700T-E/TT) vs Passive NTC (e.g. NCP18WF104J03RB)
extern  TEMP_SENS_LUT_t     Temp_Sens_LUT;
extern  TEMP_SENS_LUT_t     Temp_Sens_LUT_M1;

/* PWM configurations*/
#define PWM_INVERSION       (false)
#define PWM_TRIG_ADVANCE    (0U)        // [ticks]

/* Miscellaneous BSP definitions */
#define KIT_ID                (0x0009UL)    // For GUI's recognition of HW

enum
{
    // ADC sequence 0 results
    ADC_ISAMPA = 0, ADC_ISAMPC = 1, ADC_VBUS = 2, ADC_TEMP = 3, ADC_VV = 4,
    // ADC sequence 1 results
    ADC_ISAMPB = 5, ADC_ISAMPD = 6, ADC_VPOT = 7, ADC_VU = 8,   ADC_VW = 9,
    // Totals
    ADC_SEQ_MAX = 2, ADC_SAMP_PER_SEQ_MAX = 5, ADC_MAX = 10
};
extern void* ADC_Result_Regs[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern uint8_t DMA_Result_Indices[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern cy_stc_dma_descriptor_t* DMA_Descriptors[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern const cy_stc_dma_descriptor_config_t* DMA_Descriptor_Configs[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];

void MCU_RoutingConfigMUXA();  // Routing ADC sequences, ADC0::[ISAMPA,ISAMPC,VBUS,TEMP,VV] & ADC1::[ISAMPB,ISAMPD,VPOT,VU,VW], {ISAMPA,ISAMPB,ISAMPC,ISAMPD}={IU,IV,IW,IDCLINKAVG}
//void MCU_RoutingConfigMUXB();  // Routing ADC sequences, ADC0::[ISAMPA,ISAMPC,VBUS,TEMP,VV] & ADC1::[ISAMPB,ISAMPD,VPOT,VU,VW], {ISAMPA,ISAMPB,ISAMPC,ISAMPD}={IDCLINK,IDCLINK,IDCLINKAVG,IDCLINKAVG}

#if (MOTOR_CTRL_MOTOR1_ENABLED)
extern void* ADC_Result_Regs_M1[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern uint8_t DMA_Result_Indices_M1[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern cy_stc_dma_descriptor_t* DMA_Descriptors_M1[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];
extern const cy_stc_dma_descriptor_config_t* DMA_Descriptor_Configs_M1[ADC_SEQ_MAX][ADC_SAMP_PER_SEQ_MAX];

void MCU_RoutingConfigMUXA_M1();
void MCU_RoutingConfigMUXB_M1();
#endif

#endif

