/*******************************************************************************
 * File Name: cycfg_peripherals.h
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_device.h"
#include "cy_hppass.h"
#include "cy_sysint.h"
#include "cy_tcpwm_pwm.h"
#include "cy_sysclk.h"
#include "cycfg_routing.h"
#include "cy_tcpwm_counter.h"

#if defined (CY_USING_HAL)
#include "cyhal.h"
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#include "mtb_hal_hw_types.h"
#include "cycfg_clocks.h"
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define debug600_0_ENABLED 1U
#define pass_0_ENABLED 1U
#define pass_0_ac_0_ENABLED 1U
#define pass_0_ac_0_stt_0_vstate_0_ENABLED 1U
#define pass_0_input_trigger_0_ENABLED 1U
#define pass_0_input_trigger_0_IDX 0U
#define pass_0_output_pulse_trigger_0_ENABLED 1U
#define pass_0_output_pulse_trigger_0_IDX 0U
#define pass_0_sar_0_ENABLED 1U
#define pass_0_sar_0_VREF 3300U
#define ADC_SAMP_IU_ENABLED 1U
#define ADC_SAMP_IU_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(2U)
#define ADC_SAMP_IU_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_2
#define ADC_SAMP_IU_CHAN_IDX 2U
#define AN_A2_CHAN_IDX 2U
#define ADC_SAMP_IV_ENABLED 1U
#define ADC_SAMP_IV_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(3U)
#define ADC_SAMP_IV_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_3
#define ADC_SAMP_IV_CHAN_IDX 3U
#define AN_A3_CHAN_IDX 3U
#define ADC_SAMP_IW_ENABLED 1U
#define ADC_SAMP_IW_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(4U)
#define ADC_SAMP_IW_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_4
#define ADC_SAMP_IW_CHAN_IDX 4U
#define AN_A4_CHAN_IDX 4U
#define ADC_SAMP_VBUS_ENABLED 1U
#define ADC_SAMP_VBUS_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(5U)
#define ADC_SAMP_VBUS_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_5
#define ADC_SAMP_VBUS_CHAN_IDX 5U
#define AN_A5_CHAN_IDX 5U
#define pass_0_sar_0_dir_sampler_2_ENABLED 1U
#define pass_0_sar_0_dir_sampler_3_ENABLED 1U
#define pass_0_sar_0_dir_sampler_4_ENABLED 1U
#define pass_0_sar_0_dir_sampler_5_ENABLED 1U
#define ADC_SEQ0_ENABLED 1U
#define SYNC_ISR1_ENABLED 1U
#define SYNC_ISR1_HW TCPWM0
#define SYNC_ISR1_NUM 0UL
#define SYNC_ISR1_IRQ tcpwm_0_interrupts_0_IRQn
#define EXE_TIMER_ENABLED 1U
#define EXE_TIMER_HW TCPWM0
#define EXE_TIMER_NUM 1UL
#define HALL_TIMER_ENABLED 1U
#define HALL_TIMER_HW TCPWM0
#define HALL_TIMER_NUM 2UL
#define PWM_U_ENABLED 1U
#define PWM_U_HW TCPWM0
#define PWM_U_NUM 256UL
#define PWM_V_ENABLED 1U
#define PWM_V_HW TCPWM0
#define PWM_V_NUM 257UL
#define PWM_W_ENABLED 1U
#define PWM_W_HW TCPWM0
#define PWM_W_NUM 258UL
#define PWM_SYNC_ENABLED 1U
#define PWM_SYNC_HW TCPWM0
#define PWM_SYNC_NUM 259UL
#define ADC0_ISR0_ENABLED 1U
#define ADC0_ISR0_HW TCPWM0
#define ADC0_ISR0_NUM 260UL
#define FC_PWM_COUNTER_ENABLED 1U
#define FC_PWM_COUNTER_HW TCPWM0
#define FC_PWM_COUNTER_NUM 261UL
#define FC_PWM_COUNTER_IRQ tcpwm_0_interrupts_261_IRQn
#define START_SIGNAL_COUNTER_ENABLED 1U
#define START_SIGNAL_COUNTER_HW TCPWM0
#define START_SIGNAL_COUNTER_NUM 262UL
#define START_SIGNAL_COUNTER_IRQ tcpwm_0_interrupts_262_IRQn

extern const cy_stc_hppass_cfg_t pass_0_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t pass_0_adc_hal_obj;
extern const cyhal_adc_configurator_t pass_0_adc_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC)
extern const mtb_hal_adc_configurator_t pass_0_adc_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC) */

extern const cy_stc_hppass_ac_stt_t pass_0_ac_0_stt_0_config[];
extern const cy_stc_hppass_sar_t pass_0_sar_0_config;
extern const cy_stc_hppass_sar_chan_t ADC_SAMP_IU_config;
extern const cy_stc_hppass_sar_chan_t ADC_SAMP_IV_config;
extern const cy_stc_hppass_sar_chan_t ADC_SAMP_IW_config;
extern const cy_stc_hppass_sar_chan_t ADC_SAMP_VBUS_config;
extern const cy_stc_hppass_sar_grp_t ADC_SEQ0_config;
extern const cy_stc_tcpwm_pwm_config_t SYNC_ISR1_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SYNC_ISR1_clock_ref;
extern const mtb_hal_clock_t SYNC_ISR1_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t SYNC_ISR1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SYNC_ISR1_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SYNC_ISR1_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t SYNC_ISR1_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_counter_config_t EXE_TIMER_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t EXE_TIMER_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t EXE_TIMER_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_timer_configurator_t EXE_TIMER_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t EXE_TIMER_clock_ref;
extern const mtb_hal_clock_t EXE_TIMER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t EXE_TIMER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_counter_config_t HALL_TIMER_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t HALL_TIMER_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t HALL_TIMER_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_timer_configurator_t HALL_TIMER_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t HALL_TIMER_clock_ref;
extern const mtb_hal_clock_t HALL_TIMER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t HALL_TIMER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_pwm_config_t PWM_U_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_U_clock_ref;
extern const mtb_hal_clock_t PWM_U_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_U_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_U_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_U_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_U_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_V_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_V_clock_ref;
extern const mtb_hal_clock_t PWM_V_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_V_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_V_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_V_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_V_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_W_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_W_clock_ref;
extern const mtb_hal_clock_t PWM_W_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_W_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_W_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_W_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_W_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_SYNC_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_SYNC_clock_ref;
extern const mtb_hal_clock_t PWM_SYNC_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_SYNC_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_SYNC_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_SYNC_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_SYNC_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t ADC0_ISR0_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t ADC0_ISR0_clock_ref;
extern const mtb_hal_clock_t ADC0_ISR0_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t ADC0_ISR0_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ADC0_ISR0_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t ADC0_ISR0_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t ADC0_ISR0_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_counter_config_t FC_PWM_COUNTER_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t FC_PWM_COUNTER_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t FC_PWM_COUNTER_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_timer_configurator_t FC_PWM_COUNTER_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t FC_PWM_COUNTER_clock_ref;
extern const mtb_hal_clock_t FC_PWM_COUNTER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t FC_PWM_COUNTER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_counter_config_t START_SIGNAL_COUNTER_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t START_SIGNAL_COUNTER_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t START_SIGNAL_COUNTER_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_timer_configurator_t START_SIGNAL_COUNTER_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t START_SIGNAL_COUNTER_clock_ref;
extern const mtb_hal_clock_t START_SIGNAL_COUNTER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t START_SIGNAL_COUNTER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

void pass_0_start(void);
void init_cycfg_peripherals(void);
void reserve_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERALS_H */
