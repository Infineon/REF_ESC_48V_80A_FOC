/*******************************************************************************
 * File Name: cycfg_routing.h
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#include "cycfg_notices.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define ioss_0_port_1_pin_2_HSIOM P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK
#define ioss_0_port_1_pin_3_HSIOM P1_3_DEBUG600_SWJ_SWDIO_TMS
#define ioss_0_port_2_pin_1_HSIOM P2_1_PERI_TR_IO_OUTPUT7
#define ioss_0_port_4_pin_0_HSIOM P4_0_PERI_TR_IO_OUTPUT14
#define ioss_0_port_4_pin_1_HSIOM P4_1_PERI_TR_IO_OUTPUT15
#define ioss_0_port_4_pin_2_HSIOM P4_2_PERI_TR_IO_OUTPUT16
#define ioss_0_port_4_pin_3_HSIOM P4_3_PERI_TR_IO_OUTPUT17
#define ioss_0_port_4_pin_4_HSIOM P4_4_PERI_TR_IO_OUTPUT18
#define ioss_0_port_4_pin_5_HSIOM P4_5_PERI_TR_IO_OUTPUT19
#define ioss_0_port_7_pin_2_HSIOM P7_2_PERI_TR_IO_INPUT32
#define ADC0_ISR0_reload_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN12
#define ADC0_ISR0_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_260
#define ADC0_ISR0_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_4
#define DMA_ADC_0_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_0_PDMA0_TR_IN0
#define FC_PWM_COUNTER_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT5_TR3_IN
#define FC_PWM_COUNTER_capture1_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT5_TR3_IN
#define FC_PWM_digital_in_0_TRIGGER_IN TRIG_IN_MUX_11_HSIOM_TR_OUT32
#define pass_0_input_trigger_0_tr_a_in_0_TRIGGER_OUT TRIG_OUT_MUX_14_PASS_TR_A_IN0
#define pass_0_output_pulse_trigger_0_tr_pulse_out_0_TRIGGER_IN TRIG_IN_MUX_0_PASS_PULSE0
#define PWM_SYNC_reload_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN12
#define PWM_SYNC_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_3
#define PWM_U_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN13
#define PWM_U_reload_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN12
#define PWM_U_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_256
#define PWM_U_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_256
#define PWM_V_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN13
#define PWM_V_reload_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN12
#define PWM_V_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_257
#define PWM_V_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_257
#define PWM_W_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN13
#define PWM_W_reload_0_TRIGGER_OUT TRIG_OUT_MUX_10_TCPWM0_TR_IN12
#define PWM_W_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_258
#define PWM_W_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_258
#define PWMUH_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT14
#define PWMUL_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT15
#define PWMVH_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT16
#define PWMVL_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT17
#define PWMWH_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT18
#define PWMWL_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT19
#define SYNC_ISR1_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_0
#define TEST_PIN_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT7
#define TCPWM0_GRP1_CNT0_CAPTURE0_VALUE 0x12
#define TCPWM0_GRP1_CNT0_RELOAD_VALUE 0x11
#define TCPWM0_GRP1_CNT1_CAPTURE0_VALUE 0x12
#define TCPWM0_GRP1_CNT1_RELOAD_VALUE 0x11
#define TCPWM0_GRP1_CNT2_CAPTURE0_VALUE 0x12
#define TCPWM0_GRP1_CNT2_RELOAD_VALUE 0x11
#define TCPWM0_GRP1_CNT3_RELOAD_VALUE 0x11
#define TCPWM0_GRP1_CNT4_RELOAD_VALUE 0x11
#define TCPWM0_GRP1_CNT5_CAPTURE0_VALUE 0x3
#define TCPWM0_GRP1_CNT5_CAPTURE1_VALUE 0x3

void init_cycfg_routing(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_ROUTING_H */
