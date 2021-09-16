#include <linux/module.h>

int skeleton_init(void)
{
	printk("the module is now loaded \n");
	return 0;
}

void skeleton_exit(void)
{
	printk("the module is now unloaded \n");
}

module_init(skeleton_init);
module_exit(skeleton_exit);
MODULE_LICENSE("GPL");
