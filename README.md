# Kernel-module-(Embedded LInux :
kernel module 
# steps :
Sources (https://gitlab.cs.pub.ro/so2/so2-labs)

-install docker on ubunuu (container runtime)to isolate the userspace 

-clone this repostory (https://gitlab.cs.pub.ro/so2/so2-labs.git)

-run this command (sudo ./local.sh docker interactive --privileged)

-LABS=kernel_modules make skels

-make console (to be in demu )


# compilation of kernel modules 

kernel:
1-compile or build tools mconf.
2-load K config 
3-you will get menuconfig (so you can active ,desactive or search for  symbols using this command (make menuconfig )


ELF relocatable =not executable

##
Create a new directory under skels (inside the container):
Create 3 files Kbuild, Makefile and techleef.c:

cd skels
mkdir techleef && cd techleef
touch Kbuild Makefile techleef.c


techleef.c:

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



Kbuild:

obj-m=techleef.o


Makefile:

KDIR = /linux


kbuild:
	make -C $(KDIR) M=$(shell pwd)

clean:
	make -C $(KDIR) M=$(shell pwd) clean 


And then run :
make

You should see:

oot@nawres:/linux/tools/labs/skels/module# make
make -C /linux M=/linux/tools/labs/skels/module
make[1]: Entering directory '/linux'
  CC [M]  /linux/tools/labs/skels/module/techleef.o
  MODPOST /linux/tools/labs/skels/module/Module.symvers
  CC [M]  /linux/tools/labs/skels/module/techleef.mod.o
  LD [M]  /linux/tools/labs/skels/module/techleef.ko
make[1]: Leaving directory '/linux


Go to the other terminal (same container in which you run make console to run Qemu) and load the module

cd skels/techleef
insmod techleef.ko
