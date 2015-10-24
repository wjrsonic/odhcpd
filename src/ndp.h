/**
 * Copyright (C) 2012-2013 Steven Barth <steven@midlink.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#pragma once
#include "odhcpd.h"
#include <time.h>

#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

#define NDP_MAX_NEIGHBORS 1000	// 暂时不用
#define NEIGH_GC_THRESHOLD 16	// 邻居条目达到这个值就执行垃圾回收

enum {
	NEIGH_STATE_REACHABLE,
	NEIGH_STATE_STALE,
	NEIGH_STATE_INCOMPLETE
};

struct ndp_neighbor {
	struct list_head head;
	struct interface *iface;
	int state;
	struct in6_addr addr;
	uint8_t lladdr[16];
	unsigned int lladdr_len;
	//uint8_t len;
	//time_t timeout;
};
