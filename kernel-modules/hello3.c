/* Linux Kernel Module - Command Line Arguments */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define MY_MODULE_AUTHOR "Madhur Jain <mformadhur@gmail.com>"
#define MY_MODULE_DESC "module accepts command line arguemnts"
#define MY_MODULE_LICENSE "GPL"

static int hello3_data __initdata = 3;
static char *name = "your name";
static char *street = "your street";
static char *city = "your city";
static unsigned long zip = 12345;

module_param(name, charp, 0);
MODULE_PARM_DESC(name, "Your Name");
module_param(street, charp, 0);
MODULE_PARM_DESC(street, "Your Street");
module_param(city, charp, 0);
MODULE_PARM_DESC(city, "Your City");
module_param(zip, ulong, 0);
MODULE_PARM_DESC(zip, "Your ZIP Code");


static int __init hello3_init(void) {
	printk(KERN_INFO "Loading Hello %d: Hello World %d\n", hello3_data, hello3_data);
	printk(KERN_INFO "==============================\n");
	printk(KERN_INFO "Name : %s\n", name);
	printk(KERN_INFO "Street : %s\n", street);
	printk(KERN_INFO "City : %s\n", city);
	printk(KERN_INFO "ZIP code : %lu\n", zip);

	return 0;
}

static void __exit hello3_exit(void) {
	printk(KERN_INFO "My Name: Exiting Hello3 module - Goodbye World 3\n");
}

module_init(hello3_init);
module_exit(hello3_exit);

MODULE_LICENSE(MY_MODULE_LICENSE);
MODULE_AUTHOR(MY_MODULE_AUTHOR);
MODULE_DESCRIPTION(MY_MODULE_DESC);

