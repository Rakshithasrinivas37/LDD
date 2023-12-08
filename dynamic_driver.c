#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

dev_t mydev;

static int __init dynamic_driver_init(void)
{
	alloc_chrdev_region(&mydev, 0, 1, "Dynamic driver");

	printk(KERN_INFO "Driver registered successfully\n");
	printk("Major = %d, Minor = %d\n", MAJOR(mydev), MINOR(mydev));

	return 0;
}

static void __exit dynamic_driver_exit(void)
{
	unregister_chrdev_region(mydev, 1);
	printk(KERN_INFO "Driver removed successfully\n");
}

module_init(dynamic_driver_init);
module_exit(dynamic_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rakshitha S");
MODULE_DESCRIPTION("dynamic driver");
