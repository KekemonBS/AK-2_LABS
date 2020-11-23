#include <linux/init.h>
#include <linux/module.h>

#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Buhtiy Oleksandr <sasha007.h@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");


static uint repeats = 1;
module_param(repeats, uint, 0);

MODULE_PARM_DESC(repeats, "Repeat printing n times");

static int __init initter(void)
{
  int i = 0;

  printk(KERN_INFO "Number of repeats : %d\n", repeats);

  if(repeats == 0) {
    printk(KERN_WARNING "repeats == 0");
    
  }else if(repeats >=5 && repeats <= 10) {
    printk(KERN_WARNING "5 <= repeats <= 10");
    
  } else if(repeats > 10) {
    printk(KERN_ERR "The numberOfRepeats is greater than 10");
    
    return -EINVAL;
  }

  for(i = 0; i < repeats; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);
