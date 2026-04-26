/*******************************************************************************
 * File Name: cycfg_pins.h
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.28.0.8806
 * motor-ctrl-lib 3.0.0.608
 * mtb-pdl-cat1 3.17.0.43048
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define CYBSP_SWDCK_ENABLED 1U
#define CYBSP_SWDCK_PORT GPIO_PRT1
#define CYBSP_SWDCK_PORT_NUM 1U
#define CYBSP_SWDCK_PIN 2U
#define CYBSP_SWDCK_NUM 2U
#define CYBSP_SWDCK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CYBSP_SWDCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCK_HSIOM ioss_0_port_1_pin_2_HSIOM
#define CYBSP_SWDCK_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDCK_HAL_PORT_PIN P1_2
#define CYBSP_SWDCK P1_2
#define CYBSP_SWDCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDCK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT1
#define CYBSP_SWDIO_PORT_NUM 1U
#define CYBSP_SWDIO_PIN 3U
#define CYBSP_SWDIO_NUM 3U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_3_HSIOM
    #define ioss_0_port_1_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_1_pin_3_HSIOM
#define CYBSP_SWDIO_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDIO_HAL_PORT_PIN P1_3
#define CYBSP_SWDIO P1_3
#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define TEST_PIN_ENABLED 1U
#define TEST_PIN_PORT GPIO_PRT2
#define TEST_PIN_PORT_NUM 2U
#define TEST_PIN_PIN 1U
#define TEST_PIN_NUM 1U
#define TEST_PIN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST_PIN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_1_HSIOM
    #define ioss_0_port_2_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define TEST_PIN_HSIOM ioss_0_port_2_pin_1_HSIOM
#define TEST_PIN_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define TEST_PIN_HAL_PORT_PIN P2_1
#define TEST_PIN P2_1
#define TEST_PIN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define TEST_PIN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define TEST_PIN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMUH_ENABLED 1U
#define PWMUH_PORT GPIO_PRT4
#define PWMUH_PORT_NUM 4U
#define PWMUH_PIN 0U
#define PWMUH_NUM 0U
#define PWMUH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMUH_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_0_HSIOM
    #define ioss_0_port_4_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMUH_HSIOM ioss_0_port_4_pin_0_HSIOM
#define PWMUH_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMUH_HAL_PORT_PIN P4_0
#define PWMUH P4_0
#define PWMUH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMUH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMUH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMUL_ENABLED 1U
#define PWMUL_PORT GPIO_PRT4
#define PWMUL_PORT_NUM 4U
#define PWMUL_PIN 1U
#define PWMUL_NUM 1U
#define PWMUL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMUL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_1_HSIOM
    #define ioss_0_port_4_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMUL_HSIOM ioss_0_port_4_pin_1_HSIOM
#define PWMUL_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMUL_HAL_PORT_PIN P4_1
#define PWMUL P4_1
#define PWMUL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMUL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMUL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMVH_ENABLED 1U
#define PWMVH_PORT GPIO_PRT4
#define PWMVH_PORT_NUM 4U
#define PWMVH_PIN 2U
#define PWMVH_NUM 2U
#define PWMVH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMVH_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_2_HSIOM
    #define ioss_0_port_4_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMVH_HSIOM ioss_0_port_4_pin_2_HSIOM
#define PWMVH_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMVH_HAL_PORT_PIN P4_2
#define PWMVH P4_2
#define PWMVH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMVH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMVH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMVL_ENABLED 1U
#define PWMVL_PORT GPIO_PRT4
#define PWMVL_PORT_NUM 4U
#define PWMVL_PIN 3U
#define PWMVL_NUM 3U
#define PWMVL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMVL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_3_HSIOM
    #define ioss_0_port_4_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMVL_HSIOM ioss_0_port_4_pin_3_HSIOM
#define PWMVL_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMVL_HAL_PORT_PIN P4_3
#define PWMVL P4_3
#define PWMVL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMVL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMVL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMWH_ENABLED 1U
#define PWMWH_PORT GPIO_PRT4
#define PWMWH_PORT_NUM 4U
#define PWMWH_PIN 4U
#define PWMWH_NUM 4U
#define PWMWH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMWH_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_4_HSIOM
    #define ioss_0_port_4_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMWH_HSIOM ioss_0_port_4_pin_4_HSIOM
#define PWMWH_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMWH_HAL_PORT_PIN P4_4
#define PWMWH P4_4
#define PWMWH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMWH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMWH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PWMWL_ENABLED 1U
#define PWMWL_PORT GPIO_PRT4
#define PWMWL_PORT_NUM 4U
#define PWMWL_PIN 5U
#define PWMWL_NUM 5U
#define PWMWL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWMWL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_5_HSIOM
    #define ioss_0_port_4_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define PWMWL_HSIOM ioss_0_port_4_pin_5_HSIOM
#define PWMWL_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PWMWL_HAL_PORT_PIN P4_5
#define PWMWL P4_5
#define PWMWL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PWMWL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PWMWL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define FC_PWM_ENABLED 1U
#define FC_PWM_PORT GPIO_PRT7
#define FC_PWM_PORT_NUM 7U
#define FC_PWM_PIN 2U
#define FC_PWM_NUM 2U
#define FC_PWM_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define FC_PWM_INIT_DRIVESTATE 0
#ifndef ioss_0_port_7_pin_2_HSIOM
    #define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define FC_PWM_HSIOM ioss_0_port_7_pin_2_HSIOM
#define FC_PWM_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define FC_PWM_HAL_PORT_PIN P7_2
#define FC_PWM P7_2
#define FC_PWM_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define FC_PWM_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define FC_PWM_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#define N_FAULT_HW (P8_0)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDCK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t TEST_PIN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t TEST_PIN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMUH_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMUH_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMUL_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMUL_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMVH_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMVH_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMVL_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMVL_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMWH_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMWH_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PWMWL_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWMWL_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t FC_PWM_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t FC_PWM_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
