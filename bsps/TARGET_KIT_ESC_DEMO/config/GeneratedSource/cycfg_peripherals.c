/*******************************************************************************
 * File Name: cycfg_peripherals.c
 *
 * Description:
 * Analog configuration
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

#include "cycfg_peripherals.h"

#define SYNC_ISR1_INPUT_DISABLED 0x7U
#define EXE_TIMER_INPUT_DISABLED 0x7U
#define HALL_TIMER_INPUT_DISABLED 0x7U
#define PWM_U_INPUT_DISABLED 0x7U
#define PWM_V_INPUT_DISABLED 0x7U
#define PWM_W_INPUT_DISABLED 0x7U
#define PWM_SYNC_INPUT_DISABLED 0x7U
#define ADC0_ISR0_INPUT_DISABLED 0x7U
#define FC_PWM_COUNTER_INPUT_DISABLED 0x7U
#define START_SIGNAL_COUNTER_INPUT_DISABLED 0x7U

const cy_stc_hppass_cfg_t pass_0_config =
{
    .ac =
    {
        .sttEntriesNum = 1U,
        .stt = pass_0_ac_0_stt_0_config,
        .gpioOutEnMsk = 0U,
        .startupClkDiv = 24U,
        .startup =
        {
            {
                .count = 200U,
                .sar = true,
                .csgChan = true,
                .csgSlice = false,
                .csgReady = false,
            },
            {
                .count = 50U,
                .sar = false,
                .csgChan = false,
                .csgSlice = true,
                .csgReady = false,
            },
            {
                .count = 0U,
                .sar = false,
                .csgChan = false,
                .csgSlice = false,
                .csgReady = true,
            },
            {
                .count = 0U,
                .sar = false,
                .csgChan = false,
                .csgSlice = false,
                .csgReady = false,
            },
        },
    },
    .csg = NULL,
    .sar = &pass_0_sar_0_config,
    .trigIn =
    {
        {
            .type = CY_HPPASS_TR_HW_A,
            .hwMode = CY_HPPASS_PULSE_ON_POS_SINGLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
    },
    .trigPulse =
    {
        CY_HPPASS_SAR_GROUP_0, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
    },
    .trigLevel =
    {
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
    },
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t pass_0_adc_hal_obj =
{
    .type = CYHAL_RSC_ADC,
    .block_num = 0U,
    .channel_num = 0U,
};
const cyhal_adc_configurator_t pass_0_adc_hal_config =
{
    .resource = &pass_0_adc_hal_obj,
    .hppass_config = &pass_0_config,
    .clock = NULL,
    .num_channels = 4U,
    .achieved_acquisition_time = NULL,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC)
const mtb_hal_adc_configurator_t pass_0_adc_hal_config =
{
    .base = HPPASS,
    .hppass_config = &pass_0_config,
    .num_channels = 4U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC) */

const cy_stc_hppass_ac_stt_t pass_0_ac_0_stt_0_config[] =
{
    {
        .condition = CY_HPPASS_CONDITION_FALSE,
        .action = CY_HPPASS_ACTION_STOP,
        .branchStateIdx = 0U,
        .interrupt = false,
        .count = 1U,
        .gpioOutUnlock = false,
        .gpioOutMsk = 0U,
        .csgUnlock = {false, false, false, false, false},
        .csgEnable = {false, false, false, false, false},
        .csgDacTrig = {false, false, false, false, false},
        .sarUnlock = true,
        .sarEnable = true,
        .sarGrpMsk = 0U,
        .sarMux = {{false, 0U}, {false, 0U}, {false, 0U}, {false, 0U}},
    },
};
const cy_stc_hppass_sar_t pass_0_sar_0_config =
{
    .vref = CY_HPPASS_SAR_VREF_VDDA,
    .lowSupply = false,
    .offsetCal = false,
    .linearCal = false,
    .gainCal = false,
    .chanId = false,
    .aroute = true,
    .dirSampEnMsk = 0x3CU,
    .muxSampEnMsk = 0x0U,
    .holdCount = 32U,
    .dirSampGain =
    {
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
    },
    .muxSampGain =
    {
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
    },
    .sampTime =
    {
        8U, 
        16U, 
        32U, 
    },
    .chan =
    {
        NULL, 
        NULL, 
        &ADC_SAMP_IU_config, 
        &ADC_SAMP_IV_config, 
        &ADC_SAMP_IW_config, 
        &ADC_SAMP_VBUS_config, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .grp =
    {
        &ADC_SEQ0_config, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .limit =
    {
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .muxMode =
    {
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
    },
    .fir =
    {
        NULL, 
        NULL, 
    },
    .fifo = NULL,
};
const cy_stc_hppass_sar_chan_t ADC_SAMP_IU_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_SAMP_IV_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_SAMP_IW_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_SAMP_VBUS_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_grp_t ADC_SEQ0_config =
{
    .dirSampMsk = 0x3CU,
    .muxSampMsk = 0x0U,
    .muxChanIdx =
    {
        0U, 
        3U, 
        1U, 
        1U, 
    },
    .trig = CY_HPPASS_SAR_TRIG_0,
    .sampTime = CY_HPPASS_SAR_SAMP_TIME_0,
    .priority = true,
    .continuous = false,
};
const cy_stc_tcpwm_pwm_config_t SYNC_ISR1_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 240000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 238000,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 ) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 238000,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = SYNC_ISR1_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_OVERFLOW,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SYNC_ISR1_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN0,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t SYNC_ISR1_hal_clock =
{
    .clock_ref = &SYNC_ISR1_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t SYNC_ISR1_hal_config =
{
    .base = SYNC_ISR1_HW,
    .clock = &SYNC_ISR1_hal_clock,
    .group = 0UL,
    .cntnum = 0UL,
    .max_count = 240000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SYNC_ISR1_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SYNC_ISR1_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t SYNC_ISR1_hal_config =
{
    .resource = &SYNC_ISR1_obj,
    .config = &SYNC_ISR1_config,
    .clock = &SYNC_ISR1_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_counter_config_t EXE_TIMER_config =
{
    .period = 4294967295,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .captureInputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = EXE_TIMER_INPUT_DISABLED & 0x3U,
    .capture1Input = CY_TCPWM_INPUT_0,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t EXE_TIMER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 1U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t EXE_TIMER_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t EXE_TIMER_hal_config =
{
    .resource = &EXE_TIMER_obj,
    .config = &EXE_TIMER_config,
    .clock = &EXE_TIMER_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t EXE_TIMER_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN1,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t EXE_TIMER_hal_clock =
{
    .clock_ref = &EXE_TIMER_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t EXE_TIMER_hal_config =
{
    .tcpwm_base = EXE_TIMER_HW,
    .clock = &EXE_TIMER_hal_clock,
    .tcpwm_cntnum = 1U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

const cy_stc_tcpwm_counter_config_t HALL_TIMER_config =
{
    .period = 4294967295,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .captureInputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = HALL_TIMER_INPUT_DISABLED & 0x3U,
    .capture1Input = CY_TCPWM_INPUT_0,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t HALL_TIMER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 2U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t HALL_TIMER_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 1,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t HALL_TIMER_hal_config =
{
    .resource = &HALL_TIMER_obj,
    .config = &HALL_TIMER_config,
    .clock = &HALL_TIMER_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t HALL_TIMER_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN2,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 1,
};
const mtb_hal_clock_t HALL_TIMER_hal_clock =
{
    .clock_ref = &HALL_TIMER_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t HALL_TIMER_hal_config =
{
    .tcpwm_base = HALL_TIMER_HW,
    .clock = &HALL_TIMER_hal_clock,
    .tcpwm_cntnum = 2U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

const cy_stc_tcpwm_pwm_config_t PWM_U_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 100,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 12000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 2000,
    .compare1 = 2000,
    .enableCompareSwap = true,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .swapInput = TCPWM0_GRP1_CNT0_CAPTURE0_VALUE,
    .reloadInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .reloadInput = TCPWM0_GRP1_CNT0_RELOAD_VALUE,
    .startInputMode = PWM_U_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_U_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_U_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 2000,
    .compare3 = 2000,
    .enableCompare1Swap = true,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = true,
    .kill1InputMode = PWM_U_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 100,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 100,
    .deadTimeClocksBuff_linecompl_out = 100,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_U_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN256,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_U_hal_clock =
{
    .clock_ref = &PWM_U_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_U_hal_config =
{
    .base = PWM_U_HW,
    .clock = &PWM_U_hal_clock,
    .group = 1UL,
    .cntnum = 256UL,
    .max_count = 12000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_U_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_U_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_U_hal_config =
{
    .resource = &PWM_U_obj,
    .config = &PWM_U_config,
    .clock = &PWM_U_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_V_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 100,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 12000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 6000,
    .compare1 = 6000,
    .enableCompareSwap = true,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .swapInput = TCPWM0_GRP1_CNT1_CAPTURE0_VALUE,
    .reloadInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .reloadInput = TCPWM0_GRP1_CNT1_RELOAD_VALUE,
    .startInputMode = PWM_V_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_V_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_V_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 6000,
    .compare3 = 6000,
    .enableCompare1Swap = true,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = true,
    .kill1InputMode = PWM_V_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 100,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 100,
    .deadTimeClocksBuff_linecompl_out = 100,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_V_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN257,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_V_hal_clock =
{
    .clock_ref = &PWM_V_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_V_hal_config =
{
    .base = PWM_V_HW,
    .clock = &PWM_V_hal_clock,
    .group = 1UL,
    .cntnum = 257UL,
    .max_count = 12000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_V_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 1U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_V_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_V_hal_config =
{
    .resource = &PWM_V_obj,
    .config = &PWM_V_config,
    .clock = &PWM_V_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_W_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 100,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 12000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 10000,
    .compare1 = 10000,
    .enableCompareSwap = true,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .swapInput = TCPWM0_GRP1_CNT2_CAPTURE0_VALUE,
    .reloadInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .reloadInput = TCPWM0_GRP1_CNT2_RELOAD_VALUE,
    .startInputMode = PWM_W_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_W_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_W_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 10000,
    .compare3 = 10000,
    .enableCompare1Swap = true,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = true,
    .kill1InputMode = PWM_W_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 100,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 100,
    .deadTimeClocksBuff_linecompl_out = 100,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_W_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN258,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_W_hal_clock =
{
    .clock_ref = &PWM_W_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_W_hal_config =
{
    .base = PWM_W_HW,
    .clock = &PWM_W_hal_clock,
    .group = 1UL,
    .cntnum = 258UL,
    .max_count = 12000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_W_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 2U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_W_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_W_hal_config =
{
    .resource = &PWM_W_obj,
    .config = &PWM_W_config,
    .clock = &PWM_W_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_SYNC_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 24000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 12000,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_SYNC_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .reloadInput = TCPWM0_GRP1_CNT3_RELOAD_VALUE,
    .startInputMode = PWM_SYNC_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_SYNC_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_SYNC_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 12000,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_SYNC_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_CC0_MATCH,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_SYNC_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN259,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_SYNC_hal_clock =
{
    .clock_ref = &PWM_SYNC_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_SYNC_hal_config =
{
    .base = PWM_SYNC_HW,
    .clock = &PWM_SYNC_hal_clock,
    .group = 1UL,
    .cntnum = 259UL,
    .max_count = 24000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_SYNC_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 3U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_SYNC_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_SYNC_hal_config =
{
    .resource = &PWM_SYNC_obj,
    .config = &PWM_SYNC_config,
    .clock = &PWM_SYNC_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t ADC0_ISR0_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 24000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 12000,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = ADC0_ISR0_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .reloadInput = TCPWM0_GRP1_CNT4_RELOAD_VALUE,
    .startInputMode = ADC0_ISR0_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = ADC0_ISR0_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = ADC0_ISR0_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 12000,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = ADC0_ISR0_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_CC0_MATCH,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t ADC0_ISR0_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN260,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t ADC0_ISR0_hal_clock =
{
    .clock_ref = &ADC0_ISR0_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t ADC0_ISR0_hal_config =
{
    .base = ADC0_ISR0_HW,
    .clock = &ADC0_ISR0_hal_clock,
    .group = 1UL,
    .cntnum = 260UL,
    .max_count = 24000,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t ADC0_ISR0_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 4U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t ADC0_ISR0_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t ADC0_ISR0_hal_config =
{
    .resource = &ADC0_ISR0_obj,
    .config = &ADC0_ISR0_config,
    .clock = &ADC0_ISR0_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_counter_config_t FC_PWM_COUNTER_config =
{
    .period = 65535,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 ),
    .captureInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .captureInput = TCPWM0_GRP1_CNT5_CAPTURE0_VALUE,
    .reloadInputMode = FC_PWM_COUNTER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = FC_PWM_COUNTER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = FC_PWM_COUNTER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = FC_PWM_COUNTER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .capture1Input = TCPWM0_GRP1_CNT5_CAPTURE1_VALUE,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t FC_PWM_COUNTER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 5U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t FC_PWM_COUNTER_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 2,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t FC_PWM_COUNTER_hal_config =
{
    .resource = &FC_PWM_COUNTER_obj,
    .config = &FC_PWM_COUNTER_config,
    .clock = &FC_PWM_COUNTER_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t FC_PWM_COUNTER_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN261,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 2,
};
const mtb_hal_clock_t FC_PWM_COUNTER_hal_clock =
{
    .clock_ref = &FC_PWM_COUNTER_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t FC_PWM_COUNTER_hal_config =
{
    .tcpwm_base = FC_PWM_COUNTER_HW,
    .clock = &FC_PWM_COUNTER_hal_clock,
    .tcpwm_cntnum = 261U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

const cy_stc_tcpwm_counter_config_t START_SIGNAL_COUNTER_config =
{
    .period = 24000,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC ) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .captureInputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = START_SIGNAL_COUNTER_INPUT_DISABLED & 0x3U,
    .capture1Input = CY_TCPWM_INPUT_0,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t START_SIGNAL_COUNTER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 6U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t START_SIGNAL_COUNTER_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 3,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t START_SIGNAL_COUNTER_hal_config =
{
    .resource = &START_SIGNAL_COUNTER_obj,
    .config = &START_SIGNAL_COUNTER_config,
    .clock = &START_SIGNAL_COUNTER_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t START_SIGNAL_COUNTER_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN262,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 3,
};
const mtb_hal_clock_t START_SIGNAL_COUNTER_hal_clock =
{
    .clock_ref = &START_SIGNAL_COUNTER_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t START_SIGNAL_COUNTER_hal_config =
{
    .tcpwm_base = START_SIGNAL_COUNTER_HW,
    .clock = &START_SIGNAL_COUNTER_hal_clock,
    .tcpwm_cntnum = 262U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

__WEAK void __NO_RETURN pass_0_error(cy_rslt_t error);

__WEAK void __NO_RETURN pass_0_error(cy_rslt_t error)
{
    (void)error; /* Suppress the compiler warning */
    while(true);
}
void pass_0_start(void)
{
    if (!Cy_HPPASS_AC_IsBlockReady())
    {
        cy_rslt_t hppassStatus = (cy_rslt_t)Cy_HPPASS_AC_Start(0U, 1000U);
        if (CY_RSLT_SUCCESS != hppassStatus)
        {
            pass_0_error(hppassStatus);
        }
    }
}
void init_cycfg_peripherals(void)
{
    cy_rslt_t hppassStatus = 0UL;
    hppassStatus = Cy_HPPASS_Init(&pass_0_config);
    if (CY_RSLT_SUCCESS != hppassStatus)
    {
        pass_0_error(hppassStatus);
    }
    Cy_HPPASS_SAR_CrossTalkAdjust((uint8_t)1U << 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN0, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3)
    /* Workaround for TCPWM on PSOC C3 device: Enable HRPWM block if it exists. */
    (*((volatile uint32_t *)(GET_ALIAS_ADDRESS(CY_SYSTEM_TCPWM_DISABLE_ADDR))) = 0UL);
#endif /* defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3) */
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN1, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN2, CY_SYSCLK_DIV_8_BIT, 1U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN256, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN257, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN258, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN259, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN260, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN261, CY_SYSCLK_DIV_8_BIT, 2U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN262, CY_SYSCLK_DIV_8_BIT, 3U);
}
void reserve_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&SYNC_ISR1_obj);
    cyhal_hwmgr_reserve(&EXE_TIMER_obj);
    cyhal_hwmgr_reserve(&HALL_TIMER_obj);
    cyhal_hwmgr_reserve(&PWM_U_obj);
    cyhal_hwmgr_reserve(&PWM_V_obj);
    cyhal_hwmgr_reserve(&PWM_W_obj);
    cyhal_hwmgr_reserve(&PWM_SYNC_obj);
    cyhal_hwmgr_reserve(&ADC0_ISR0_obj);
    cyhal_hwmgr_reserve(&FC_PWM_COUNTER_obj);
    cyhal_hwmgr_reserve(&START_SIGNAL_COUNTER_obj);
#endif /* defined (CY_USING_HAL) */
}
