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

#ifndef __PORT_IPC_H__
#define __PORT_IPC_H__

#include <asm/types.h>
#include <linux/compiler.h>
#include "ccci_config.h" /* for platform override */

/* MD <-> AP Msg_id mapping enum */
typedef enum {
	IPC_L4C_MSG_ID_BEGIN = 0x80000000,
#if defined(IPC_L4C_MSG_ID_LEN)
	IPC_L4C_MSG_ID_RANGE = IPC_L4C_MSG_ID_LEN,
#else
	IPC_L4C_MSG_ID_RANGE = 0x80,
#endif
	IPC_EL1_MSG_ID_BEGIN = IPC_L4C_MSG_ID_BEGIN + IPC_L4C_MSG_ID_RANGE,
	IPC_EL1_MSG_ID_RANGE = 0x20,
	IPC_CCCIIPC_MSG_ID_BEGIN = IPC_EL1_MSG_ID_BEGIN + IPC_EL1_MSG_ID_RANGE,
	IPC_CCCIIPC_MSG_ID_RANGE = 0x10,
	IPC_IPCORE_MSG_ID_BEGIN = IPC_CCCIIPC_MSG_ID_BEGIN + IPC_CCCIIPC_MSG_ID_RANGE,
	IPC_IPCORE_MSG_ID_RANGE = 0x8,
	IPC_MDT_MSG_ID_BEGIN = IPC_IPCORE_MSG_ID_BEGIN + IPC_IPCORE_MSG_ID_RANGE,
	IPC_MDT_MSG_ID_RANGE = 0x8,
	IPC_UFPM_MSG_ID_BEGIN = IPC_MDT_MSG_ID_BEGIN + IPC_MDT_MSG_ID_RANGE,
	IPC_UFPM_MSG_ID_RANGE = 0x18,
} CCCI_IPC_MSG_ID_RANGE;

typedef struct local_para {
	u8 ref_count;
	u8 _stub; /* MD complier will align ref_count to 16bit */
	u16 msg_len;
	u8 data[0];
} __packed local_para_struct;

typedef struct peer_buff {
	u16 pdu_len;
	u8 ref_count;
	u8 pb_resvered;
	u16 free_header_space;
	u16 free_tail_space;
	u8 data[0];
} __packed peer_buff_struct;

typedef struct {
	u32 src_mod_id;
	u32 dest_mod_id;
	u32 sap_id;
	u32 msg_id;
	struct local_para *local_para_ptr;
	struct peer_buff *peer_buff_ptr;
} ipc_ilm_t; /* for conn_md */

struct ccci_emi_info {
	u8 ap_domain_id;
	u8 md_domain_id;
	u8 reserve[6];
	u64 ap_view_bank0_base;
	u64 bank0_size;
	u64 ap_view_bank4_base;
	u64 bank4_size;
} __packed; /* for USB direct tethering */

/* export API */
int ccci_ipc_send_ilm(int md_id, ipc_ilm_t *in_ilm);
int ccci_get_emi_info(int md_id, struct ccci_emi_info *emi_info);

/* external API */
#if defined(CONFIG_MTK_MD_DIRECT_TETHERING_SUPPORT) || defined(CONFIG_MTK_MD_DIRECT_LOGGING_SUPPORT)
extern int rndis_md_msg_hdlr(ipc_ilm_t *ilm);
#endif
#if defined(CONFIG_MTK_MD_DIRECT_TETHERING_SUPPORT)
extern int pkt_track_md_msg_hdlr(ipc_ilm_t *ilm);
#endif

#endif				/* __PORT_IPC_H__ */
