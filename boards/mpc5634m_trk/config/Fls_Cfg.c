/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

#include "Fls.h"
#include "flash.h"
#include <stdlib.h>


#if defined(CFG_MPC5634M)

/* TODO: This can actually be read from the flash instead */
const FlashType flashInfo[] = {
	/* NO RWW */

	/* Bank 0, Array 0 (LOW) */
	[0].sectCnt = 10,
	[0].bankSize = 0x80000,
	[0].regBase = 0xC3F88000UL,
	[0].sectAddr[0] = 0, 	   /* 0, B0F0, LOW  */
	[0].addrSpace[0] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 0,
	[0].sectAddr[1] = 0x04000, /* 1, B0F1, LOW */
	[0].addrSpace[1] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 1,
	[0].sectAddr[2] = 0x08000, /* 2, B0F2, LOW */
	[0].addrSpace[2] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 2,
	[0].sectAddr[3] = 0x10000, /* 3, B0F3, LOW */
	[0].addrSpace[3] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 3,
	[0].sectAddr[4] = 0x18000, /* 4, B0F4, LOW */
	[0].addrSpace[4] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 4,
	[0].sectAddr[5] = 0x1c000, /* 5, B0F5, LOW */
	[0].addrSpace[5] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 5,
	[0].sectAddr[6] = 0x20000, /* 6, B0F5, LOW */
	[0].addrSpace[6] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 6,
	[0].sectAddr[7] = 0x30000, /* 7, B0F5, LOW */
	[0].addrSpace[7] = ADDR_SPACE_SET(ADDR_SPACE_LOW) + 7,
	[0].sectAddr[8] = 0x40000, /* 6, B0F6, MID */
	[0].addrSpace[8] = ADDR_SPACE_SET(ADDR_SPACE_MID) + 0,
	[0].sectAddr[9] = 0x60000, /* 7, B0F7, MID */
	[0].addrSpace[9] = ADDR_SPACE_SET(ADDR_SPACE_MID) + 1,
	[0].sectAddr[10] = 0x80000,

	/* Bank 1, Array 1(HIGH) */
	[1].sectCnt = 4,
	[1].bankSize = 0x100000 - 0x80000,
	[1].regBase = 0xC3FB0000UL,
	[1].sectAddr[0] = 0x80000,  /* High */
	[1].addrSpace[0] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 0,
	[1].sectAddr[1] = 0xA0000,  /* High */
	[1].addrSpace[1] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 1,
	[1].sectAddr[2] = 0xC0000,  /* High */
	[1].addrSpace[2] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 2,
	[1].sectAddr[3] = 0xE0000,  /* High */
	[1].addrSpace[3] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 3,
	[1].sectAddr[4] = 0x100000, /* End, NOT a sector */

	/* Bank 1, Array 2(HIGH) */
	[2].sectCnt = 4,
	[2].bankSize = 0x180000 - 0x100000,
	[2].regBase = 0xC3FB4000UL,
	[2].sectAddr[0] = 0x100000,  /* High */
	[2].addrSpace[0] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 0,
	[2].sectAddr[1] = 0x120000,  /* High */
	[2].addrSpace[1] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 1,
	[2].sectAddr[2] = 0x140000,  /* High */
	[2].addrSpace[2] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 2,
	[2].sectAddr[3] = 0x160000,  /* High */
	[2].addrSpace[3] = ADDR_SPACE_SET(ADDR_SPACE_HIGH) + 3,
	[2].sectAddr[4] = 0x180000, /* End, NOT a sector */
};
#else
#error CPU NOT supported
#endif


const Fls_ConfigType FlsConfigSet[]=
{
  {
#if ( FLS_AC_LOAD_ON_JOB_START == STD_ON)
    .FlsAcWrite = __FLS_ERASE_RAM__,
    .FlsAcErase = __FLS_WRITE_RAM__,
#else
    .FlsAcWrite = NULL,
    .FlsAcErase = NULL,
#endif
    .FlsJobEndNotification = NULL,
    .FlsJobErrorNotification = NULL,
    .FlsInfo = flashInfo,

	.FlsMaxReadFastMode = 16,
	.FlsMaxReadNormalMode = 16,
	.FlsMaxWriteFastMode = 32,
	.FlsMaxWriteNormalMode = 32,
//    .FlsSectorList = &fls_evbSectorList[0],
//    .FlsSectorListSize = sizeof(fls_evbSectorList)/sizeof(Fls_SectorType),
//    .FlsBlockToPartitionMap = Fls_BlockToPartitionMap,
  }
};
