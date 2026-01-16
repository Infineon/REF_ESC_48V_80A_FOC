/*******************************************************************************
 * File Name: cycfg_system.c
 *
 * Description:
 * System configuration
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

#include "cycfg_system.h"

#define CY_CFG_SYSCLK_ECO_ERROR 1
#define CY_CFG_SYSCLK_ALTHF_ERROR 2
#define CY_CFG_SYSCLK_PLL_ERROR 3
#define CY_CFG_SYSCLK_FLL_ERROR 4
#define CY_CFG_SYSCLK_WCO_ERROR 5
#define CY_CFG_SYSCLK_CLKBAK_ENABLED 1
#define CY_CFG_SYSCLK_CLKBAK_SOURCE CY_SYSCLK_BAK_IN_CLKLF
#define CY_CFG_SYSCLK_DPLL_LP0_ENABLED 1
#define CY_CFG_SYSCLK_DPLL_LP0_FEEDBACK_DIV 45
#define CY_CFG_SYSCLK_DPLL_LP0_REFERENCE_DIV 6
#define CY_CFG_SYSCLK_DPLL_LP0_OUTPUT_DIV 2
#define CY_CFG_SYSCLK_DPLL_LP0_FRAC_DIV 0
#define CY_CFG_SYSCLK_DPLL_LP0_FRAC_DITHER_EN false
#define CY_CFG_SYSCLK_DPLL_LP0_FRAC_EN true
#define CY_CFG_SYSCLK_DPLL_LP0_LF_MODE false
#define CY_CFG_SYSCLK_DPLL_LP0_OUTPUT_MODE CY_SYSCLK_FLLPLL_OUTPUT_AUTO
#define CY_CFG_SYSCLK_DPLL_LP0_OUTPUT_FREQ 180000000
#define CY_CFG_SYSCLK_DPLL_LP1_ENABLED 1
#define CY_CFG_SYSCLK_DPLL_LP1_FEEDBACK_DIV 60
#define CY_CFG_SYSCLK_DPLL_LP1_REFERENCE_DIV 6
#define CY_CFG_SYSCLK_DPLL_LP1_OUTPUT_DIV 2
#define CY_CFG_SYSCLK_DPLL_LP1_FRAC_DIV 0
#define CY_CFG_SYSCLK_DPLL_LP1_FRAC_DITHER_EN false
#define CY_CFG_SYSCLK_DPLL_LP1_FRAC_EN true
#define CY_CFG_SYSCLK_DPLL_LP1_LF_MODE false
#define CY_CFG_SYSCLK_DPLL_LP1_OUTPUT_MODE CY_SYSCLK_FLLPLL_OUTPUT_AUTO
#define CY_CFG_SYSCLK_DPLL_LP1_OUTPUT_FREQ 240000000
#define CY_CFG_SYSCLK_FLL_ENABLED 1
#define CY_CFG_SYSCLK_FLL_MULT 500U
#define CY_CFG_SYSCLK_FLL_REFDIV 120U
#define CY_CFG_SYSCLK_FLL_CCO_RANGE CY_SYSCLK_FLL_CCO_RANGE4
#define CY_CFG_SYSCLK_FLL_ENABLE_OUTDIV true
#define CY_CFG_SYSCLK_FLL_LOCK_TOLERANCE 10U
#define CY_CFG_SYSCLK_FLL_IGAIN 9U
#define CY_CFG_SYSCLK_FLL_PGAIN 5U
#define CY_CFG_SYSCLK_FLL_SETTLING_COUNT 48U
#define CY_CFG_SYSCLK_FLL_OUTPUT_MODE CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT
#define CY_CFG_SYSCLK_FLL_CCO_FREQ 355U
#define CY_CFG_SYSCLK_FLL_OUT_FREQ 100000000
#define CY_CFG_SYSCLK_CLKHF0_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF0_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF0_FREQ_MHZ 180UL
#define CY_CFG_SYSCLK_CLKHF0_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH1
#define CY_CFG_SYSCLK_CLKHF1_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF1_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF1_FREQ_MHZ 180UL
#define CY_CFG_SYSCLK_CLKHF1_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH1
#define CY_CFG_SYSCLK_CLKHF2_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF2_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF2_FREQ_MHZ 100UL
#define CY_CFG_SYSCLK_CLKHF2_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH0
#define CY_CFG_SYSCLK_CLKHF3_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF3_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF3_FREQ_MHZ 240UL
#define CY_CFG_SYSCLK_CLKHF3_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH2
#define CY_CFG_SYSCLK_CLKHF4_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF4_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF4_FREQ_MHZ 240UL
#define CY_CFG_SYSCLK_CLKHF4_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH2
#define CY_CFG_SYSCLK_CLKHF5_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF5_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF5_FREQ_MHZ 48UL
#define CY_CFG_SYSCLK_CLKHF5_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH5
#define CY_CFG_SYSCLK_CLKHF6_ENABLED 1
#define CY_CFG_SYSCLK_CLKHF6_DIVIDER CY_SYSCLK_CLKHF_NO_DIVIDE
#define CY_CFG_SYSCLK_CLKHF6_FREQ_MHZ 8UL
#define CY_CFG_SYSCLK_CLKHF6_CLKPATH CY_SYSCLK_CLKHF_IN_CLKPATH6
#define CY_CFG_SYSCLK_IHO_ENABLED 1
#define CY_CFG_SYSCLK_ILO_ENABLED 1
#define CY_CFG_SYSCLK_ILO_HIBERNATE true
#define CY_CFG_SYSCLK_IMO_ENABLED 1
#define CY_CFG_SYSCLK_CLKLF_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH0_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH0_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH1_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH1_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH2_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH2_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH3_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH3_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH4_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH4_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH5_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH5_SOURCE CY_SYSCLK_CLKPATH_IN_IHO
#define CY_CFG_SYSCLK_CLKPATH6_ENABLED 1
#define CY_CFG_SYSCLK_CLKPATH6_SOURCE CY_SYSCLK_CLKPATH_IN_IMO
#define CY_CFG_PWR_ENABLED 1
#define CY_CFG_PWR_INIT 1
#define CY_CFG_PWR_USING_PMIC 0
#define CY_CFG_PWR_VBACKUP_USING_VDDD 1
#define CY_CFG_PWR_REGULATOR_MODE_MIN 0
#define CY_CFG_PWR_USING_ULP 0

#if defined(CORE_NAME_CM33_0)
static cy_stc_dpll_lp_config_t srss_0_clock_0_dpll250_0_lp_pllConfig =
{
    .feedbackDiv = 45,
    .referenceDiv = 6,
    .outputDiv = 2,
    .pllDcoMode = true,
    .outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracDiv = 0,
    .fracDitherEn = false,
    .fracEn = true,
    .sscgDepth = 0x0U,
    .sscgRate = 0x0U,
    .sscgDitherEn = 0x0U,
    .sscgMode = 0x0U,
    .sscgEn = 0x0U,
    .dcoCode = 0x0U,
    .accMode = 0x1U,
    .tdcMode = 0x1U,
    .pllTg = 0x0U,
    .accCntLock = 0x0U,
    .kiInt = 0x24U,
    .kpInt = 0x1CU,
    .kiAccInt = 0x23U,
    .kpAccInt = 0x1AU,
    .kiFrac = 0x24U,
    .kpFrac = 0x20U,
    .kiAccFrac = 0x23U,
    .kpAccFrac = 0x1AU,
    .kiSscg = 0x18U,
    .kpSscg = 0x18U,
    .kiAccSscg = 0x16U,
    .kpAccSscg = 0x14U,
};
static cy_stc_pll_manual_config_t srss_0_clock_0_dpll250_0_pllConfig =
{
    .lpPllCfg = &srss_0_clock_0_dpll250_0_lp_pllConfig,
};
static cy_stc_dpll_lp_config_t srss_0_clock_0_dpll250_1_lp_pllConfig =
{
    .feedbackDiv = 60,
    .referenceDiv = 6,
    .outputDiv = 2,
    .pllDcoMode = true,
    .outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
    .fracDiv = 0,
    .fracDitherEn = false,
    .fracEn = true,
    .sscgDepth = 0x0U,
    .sscgRate = 0x0U,
    .sscgDitherEn = 0x0U,
    .sscgMode = 0x0U,
    .sscgEn = 0x0U,
    .dcoCode = 0x0U,
    .accMode = 0x1U,
    .tdcMode = 0x1U,
    .pllTg = 0x0U,
    .accCntLock = 0x0U,
    .kiInt = 0x24U,
    .kpInt = 0x1CU,
    .kiAccInt = 0x23U,
    .kpAccInt = 0x1AU,
    .kiFrac = 0x24U,
    .kpFrac = 0x20U,
    .kiAccFrac = 0x23U,
    .kpAccFrac = 0x1AU,
    .kiSscg = 0x18U,
    .kpSscg = 0x18U,
    .kiAccSscg = 0x16U,
    .kpAccSscg = 0x14U,
};
static cy_stc_pll_manual_config_t srss_0_clock_0_dpll250_1_pllConfig =
{
    .lpPllCfg = &srss_0_clock_0_dpll250_1_lp_pllConfig,
};
#endif /* defined(CORE_NAME_CM33_0) */

#if (!defined(CY_DEVICE_SECURE))
static const cy_stc_fll_manual_config_t srss_0_clock_0_fll_0_fllConfig =
{
    .fllMult = 500U,
    .refDiv = 120U,
    .ccoRange = CY_SYSCLK_FLL_CCO_RANGE4,
    .enableOutputDiv = true,
    .lockTolerance = 10U,
    .igain = 9U,
    .pgain = 5U,
    .settlingCount = 48U,
    .outputMode = CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT,
    .cco_Freq = 355U,
};
#endif /* (!defined(CY_DEVICE_SECURE)) */

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t srss_0_clock_0_pathmux_0_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 0U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_1_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 1U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_2_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 2U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_3_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 3U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_4_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 4U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_5_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 5U,
    .channel_num = 0U,
};
const cyhal_resource_inst_t srss_0_clock_0_pathmux_6_obj =
{
    .type = CYHAL_RSC_CLKPATH,
    .block_num = 6U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

__WEAK void cycfg_ClockStartupError(uint32_t error);

#if ((!defined(CY_DEVICE_SECURE)) && (defined(CY_CFG_SYSCLK_FLL_ENABLED)))
__STATIC_INLINE void Cy_SysClk_FllDeInit(void);
#endif /* ((!defined(CY_DEVICE_SECURE)) && (defined(CY_CFG_SYSCLK_FLL_ENABLED))) */

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_ClkBakInit(void);
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void Cy_SysClk_Dpll_Lp0_Init(void);
__STATIC_INLINE void Cy_SysClk_Dpll_Lp1_Init(void);

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_FllInit(void);
__STATIC_INLINE void Cy_SysClk_ClkHf0Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf1Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf2Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf3Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf4Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf5Init(void);
__STATIC_INLINE void Cy_SysClk_ClkHf6Init(void);
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void Cy_SysClk_IhoInit(void);

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_IloInit(void);
__STATIC_INLINE void Cy_SysClk_ClkLfInit(void);
__STATIC_INLINE void Cy_SysClk_ClkPath0Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath1Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath2Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath3Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath4Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath5Init(void);
__STATIC_INLINE void Cy_SysClk_ClkPath6Init(void);
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void init_cycfg_power(void);

__WEAK void cycfg_ClockStartupError(uint32_t error)
{
    (void)error; /* Suppress the compiler warning */
    while(1);
}

#if ((!defined(CY_DEVICE_SECURE)) && (defined(CY_CFG_SYSCLK_FLL_ENABLED)))
__STATIC_INLINE void Cy_SysClk_FllDeInit(void)
{
    Cy_SysClk_FllDisable();
}
#endif /* ((!defined(CY_DEVICE_SECURE)) && (defined(CY_CFG_SYSCLK_FLL_ENABLED))) */

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_ClkBakInit(void)
{
    Cy_SysClk_ClkBakSetSource(CY_SYSCLK_BAK_IN_CLKLF);
}
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void Cy_SysClk_Dpll_Lp0_Init(void)
{
    Cy_SysClk_PllDisable(SRSS_PLL_250M_0_PATH_NUM);

    if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllManualConfigure(SRSS_PLL_250M_0_PATH_NUM, &srss_0_clock_0_dpll250_0_pllConfig))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_PLL_ERROR);
    }
    if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllEnable(SRSS_PLL_250M_0_PATH_NUM, 10000u))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_PLL_ERROR);
    }
}
__STATIC_INLINE void Cy_SysClk_Dpll_Lp1_Init(void)
{
    Cy_SysClk_PllDisable(SRSS_PLL_250M_1_PATH_NUM);

    if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllManualConfigure(SRSS_PLL_250M_1_PATH_NUM, &srss_0_clock_0_dpll250_1_pllConfig))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_PLL_ERROR);
    }
    if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllEnable(SRSS_PLL_250M_1_PATH_NUM, 10000u))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_PLL_ERROR);
    }
}

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_FllInit(void)
{
    if (CY_SYSCLK_SUCCESS != Cy_SysClk_FllManualConfigure(&srss_0_clock_0_fll_0_fllConfig))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_FLL_ERROR);
    }
    if (CY_SYSCLK_SUCCESS != Cy_SysClk_FllEnable(200000UL))
    {
        cycfg_ClockStartupError(CY_CFG_SYSCLK_FLL_ERROR);
    }
}
__STATIC_INLINE void Cy_SysClk_ClkHf0Init(void)
{
    Cy_SysClk_ClkHfSetSource(0U, CY_CFG_SYSCLK_CLKHF0_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(0U, CY_SYSCLK_CLKHF_NO_DIVIDE);
}
__STATIC_INLINE void Cy_SysClk_ClkHf1Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF1, CY_CFG_SYSCLK_CLKHF1_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF1, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF1);
}
__STATIC_INLINE void Cy_SysClk_ClkHf2Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF2, CY_CFG_SYSCLK_CLKHF2_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF2, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF2);
}
__STATIC_INLINE void Cy_SysClk_ClkHf3Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF3, CY_CFG_SYSCLK_CLKHF3_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF3, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF3);
}
__STATIC_INLINE void Cy_SysClk_ClkHf4Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF4, CY_CFG_SYSCLK_CLKHF4_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF4, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF4);
}
__STATIC_INLINE void Cy_SysClk_ClkHf5Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF5, CY_CFG_SYSCLK_CLKHF5_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF5, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF5);
}
__STATIC_INLINE void Cy_SysClk_ClkHf6Init(void)
{
    Cy_SysClk_ClkHfSetSource(CY_CFG_SYSCLK_CLKHF6, CY_CFG_SYSCLK_CLKHF6_CLKPATH);
    Cy_SysClk_ClkHfSetDivider(CY_CFG_SYSCLK_CLKHF6, CY_SYSCLK_CLKHF_NO_DIVIDE);
    Cy_SysClk_ClkHfEnable(CY_CFG_SYSCLK_CLKHF6);
}
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void Cy_SysClk_IhoInit(void)
{
    Cy_SysClk_IhoEnable();
}

#if (!defined(CY_DEVICE_SECURE))
__STATIC_INLINE void Cy_SysClk_IloInit(void)
{
    /* The WDT is unlocked in the default startup code */
    Cy_SysClk_IloEnable();
    Cy_SysClk_IloHibernateOn(true);
}
__STATIC_INLINE void Cy_SysClk_ClkLfInit(void)
{
    /* The WDT is unlocked in the default startup code */
    Cy_SysClk_ClkLfSetSource(CY_SYSCLK_CLKLF_IN_ILO);
}
__STATIC_INLINE void Cy_SysClk_ClkPath0Init(void)
{
    Cy_SysClk_ClkPathSetSource(0U, CY_CFG_SYSCLK_CLKPATH0_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath1Init(void)
{
    Cy_SysClk_ClkPathSetSource(1U, CY_CFG_SYSCLK_CLKPATH1_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath2Init(void)
{
    Cy_SysClk_ClkPathSetSource(2U, CY_CFG_SYSCLK_CLKPATH2_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath3Init(void)
{
    Cy_SysClk_ClkPathSetSource(3U, CY_CFG_SYSCLK_CLKPATH3_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath4Init(void)
{
    Cy_SysClk_ClkPathSetSource(4U, CY_CFG_SYSCLK_CLKPATH4_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath5Init(void)
{
    Cy_SysClk_ClkPathSetSource(5U, CY_CFG_SYSCLK_CLKPATH5_SOURCE);
}
__STATIC_INLINE void Cy_SysClk_ClkPath6Init(void)
{
    Cy_SysClk_ClkPathSetSource(6U, CY_CFG_SYSCLK_CLKPATH6_SOURCE);
}
#endif /* (!defined(CY_DEVICE_SECURE)) */

__STATIC_INLINE void init_cycfg_power(void)
{
    Cy_SysPm_Init();
    /* **Reset the Backup domain on POR, XRES, BOD only if Backup domain is supplied by VDDD** */
    #if (CY_CFG_PWR_VBACKUP_USING_VDDD)
        #ifdef CY_CFG_SYSCLK_ILO_ENABLED
            if (0u == Cy_SysLib_GetResetReason() /* POR, XRES, or BOD */)
            {
                Cy_SysLib_ResetBackupDomain();
                Cy_SysClk_IloDisable();
                Cy_SysClk_IloInit();
            }
        #endif /* CY_CFG_SYSCLK_ILO_ENABLED */
    #endif /* CY_CFG_PWR_VBACKUP_USING_VDDD */

    /* **System Active Power Mode Profile Configuration** */
    #if (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_OD)
        Cy_SysPm_SystemEnterOd();
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_LP)
        Cy_SysPm_SystemEnterLp();
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_MF)
        Cy_SysPm_SystemEnterMf();
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_ULP)
        Cy_SysPm_SystemEnterUlp();
    #endif /* CY_CFG_PWR_SYS_ACTIVE_PROFILE */

    /* **System Active Low Power Profile(LPACTIVE/LPSLEEP) Configuration** */
    #if (CY_CFG_PWR_SYS_LP_PROFILE_MODE)
        Cy_SysPm_SystemLpActiveEnter();
    #endif /* CY_CFG_PWR_SYS_ACTIVE_MODE */

    /* **System Regulators Low Current Configuration** */
    #if (CY_CFG_PWR_REGULATOR_MODE_MIN)
        Cy_SysPm_SystemSetMinRegulatorCurrent();
    #endif /* CY_CFG_PWR_REGULATOR_MODE_MIN */

    /* **System Idle Power Mode Configuration** */
    #if (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP);
    #elif (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP_RAM);
    #elif (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_OFF)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP_OFF);
    #endif /* CY_CFG_PWR_SYS_IDLE_MODE */
}
void init_cycfg_system(void)
{
    /* Set worst case memory wait states (! ultra low power, 180 MHz), will update at the end */
    Cy_SysLib_SetWaitStates(false, 180UL);
    
    /* Unlock WDT to be able to modify LFCLK registers */
    Cy_WDT_Unlock();
    
    #ifdef CY_CFG_PWR_ENABLED
        #ifdef CY_CFG_PWR_INIT
            init_cycfg_power();
        #else
            #warning Power system will not be configured. Update power personality to v1.20 or later.
        #endif /* CY_CFG_PWR_INIT */
    #endif /* CY_CFG_PWR_ENABLED */
    
    /* Disable FLL */
    #ifdef CY_CFG_SYSCLK_FLL_ENABLED
        Cy_SysClk_FllDeInit();
    #endif
    
    /* Enable all source clocks */
    #ifdef CY_CFG_SYSCLK_PILO_ENABLED
        Cy_SysClk_PiloInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_WCO_ENABLED
        Cy_SysClk_WcoInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_ECO_ENABLED
        Cy_SysClk_EcoInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKLF_ENABLED
        Cy_SysClk_ClkLfInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_EXTCLK_ENABLED
        Cy_SysClk_ExtClkInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_IHO_ENABLED
        Cy_SysClk_IhoInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_ALTHF_ENABLED
        Cy_SysClk_AltHfInit();
    #endif
    
    #if defined (SRSS_PLL_250M_0_PATH_NUM) && !defined (CY_CFG_SYSCLK_DPLL_LP0_ENABLED)
        Cy_SysClk_PllDisable(SRSS_PLL_250M_0_PATH_NUM);
    #endif
    #if defined (SRSS_PLL_250M_1_PATH_NUM) && !defined (CY_CFG_SYSCLK_DPLL_LP1_ENABLED)
        Cy_SysClk_PllDisable(SRSS_PLL_250M_1_PATH_NUM);
    #endif
    
    /* Configure Path Clocks */
    #ifdef CY_CFG_SYSCLK_CLKPATH1_ENABLED
        Cy_SysClk_ClkPath1Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH2_ENABLED
        Cy_SysClk_ClkPath2Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH3_ENABLED
        Cy_SysClk_ClkPath3Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH4_ENABLED
        Cy_SysClk_ClkPath4Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH5_ENABLED
        Cy_SysClk_ClkPath5Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH6_ENABLED
        Cy_SysClk_ClkPath6Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH7_ENABLED
        Cy_SysClk_ClkPath7Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH8_ENABLED
        Cy_SysClk_ClkPath8Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH9_ENABLED
        Cy_SysClk_ClkPath9Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH10_ENABLED
        Cy_SysClk_ClkPath10Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH11_ENABLED
        Cy_SysClk_ClkPath11Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH12_ENABLED
        Cy_SysClk_ClkPath12Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH13_ENABLED
        Cy_SysClk_ClkPath13Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH14_ENABLED
        Cy_SysClk_ClkPath14Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKPATH15_ENABLED
        Cy_SysClk_ClkPath15Init();
    #endif
    
    /* Configure and enable PLLs */
    #ifdef CY_CFG_SYSCLK_DPLL_LP0_ENABLED
        Cy_SysClk_Dpll_Lp0_Init();
    #endif
    #ifdef CY_CFG_SYSCLK_DPLL_LP1_ENABLED
        Cy_SysClk_Dpll_Lp1_Init();
    #endif
    /* Configure HF clocks */
    #ifdef CY_CFG_SYSCLK_CLKHF1_ENABLED
        Cy_SysClk_ClkHf1Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF2_ENABLED
        Cy_SysClk_ClkHf2Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF3_ENABLED
        Cy_SysClk_ClkHf3Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF4_ENABLED
        Cy_SysClk_ClkHf4Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF5_ENABLED
        Cy_SysClk_ClkHf5Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF6_ENABLED
        Cy_SysClk_ClkHf6Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF7_ENABLED
        Cy_SysClk_ClkHf7Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF8_ENABLED
        Cy_SysClk_ClkHf8Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF9_ENABLED
        Cy_SysClk_ClkHf9Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF10_ENABLED
        Cy_SysClk_ClkHf10Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF11_ENABLED
        Cy_SysClk_ClkHf11Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF12_ENABLED
        Cy_SysClk_ClkHf12Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF13_ENABLED
        Cy_SysClk_ClkHf13Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF14_ENABLED
        Cy_SysClk_ClkHf14Init();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF15_ENABLED
        Cy_SysClk_ClkHf15Init();
    #endif
    
    /* Configure miscellaneous clocks */
    #ifdef CY_CFG_SYSCLK_CLKALTSYSTICK_ENABLED
        Cy_SysClk_ClkAltSysTickInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKPUMP_ENABLED
        Cy_SysClk_ClkPumpInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKBAK_ENABLED
        Cy_SysClk_ClkBakInit();
    #endif
    
    /* Configure default enabled clocks */
    #ifdef CY_CFG_SYSCLK_ILO_ENABLED
        Cy_SysClk_IloInit();
    #endif
    
    #ifndef CY_CFG_SYSCLK_IMO_ENABLED
        #error the IMO must be enabled for proper chip operation
    #endif
    
    #ifdef CY_CFG_SYSCLK_MFO_ENABLED
        Cy_SysClk_MfoInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKMF_ENABLED
        Cy_SysClk_ClkMfInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKPWR_ENABLED
        Cy_SysClk_ClkPwrInit();
    #endif
    
    #ifdef CY_CFG_SYSCLK_CLKPATH0_ENABLED
        Cy_SysClk_ClkPath0Init();
    #endif
    
    /* Configure and enable FLL */
    #ifdef CY_CFG_SYSCLK_FLL_ENABLED
        Cy_SysClk_FllInit();
    #endif
    
    Cy_SysClk_ClkHf0Init();
    
    /* Disable Unused Clock Sources */
    #ifndef CY_CFG_SYSCLK_IHO_ENABLED
        Cy_SysClk_IhoDisable();
    #endif
    
    /* Set accurate flash wait states */
    #if (defined (CY_CFG_PWR_ENABLED) && defined (CY_CFG_SYSCLK_CLKHF0_ENABLED))
        Cy_SysLib_SetWaitStates(CY_CFG_PWR_USING_ULP != 0, CY_CFG_SYSCLK_CLKHF0_FREQ_MHZ);
    #endif
    
    #if defined(CY_CFG_SYSCLK_ECO_PRESCALER_ENABLED)
        Cy_SysClk_EcoPrescalerInit();
    #endif /* defined (CY_CFG_SYSCLK_ECO_PRESCALER_ENABLED) */
    
    #ifdef CY_CFG_SYSCLK_CLKALTSYSTICK_ENABLED
        Cy_SysClk_ClkAltSysTickInit();
    #endif
    
    /* Update System Core Clock values for correct Cy_SysLib_Delay functioning */
    SystemCoreClockUpdate();
    /* Configure HF clocks CSV */
    #ifdef CY_CFG_SYSCLK_CLKHF0_CSV_ENABLED
        Cy_SysClk_ClkHf0CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF1_CSV_ENABLED
        Cy_SysClk_ClkHf1CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF2_CSV_ENABLED
        Cy_SysClk_ClkHf2CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF3_CSV_ENABLED
        Cy_SysClk_ClkHf3CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF4_CSV_ENABLED
        Cy_SysClk_ClkHf4CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF5_CSV_ENABLED
        Cy_SysClk_ClkHf5CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF6_CSV_ENABLED
        Cy_SysClk_ClkHf6CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF7_CSV_ENABLED
        Cy_SysClk_ClkHf7CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF8_CSV_ENABLED
        Cy_SysClk_ClkHf8CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF9_CSV_ENABLED
        Cy_SysClk_ClkHf9CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF10CSV_ENABLED
        Cy_SysClk_ClkHf10CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF11_CSV_ENABLED
        Cy_SysClk_ClkHf11CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF12_CSV_ENABLED
        Cy_SysClk_ClkHf12CsvInit();
    #endif
    #ifdef CY_CFG_SYSCLK_CLKHF13_CSV_ENABLED
        Cy_SysClk_ClkHf13CsvInit();
    #endif
    
    /* Configure LF clocks CSV */
    #ifdef CY_CFG_SYSCLK_CLKLF_CSV_ENABLED
        Cy_SysClk_ClkLfCsvInit();
    #endif
#if (!defined(CY_DEVICE_SECURE))
    CY_UNUSED_PARAM(srss_0_clock_0_fll_0_fllConfig);
#endif /* (!defined(CY_DEVICE_SECURE)) */
#if defined (CY_USING_HAL)
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_0_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_1_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_2_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_3_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_4_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_5_obj)))
    {
        CY_HALT();
    }
    if(CY_RSLT_SUCCESS != (cyhal_hwmgr_reserve(&srss_0_clock_0_pathmux_6_obj)))
    {
        CY_HALT();
    }
#endif /* defined (CY_USING_HAL) */
}
