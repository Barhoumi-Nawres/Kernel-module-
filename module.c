#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_DESCRIPTION("kernel module");
MODULE_AUTHOR("module");
MODULE_LICENSE("GPL");

static int __init my_module_init(void)
{
    pr_debug("hello from the kernel module\n");
    return 0;
}

static void __exit my_module_exit(void)
{
    pr_debug("good bye from kernel module \n");
}

module_init(my_module_init);
module_exit(my_module_exit);
