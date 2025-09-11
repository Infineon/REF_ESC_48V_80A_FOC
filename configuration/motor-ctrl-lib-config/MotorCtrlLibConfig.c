/*******************************************************************************
 * Copyright 2021-2024, Cypress Semiconductor Corporation (an Infineon company)
 *or an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
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
#include "MotorCtrlLibConfig.h"

MOTOR_t motor[MOTOR_CTRL_NO_OF_MOTOR] = {
    {
        .motor_instance = 0,
        .sm_ptr = &sm[0],
        .vars_ptr = &vars[0],
        .ctrl_ptr = &ctrl[0],
        .params_ptr = &params[0],
        .obs_ptr = &obs[0],
        .faults_ptr = &faults[0],
        .protect_ptr = &protect[0],
        .hall_ptr = &hall[0],
        .sensor_iface_ptr = &sensor_iface[0],
        .inc_encoder_ptr = &inc_encoder[0],
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
        .profiler_ptr = &profiler[0],
#endif
    }
#if (MOTOR_CTRL_MOTOR1_ENABLED)
    ,
    {
        .motor_instance = 1,
        .sm_ptr = &sm[1],
        .vars_ptr = &vars[1],
        .ctrl_ptr = &ctrl[1],
        .params_ptr = &params[1],
        .obs_ptr = &obs[1],
        .faults_ptr = &faults[1],
        .protect_ptr = &protect[1],
        .hall_ptr = &hall[1],
        .sensor_iface_ptr = &sensor_iface[1],
        .inc_encoder_ptr = &inc_encoder[1],
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
        .profiler_ptr = &profiler[1],
#endif
    }
#endif
};
