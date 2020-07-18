/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

#ifndef AUDIO_SPKPROTECT_MSG_ID_H
#define AUDIO_SPKPROTECT_MSG_ID_H

typedef enum {
	SPK_PROTECT_OPEN = 0x1,
	SPK_PROTECT_CLOSE,
	SPK_PROTECT_PREPARE,
	SPK_PROTECT_PLATMEMPARAM,
	SPK_PROTECT_DLMEMPARAM,
	SPK_PROTECT_IVMEMPARAM,
	SPK_PROTECT_HWPARAM,
	SPK_PROTECT_DLCOPY,
	SPK_PROTECT_START,
	SPK_PROTECT_STOP,
	SPK_PROTECT_SETPRAM,
	SPK_PROTECT_NEEDDATA,
	SPK_PROTTCT_PCMDUMP_ON,
	SPK_PROTTCT_PCMDUMP_OFF,
	SPK_PROTECT_PCMDUMP_OK,
	SPK_PROTECT_IRQDL,
	SPK_PROTECT_IRQUL,
	SPK_PROTECT_SPEECH_OPEN = 0x101,
	SPK_PROTECT_SPEECH_CLOSE,
	SPK_PROTECT_SPEECH_PREPARE,
	SPK_PROTECT_SPEECH_MDFEEDBACKPARAM,
	SPK_PROTECT_SPEECH_DLMEMPARAM,
	SPK_PROTECT_SPEECH_IVMEMPARAM,
	SPK_PROTECT_SPEECH_HWPARAM,
	SPK_PROTECT_SPEECH_DLCOPY,
	SPK_PROTECT_SPEECH_START,
	SPK_PROTECT_SPEECH_STOP,
	SPK_PROTECT_SPEECH_SETPRAM,
	SPK_PROTECT_SPEECH_NEEDDATA,
	SPK_PROTECT_SPEECH_IRQDL,
	SPK_PROTECT_SPEECH_IRQUL,
	SPK_PROTECT_CONFIGURE,
	SPK_PROTECT_CALIB,
	SPK_PROTECT_VAR,
} IPI_RECEIVED_SPK_PROTECTION;

#endif /* end of AUDIO_SPKPROTECT_MSG_ID_H */

