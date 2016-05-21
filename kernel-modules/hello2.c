/* Linux Kernel Module - __initdata Macro */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define MY_MODULE_AUTHOR "Madhur Jain <mformadhur@gmail.com>"
#define MY_MODULE_DESC "module uses initdata macro"
#define MY_MODULE_LICENSE "GPL"


static int hello2_data __initdata = 2;

static int __init hello2_init(void) {
	printk(KERN_INFO "My Name: Loading Hello%d module - Hello World %d\n", hello2_data, hello2_data);
	return 0;
}

static void __exit hello2_exit(void) {
	printk(KERN_INFO "My Name: Exiting Hello2 module - Goodbye World 2\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

MODULE_LICENSE(MY_MODULE_LICENSE);
MODULE_AUTHOR(MY_MODULE_AUTHOR);
MODULE_DESCRIPTION(MY_MODULE_DESC);

