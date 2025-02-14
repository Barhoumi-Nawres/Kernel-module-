# Kernel-module-
kernel module 
# steps :
Sources (https://gitlab.cs.pub.ro/so2/so2-labs)

-install docker on ubunuu (container runtime)to isolate the userspace 

-clone this repostory (https://gitlab.cs.pub.ro/so2/so2-labs.git)

-run this command (sudo ./local.sh docker interactive --privileged)

-LABS=kernel_modules make skels

-make console

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

MODULE_DESCRIPTION("TechLeef hello module");
MODULE_AUTHOR("TechLeef");
MODULE_LICENSE("GPL");

static int __init techleef_init(void){
    pr_debug("Hello TechLeef Module\n");
    return 0;
}

static void __exit techleef_exit(void){
    pr_debug("GoodBye from TechLeef Module\n");
}

module_init(techleef_init);
module_exit(techleef_exit);


Kbuild:

ccflags-y += -DDEBUG
obj-m = techleef.o


Makefile:

KDIR = /linux

kbuild:
    make -C $(KDIR) M=$(shell pwd)

clean:
    make -C $(KDIR) M=$(shell pwd) clean


Compile

make


You should see:

make -C /linux M=/linux/tools/labs/skels/techleef
make[1]: Entering directory '/linux'
  CC [M]  /linux/tools/labs/skels/techleef/techleef.o
  MODPOST /linux/tools/labs/skels/techleef/Module.symvers
  CC [M]  /linux/tools/labs/skels/techleef/techleef.mod.o
  LD [M]  /linux/tools/labs/skels/techleef/techleef.ko
make[1]: Leaving directory '/linux'


Go to the other terminal (same container in which you run make console to run Qemu) and load the module

cd skels/techleef
insmod techleef.ko
