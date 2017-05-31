// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XCURVE25519_DONNA_H
#define XCURVE25519_DONNA_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xcurve25519_donna_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XCurve25519_donna_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XCurve25519_donna;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XCurve25519_donna_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XCurve25519_donna_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XCurve25519_donna_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XCurve25519_donna_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XCurve25519_donna_Initialize(XCurve25519_donna *InstancePtr, u16 DeviceId);
XCurve25519_donna_Config* XCurve25519_donna_LookupConfig(u16 DeviceId);
int XCurve25519_donna_CfgInitialize(XCurve25519_donna *InstancePtr, XCurve25519_donna_Config *ConfigPtr);
#else
int XCurve25519_donna_Initialize(XCurve25519_donna *InstancePtr, const char* InstanceName);
int XCurve25519_donna_Release(XCurve25519_donna *InstancePtr);
#endif

void XCurve25519_donna_Start(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_IsDone(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_IsIdle(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_IsReady(XCurve25519_donna *InstancePtr);
void XCurve25519_donna_EnableAutoRestart(XCurve25519_donna *InstancePtr);
void XCurve25519_donna_DisableAutoRestart(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_return(XCurve25519_donna *InstancePtr);

u32 XCurve25519_donna_Get_mypublic_BaseAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_mypublic_HighAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_mypublic_TotalBytes(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_mypublic_BitWidth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_mypublic_Depth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Write_mypublic_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Read_mypublic_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Write_mypublic_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);
u32 XCurve25519_donna_Read_mypublic_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);
u32 XCurve25519_donna_Get_secret_BaseAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_secret_HighAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_secret_TotalBytes(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_secret_BitWidth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_secret_Depth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Write_secret_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Read_secret_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Write_secret_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);
u32 XCurve25519_donna_Read_secret_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);
u32 XCurve25519_donna_Get_basepoint_BaseAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_basepoint_HighAddress(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_basepoint_TotalBytes(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_basepoint_BitWidth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Get_basepoint_Depth(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_Write_basepoint_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Read_basepoint_Words(XCurve25519_donna *InstancePtr, int offset, int *data, int length);
u32 XCurve25519_donna_Write_basepoint_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);
u32 XCurve25519_donna_Read_basepoint_Bytes(XCurve25519_donna *InstancePtr, int offset, char *data, int length);

void XCurve25519_donna_InterruptGlobalEnable(XCurve25519_donna *InstancePtr);
void XCurve25519_donna_InterruptGlobalDisable(XCurve25519_donna *InstancePtr);
void XCurve25519_donna_InterruptEnable(XCurve25519_donna *InstancePtr, u32 Mask);
void XCurve25519_donna_InterruptDisable(XCurve25519_donna *InstancePtr, u32 Mask);
void XCurve25519_donna_InterruptClear(XCurve25519_donna *InstancePtr, u32 Mask);
u32 XCurve25519_donna_InterruptGetEnabled(XCurve25519_donna *InstancePtr);
u32 XCurve25519_donna_InterruptGetStatus(XCurve25519_donna *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
