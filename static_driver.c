#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

dev_t mydev = MKDEV(250, 0);

static int __init static_driver_init(void)
{
	register_chrdev_region(mydev, 1, "Static driver");

	printk(KERN_INFO "Driver registered successfully\n");
	printk("Major = %d, Minor = %d\n", MAJOR(mydev), MINOR(mydev));

	return 0;
}

static void __exit static_driver_exit(void)
{
	unregister_chrdev_region(mydev, 1);
	printk(KERN_INFO "Driver removed successfully\n");
}

module_init(static_driver_init);
module_exit(static_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rakshitha S");
MODULE_DESCRIPTION("Static driver");
