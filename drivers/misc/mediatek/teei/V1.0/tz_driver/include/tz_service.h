/*
 * Copyright (c) 2015-2016 MICROTRUST Incorporated
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef TZ_SERVICE_H
#define TZ_SERVICE_H

#ifdef VFS_RDWR_SEM
extern struct semaphore VFS_rd_sem;
extern struct semaphore VFS_wr_sem;
#else
extern struct completion VFS_rd_comp;
extern struct completion VFS_wr_comp;
#endif

int wait_for_service_done(void);
int teei_service_init(void);
void set_sch_nq_cmd(void);
void set_sch_load_img_cmd(void);
long create_cmd_buff(void);
void set_fp_command(unsigned long memory_size);
void set_cancel_command(unsigned long memory_size);
/*int send_fp_command(unsigned long share_memory_size);*/
void set_keymaster_command(unsigned long memory_size);
int send_keymaster_command(unsigned long share_memory_size);
void set_gatekeeper_command(unsigned long memory_size);
int send_gatekeeper_command(unsigned long share_memory_size);

#endif /*  end of TZ_SERVICE_H */
