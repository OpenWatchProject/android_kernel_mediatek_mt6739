/*************************************************************************/ /*!
@File
@Title          RGX debug header file
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Header for the RGX debugging functions
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/

#if !defined(__RGXDEBUG_H__)
#define __RGXDEBUG_H__

#include "pvrsrv_error.h"
#include "img_types.h"
#include "device.h"
#include "pvr_notifier.h"
#include "pvrsrv.h"
#include "rgxdevice.h"


/**
 * Debug utility macro for printing FW IRQ count and Last sampled IRQ count in 
 * LISR for each RGX FW thread.
 * Macro takes pointer to PVRSRV_RGXDEV_INFO as input.
 */
#define RGXDEBUG_PRINT_IRQ_COUNT(psRgxDevInfo) \
	do \
	{ \
		IMG_UINT32 ui32TID; \
		for (ui32TID = 0; ui32TID < RGXFW_THREAD_NUM; ui32TID++) \
		{ \
			PVR_DPF((DBGPRIV_VERBOSE, \
					"RGX FW thread %u: FW IRQ count = %u, Last sampled IRQ count in LISR = %u)", \
					ui32TID, \
					(psRgxDevInfo)->psRGXFWIfTraceBuf->aui32InterruptCount[ui32TID], \
					(psRgxDevInfo)->aui32SampleIRQCount[ui32TID])); \
		} \
	} while(0)

/*!
*******************************************************************************

 @Function	RGXPanic

 @Description

 Called when an unrecoverable situation is detected. Dumps RGX debug
 information and tells the OS to panic.

 @Input psDevInfo - RGX device info

 @Return void

******************************************************************************/
void RGXPanic(PVRSRV_RGXDEV_INFO	*psDevInfo);

/*!
*******************************************************************************

 @Function	RGXDumpDebugInfo

 @Description

 Dump useful debugging info. Dumps lesser information than PVRSRVDebugRequest.
 Does not dump debugging information for all requester types.(SysDebug, ServerSync info)

 @Input pfnDumpDebugPrintf  - Optional replacement print function
 @Input pvDumpDebugFile     - Optional file identifier to be passed to the
                              'printf' function if required
 @Input psDevInfo           - RGX device info

 @Return   void

******************************************************************************/
void RGXDumpDebugInfo(DUMPDEBUG_PRINTF_FUNC *pfnDumpDebugPrintf,
			void *pvDumpDebugFile,
			PVRSRV_RGXDEV_INFO *psDevInfo);

/*!
*******************************************************************************

 @Function	RGXDebugRequestProcess

 @Description

 This function will print out the debug for the specificed level of
 verbosity

 @Input pfnDumpDebugPrintf  - Optional replacement print function
 @Input pvDumpDebugFile     - Optional file identifier to be passed to the
                              'printf' function if required
 @Input psDevInfo           - RGX device info
 @Input ui32VerbLevel       - Verbosity level

 @Return   void

******************************************************************************/
void RGXDebugRequestProcess(DUMPDEBUG_PRINTF_FUNC *pfnDumpDebugPrintf,
				void *pvDumpDebugFile,
				PVRSRV_RGXDEV_INFO *psDevInfo,
				IMG_UINT32 ui32VerbLevel);

/*!
*******************************************************************************

 @Function	RGXDumpFirmwareTrace

 @Description Dumps the decoded version of the firmware trace buffer.

 Dump useful debugging info

 @Input pfnDumpDebugPrintf  - Optional replacement print function
 @Input pvDumpDebugFile     - Optional file identifier to be passed to the
                              'printf' function if required
 @Input psDevInfo           - RGX device info

 @Return   void

******************************************************************************/
void RGXDumpFirmwareTrace(DUMPDEBUG_PRINTF_FUNC *pfnDumpDebugPrintf,
				void *pvDumpDebugFile,
				PVRSRV_RGXDEV_INFO  *psDevInfo);

/*!
*******************************************************************************

 @Function	RGXReadWithSP

 @Description

 Reads data from a memory location (FW memory map) using the META Slave Port

 @Input  ui32FWAddr - 32 bit FW address

 @Return IMG_UINT32
******************************************************************************/
IMG_UINT32 RGXReadWithSP(IMG_UINT32 ui32FWAddr);


#if defined(SUPPORT_EXTRA_METASP_DEBUG)
/*!
*******************************************************************************

 @Function     ValidateFWImageWithSP

 @Description  Compare the Firmware image as seen from the CPU point of view
               against the same memory area as seen from the META point of view

 @Input        psDevInfo - Device Info

 @Return       PVRSRV_ERROR
******************************************************************************/
PVRSRV_ERROR ValidateFWImageWithSP(PVRSRV_RGXDEV_INFO *psDevInfo);
#endif /* defined(SUPPORT_EXTRA_METASP_DEBUG) */

#if defined(CONFIG_MACH_MT6799)
void MTKQueryPowerState(int caller);
#endif

#endif /* __RGXDEBUG_H__ */
