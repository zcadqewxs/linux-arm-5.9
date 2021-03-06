// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright 2011 Freescale Semiconductor, Inc. All Rights Reserved.
 * Copyright 2011 Linaro Limited
 */
#include "devices-common.h"
#include "../common.h"

struct platform_device *__init mxc_register_gpio(char *name, int id,
	resource_size_t iobase, resource_size_t iosize, int irq, int irq_high)
{
	struct resource res[] = {
		{
			.start = iobase,
			.end = iobase + iosize - 1,
			.flags = IORESOURCE_MEM,
		}, {
			.start = irq,
			.end = irq,
			.flags = IORESOURCE_IRQ,
		}, {
			.start = irq_high,
			.end = irq_high,
			.flags = IORESOURCE_IRQ,
		},
	};
	unsigned int nres;

	nres = irq_high ? ARRAY_SIZE(res) : ARRAY_SIZE(res) - 1;
	return platform_device_register_resndata(&mxc_aips_bus, name, id, res, nres, NULL, 0);
}
