// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2014.1
// Copyright (C) 2014 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xtriple_aes.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XTriple_aes_CfgInitialize(XTriple_aes *InstancePtr, XTriple_aes_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XTriple_aes_Start(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL) & 0x80;
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XTriple_aes_IsDone(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XTriple_aes_IsIdle(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XTriple_aes_IsReady(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XTriple_aes_EnableAutoRestart(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XTriple_aes_DisableAutoRestart(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XTriple_aes_Get_return(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_AP_RETURN);
    return Data;
}
void XTriple_aes_Set_sourceAddress(XTriple_aes *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_SOURCEADDRESS_DATA, Data);
}

u32 XTriple_aes_Get_sourceAddress(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_SOURCEADDRESS_DATA);
    return Data;
}

void XTriple_aes_Set_sourceAddress_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_SOURCEADDRESS_CTRL, 1);
}

u32 XTriple_aes_Get_sourceAddress_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_SOURCEADDRESS_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_key_in_V(XTriple_aes *InstancePtr, XTriple_aes_Key_in_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 12, Data.word_3);
}

XTriple_aes_Key_in_v XTriple_aes_Get_key_in_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Key_in_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_key_in_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_CTRL, 1);
}

u32 XTriple_aes_Get_key_in_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_key_in1_V(XTriple_aes *InstancePtr, XTriple_aes_Key_in1_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 12, Data.word_3);
}

XTriple_aes_Key_in1_v XTriple_aes_Get_key_in1_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Key_in1_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_key_in1_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_CTRL, 1);
}

u32 XTriple_aes_Get_key_in1_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN1_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_key_in2_V(XTriple_aes *InstancePtr, XTriple_aes_Key_in2_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 12, Data.word_3);
}

XTriple_aes_Key_in2_v XTriple_aes_Get_key_in2_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Key_in2_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_key_in2_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_CTRL, 1);
}

u32 XTriple_aes_Get_key_in2_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_KEY_IN2_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_iv_V(XTriple_aes *InstancePtr, XTriple_aes_Iv_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 12, Data.word_3);
}

XTriple_aes_Iv_v XTriple_aes_Get_iv_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Iv_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_iv_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_CTRL, 1);
}

u32 XTriple_aes_Get_iv_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_iv1_V(XTriple_aes *InstancePtr, XTriple_aes_Iv1_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 12, Data.word_3);
}

XTriple_aes_Iv1_v XTriple_aes_Get_iv1_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Iv1_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_iv1_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_CTRL, 1);
}

u32 XTriple_aes_Get_iv1_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV1_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_iv2_V(XTriple_aes *InstancePtr, XTriple_aes_Iv2_v Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 0, Data.word_0);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 4, Data.word_1);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 8, Data.word_2);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 12, Data.word_3);
}

XTriple_aes_Iv2_v XTriple_aes_Get_iv2_V(XTriple_aes *InstancePtr) {
    XTriple_aes_Iv2_v Data;

    Data.word_0 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 0);
    Data.word_1 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 4);
    Data.word_2 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 8);
    Data.word_3 = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_DATA + 12);
    return Data;
}

void XTriple_aes_Set_iv2_V_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_CTRL, 1);
}

u32 XTriple_aes_Get_iv2_V_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IV2_V_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_destinationAddress(XTriple_aes *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_DESTINATIONADDRESS_DATA, Data);
}

u32 XTriple_aes_Get_destinationAddress(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_DESTINATIONADDRESS_DATA);
    return Data;
}

void XTriple_aes_Set_destinationAddress_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_DESTINATIONADDRESS_CTRL, 1);
}

u32 XTriple_aes_Get_destinationAddress_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_DESTINATIONADDRESS_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_numBytes(XTriple_aes *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_NUMBYTES_DATA, Data);
}

u32 XTriple_aes_Get_numBytes(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_NUMBYTES_DATA);
    return Data;
}

void XTriple_aes_Set_numBytes_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_NUMBYTES_CTRL, 1);
}

u32 XTriple_aes_Get_numBytes_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_NUMBYTES_CTRL);
    return Data & 0x1;
}

void XTriple_aes_Set_mode(XTriple_aes *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_MODE_DATA, Data);
}

u32 XTriple_aes_Get_mode(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_MODE_DATA);
    return Data;
}

void XTriple_aes_Set_mode_vld(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_MODE_CTRL, 1);
}

u32 XTriple_aes_Get_mode_vld(XTriple_aes *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_MODE_CTRL);
    return Data & 0x1;
}

void XTriple_aes_InterruptGlobalEnable(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_GIE, 1);
}

void XTriple_aes_InterruptGlobalDisable(XTriple_aes *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_GIE, 0);
}

void XTriple_aes_InterruptEnable(XTriple_aes *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IER);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IER, Register | Mask);
}

void XTriple_aes_InterruptDisable(XTriple_aes *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IER);
    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IER, Register & (~Mask));
}

void XTriple_aes_InterruptClear(XTriple_aes *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTriple_aes_WriteReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_ISR, Mask);
}

u32 XTriple_aes_InterruptGetEnabled(XTriple_aes *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_IER);
}

u32 XTriple_aes_InterruptGetStatus(XTriple_aes *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XTriple_aes_ReadReg(InstancePtr->Axilites_BaseAddress, XTRIPLE_AES_AXILITES_ADDR_ISR);
}

