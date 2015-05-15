// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2014.1
// Copyright (C) 2014 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xqam_runner.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XQam_runner_CfgInitialize(XQam_runner *InstancePtr, XQam_runner_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XQam_runner_Start(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL) & 0x80;
    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XQam_runner_IsDone(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XQam_runner_IsIdle(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XQam_runner_IsReady(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XQam_runner_EnableAutoRestart(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XQam_runner_DisableAutoRestart(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XQam_runner_Get_return(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_AP_RETURN);
    return Data;
}
void XQam_runner_Set_input_d_i(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_I_DATA, Data);
}

u32 XQam_runner_Get_input_d_i(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_I_DATA);
    return Data;
}

void XQam_runner_Set_input_d_i_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_I_CTRL, 1);
}

u32 XQam_runner_Get_input_d_i_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_I_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_input_d_q(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_Q_DATA, Data);
}

u32 XQam_runner_Get_input_d_q(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_Q_DATA);
    return Data;
}

void XQam_runner_Set_input_d_q_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_Q_CTRL, 1);
}

u32 XQam_runner_Get_input_d_q_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_D_Q_CTRL);
    return Data & 0x1;
}

u32 XQam_runner_Get_output_d_i(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_D_I_DATA);
    return Data;
}

u32 XQam_runner_Get_output_d_q(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_D_Q_DATA);
    return Data;
}

void XQam_runner_Set_input_ph_i(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_I_DATA, Data);
}

u32 XQam_runner_Get_input_ph_i(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_I_DATA);
    return Data;
}

void XQam_runner_Set_input_ph_i_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_I_CTRL, 1);
}

u32 XQam_runner_Get_input_ph_i_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_I_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_input_ph_q(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_Q_DATA, Data);
}

u32 XQam_runner_Get_input_ph_q(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_Q_DATA);
    return Data;
}

void XQam_runner_Set_input_ph_q_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_Q_CTRL, 1);
}

u32 XQam_runner_Get_input_ph_q_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_INPUT_PH_Q_CTRL);
    return Data & 0x1;
}

u32 XQam_runner_Get_output_ph_i(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_PH_I_DATA);
    return Data;
}

u32 XQam_runner_Get_output_ph_i_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_PH_I_CTRL);
    return Data & 0x1;
}

u32 XQam_runner_Get_output_ph_q(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_PH_Q_DATA);
    return Data;
}

u32 XQam_runner_Get_output_ph_q_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_OUTPUT_PH_Q_CTRL);
    return Data & 0x1;
}

u32 XQam_runner_Get_loop_out(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_LOOP_OUT_DATA);
    return Data;
}

u32 XQam_runner_Get_loop_out_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_LOOP_OUT_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_qam(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_QAM_DATA, Data);
}

u32 XQam_runner_Get_control_in_qam(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_QAM_DATA);
    return Data;
}

void XQam_runner_Set_control_in_qam_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_QAM_CTRL, 1);
}

u32 XQam_runner_Get_control_in_qam_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_QAM_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_lf_p(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_P_DATA, Data);
}

u32 XQam_runner_Get_control_in_lf_p(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_P_DATA);
    return Data;
}

void XQam_runner_Set_control_in_lf_p_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_P_CTRL, 1);
}

u32 XQam_runner_Get_control_in_lf_p_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_P_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_lf_i(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_I_DATA, Data);
}

u32 XQam_runner_Get_control_in_lf_i(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_I_DATA);
    return Data;
}

void XQam_runner_Set_control_in_lf_i_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_I_CTRL, 1);
}

u32 XQam_runner_Get_control_in_lf_i_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_I_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_lf_out_gain(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_OUT_GAIN_DATA, Data);
}

u32 XQam_runner_Get_control_in_lf_out_gain(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_OUT_GAIN_DATA);
    return Data;
}

void XQam_runner_Set_control_in_lf_out_gain_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_OUT_GAIN_CTRL, 1);
}

u32 XQam_runner_Get_control_in_lf_out_gain_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_LF_OUT_GAIN_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_reg_clr(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_CLR_DATA, Data);
}

u32 XQam_runner_Get_control_in_reg_clr(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_CLR_DATA);
    return Data;
}

void XQam_runner_Set_control_in_reg_clr_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_CLR_CTRL, 1);
}

u32 XQam_runner_Get_control_in_reg_clr_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_CLR_CTRL);
    return Data & 0x1;
}

void XQam_runner_Set_control_in_reg_init(XQam_runner *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_INIT_DATA, Data);
}

u32 XQam_runner_Get_control_in_reg_init(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_INIT_DATA);
    return Data;
}

void XQam_runner_Set_control_in_reg_init_vld(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_INIT_CTRL, 1);
}

u32 XQam_runner_Get_control_in_reg_init_vld(XQam_runner *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_CONTROL_IN_REG_INIT_CTRL);
    return Data & 0x1;
}

void XQam_runner_InterruptGlobalEnable(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_GIE, 1);
}

void XQam_runner_InterruptGlobalDisable(XQam_runner *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_GIE, 0);
}

void XQam_runner_InterruptEnable(XQam_runner *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_IER);
    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_IER, Register | Mask);
}

void XQam_runner_InterruptDisable(XQam_runner *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_IER);
    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_IER, Register & (~Mask));
}

void XQam_runner_InterruptClear(XQam_runner *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQam_runner_WriteReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_ISR, Mask);
}

u32 XQam_runner_InterruptGetEnabled(XQam_runner *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_IER);
}

u32 XQam_runner_InterruptGetStatus(XQam_runner *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XQam_runner_ReadReg(InstancePtr->Axilites_BaseAddress, XQAM_RUNNER_AXILITES_ADDR_ISR);
}

