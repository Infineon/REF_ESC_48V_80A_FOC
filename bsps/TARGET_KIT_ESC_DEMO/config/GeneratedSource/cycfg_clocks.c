/*******************************************************************************
 * File Name: cycfg_clocks.c
 *
 * Description:
 * Clock configuration
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

#include "cycfg_clocks.h"

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CLK_TCPWM_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_TCPWM_HW,
    .channel_num = CLK_TCPWM_NUM,
};
const cyhal_resource_inst_t CLK_HALL_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_HALL_HW,
    .channel_num = CLK_HALL_NUM,
};
const cyhal_resource_inst_t CLK_FC_PWM_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_FC_PWM_HW,
    .channel_num = CLK_FC_PWM_NUM,
};
const cyhal_resource_inst_t peri_0_group_5_div_8_3_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_group_5_div_8_3_HW,
    .channel_num = peri_0_group_5_div_8_3_NUM,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void)
{
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_TCPWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)CLK_TCPWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_TCPWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_HALL_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)CLK_HALL_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_HALL_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_FC_PWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 2U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)CLK_FC_PWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 2U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_FC_PWM_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 2U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_3_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 3U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_3_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 3U, 9U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_3_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 3U);
}
void reserve_cycfg_clocks(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&CLK_TCPWM_obj);
    cyhal_hwmgr_reserve(&CLK_HALL_obj);
    cyhal_hwmgr_reserve(&CLK_FC_PWM_obj);
    cyhal_hwmgr_reserve(&peri_0_group_5_div_8_3_obj);
#endif /* defined (CY_USING_HAL) */
}
