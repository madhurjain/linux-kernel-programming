/* Linux Kernel Module - Hello World */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define MY_MODULE_AUTHOR "Madhur Jain <mformadhur@gmail.com>"
#define MY_MODULE_DESC "Hello World 1 Module"
#define MY_MODULE_LICENSE "GPL"


static int __init hello1_init(void) {
	printk(KERN_INFO "My Name: Loading Hello1 module - Hello World 1\n");
	return 0;
}

static void __exit hello1_exit(void) {
	printk(KERN_INFO "My Name: Exiting Hello1 module - Goodbye World 1\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

MODULE_LICENSE(MY_MODULE_LICENSE);
MODULE_AUTHOR(MY_MODULE_AUTHOR);
MODULE_DESCRIPTION(MY_MODULE_DESC);

