/*
 * a simple char device driver: globalfifo
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/module.h>
#include <linux/platform_device.h>

static struct platform_device globalfifo_pdev = { 
        .name           = "globalfifo",
        .id             = -1,
};

static int __init globalfifodev_init(void)
{
	return platform_device_register(&globalfifo_pdev);
}
module_init(globalfifodev_init);

static void __exit globalfifodev_exit(void)
{
	platform_device_unregister(&globalfifo_pdev);
}
module_exit(globalfifodev_exit);

MODULE_AUTHOR("Barry Song <baohua@kernel.org>");
MODULE_LICENSE("GPL v2");
