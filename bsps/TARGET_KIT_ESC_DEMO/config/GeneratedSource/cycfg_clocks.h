/*******************************************************************************
 * File Name: cycfg_clocks.h
 *
 * Description:
 * Clock configuration
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

#if !defined(CYCFG_CLOCKS_H)
#define CYCFG_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define CLK_TCPWM_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define CLK_TCPWM_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CLK_TCPWM_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CLK_TCPWM_NUM 0U
#define CLK_TCPWM_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CLK_TCPWM_GRP_NUM)
#define CLK_TCPWM_GRP_NUM CLK_TCPWM_GRP_NUM
#endif /* !defined (CLK_TCPWM_GRP_NUM) */

#define CLK_HALL_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define CLK_HALL_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CLK_HALL_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CLK_HALL_NUM 1U
#define CLK_HALL_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CLK_HALL_GRP_NUM)
#define CLK_HALL_GRP_NUM CLK_HALL_GRP_NUM
#endif /* !defined (CLK_HALL_GRP_NUM) */

#define CLK_FC_PWM_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define CLK_FC_PWM_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CLK_FC_PWM_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CLK_FC_PWM_NUM 2U
#define CLK_FC_PWM_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CLK_FC_PWM_GRP_NUM)
#define CLK_FC_PWM_GRP_NUM CLK_FC_PWM_GRP_NUM
#endif /* !defined (CLK_FC_PWM_GRP_NUM) */

#define peri_0_group_5_div_8_3_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define peri_0_group_5_div_8_3_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_5_div_8_3_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_5_div_8_3_NUM 3U
#define PERI_0_GROUP_5_DIV_8_3_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_5_div_8_3_GRP_NUM)
#define peri_0_group_5_div_8_3_GRP_NUM PERI_0_GROUP_5_DIV_8_3_GRP_NUM
#endif /* !defined (peri_0_group_5_div_8_3_GRP_NUM) */

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t CLK_TCPWM_obj;
extern const cyhal_resource_inst_t CLK_HALL_obj;
extern const cyhal_resource_inst_t CLK_FC_PWM_obj;
extern const cyhal_resource_inst_t peri_0_group_5_div_8_3_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void);
void reserve_cycfg_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_CLOCKS_H */
