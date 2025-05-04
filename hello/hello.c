#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static  int __init hello_start(void){

printk(KERN_INFO "hello module-nawres\n");
return 0;

}
 
static void __exit hello_end(void){
printk(KERN_INFO "goodbye module-nawres\n");
}


MODULE_AUTHOR("nawres");
MODULE_DESCRIPTION("a simple linux kernel module");
MODULE_LICENSE("GPL");

module_init(hello_start);
module_exit(hello_end);
