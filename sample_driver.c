#include<linux/module.h>

static int __init sample_init(void)
{
	pr_info("Hello world\n");
	return 0;
}

static void __exit sample_exit(void)
{
	pr_info("Bye world\n");
}

module_init(sample_init);
module_exit(sample_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rakshitha");

