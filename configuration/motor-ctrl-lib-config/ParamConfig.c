/*******************************************************************************
* Copyright 2021-2024, Cypress Semiconductor Corporation (an Infineon company) or
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

#include "ParamConfig.h"
#if defined(MOTOR_CTRL_USE_GUI_GENERATED_PARAM)
#include "ParamConfig_Generated.h"
#endif


void PARAMS_Init(MOTOR_t *motor_ptr)
{
    PARAMS_t* params_ptr = motor_ptr->params_ptr;

    // Parameters are initialized and saved in flash if
    // - Flash read is not successful
    // - First time running the FW
    // - FW update causes parameter incompatibility

    bool params_id_check = hw_fcn.FlashRead(motor_ptr->motor_instance, (PARAMS_ID_t) { PARAMS_CODE, BUILD_CONFIG_ID, PARAMS_VER }, params_ptr);

    if (!params_id_check || PARAMS_ALWAYS_OVERWRITE)
    {
        if(motor_ptr->motor_instance  ==0)
        {
            PARAMS_InitManual(params_ptr);
#if defined(MOTOR_CTRL_USE_GUI_GENERATED_ADV_PARAM)
            Motor_Ctrl_AdvanceParameter(params_ptr); /* Update some of auto calculation parameter such as Kp, ki  and  auto calculation for those parameters are skipped*/
#endif
        }
#if (MOTOR_CTRL_MOTOR1_ENABLED)
        if(motor_ptr->motor_instance  ==1)
        {
            PARAMS_InitManual_M1(params_ptr);
#if defined(MOTOR_CTRL_USE_GUI_GENERATED_ADV_PARAM)
            Motor_Ctrl_AdvanceParameter_M1(params_ptr); /* Update some of auto calculation parameter such as Kp, ki  and skip auto calculation for those parameters */
#endif
        }
#endif
        PARAMS_InitAutoCalc(params_ptr);
        hw_fcn.FlashWrite(motor_ptr->motor_instance,params_ptr);
    }

    // mc_info.chip_id is read by hardware interface from the chip
    mc_info.kit_id = KIT_ID;
}

void PARAMS_InitManual(PARAMS_t* params_ptr)
{
    params_ptr->id.code = PARAMS_CODE;
    params_ptr->id.build_config = BUILD_CONFIG_ID;
    params_ptr->id.ver = PARAMS_VER;

    params_ptr->motor.P = MOTOR_POLE; // [#]
    params_ptr->motor.lq = MOTOR_LQ; // [H]
    params_ptr->motor.ld = MOTOR_LD; // [H]
    params_ptr->motor.lam = MOTOR_I_AM; // [Wb]
    params_ptr->motor.r = MOTOR_R; // [Ohm]
    params_ptr->motor.T_max = MOTOR_TORQUE_MAX; // [Nm]
    params_ptr->motor.i_peak = MOTOR_CURRENT_PEAK; // [A]
    params_ptr->motor.i_cont = MOTOR_CURRENT_CONT; // [A]
    params_ptr->motor.id_max = MOTOR_ID_MAX; // [A]
    params_ptr->motor.v_nom = LINE_TO_PHASE(MOTOR_VOLTAGE); // [Vpk-ln]
    params_ptr->motor.w_nom.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_NORM_SPEED)), MOTOR_POLE); // [Ra/sec-elec]
    params_ptr->motor.w_max.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_MAX_SPEED)), MOTOR_POLE); // [Ra/sec-elec]
#if defined(CTRL_METHOD_SFO)
    params_ptr->motor.mtpv_margin = PERC_TO_NORM(MOTOR_MTPV_TORQUE_MARGIN); // [%]
#endif
    params_ptr->motor.i2t.therm_tau = MOTOR_CTRL_I2T_THERM_TAU; // [sec]
    params_ptr->motor.i2t.on_level = PERC_TO_NORM(100.0f); // [%]
    params_ptr->motor.i2t.off_level = PERC_TO_NORM(95.0f); // [%]
    // System Parameters:
    // Sampling Parameters:
    params_ptr->sys.samp.fpwm_fs0_ratio = MOTOR_CTRL_FPWM_FS0_RATIO; // []
    params_ptr->sys.samp.fs0 = MOTOR_CTRL_FASTLOOP_FREQ; // [Hz], at least 1.2 decade above maximum electrical frequency, 1.5kHz~>25kHz
    params_ptr->sys.samp.fs0_fs1_ratio = MOTOR_CTRL_FS0_FS1_RATIO; // []

    // Calibration Parameters:
    params_ptr->sys.analog.calib.i_u = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.i_v = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.i_w = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.v_uz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_vz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_wz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_dc = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.temp_ps = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, C}
    params_ptr->sys.analog.calib.pot = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, %}
    // Analog Sensor Filter Parameters:
    params_ptr->sys.analog.filt.w0_i_ph = DISABLE_LPF_FS(MOTOR_CTRL_FASTLOOP_FREQ ); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_v_ph = DISABLE_LPF_FS(MOTOR_CTRL_FASTLOOP_FREQ ); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_v_dc = TAU_TO_RADSEC(0.100f); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_temp_ps = TAU_TO_RADSEC(1.000f); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_pot = TAU_TO_RADSEC(0.200f); // [Ra/sec]
    // Shunt Parameters:
    params_ptr->sys.analog.shunt.type = ADC_CS_SHUNT_TYPE;
    params_ptr->sys.analog.shunt.opamp_gain = ADC_CS_OPAMP_GAIN;
    params_ptr->sys.analog.shunt.hyb_mod.adc_t_min = ADC_CS_SS_MIN_SEGMENT_TIME; // [sec]
    params_ptr->sys.analog.shunt.hyb_mod.ki = MOTOR_CTRL_SS_HMOD_KI; // [#]
    params_ptr->sys.analog.shunt.res = ADC_CS_SHUNT_RES; // [Ohm]
    params_ptr->sys.analog.shunt.cs_settle_raio = ADC_CS_SETTLE_RATIO;
    
    params_ptr->sys.analog.shunt.current_sense_polarity = ADC_CS_CURRENT_SENSE_POLARITY;
    params_ptr->sys.analog.cs_meas_type = ADC_CS_CURRENT_MEASUREMENT_TYPE;
    params_ptr->sys.analog.shunt.current_sensitivity = ADC_CS_CURRENT_SENSITIVITY; // [V/A]

    params_ptr->sys.analog.offset_null_time = 0.250f; // [sec], this will determine the loop-gain of auto-offset-nulling loop
    // Rate Limiter Parameters:
    params_ptr->sys.rate_lim.w_cmd.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_SPEED_CMD_RATE)), MOTOR_POLE); // [(Ra/sec-elec)/sec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->sys.rate_lim.i_cmd = MOTOR_CTRL_CURRENT_CMD_RATE; // [A/sec]
#elif defined(CTRL_METHOD_SFO)
    params_ptr->sys.rate_lim.T_cmd =MOTOR_CTRL_TORQUE_CMD_RATE; // [Nm/sec]
#endif
    // Fault Parameters:
    params_ptr->sys.faults.oc_thresh = PERC_TO_NORM(MOTOR_CTRL_OVER_CURRENT_THRESH); // [%]
    params_ptr->sys.faults.vdc_time = MOTOR_CTRL_VDC_DEBOUNCE_TIME; // [sec]
    params_ptr->sys.faults.temp_ps_thresh = MOTOR_CTRL_OVER_TEMP_THRESH; // [Celsius]
    params_ptr->sys.faults.short_method = MOTOR_CTRL_FAULT_SHORT_METHOD; // []
    params_ptr->sys.faults.max_clr_tries = MOTOR_CTRL_MAX_FAULT_CLR_TRIES; // []
    params_ptr->sys.faults.watchdog_time = 1000; // [ms]
    // Command Parameters:
    params_ptr->sys.cmd.source = MOTOR_CTRL_COMMAND_SOURCE;
    params_ptr->sys.cmd.w_max.mech = HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_COMMAND_MAX_SPEED)); //[Ra/sec-elec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->sys.cmd.i_max = MOTOR_CTRL_COMMAND_MAX_CURRENT; // [A]
#elif defined(CTRL_METHOD_SFO)
    params_ptr->sys.cmd.T_max = MOTOR_CTRL_COMMAND_MAX_TORQUE; // [Nm]
#endif
    // Rest of System Parameters:
    params_ptr->sys.fb.hall.track_loop.w0_w = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.w0_th.min = HZ_TO_RADSEC(1.5f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.w0_th.max = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.tau_ratio = 1.5f; // [sec/sec]=[]
    params_ptr->sys.fb.hall.w_zsd_thresh.elec = params_ptr->motor.w_nom.elec * 0.008f; // [Ra/sec-elec]
    params_ptr->sys.fb.hall.th_r_offset.elec = DEG_TO_RAD(MOTOR_CTRL_HALL_ANGLE_OFFSET);
    params_ptr->sys.fb.hall.block_comm_offset_comp = MOTOR_CTRL_HALL_ANGLE_OFFSET_COMP; // []

    params_ptr->sys.fb.encoder.track_loop.cpr = MOTOR_CTRL_ENCODER_CPR; // [#], Nanotech NME2-UVW-W14-05-C
    params_ptr->sys.fb.encoder.track_loop.w0_w = HZ_TO_RADSEC(75.0f);   // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.w0_th.min = HZ_TO_RADSEC(1.5f); // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.w0_th.max = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.tau_ratio = MOTOR_CTRL_ENCODER_TIME_CONST;  // [sec/sec]=[]
    params_ptr->sys.fb.encoder.w_zsd_thresh.elec =  MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_ENCODER_ZERO_SPEED_THRESH)), MOTOR_POLE); // [Ra/sec-elec]

    params_ptr->sys.boot_time = MOTOR_CTRL_BOOTSTRAP_TIME; // [sec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
    params_ptr->sys.dyno_lock_time = 0.500f; // [sec]
#endif
    params_ptr->sys.vdc_nom = MOTOR_CTRL_VDC_NOM_VOLT; // [V]

    // Observer Parameters:
    params_ptr->obs.flux_filt.k1 = 0.2f; // [#]
    params_ptr->obs.flux_filt.k2 = 0.02f; // [#]
    params_ptr->obs.flux_filt.k3 = 0.002f; // [#]
    params_ptr->obs.biquad_a[0] = 1.0f; // [#]
    params_ptr->obs.biquad_a[1] = 0.0f; // [1/(Ra/sec)]
    params_ptr->obs.biquad_a[2] = 0.0f; // [1/(Ra/sec)^2]
    params_ptr->obs.biquad_b[0] = 1.0f; // [#]
    params_ptr->obs.biquad_b[1] = 1.0f / HZ_TO_RADSEC(25.0f) + 1.0f / HZ_TO_RADSEC(75.0f); // [1/(Ra/sec)]
    params_ptr->obs.biquad_b[2] = 1.0f / HZ_TO_RADSEC(25.0f) / HZ_TO_RADSEC(75.0f); // [1/(Ra/sec)^2]
    params_ptr->obs.pll.w0 = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->obs.pll.w_max.elec = params_ptr->motor.w_max.elec * 1.5f; // [Ra/sec-elec]
    params_ptr->obs.w_thresh.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_OBS_SPEED_THRESH)), MOTOR_POLE) ; // [Ra/sec-elec]
    params_ptr->obs.w_hyst.elec = params_ptr->obs.w_thresh.elec * 0.25f; // [Ra/sec-elec]
    params_ptr->obs.lock_time = MOTOR_CTRL_OBS_MIN_LOCK_TIME; // [sec]

    // Mechanical System Parameters:
    params_ptr->mech.inertia = MECH_INERTIA; // [kg.m^2]=[(N.m)/(Ra/sec-mech).sec], =1/2*m*r^2
    params_ptr->mech.viscous = MECH_VISCOUS; // [kg.m^2/sec]=[(N.m)/(Ra/sec-mech)]
    params_ptr->mech.friction = MECH_FRICTION; // [kg.m^2/sec^2]=[N.m]

    // Filter Parameters:
    params_ptr->filt.spd_ar_en = MOTOR_CTRL_SPEED_AR_FILTER; // [#]
    params_ptr->filt.spd_ar_wp[0] = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->filt.spd_ar_wp[1] = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->filt.spd_ar_wz[0] = INFINITY; // [Ra/sec]
    params_ptr->filt.spd_ar_wz[1] = INFINITY; // [Ra/sec]
    params_ptr->filt.acc_w0 = HZ_TO_RADSEC(1.0f); // [Ra/sec]
    params_ptr->filt.trq_w0 = HZ_TO_RADSEC(MOTOR_CTRL_TORQUE_FILT_BW); // [Ra/sec]

    // Control Mode:
    params_ptr->ctrl.mode = MOTOR_CTRL_CTRL_MODE; // [#]

    // Speed Control Parameters:
    params_ptr->ctrl.speed.bw = HZ_TO_RADSEC(MOTOR_CTRL_SPEED_BW); // [Ra/sec], at least 0.5 dec below field weakening loop's bandwidth
    params_ptr->ctrl.speed.ki_multiple = MOTOR_CTRL_SPEED_KI_MULTIPLE; // [#]
    params_ptr->ctrl.speed.ol_cl_tr_coeff = PERC_TO_NORM(MOTOR_CTRL_SPEED_OL_CL_TR_COEFF); // [%]

    // Current Control Parameters:
#if defined(CTRL_METHOD_TBC)    
    params_ptr->ctrl.curr.bypass = MOTOR_CTRL_CURRENT_BYPASS;
#endif
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.curr.bw = HZ_TO_RADSEC(MOTOR_CTRL_CURRENT_BW); // [Ra/sec], at least one dec below switching frequency
    params_ptr->ctrl.curr.ff_coef = PERC_TO_NORM(MOTOR_CTRL_CURRENT_FF_COEFF); // [#]
    params_ptr->ctrl.curr.i_cmd_thresh = MOTOR_CTRL_CURRENT_STARTUP_THRESH; // [A]
    params_ptr->ctrl.curr.i_cmd_hyst = params_ptr->ctrl.curr.i_cmd_thresh * 0.80f; // [A]
    params_ptr->ctrl.curr.i_cmd_ol = 0.40f * params_ptr->motor.i_cont; // [A]

#elif defined(CTRL_METHOD_SFO)
    // Torque Controller Parameters:
    params_ptr->ctrl.trq.w_p = HZ_TO_RADSEC(MOTOR_CTRL_TORQUE_BW); // [Ra/sec]
    params_ptr->ctrl.trq.w_ratio = PERC_TO_NORM(MOTOR_CTRL_POLE_ZERO_RATIO); // [%], = w_p/w_z, w_p<w_z
    params_ptr->ctrl.trq.delta_max.elec = DEG_TO_RAD(MOTOR_CTRL_MAX_LOAD_ANGLE); // [Ra-elec]
    params_ptr->ctrl.trq.T_cmd_thresh = MOTOR_CTRL_STARTUP_THRESH; // [Nm]
    params_ptr->ctrl.trq.T_cmd_hyst = MOTOR_CTRL_STARTUP_THRESH_HYS; // [Nm]
    params_ptr->ctrl.trq.curr_lmt_t_reach = MOTOR_CTRL_TIME_SM_CURRENT; // [sec]

    // Flux Controller Parameters:
    params_ptr->ctrl.flux.bw = HZ_TO_RADSEC(MOTOR_CTRL_FLUX_BW); // [Ra/sec]
    params_ptr->ctrl.flux.pole_sep = MOTOR_CTRL_FLUX_POLE_SEP_RATIO; // [#]

    // Load Angle Controller Parameters:
    params_ptr->ctrl.delta.bw = HZ_TO_RADSEC(MOTOR_CTRL_LOAD_ANGLE_BW); // [Ra/sec]
    params_ptr->ctrl.delta.bw_mult = MOTOR_CTRL_BW_MUL; // [#]
    params_ptr->ctrl.delta.bw_mult_wl.elec = HZ_TO_RADSEC(MOTOR_CTRL_BW_MUL_LS_THRESH); // [Ra/sec-elec]
    params_ptr->ctrl.delta.bw_mult_wh.elec = HZ_TO_RADSEC(MOTOR_CTRL_BW_MUL_HS_THRESH); // [Ra/sec-elec]
    params_ptr->ctrl.delta.pole_sep = MOTOR_CTRL_LOAD_POLE_SEP_RATIO; // [#]
#endif

    // Voltage Control Parameters:
    params_ptr->ctrl.volt.w_thresh.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_VOLT_STARTUP_THRESH)), MOTOR_POLE); // [Ra/sec-elec], min speed for voltage control
    params_ptr->ctrl.volt.w_hyst.elec = params_ptr->ctrl.volt.w_thresh.elec * 0.5f; // [Ra/sec-elec]
    params_ptr->ctrl.volt.v_min = MOTOR_CTRL_VOLT_VF_OFFSET; // [Vpk]
    params_ptr->ctrl.volt.v_to_f_ratio = MOTOR_CTRL_VOLT_VF_RATIO; // [Vpk/(Ra/sec-elec)]
    params_ptr->ctrl.volt.mod_method = MOTOR_CTRL_VOLT_MOD_SCHEME;
    params_ptr->ctrl.volt.five_seg.en = MOTOR_CTRL_FIVE_SEG_MOD; //5-segment enable
    params_ptr->ctrl.volt.five_seg.active_mi = PERC_TO_NORM(MOTOR_CTRL_FIVE_SEG_MOD_ACT_THRESH); //mi = Vpeak/(2*vdc/3)
    params_ptr->ctrl.volt.five_seg.inactive_mi = PERC_TO_NORM(MOTOR_CTRL_FIVE_SEG_MOD_INACT_THRESH);
    params_ptr->ctrl.volt.five_seg.w0_filt = HZ_TO_RADSEC(1.0f);

#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)

    // Flux Weakenning Parameters:
    params_ptr->ctrl.flux_weaken.en = MOTOR_CTRL_FLUX_WEAKEN; // [#]
    params_ptr->ctrl.flux_weaken.vdc_coeff = LINE_TO_PHASE(MOTOR_CTRL_FLUX_WEAKEN_VOLT_MARGIN); // [#]
#if defined(CTRL_METHOD_RFO)
    params_ptr->ctrl.flux_weaken.bw = HZ_TO_RADSEC(MOTOR_CTRL_FLUX_WEAKEN_BW); // [Ra/sec], at least 0.5 dec below current loop's bandwidth
#endif

    // Align (Pre-Positioning) Parameters:
    params_ptr->ctrl.align.time = MOTOR_CTRL_ALIGN_TIME; // [sec]
    params_ptr->ctrl.align.voltage = MOTOR_CTRL_ALIGN_VOLTAGE; // [Vpk]

    // Six Pulse Injection Parameters:
    params_ptr->ctrl.six_pulse_inj.i_peak = MOTOR_CTRL_SIX_PULSE_INJ_MAX_CURRENT; // [A], this is the target value, not the actual value

    // High Frequency Injection Parameters:
    params_ptr->ctrl.high_freq_inj.w_h = HZ_TO_RADSEC(MOTOR_CTRL_HFI_INJECT_FREQ); // [Ra/sec], at least 1 decade below switching frequency
    params_ptr->ctrl.high_freq_inj.w_sep = HZ_TO_RADSEC(MOTOR_CTRL_HFI_SEPARATION_FREQ); // [Ra/sec], at least 1 decade below switching frequency
    params_ptr->ctrl.high_freq_inj.pll.w0 = HZ_TO_RADSEC(60.0f); // [Ra/sec]
    params_ptr->ctrl.high_freq_inj.pll.w_max.elec = 0.5f * (params_ptr->ctrl.high_freq_inj.w_h - params_ptr->ctrl.high_freq_inj.w_sep); // [Ra/sec-elec]
    params_ptr->ctrl.high_freq_inj.i_qd_r_peak.d = MOTOR_CTRL_HFI_MAX_CURRENT; // [A], excitation current peak (d-axis), limiting factor (larger than q-axis)

    // Profiler Parameters (needs high fs0 & fpwm e.g. fs0=30kHz, fpwm=60kHz):
    params_ptr->profiler.overwrite = MOTOR_CTRL_PROFILER_PARAM_OVERWRITE; // []
    params_ptr->profiler.cmd_thresh = PERC_TO_NORM(MOTOR_CTRL_PROFILER_CMD_THRESH); // [%]
    params_ptr->profiler.cmd_hyst = PERC_TO_NORM(MOTOR_CTRL_PROFILER_CMD_HYST); // [%]
    params_ptr->profiler.i_cmd_dc = MOTOR_CTRL_PROFILER_I_CMD_DC; // [A]
    params_ptr->profiler.i_cmd_ac = MOTOR_CTRL_PROFILER_I_CMD_AC; // [A]
    params_ptr->profiler.w_cmd_elec.min = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_PROFILER_SPEED_CMD_MIN)), MOTOR_POLE); // [Ra/sec-elec], must be well above params_ptr->obs.w_thresh.elec
    params_ptr->profiler.w_cmd_elec.max = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_PROFILER_SPEED_CMD_MAX)), MOTOR_POLE); // [Ra/sec-elec]
    params_ptr->profiler.time_rot_lock = MOTOR_CTRL_PROFILER_ROTOR_LOCK_TIME; // [sec]
    params_ptr->profiler.time_spd = MOTOR_CTRL_PROFILER_FLUX_EST_TIME; // [sec]

#elif defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.tbc.mode = MOTOR_CTRL_TBC_MODE;
    params_ptr->ctrl.tbc.trap.ramp_cnt = MOTOR_CTRL_TBC_TRAP_RAMP_COUNT; // [#]
    params_ptr->ctrl.tbc.trap.ramp_main_bw_ratio = MOTOR_CTRL_TBC_TRAP_RAMP_BW_RATIO; // [#]
    params_ptr->ctrl.tbc.trap.ramp_ff_coef = MOTOR_CTRL_TBC_TRAP_RAMP_FF_COEF; // [V/A]
    params_ptr->ctrl.tbc.trap.main_ff_coef = MOTOR_CTRL_TBC_TRAP_MAIN_FF_COEF; // [#]

#endif

}
#if (MOTOR_CTRL_MOTOR1_ENABLED)
void PARAMS_InitManual_M1(PARAMS_t* params_ptr)
{
    params_ptr->id.code = PARAMS_CODE;
    params_ptr->id.build_config = BUILD_CONFIG_ID;
    params_ptr->id.ver = PARAMS_VER;

    params_ptr->motor.P = MOTOR_POLE_M1; // [#]
    params_ptr->motor.lq = MOTOR_LQ_M1; // [H]
    params_ptr->motor.ld = MOTOR_LD_M1; // [H]
    params_ptr->motor.lam = MOTOR_I_AM_M1; // [Wb]
    params_ptr->motor.r = MOTOR_R_M1; // [Ohm]
    params_ptr->motor.T_max = MOTOR_TORQUE_MAX_M1; // [Nm]
    params_ptr->motor.i_peak = MOTOR_CURRENT_PEAK_M1; // [A]
    params_ptr->motor.i_cont = MOTOR_CURRENT_CONT_M1; // [A]
    params_ptr->motor.id_max = MOTOR_ID_MAX_M1; // [A]
    params_ptr->motor.v_nom = LINE_TO_PHASE(MOTOR_VOLTAGE_M1); // [Vpk-ln]
    params_ptr->motor.w_nom.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_NORM_SPEED_M1)), MOTOR_POLE_M1); // [Ra/sec-elec]
    params_ptr->motor.w_max.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_MAX_SPEED_M1)), MOTOR_POLE_M1); // [Ra/sec-elec]
#if defined(CTRL_METHOD_SFO)
    params_ptr->motor.mtpv_margin = PERC_TO_NORM(MOTOR_MTPV_TORQUE_MARGIN_M1); // [%]
#endif
    params_ptr->motor.i2t.therm_tau = MOTOR_CTRL_I2T_THERM_TAU_M1; // [sec]
    params_ptr->motor.i2t.on_level = PERC_TO_NORM(100.0f); // [%]
    params_ptr->motor.i2t.off_level = PERC_TO_NORM(95.0f); // [%]

    // System Parameters:
    // Sampling Parameters:
    params_ptr->sys.samp.fpwm_fs0_ratio = MOTOR_CTRL_FPWM_FS0_RATIO_M1; // []
    params_ptr->sys.samp.fs0 = MOTOR_CTRL_FASTLOOP_FREQ_M1; // [Hz], at least 1.2 decade above maximum electrical frequency, 1.5kHz~>25kHz
    params_ptr->sys.samp.fs0_fs1_ratio = MOTOR_CTRL_FS0_FS1_RATIO_M1; // []

    // Calibration Parameters:
    params_ptr->sys.analog.calib.i_u = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.i_v = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.i_w = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, A}
    params_ptr->sys.analog.calib.v_uz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_vz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_wz = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.v_dc = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, V}
    params_ptr->sys.analog.calib.temp_ps = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, C}
    params_ptr->sys.analog.calib.pot = (CALIB_PARAMS_t){ 1.0f, 0.0f }; // {%, %}
    // Analog Sensor Filter Parameters:
    params_ptr->sys.analog.filt.w0_i_ph = DISABLE_LPF_FS(MOTOR_CTRL_FASTLOOP_FREQ_M1 ); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_v_ph = DISABLE_LPF_FS(MOTOR_CTRL_FASTLOOP_FREQ_M1 ); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_v_dc = TAU_TO_RADSEC(0.100f); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_temp_ps = TAU_TO_RADSEC(1.000f); // [Ra/sec]
    params_ptr->sys.analog.filt.w0_pot = TAU_TO_RADSEC(0.200f); // [Ra/sec]
    // Shunt Parameters:
    params_ptr->sys.analog.shunt.type = ADC_CS_SHUNT_TYPE_M1;//Single_Shunt,//
    params_ptr->sys.analog.shunt.opamp_gain = ADC_CS_OPAMP_GAIN_M1;
    params_ptr->sys.analog.shunt.hyb_mod.adc_t_min = ADC_CS_SS_MIN_SEGMENT_TIME_M1; // [sec]
    params_ptr->sys.analog.shunt.hyb_mod.ki = MOTOR_CTRL_SS_HMOD_KI_M1; // [#]
    params_ptr->sys.analog.shunt.res = ADC_CS_SHUNT_RES_M1; // [Ohm]
    params_ptr->sys.analog.shunt.cs_settle_raio = ADC_CS_SETTLE_RATIO_M1;

    params_ptr->sys.analog.shunt.current_sense_polarity = ADC_CS_CURRENT_SENSE_POLARITY_M1;
    params_ptr->sys.analog.cs_meas_type = ADC_CS_CURRENT_MEASUREMENT_TYPE_M1;
    params_ptr->sys.analog.shunt.current_sensitivity = ADC_CS_CURRENT_SENSITIVITY_M1; // [V/A]

    params_ptr->sys.analog.offset_null_time = 0.250f; // [sec], this will determine the loop-gain of auto-offset-nulling loop
    // Rate Limiter Parameters:
    params_ptr->sys.rate_lim.w_cmd.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_SPEED_CMD_RATE_M1)), MOTOR_POLE_M1); // [(Ra/sec-elec)/sec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->sys.rate_lim.i_cmd = MOTOR_CTRL_CURRENT_CMD_RATE_M1; // [A/sec]
#elif defined(CTRL_METHOD_SFO)
    params_ptr->sys.rate_lim.T_cmd =MOTOR_CTRL_TORQUE_CMD_RATE_M1; // [Nm/sec]
#endif
    // Fault Parameters:
    params_ptr->sys.faults.oc_thresh = PERC_TO_NORM(MOTOR_CTRL_OVER_CURRENT_THRESH_M1); // [%]
    params_ptr->sys.faults.vdc_time = MOTOR_CTRL_VDC_DEBOUNCE_TIME_M1; // [sec]
    params_ptr->sys.faults.temp_ps_thresh = MOTOR_CTRL_OVER_TEMP_THRESH_M1; // [Celsius]
    params_ptr->sys.faults.short_method = MOTOR_CTRL_FAULT_SHORT_METHOD_M1; // []
    params_ptr->sys.faults.max_clr_tries = MOTOR_CTRL_MAX_FAULT_CLR_TRIES_M1; // []
    params_ptr->sys.faults.watchdog_time = 1000; // [ms]
    // Command Parameters:
    params_ptr->sys.cmd.source = MOTOR_CTRL_COMMAND_SOURCE_M1;
    params_ptr->sys.cmd.w_max.mech = HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_COMMAND_MAX_SPEED_M1)); //[Ra/sec-elec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->sys.cmd.i_max = MOTOR_CTRL_COMMAND_MAX_CURRENT_M1; // [A]
#elif defined(CTRL_METHOD_SFO)
    params_ptr->sys.cmd.T_max = MOTOR_CTRL_COMMAND_MAX_TORQUE_M1; // [Nm]
#endif
    // Rest of System Parameters:
    params_ptr->sys.fb.hall.track_loop.w0_w = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.w0_th.min = HZ_TO_RADSEC(1.5f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.w0_th.max = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.hall.track_loop.tau_ratio = 1.5f; // [sec/sec]=[]
    params_ptr->sys.fb.hall.w_zsd_thresh.elec = params_ptr->motor.w_nom.elec * 0.008f; // [Ra/sec-elec]
    params_ptr->sys.fb.hall.th_r_offset.elec = DEG_TO_RAD(MOTOR_CTRL_HALL_ANGLE_OFFSET_M1);
    params_ptr->sys.fb.hall.block_comm_offset_comp = MOTOR_CTRL_HALL_ANGLE_OFFSET_COMP_M1; // []

    params_ptr->sys.fb.encoder.track_loop.cpr = MOTOR_CTRL_ENCODER_CPR_M1; // [#], Nanotech NME2-UVW-W14-05-C
    params_ptr->sys.fb.encoder.track_loop.w0_w = HZ_TO_RADSEC(75.0f);   // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.w0_th.min = HZ_TO_RADSEC(1.5f); // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.w0_th.max = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->sys.fb.encoder.track_loop.tau_ratio = MOTOR_CTRL_ENCODER_TIME_CONST_M1;  // [sec/sec]=[]
    params_ptr->sys.fb.encoder.w_zsd_thresh.elec =  MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_ENCODER_ZERO_SPEED_THRESH_M1)), MOTOR_POLE_M1); // [Ra/sec-elec]

    params_ptr->sys.boot_time = MOTOR_CTRL_BOOTSTRAP_TIME_M1; // [sec]
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
    params_ptr->sys.dyno_lock_time = 0.500f; // [sec]
#endif
    params_ptr->sys.vdc_nom = MOTOR_CTRL_VDC_NOM_VOLT_M1; // [V]

    // Observer Parameters:
    params_ptr->obs.flux_filt.k1 = 0.2f; // [#]
    params_ptr->obs.flux_filt.k2 = 0.02f; // [#]
    params_ptr->obs.flux_filt.k3 = 0.002f; // [#]
    params_ptr->obs.biquad_a[0] = 1.0f; // [#]
    params_ptr->obs.biquad_a[1] = 0.0f; // [1/(Ra/sec)]
    params_ptr->obs.biquad_a[2] = 0.0f; // [1/(Ra/sec)^2]
    params_ptr->obs.biquad_b[0] = 1.0f; // [#]
    params_ptr->obs.biquad_b[1] = 1.0f / HZ_TO_RADSEC(25.0f) + 1.0f / HZ_TO_RADSEC(75.0f); // [1/(Ra/sec)]
    params_ptr->obs.biquad_b[2] = 1.0f / HZ_TO_RADSEC(25.0f) / HZ_TO_RADSEC(75.0f); // [1/(Ra/sec)^2]
    params_ptr->obs.pll.w0 = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->obs.pll.w_max.elec = params_ptr->motor.w_max.elec * 1.5f; // [Ra/sec-elec]
    params_ptr->obs.w_thresh.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_OBS_SPEED_THRESH_M1)), MOTOR_POLE_M1) ; // [Ra/sec-elec]
    params_ptr->obs.w_hyst.elec = params_ptr->obs.w_thresh.elec * 0.25f; // [Ra/sec-elec]
    params_ptr->obs.lock_time = MOTOR_CTRL_OBS_MIN_LOCK_TIME_M1; // [sec]

    // Mechanical System Parameters:
    params_ptr->mech.inertia = MECH_INERTIA_M1; // [kg.m^2]=[(N.m)/(Ra/sec-mech).sec], =1/2*m*r^2
    params_ptr->mech.viscous = MECH_VISCOUS_M1; // [kg.m^2/sec]=[(N.m)/(Ra/sec-mech)]
    params_ptr->mech.friction = MECH_FRICTION_M1; // [kg.m^2/sec^2]=[N.m]

    // Filter Parameters:
    params_ptr->filt.spd_ar_en = MOTOR_CTRL_SPEED_AR_FILTER_M1; // [#]
    params_ptr->filt.spd_ar_wp[0] = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->filt.spd_ar_wp[1] = HZ_TO_RADSEC(75.0f); // [Ra/sec]
    params_ptr->filt.spd_ar_wz[0] = INFINITY; // [Ra/sec]
    params_ptr->filt.spd_ar_wz[1] = INFINITY; // [Ra/sec]
    params_ptr->filt.acc_w0 = HZ_TO_RADSEC(1.0f); // [Ra/sec]
    params_ptr->filt.trq_w0 = HZ_TO_RADSEC(MOTOR_CTRL_TORQUE_FILT_BW_M1); // [Ra/sec]

    // Control Mode:
    params_ptr->ctrl.mode = MOTOR_CTRL_CTRL_MODE_M1; // [#]

    // Speed Control Parameters:
    params_ptr->ctrl.speed.bw = HZ_TO_RADSEC(MOTOR_CTRL_SPEED_BW_M1); // [Ra/sec], at least 0.5 dec below field weakening loop's bandwidth
    params_ptr->ctrl.speed.ki_multiple = MOTOR_CTRL_SPEED_KI_MULTIPLE_M1; // [#]
    params_ptr->ctrl.speed.ol_cl_tr_coeff = PERC_TO_NORM(MOTOR_CTRL_SPEED_OL_CL_TR_COEFF_M1); // [%]

    // Current Control Parameters:
#if defined(CTRL_METHOD_TBC)    
    params_ptr->ctrl.curr.bypass = MOTOR_CTRL_CURRENT_BYPASS_M1;
#endif
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.curr.bw = HZ_TO_RADSEC(MOTOR_CTRL_CURRENT_BW_M1); // [Ra/sec], at least one dec below switching frequency
    params_ptr->ctrl.curr.ff_coef = PERC_TO_NORM(MOTOR_CTRL_CURRENT_FF_COEFF_M1); // [#]
    params_ptr->ctrl.curr.i_cmd_thresh = MOTOR_CTRL_CURRENT_STARTUP_THRESH_M1; // [A]
    params_ptr->ctrl.curr.i_cmd_hyst = params_ptr->ctrl.curr.i_cmd_thresh * 0.80f; // [A]
    params_ptr->ctrl.curr.i_cmd_ol = 0.40f * params_ptr->motor.i_cont; // [A]

#elif defined(CTRL_METHOD_SFO)
    // Torque Controller Parameters:
    params_ptr->ctrl.trq.w_p = HZ_TO_RADSEC(MOTOR_CTRL_TORQUE_BW_M1); // [Ra/sec]
    params_ptr->ctrl.trq.w_ratio = PERC_TO_NORM(MOTOR_CTRL_POLE_ZERO_RATIO_M1); // [%], = w_p/w_z, w_p<w_z
    params_ptr->ctrl.trq.delta_max.elec = DEG_TO_RAD(MOTOR_CTRL_MAX_LOAD_ANGLE_M1); // [Ra-elec]
    params_ptr->ctrl.trq.T_cmd_thresh = MOTOR_CTRL_STARTUP_THRESH_M1; // [Nm]
    params_ptr->ctrl.trq.T_cmd_hyst = MOTOR_CTRL_STARTUP_THRESH_HYS_M1; // [Nm]
    params_ptr->ctrl.trq.curr_lmt_t_reach = MOTOR_CTRL_TIME_SM_CURRENT_M1; // [sec]

    // Flux Controller Parameters:
    params_ptr->ctrl.flux.bw = HZ_TO_RADSEC(MOTOR_CTRL_FLUX_BW_M1); // [Ra/sec]
    params_ptr->ctrl.flux.pole_sep = MOTOR_CTRL_FLUX_POLE_SEP_RATIO_M1; // [#]

    // Load Angle Controller Parameters:
    params_ptr->ctrl.delta.bw = HZ_TO_RADSEC(MOTOR_CTRL_LOAD_ANGLE_BW_M1); // [Ra/sec]
    params_ptr->ctrl.delta.bw_mult = MOTOR_CTRL_BW_MUL_M1; // [#]
    params_ptr->ctrl.delta.bw_mult_wl.elec = HZ_TO_RADSEC(MOTOR_CTRL_BW_MUL_LS_THRESH_M1); // [Ra/sec-elec]
    params_ptr->ctrl.delta.bw_mult_wh.elec = HZ_TO_RADSEC(MOTOR_CTRL_BW_MUL_HS_THRESH_M1); // [Ra/sec-elec]
    params_ptr->ctrl.delta.pole_sep = MOTOR_CTRL_LOAD_POLE_SEP_RATIO_M1; // [#]
#endif

    // Voltage Control Parameters:
    params_ptr->ctrl.volt.w_thresh.elec = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_VOLT_STARTUP_THRESH_M1)), MOTOR_POLE_M1); // [Ra/sec-elec], min speed for voltage control
    params_ptr->ctrl.volt.w_hyst.elec = params_ptr->ctrl.volt.w_thresh.elec * 0.5f; // [Ra/sec-elec]
    params_ptr->ctrl.volt.v_min = MOTOR_CTRL_VOLT_VF_OFFSET_M1; // [Vpk]
    params_ptr->ctrl.volt.v_to_f_ratio = MOTOR_CTRL_VOLT_VF_RATIO_M1; // [Vpk/(Ra/sec-elec)]
    params_ptr->ctrl.volt.mod_method = MOTOR_CTRL_VOLT_MOD_SCHEME_M1;
    params_ptr->ctrl.volt.five_seg.en = MOTOR_CTRL_FIVE_SEG_MOD_M1; //5-segment enable
    params_ptr->ctrl.volt.five_seg.active_mi = PERC_TO_NORM(MOTOR_CTRL_FIVE_SEG_MOD_ACT_THRESH_M1); //mi = Vpeak/(2*vdc/3)
    params_ptr->ctrl.volt.five_seg.inactive_mi = PERC_TO_NORM(MOTOR_CTRL_FIVE_SEG_MOD_INACT_THRESH_M1);
    params_ptr->ctrl.volt.five_seg.w0_filt = HZ_TO_RADSEC(1.0f);

#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
    // Flux Weakenning Parameters:
    params_ptr->ctrl.flux_weaken.en = MOTOR_CTRL_FLUX_WEAKEN_M1; // [#]
    params_ptr->ctrl.flux_weaken.vdc_coeff = LINE_TO_PHASE(MOTOR_CTRL_FLUX_WEAKEN_VOLT_MARGIN_M1); // [#]
#if defined(CTRL_METHOD_RFO)
    params_ptr->ctrl.flux_weaken.bw = HZ_TO_RADSEC(MOTOR_CTRL_FLUX_WEAKEN_BW_M1); // [Ra/sec], at least 0.5 dec below current loop's bandwidth
#endif

    // Align (Pre-Positioning) Parameters:
    params_ptr->ctrl.align.time = MOTOR_CTRL_ALIGN_TIME_M1; // [sec]
    params_ptr->ctrl.align.voltage = MOTOR_CTRL_ALIGN_VOLTAGE_M1; // [Vpk]

    // Six Pulse Injection Parameters:
    params_ptr->ctrl.six_pulse_inj.i_peak = MOTOR_CTRL_SIX_PULSE_INJ_MAX_CURRENT_M1; // [A], this is the target value, not the actual value

    // High Frequency Injection Parameters:
    params_ptr->ctrl.high_freq_inj.w_h = HZ_TO_RADSEC(MOTOR_CTRL_HFI_INJECT_FREQ_M1); // [Ra/sec], at least 1 decade below switching frequency
    params_ptr->ctrl.high_freq_inj.w_sep = HZ_TO_RADSEC(MOTOR_CTRL_HFI_SEPARATION_FREQ_M1); // [Ra/sec], at least 1 decade below switching frequency
    params_ptr->ctrl.high_freq_inj.pll.w0 = HZ_TO_RADSEC(60.0f); // [Ra/sec]
    params_ptr->ctrl.high_freq_inj.pll.w_max.elec = 0.5f * (params_ptr->ctrl.high_freq_inj.w_h - params_ptr->ctrl.high_freq_inj.w_sep); // [Ra/sec-elec]
    params_ptr->ctrl.high_freq_inj.i_qd_r_peak.d = MOTOR_CTRL_HFI_MAX_CURRENT_M1; // [A], excitation current peak (d-axis), limiting factor (larger than q-axis)

    // Profiler Parameters (needs high fs0 & fpwm e.g. fs0=30kHz, fpwm=60kHz):
    params_ptr->profiler.overwrite = MOTOR_CTRL_PROFILER_PARAM_OVERWRITE_M1; // []
    params_ptr->profiler.cmd_thresh = PERC_TO_NORM(MOTOR_CTRL_PROFILER_CMD_THRESH_M1); // [%]
    params_ptr->profiler.cmd_hyst = PERC_TO_NORM(MOTOR_CTRL_PROFILER_CMD_HYST_M1); // [%]
    params_ptr->profiler.i_cmd_dc = MOTOR_CTRL_PROFILER_I_CMD_DC_M1; // [A]
    params_ptr->profiler.i_cmd_ac = MOTOR_CTRL_PROFILER_I_CMD_AC_M1; // [A]
    params_ptr->profiler.w_cmd_elec.min = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_PROFILER_SPEED_CMD_MIN_M1)), MOTOR_POLE_M1); // [Ra/sec-elec], must be well above params_ptr->obs.w_thresh.elec
    params_ptr->profiler.w_cmd_elec.max = MECH_TO_ELEC(HZ_TO_RADSEC(RPM_TO_HZ(MOTOR_CTRL_PROFILER_SPEED_CMD_MAX_M1)), MOTOR_POLE_M1); // [Ra/sec-elec]
    params_ptr->profiler.time_rot_lock = MOTOR_CTRL_PROFILER_ROTOR_LOCK_TIME_M1; // [sec]
    params_ptr->profiler.time_spd = MOTOR_CTRL_PROFILER_FLUX_EST_TIME_M1; // [sec]

#elif defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.tbc.mode = MOTOR_CTRL_TBC_MODE_M1;
    params_ptr->ctrl.tbc.trap.ramp_cnt = MOTOR_CTRL_TBC_TRAP_RAMP_COUNT_M1; // [#]
    params_ptr->ctrl.tbc.trap.ramp_main_bw_ratio = MOTOR_CTRL_TBC_TRAP_RAMP_BW_RATIO_M1; // [#]
    params_ptr->ctrl.tbc.trap.ramp_ff_coef = MOTOR_CTRL_TBC_TRAP_RAMP_FF_COEF_M1; // [V/A]
    params_ptr->ctrl.tbc.trap.main_ff_coef = MOTOR_CTRL_TBC_TRAP_MAIN_FF_COEF_M1; // [#]

#endif
}
#endif
void PARAMS_InitAutoCalc(PARAMS_t* params_ptr)
{
    // Motor Parameters:
    params_ptr->motor.zeta = MAX(params_ptr->motor.lq / params_ptr->motor.ld, 1.01f); // [#] limited to avoid division by zero when calculating 1/(zeta-1)
#if defined(CTRL_METHOD_SFO)
    params_ptr->motor.mtpa_lut.x_min = 0.0f;    // [Nm]
    params_ptr->motor.mtpa_lut.x_max = params_ptr->motor.T_max; // [Nm]
    params_ptr->motor.mtpa_lut.x_step = (params_ptr->motor.mtpa_lut.x_max - params_ptr->motor.mtpa_lut.x_min) / (LUT_1D_WIDTH - 1); // [Nm]
    params_ptr->motor.mtpa_lut.x_step_inv = 1.0f / params_ptr->motor.mtpa_lut.x_step; // [1/Nm]
    float c1, c2, c3, c4, lad, laq_sq;
    c1 = 0.5f * POW_TWO(params_ptr->motor.ld / ((params_ptr->motor.zeta - 1.0f) * 0.75f * params_ptr->motor.P) * params_ptr->motor.mtpa_lut.x_step);
    c2 = params_ptr->motor.zeta / (params_ptr->motor.zeta - 1.0f) * params_ptr->motor.lam;
    c3 = (params_ptr->motor.zeta - 0.75f) / (params_ptr->motor.zeta - 1.0f) * params_ptr->motor.lam;
    c4 = POW_TWO(params_ptr->motor.zeta);
    lad = params_ptr->motor.lam; // [Wb]
    laq_sq = 0.0f; // [Wb^2]
    params_ptr->motor.mtpa_lut.y[0] = params_ptr->motor.lam; // [Wb]
    for (uint32_t index = 1U; index < LUT_1D_WIDTH; ++index)
    {
        lad += c1 / POW_TWO(lad - c2) / (lad - c3) * (index - 0.5f); // [Wb]
        laq_sq = c4 * (lad - params_ptr->motor.lam) * (lad - c2); // [Wb^2]
        params_ptr->motor.mtpa_lut.y[index] = sqrtf(POW_TWO(lad) + laq_sq); // [Wb]
    }
    params_ptr->motor.mtpv_lut.x_min = 0.0f; // [Wb]
    params_ptr->motor.mtpv_lut.x_max = params_ptr->motor.mtpa_lut.y[LUT_1D_WIDTH - 1]; // [Wb], =la_max
    params_ptr->motor.mtpv_lut.x_step = (params_ptr->motor.mtpv_lut.x_max - params_ptr->motor.mtpv_lut.x_min) / (LUT_1D_WIDTH - 1); // [Wb]
    params_ptr->motor.mtpv_lut.x_step_inv = 1.0f / params_ptr->motor.mtpv_lut.x_step; // [1/Wb]
    float cos, sin;
    c1 = params_ptr->motor.mtpv_margin * 0.75f * params_ptr->motor.P * POW_TWO(params_ptr->motor.mtpv_lut.x_step) * (params_ptr->motor.zeta - 1.0f) / (params_ptr->motor.ld * params_ptr->motor.zeta);
    c2 = 0.25f * params_ptr->motor.lam * params_ptr->motor.zeta / (params_ptr->motor.mtpv_lut.x_step * (params_ptr->motor.zeta - 1.0f));
    params_ptr->motor.mtpv_lut.y[0] = 0.0f; // [Nm]
    for (uint32_t index = 1U; index < LUT_1D_WIDTH; ++index)
    {
        c3 = c2 / index;
        cos = c3 - sqrtf(POW_TWO(c3) + 0.5f);
        sin = sqrtf(1.0f - POW_TWO(cos));
        params_ptr->motor.mtpv_lut.y[index] = c1 * POW_TWO(index) * sin * (4.0f * c3 - cos);
    }
#endif

    // System Parameters:
    // Sampling Parameters:
    params_ptr->sys.samp.ts0 = 1.0f / params_ptr->sys.samp.fs0; // [sec]
    params_ptr->sys.samp.fpwm = params_ptr->sys.samp.fs0 * params_ptr->sys.samp.fpwm_fs0_ratio; // [Hz]
    params_ptr->sys.samp.tpwm = 1.0f / params_ptr->sys.samp.fpwm; // [Hz]
    params_ptr->sys.samp.fs1 = params_ptr->sys.samp.fs0 / params_ptr->sys.samp.fs0_fs1_ratio; // [Hz]
    params_ptr->sys.samp.ts1 = 1.0f / params_ptr->sys.samp.fs1; // [sec]
    params_ptr->sys.analog.shunt.hyb_mod.adc_d_min = 2.0f * params_ptr->sys.analog.shunt.hyb_mod.adc_t_min * params_ptr->sys.samp.fpwm; // [%]

    // Fault Parameters:
    if(!params_ptr->autocal_disable.vdc_fault_threshold) /*Skip the calculation if this bit is set*/
    {
      params_ptr->sys.faults.vdc_thresh.min = params_ptr->sys.vdc_nom * 0.7f; // [V]
      params_ptr->sys.faults.vdc_thresh.max = params_ptr->sys.vdc_nom * 1.3f; // [V]
    }
    if(!params_ptr->autocal_disable.speed_fault_threshold)/*Skip the calculation if this bit is set*/
    {
      params_ptr->sys.faults.w_thresh.elec = params_ptr->motor.w_max.elec * 2.0f; // [Ra/sec-elec]
    }
    switch (params_ptr->ctrl.mode)
    {
    case Volt_Mode_Open_Loop:
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
    case Speed_Mode_FOC_Sensorless_Align_Startup:
    case Speed_Mode_FOC_Sensorless_SixPulse_Startup:
    case Speed_Mode_FOC_Sensorless_HighFreq_Startup:
    case Speed_Mode_FOC_Sensorless_Volt_Startup:
#endif
#if defined(CTRL_METHOD_RFO)
    case Speed_Mode_FOC_Sensorless_Curr_Startup:
    case Speed_Mode_FOC_Encoder_Align_Startup:
    case Speed_Mode_FOC_Hall:
#elif defined(CTRL_METHOD_TBC)
    case Speed_Mode_Block_Comm_Hall:
#endif
        params_ptr->sys.faults.cmd_clr_thresh = (params_ptr->ctrl.volt.w_thresh.elec - params_ptr->ctrl.volt.w_hyst.elec) / MECH_TO_ELEC(params_ptr->sys.cmd.w_max.mech, params_ptr->motor.P);
        break;
#if defined(CTRL_METHOD_RFO)
    case Curr_Mode_Open_Loop:
    case Curr_Mode_FOC_Sensorless_Align_Startup:
    case Curr_Mode_FOC_Sensorless_SixPulse_Startup:
    case Curr_Mode_FOC_Sensorless_HighFreq_Startup:
    case Curr_Mode_FOC_Sensorless_Dyno:
    case Curr_Mode_FOC_Encoder_Align_Startup:
    case Curr_Mode_FOC_Hall:
#elif defined(CTRL_METHOD_TBC)
    case Curr_Mode_Block_Comm_Hall:
#endif
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
        params_ptr->sys.faults.cmd_clr_thresh = (params_ptr->ctrl.curr.i_cmd_thresh - params_ptr->ctrl.curr.i_cmd_hyst) / params_ptr->sys.cmd.i_max;
        break;
#endif
#if defined(CTRL_METHOD_SFO)
    case Trq_Mode_FOC_Sensorless_Align_Startup:
    case Trq_Mode_FOC_Sensorless_SixPulse_Startup:
    case Trq_Mode_FOC_Sensorless_HighFreq_Startup:
    case Trq_Mode_FOC_Sensorless_Dyno:
        params_ptr->sys.faults.cmd_clr_thresh = (params_ptr->ctrl.trq.T_cmd_thresh - params_ptr->ctrl.trq.T_cmd_hyst) / params_ptr->sys.cmd.T_max;
        break;
#endif
#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)
    case Profiler_Mode:
        params_ptr->sys.faults.cmd_clr_thresh = params_ptr->profiler.cmd_thresh - params_ptr->profiler.cmd_hyst;
        break;
#endif
    default:
        params_ptr->sys.faults.cmd_clr_thresh = 0.0f;
        break;
    }

#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_TBC)
    if(params_ptr->sys.fb.mode != Direct)
    {
      params_ptr->sys.fb.mode = Sensorless;
#if defined(CTRL_METHOD_RFO)
      if ((params_ptr->ctrl.mode == Speed_Mode_FOC_Hall) || (params_ptr->ctrl.mode == Curr_Mode_FOC_Hall))
      {
          params_ptr->sys.fb.mode = Hall;
      }
      else if ((params_ptr->ctrl.mode == Speed_Mode_FOC_Encoder_Align_Startup) || (params_ptr->ctrl.mode == Curr_Mode_FOC_Encoder_Align_Startup))
      {
          params_ptr->sys.fb.mode = AqB_Enc;
      }
#elif defined(CTRL_METHOD_TBC)
      if ((params_ptr->ctrl.mode == Speed_Mode_Block_Comm_Hall) || (params_ptr->ctrl.mode == Curr_Mode_Block_Comm_Hall))
      {
          params_ptr->sys.fb.mode = Hall;
      }
#endif
    }
#endif
#if defined(CTRL_METHOD_SFO)
    params_ptr->sys.fb.mode = Sensorless;
#endif
    params_ptr->sys.fb.hall.track_loop.cpr = (uint16_t)(params_ptr->motor.P) * 3U; // [#], always 6*(P/2) for hall sensor

    // Observer Parameters:
    params_ptr->obs.flux_filt.c1_coeff = params_ptr->obs.flux_filt.k1 + params_ptr->obs.flux_filt.k2 + params_ptr->obs.flux_filt.k3; // [#]
    params_ptr->obs.flux_filt.c2_coeff = params_ptr->obs.flux_filt.k1 * params_ptr->obs.flux_filt.k2 + \
        params_ptr->obs.flux_filt.k2 * params_ptr->obs.flux_filt.k3 + \
        params_ptr->obs.flux_filt.k1 * params_ptr->obs.flux_filt.k3; // [#]
    params_ptr->obs.flux_filt.c3_coeff = params_ptr->obs.flux_filt.k1 * params_ptr->obs.flux_filt.k2 * params_ptr->obs.flux_filt.k3; // [#]
    params_ptr->obs.flux_filt.gain = sqrtf(POW_TWO(1.0f - params_ptr->obs.flux_filt.c2_coeff) + POW_TWO(params_ptr->obs.flux_filt.c3_coeff - params_ptr->obs.flux_filt.c1_coeff)); // [#]
    params_ptr->obs.flux_filt.th_p.elec = ATan2(params_ptr->obs.flux_filt.c1_coeff - params_ptr->obs.flux_filt.c3_coeff, 1.0f - params_ptr->obs.flux_filt.c2_coeff); // [Ra-elec]
    ParkInit(-params_ptr->obs.flux_filt.th_p.elec, &params_ptr->obs.flux_filt.phase_lead);

    if(!params_ptr->autocal_disable.observer_pll) /*Skip the calculation if this bit is set*/
    {
      params_ptr->obs.pll.kp = params_ptr->obs.pll.w0 / params_ptr->motor.lam; // [(Ra/sec-elec)/Wb]
      params_ptr->obs.pll.ki = POW_TWO(params_ptr->obs.pll.w0) / params_ptr->motor.lam * 0.5f; // [(Ra/sec).(Ra/sec-elec)/Wb]
    }

    params_ptr->obs.pll.th_offset.elec = params_ptr->obs.flux_filt.th_p.elec; // [Ra-elec]

    // Mechanical System Parameters:

    // Filter Parameters:

    // Speed Control Parameters:
#if defined(CTRL_METHOD_RFO)
    if(!params_ptr->autocal_disable.speed_control) /*Skip the calculation if this bit is set*/
    {
      params_ptr->ctrl.speed.kp = ((8.0f / 3.0f) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.inertia * params_ptr->ctrl.speed.bw; // [A/(Ra/sec-elec)]
      params_ptr->ctrl.speed.ki = ((8.0f / 3.0f) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.viscous * params_ptr->ctrl.speed.bw * params_ptr->ctrl.speed.ki_multiple; // [A/(Ra/sec-elec).(Ra/sec)]
    }
    params_ptr->ctrl.speed.ff_k_inertia = ((8.0f / 3.0f) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.inertia; // [A/(Ra/sec-elec).sec]
    params_ptr->ctrl.speed.ff_k_viscous = ((8.0f / 3.0f) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.viscous; // [A/(Ra/sec-elec)]
    params_ptr->ctrl.speed.ff_k_friction = ((4.0f / 3.0f) / (params_ptr->motor.P * params_ptr->motor.lam)) * params_ptr->mech.friction; // [A]

#elif defined(CTRL_METHOD_SFO)
    if(!params_ptr->autocal_disable.speed_control) /*Skip the calculation if this bit is set*/
    {
      params_ptr->ctrl.speed.kp = 2.0f / params_ptr->motor.P * params_ptr->mech.inertia * params_ptr->ctrl.speed.bw; // [Nm/(Ra/sec-elec)]
      params_ptr->ctrl.speed.ki = 2.0f / params_ptr->motor.P * params_ptr->mech.viscous * params_ptr->ctrl.speed.bw * params_ptr->ctrl.speed.ki_multiple; // [Nm/(Ra/sec-elec).(Ra/sec)]
    }
    params_ptr->ctrl.speed.ff_k_inertia = 2.0f / params_ptr->motor.P * params_ptr->mech.inertia; // [Nm/(Ra/sec-elec).sec]
    params_ptr->ctrl.speed.ff_k_viscous = 2.0f / params_ptr->motor.P * params_ptr->mech.viscous; // [Nm/(Ra/sec-elec)]
    params_ptr->ctrl.speed.ff_k_friction = params_ptr->mech.friction; // [Nm]

#elif defined(CTRL_METHOD_TBC)
    if(!params_ptr->autocal_disable.speed_control) /*Skip the calculation if this bit is set*/
    {
      params_ptr->ctrl.speed.kp = ((2.0f * SQRT_TWO) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.inertia * params_ptr->ctrl.speed.bw; // [A/(Ra/sec-elec)]
      params_ptr->ctrl.speed.ki = ((2.0f * SQRT_TWO) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.viscous * params_ptr->ctrl.speed.bw * params_ptr->ctrl.speed.ki_multiple; // [A/(Ra/sec-elec).(Ra/sec)]
    }
    params_ptr->ctrl.speed.ff_k_inertia = ((2.0f * SQRT_TWO) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.inertia; // [A/(Ra/sec-elec).sec]
    params_ptr->ctrl.speed.ff_k_viscous = ((2.0f * SQRT_TWO) / (POW_TWO(params_ptr->motor.P) * params_ptr->motor.lam)) * params_ptr->mech.viscous; // [A/(Ra/sec-elec)]
    params_ptr->ctrl.speed.ff_k_friction = (SQRT_TWO / (params_ptr->motor.P * params_ptr->motor.lam)) * params_ptr->mech.friction; // [A]

#endif

#if defined(CTRL_METHOD_RFO)
    // Current Control Parameters:
    if(!params_ptr->autocal_disable.current_control) /*Execute calculation if this bit is not set*/
    {
      params_ptr->ctrl.curr.kp.q = params_ptr->ctrl.curr.bw * params_ptr->motor.lq; // [V/A]
      params_ptr->ctrl.curr.kp.d = params_ptr->ctrl.curr.bw * params_ptr->motor.ld; // [V/A]
      params_ptr->ctrl.curr.ki.q = params_ptr->ctrl.curr.bw * params_ptr->motor.r; // [V/A.(Ra/sec)]
      params_ptr->ctrl.curr.ki.d = params_ptr->ctrl.curr.bw * params_ptr->motor.r; // [V/A.(Ra/sec)]
    }
    params_ptr->ctrl.curr.v_max.q = LINE_TO_PHASE(params_ptr->sys.vdc_nom); // [V]
    params_ptr->ctrl.curr.v_max.d = LINE_TO_PHASE(params_ptr->sys.vdc_nom); // [V]

#elif defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.curr.k_bypass = params_ptr->motor.r * ONE_OVER_SQRT_TWO; // [V/A]
    if(!params_ptr->autocal_disable.current_control) /*Execute calculation if this bit is not set*/
    {
      params_ptr->ctrl.curr.kp = params_ptr->ctrl.curr.bw * (0.5f * ONE_OVER_SQRT_TWO) * (params_ptr->motor.lq + params_ptr->motor.ld); // [V/A]
      params_ptr->ctrl.curr.ki = params_ptr->ctrl.curr.bw * ONE_OVER_SQRT_TWO * params_ptr->motor.r; // [V/A.(Ra/sec)]
    }
    params_ptr->ctrl.curr.v_max = 0.5f * params_ptr->sys.vdc_nom; // [V]

#elif defined(CTRL_METHOD_SFO)
    // Torque Controller Parameters:
    float k = 0.75f * params_ptr->motor.P * params_ptr->motor.lam * (params_ptr->motor.lam / params_ptr->motor.ld + (1.0f / params_ptr->motor.lq - 1.0f / params_ptr->motor.ld) * params_ptr->motor.lam);
    if(!params_ptr->autocal_disable.torque_control) /*Execute calculation if this bit is not set*/
    {
      params_ptr->ctrl.trq.kp = params_ptr->ctrl.trq.w_ratio / ((1.0f - params_ptr->ctrl.trq.w_ratio) * k); // [(Ra-elec)/(Nm)]
      params_ptr->ctrl.trq.ki = params_ptr->ctrl.trq.w_p / ((1.0f - params_ptr->ctrl.trq.w_ratio) * k); // [(Ra/sec).(Ra-elec)/(Nm)]
    }
    float dl = MIN(ABS(params_ptr->motor.lq - params_ptr->motor.ld), 1.0E-9f);
    c1 = 1.0f / (0.75f * params_ptr->motor.P * params_ptr->motor.lam);
    c2 = 1.0f / sqrtf(0.375f * params_ptr->motor.P * dl * params_ptr->motor.T_max);
    float c_min = MIN(c1, c2);
    params_ptr->ctrl.trq.curr_lmt_ki = params_ptr->sys.samp.ts1 * (params_ptr->motor.i_peak - params_ptr->motor.i_cont) / (c_min * params_ptr->ctrl.trq.curr_lmt_t_reach);

    // Flux Controller Parameters:
    if(!params_ptr->autocal_disable.flux_control) /*Execute calculation if this bit is not set*/
    {
      params_ptr->ctrl.flux.kp = params_ptr->ctrl.flux.bw * params_ptr->ctrl.flux.pole_sep; // [V/Wb]
      params_ptr->ctrl.flux.ki = POW_TWO(params_ptr->ctrl.flux.bw) * (params_ptr->ctrl.flux.pole_sep - 1.0f); // [(Ra/sec).V/Wb]
    }
    params_ptr->ctrl.flux.vd_max = LINE_TO_PHASE(params_ptr->sys.vdc_nom); // [V]

    // Load Angle Controller Parameters:
    params_ptr->ctrl.delta.bw_mult_slope = 1.0f / (params_ptr->ctrl.delta.bw_mult_wh.elec - params_ptr->ctrl.delta.bw_mult_wl.elec); // [1/(Ra/sec-elec)]
    params_ptr->ctrl.delta.bw_mult_inter = -params_ptr->ctrl.delta.bw_mult_wl.elec / (params_ptr->ctrl.delta.bw_mult_wh.elec - params_ptr->ctrl.delta.bw_mult_wl.elec); // [#]
    params_ptr->ctrl.delta.vq_max = LINE_TO_PHASE(params_ptr->sys.vdc_nom); // [V]

#endif

    // Voltage Control Parameters:

#if defined(CTRL_METHOD_RFO) || defined(CTRL_METHOD_SFO)

    // Flux Weakenning Parameters:
#if defined(CTRL_METHOD_RFO)
    if(!params_ptr->autocal_disable.flux_weakening) /*Execute calculation if this bit is not set*/
    {
      params_ptr->ctrl.flux_weaken.ki = params_ptr->motor.lam / (params_ptr->motor.ld * LINE_TO_PHASE(params_ptr->sys.vdc_nom)) * params_ptr->ctrl.flux_weaken.bw * params_ptr->sys.samp.ts1; // % [Ra/sec.A/V]
    }
#elif defined(CTRL_METHOD_SFO)
    params_ptr->ctrl.flux_weaken.w_min.elec = 0.5f * params_ptr->sys.vdc_nom * params_ptr->ctrl.flux_weaken.vdc_coeff / params_ptr->motor.mtpa_lut.y[LUT_1D_WIDTH - 1]; // [Ra/sec-elec]
#endif

    // Six Pulse Injection Parameters:
    float motor_l_ave = 0.5f * (params_ptr->motor.lq + params_ptr->motor.ld); // [H]
    float motor_tau_ave = motor_l_ave / params_ptr->motor.r; // [sec]
    params_ptr->ctrl.six_pulse_inj.t_on = QUANTIZE_FLOAT(motor_tau_ave, params_ptr->sys.samp.ts0); // [sec], to maximize the difference between currents
    params_ptr->ctrl.six_pulse_inj.t_off = QUANTIZE_FLOAT(10.0f * motor_tau_ave, params_ptr->sys.samp.ts0); // [sec], enough time for current to go to zero
    params_ptr->ctrl.six_pulse_inj.v_pulse = (1.5f / (1.0f - EXP_MINUS_ONE)) * params_ptr->motor.r * params_ptr->ctrl.six_pulse_inj.i_peak; // [V], dc+ to dc-

    // High Frequency Injection Parameters:
    params_ptr->ctrl.high_freq_inj.v_qd_r_coeff.q = params_ptr->ctrl.high_freq_inj.i_qd_r_peak.d * params_ptr->motor.ld; // [V/(Ra/sec)]
    params_ptr->ctrl.high_freq_inj.v_qd_r_coeff.d = params_ptr->ctrl.high_freq_inj.i_qd_r_peak.d * params_ptr->motor.ld * params_ptr->ctrl.high_freq_inj.w_h; // [V]

    params_ptr->ctrl.high_freq_inj.i_qd_r_peak.q = params_ptr->ctrl.high_freq_inj.i_qd_r_peak.d *
        0.5f * (params_ptr->motor.zeta - 1.0f) / params_ptr->motor.zeta; //[A], excitation current peak (q-axis), smaller than (d-axis)

    params_ptr->ctrl.high_freq_inj.pll.kp = params_ptr->ctrl.high_freq_inj.pll.w0 / params_ptr->ctrl.high_freq_inj.i_qd_r_peak.q; // [(Ra/sec-elec)/A]
    params_ptr->ctrl.high_freq_inj.pll.ki = 0.25f * POW_TWO(params_ptr->ctrl.high_freq_inj.pll.w0) / params_ptr->ctrl.high_freq_inj.i_qd_r_peak.q; // [(Ra/sec).(Ra/sec-elec)/A]
    params_ptr->ctrl.high_freq_inj.pll.th_offset.elec = 0.0f;

    params_ptr->ctrl.high_freq_inj.lpf_biquad_a[0] = 1.0f; // [#], dc gain
    params_ptr->ctrl.high_freq_inj.lpf_biquad_a[1] = 0.0f; // [1/(Ra/sec)]
    params_ptr->ctrl.high_freq_inj.lpf_biquad_a[2] = 0.0f; // [1/(Ra/sec)^2]
    params_ptr->ctrl.high_freq_inj.lpf_biquad_b[0] = 1.0f; // [#]
    params_ptr->ctrl.high_freq_inj.lpf_biquad_b[1] = 2.0f / params_ptr->ctrl.high_freq_inj.w_sep; // [1/(Ra/sec)]
    params_ptr->ctrl.high_freq_inj.lpf_biquad_b[2] = 1.0f / POW_TWO(params_ptr->ctrl.high_freq_inj.w_sep); // [1/(Ra/sec)^2]
#if defined(CTRL_METHOD_RFO)
    params_ptr->ctrl.high_freq_inj.bw_red_coeff = params_ptr->ctrl.high_freq_inj.w_sep / params_ptr->ctrl.curr.bw;
#elif defined(CTRL_METHOD_SFO)
    params_ptr->ctrl.high_freq_inj.bw_red_coeff = params_ptr->ctrl.high_freq_inj.w_sep / MAX(params_ptr->ctrl.flux.bw, params_ptr->ctrl.delta.bw);
#endif
    params_ptr->ctrl.high_freq_inj.lock_time = RADSEC_TO_TAU(params_ptr->ctrl.high_freq_inj.pll.w0) * 40.0f; // [sec]

    // Profiler Parameters:
    // Ranges:
    // r:        10m -> 700m   ,[Ohm]
    // l:        10u -> 700u   ,[H]
    // f (=r/l): 500 -> 1000   ,[Hz]
    const MINMAX_t Range_R = { 10.0E-3f, 700.0E-3f }; // [Ohm]
    const MINMAX_t Range_F = { 900.0f, 1100.0f }; // [Hz], excitation

    const float Slope_F = (Range_F.max - Range_F.min) / (PROF_FREQ_POINTS - 1);
    for (uint8_t index = 0U; index < PROF_FREQ_POINTS; ++index)
    {
        params_ptr->profiler.w_h[index] = HZ_TO_RADSEC(Range_F.min + Slope_F * index); // [Ra/sec]
    }
    params_ptr->profiler.w_sep = HZ_TO_RADSEC(Range_F.min * 0.1f); // [Ra/sec]
    params_ptr->profiler.w0_idc = params_ptr->profiler.w_sep * 0.5f; // [Ra/sec]
    params_ptr->profiler.kp_idc = params_ptr->profiler.w0_idc / params_ptr->profiler.w_sep * AVE(Range_R.min, Range_R.max); // [V/A]
    params_ptr->profiler.ki_idc = params_ptr->profiler.w0_idc * AVE(Range_R.min, Range_R.max); // [(V/A).(Ra/sec)]
    params_ptr->profiler.time_res = 80.0f * RADSEC_TO_TAU(params_ptr->profiler.w_sep); // [sec]
    params_ptr->profiler.time_ind = 80.0f * RADSEC_TO_TAU(params_ptr->profiler.w_sep); // [sec]
    params_ptr->profiler.w0_flux = TAU_TO_RADSEC(params_ptr->profiler.time_spd * 0.1f);

#elif defined(CTRL_METHOD_TBC)
    params_ptr->ctrl.tbc.trap.ramp_kp = params_ptr->ctrl.curr.kp * params_ptr->ctrl.tbc.trap.ramp_main_bw_ratio; // [V/A]
    params_ptr->ctrl.tbc.trap.ramp_ki = params_ptr->ctrl.curr.ki * params_ptr->ctrl.tbc.trap.ramp_main_bw_ratio; // [(V/A).(Ra/sec)]
    params_ptr->ctrl.tbc.trap.ramp_cnt_inv = (params_ptr->ctrl.tbc.trap.ramp_cnt == 0U) ? 1.0f : 1.0f / (float)(params_ptr->ctrl.tbc.trap.ramp_cnt); // [#]

#endif

}
