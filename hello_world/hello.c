#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SComp25TP4");
MODULE_DESCRIPTION("A simple Hello World kernel module");
MODULE_VERSION("1.0");

static int hello_init(void)
{
    printk(KERN_INFO "Hello, Puntos Flotantes!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "Goodbye, Puntos Flotantes!\n");
}

module_init(hello_init);
module_exit(hello_exit);