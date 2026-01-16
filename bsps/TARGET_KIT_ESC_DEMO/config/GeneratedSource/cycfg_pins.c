/*******************************************************************************
 * File Name: cycfg_pins.c
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.50.0
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

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLDOWN,
    .hsiom = CYBSP_SWDCK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_SWDCK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_SWDCK_PORT_NUM,
    .channel_num = CYBSP_SWDCK_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP,
    .hsiom = CYBSP_SWDIO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t CYBSP_SWDIO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_SWDIO_PORT_NUM,
    .channel_num = CYBSP_SWDIO_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t TEST_PIN_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = TEST_PIN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t TEST_PIN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = TEST_PIN_PORT_NUM,
    .channel_num = TEST_PIN_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMUH_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMUH_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMUH_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMUH_PORT_NUM,
    .channel_num = PWMUH_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMUL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMUL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMUL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMUL_PORT_NUM,
    .channel_num = PWMUL_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMVH_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMVH_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMVH_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMVH_PORT_NUM,
    .channel_num = PWMVH_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMVL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMVL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMVL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMVL_PORT_NUM,
    .channel_num = PWMVL_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMWH_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMWH_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMWH_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMWH_PORT_NUM,
    .channel_num = PWMWH_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PWMWL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PWMWL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWMWL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PWMWL_PORT_NUM,
    .channel_num = PWMWL_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t FC_PWM_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_PULLDOWN,
    .hsiom = FC_PWM_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t FC_PWM_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = FC_PWM_PORT_NUM,
    .channel_num = FC_PWM_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t N_FAULT_HW_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = N_FAULT_HW_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t N_FAULT_HW_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = N_FAULT_HW_PORT_NUM,
    .channel_num = N_FAULT_HW_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(CYBSP_SWDCK_PORT, CYBSP_SWDCK_PIN, &CYBSP_SWDCK_config);
    Cy_GPIO_Pin_Init(CYBSP_SWDIO_PORT, CYBSP_SWDIO_PIN, &CYBSP_SWDIO_config);
    Cy_GPIO_Pin_Init(TEST_PIN_PORT, TEST_PIN_PIN, &TEST_PIN_config);
    Cy_GPIO_Pin_Init(PWMUH_PORT, PWMUH_PIN, &PWMUH_config);
    Cy_GPIO_Pin_Init(PWMUL_PORT, PWMUL_PIN, &PWMUL_config);
    Cy_GPIO_Pin_Init(PWMVH_PORT, PWMVH_PIN, &PWMVH_config);
    Cy_GPIO_Pin_Init(PWMVL_PORT, PWMVL_PIN, &PWMVL_config);
    Cy_GPIO_Pin_Init(PWMWH_PORT, PWMWH_PIN, &PWMWH_config);
    Cy_GPIO_Pin_Init(PWMWL_PORT, PWMWL_PIN, &PWMWL_config);
    Cy_GPIO_Pin_Init(FC_PWM_PORT, FC_PWM_PIN, &FC_PWM_config);
    Cy_GPIO_Pin_Init(N_FAULT_HW_PORT, N_FAULT_HW_PIN, &N_FAULT_HW_config);
}
void reserve_cycfg_pins(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&CYBSP_SWDCK_obj);
    cyhal_hwmgr_reserve(&CYBSP_SWDIO_obj);
    cyhal_hwmgr_reserve(&TEST_PIN_obj);
    cyhal_hwmgr_reserve(&PWMUH_obj);
    cyhal_hwmgr_reserve(&PWMUL_obj);
    cyhal_hwmgr_reserve(&PWMVH_obj);
    cyhal_hwmgr_reserve(&PWMVL_obj);
    cyhal_hwmgr_reserve(&PWMWH_obj);
    cyhal_hwmgr_reserve(&PWMWL_obj);
    cyhal_hwmgr_reserve(&FC_PWM_obj);
    cyhal_hwmgr_reserve(&N_FAULT_HW_obj);
#endif /* defined (CY_USING_HAL) */
}
