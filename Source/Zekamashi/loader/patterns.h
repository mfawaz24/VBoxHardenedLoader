/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2017 - 2018
*
*  TITLE:       PATTERNS.H
*
*  VERSION:     1.90
*
*  DATE:        11 Jan 2018
*
*  Search patterns and patches header file.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#pragma once

typedef struct _TABLE_DESC {
    PVOID   DDTablePointer;
    ULONG   DDTableSize;
} TABLE_DESC, *PTABLE_DESC;

typedef struct _BINARY_PATCH_BLOCK {
    ULONG	VirtualOffset;
    UCHAR	DataLength;
    UCHAR	Data[1];
} BINARY_PATCH_BLOCK, *PBINARY_PATCH_BLOCK;

typedef struct _BINARY_PATCH_BLOCK_INTERNAL {
    ULONG	VirtualOffset;
    UCHAR	DataLength;
    UCHAR	Data[32];
} BINARY_PATCH_BLOCK_INTERNAL, *PBINARY_PATCH_BLOCK_INTERNAL;

//patches

static const unsigned char VBOX_PATCH[] = { 0x51, 0x52 };

static const unsigned char JUSTVIRTUALBOX_PATCH[] = { 
    0x4D, 0x61, 0x67, 0x69, 0x63, 0x61, 0x6C, 0x52 };

static const unsigned char CONFIGURATION_PATCH[] = {
    0x44, 0x73, 0x64, 0x74, 0x46, 0x69, 0x6C, 0x65, 0x50, 0x61, 0x74, 0x68, 0x00, 0x53,
    0x73, 0x64, 0x74, 0x46, 0x69, 0x6C, 0x65, 0x50, 0x61, 0x74, 0x68, 0x00, 0x00 };

static const unsigned char HWID_PATCH_VIDEO_1[] = { 0xDE, 0x10 };

static const unsigned char HWID_PATCH_VIDEO_2[] = { 0xED, 0x1C };

static const unsigned char HWID_PATCH[] = { 0xCA, 0xC0 };

//patterns

static const unsigned char FACP_PATTERN[] = {
    0xC7, 0x44, 0x24, 0x30, 0x56, 0x42, 0x4F, 0x58,
    0x89, 0x45, 0x90, 0xC7, 0x44, 0x24, 0x34, 0x46,
    0x41, 0x43, 0x50 };

static const unsigned char RSDT_PATTERN[] = {
    0xC7, 0x47, 0x10, 0x56, 0x42, 0x4F, 0x58, 0xC7,
    0x47, 0x14, 0x52, 0x53, 0x44, 0x54
};

static const unsigned char XSDT_PATTERN[] = {
    0xC7, 0x43, 0x10, 0x56, 0x42, 0x4F, 0x58, 0xC7,
    0x43, 0x14, 0x58, 0x53, 0x44, 0x54
};

static const unsigned char APIC_PATTERN[] = {
    0xC7, 0x40, 0x10, 0x56, 0x42, 0x4F, 0x58, 0xC7,
    0x40, 0x14, 0x41, 0x50, 0x49, 0x43
};

static const unsigned char HPET_PATTERN[] = {
    0xC7, 0x45, 0xD0, 0x56, 0x42, 0x4F, 0x58, 0x32,
    0xD2, 0xC7, 0x45, 0xD4, 0x48, 0x50, 0x45, 0x54
};

static const unsigned char MCFG_PATTERN[] = {
    0xC7, 0x45, 0xD0, 0x56, 0x42, 0x4F, 0x58, 0xFE,
    0xC8, 0xC7, 0x45, 0xD4, 0x4D, 0x43, 0x46, 0x47
};

static const unsigned char VBOXCPU_PATTERN[] = {
    0x48, 0xB8, 0x56, 0x42, 0x4F, 0x58, 0x43, 0x50,
    0x55, 0x20
};

static const unsigned char JUSTVBOX_PATTERN[] = {
    0x41, 0xC7, 0x01, 0x56, 0x42, 0x4F, 0x58, 0x66,
    0xC7, 0x81, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01
};

static const unsigned char JUSTVIRTUALBOX_PATTERN[] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x42,
    0x6F, 0x78, 0x00
};

static const unsigned char VIRTUALBOX2020_PATTERN[] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x42,
    0x6F, 0x78, 0x20, 0x20, 0x00
};

static const unsigned char VIRTUALBOXGIM_PATTERN[] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x42,
    0x6F, 0x78, 0x20, 0x47, 0x49, 0x4D, 0x20, 0x44,
    0x65, 0x76, 0x69, 0x63, 0x65, 0x00
};

static const unsigned char VIRTUALBOXVMM_PATTERN[] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x42,
    0x6F, 0x78, 0x20, 0x56, 0x4D, 0x4D, 0x20, 0x44,
    0x65, 0x76, 0x69, 0x63, 0x65, 0x0A, 0x00
};

static const unsigned char CFGSTRINGS_PATTERN[] = {
    0x50, 0x61, 0x72, 0x61, 0x6C, 0x6C, 0x65, 0x6C,
    0x30, 0x49, 0x72, 0x71, 0x00, 0x50, 0x61, 0x72,
    0x61, 0x6C, 0x6C, 0x65, 0x6C, 0x31, 0x49, 0x72,
    0x71, 0x00, 0x00
};

/*static const unsigned char CDROMVBOX_PATTERN[] = {
    0x31, 0x2E, 0x30, 0x00, 0x43, 0x44, 0x2D, 0x52,
    0x4F, 0x4D, 0x00, 0x00, 0x56, 0x42, 0x4F, 0x58,
    0x00
};*/

static const unsigned char PCI80EE_PATTERN[] = {
    0xB8, 0xEE, 0x80, 0x00, 0x00
};

static const unsigned char PCIBEEF_PATTERN[] = {
    0xB8, 0xEF, 0xBE, 0x00, 0x00
};

static const unsigned char PCICAFE_PATTERN[] = {
    0xB8, 0xFE, 0xCA, 0x00, 0x00
};

static const unsigned char HVID_PATTERN[] = {
    0xC7, 0x40, 0xE8, 0x56, 0x42, 0x6F, 0x78, 0xC7,
    0x40, 0xEC, 0x56, 0x42, 0x6F, 0x78, 0x48, 0xC7,
    0x40, 0xF0, 0x56, 0x42, 0x6F, 0x78
};

UINT ProcessVirtualBoxFile(
    _In_        LPTSTR lpszPath,
    _In_        PVOID *OutputBuffer,
    _Inout_opt_ DWORD *OutputBufferSize
);
