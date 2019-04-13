/*
 * Nikolay Nikolov
 * 04/13/2019
 * ECE 373
 *
 * BASED ON THE WORK OF PJ WASKIEWICZ
 * and the Linux Device Drivers book by John Madieu Ch.2 p21
 * and The Linux Kernel Module Programming Guide Chapter 2. Hello World
 *http://tldp.org/LDP/lkmpg/2.6/html/x181.html

 * For a module to be operational , you should load it into the kernel,
 * either by using insmod given the module path as an argument or using modprobe
 *
 * E.g. insmod /path/to/mydrv.ko
 *
 * __ init and __exit are kernel macros defined in include/linux/init.h
 * the init keyword tells the linker to place the code in a dedicated 
 * section into the kernel object file.
 * This section is known in advance to the kernel and freed when the module
 * is loaded. Only applies to build-in drivers. 
 */ 

#include<linux/module.h>
#include<linux/types.h>
#include<linux/init.h>

static int  __init hello_init(void)
{

  printk(KERN_INFO "Hello, Kernel! \n");

  return 0;

}

static void __exit hello_exit(void)
{
  printk(KERN_INFO "Goodbye kernel! \n");

}

MODULE_AUTHOR("NIK NIKOLOV");
MODULE_LICENSE("GPL");
MODULE_VERSION("9000");

module_init(hello_init);
module_exit(hello_exit);


