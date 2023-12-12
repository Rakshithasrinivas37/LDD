#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>

dev_t mydev;

struct cdev my_cdev;


struct class *my_class;
struct device *my_device;

int file_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int file_release(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t file_read(struct file *filp, char __user *buff, size_t count, loff_t *offset)
{
	return 0;
}

ssize_t file_write(struct file *filp, const char __user *buff, size_t count, loff_t *offset)
{
	return 0;
}

struct file_operations my_fops =
{
	.owner   = THIS_MODULE,
	.open    = file_open,
	.release = file_release,
	.read    = file_read,
	.write   = file_write
};

static int __init dynamic_driver_init(void)
{
	alloc_chrdev_region(&mydev, 0, 1, "Dynamic driver");

	printk(KERN_INFO "Driver registered successfully\n");
	printk("Major = %d, Minor = %d\n", MAJOR(mydev), MINOR(mydev));

	cdev_init(&my_cdev, &my_fops);
	cdev_add(&my_cdev, mydev, 1);

	my_class = class_create(THIS_MODULE, "My_class");
	my_device = device_create(my_class, NULL, mydev, NULL, "My_device");

	return 0;
}

static void __exit dynamic_driver_exit(void)
{
	device_destroy(my_class, mydev);
	class_destroy(my_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(mydev, 1);
	printk(KERN_INFO "Driver removed successfully\n");
}

module_init(dynamic_driver_init);
module_exit(dynamic_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rakshitha S");
MODULE_DESCRIPTION("dynamic driver");