#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <asm-generic/bug.h>
#include <linux/ktime.h>
#include <linux/slab.h>

struct head_list {
	struct head_list *next;
	ktime_t time;
};

MODULE_AUTHOR("Buhtiy Oleksandr <sasha007.h@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint repeats = 1;
module_param(repeats, uint, 0);

MODULE_PARM_DESC(repeats, "Repeat printing n times");

static struct head_list *head;

static int __init initter(void)
{
	int i = 0;
	struct head_list *previous, *curr, *node;

	pr_info("Number of repeats : %d\n", repeats);
	if (repeats == 0) {
		pr_warn("repeats == 0");
	} else if (repeats >= 5 && repeats <= 10) {
		pr_warn("5 <= repeats <= 10");
	} else if (repeats > 10) {
		BUG_ON(1);
		//pr_err("The numberOfRepeats is greater than 10");
		//return -EINVAL;
	}

	head = kmalloc(sizeof(struct head_list *), GFP_KERNEL);
	curr = head;

	for (i = 0; i < repeats; i++) {
		if (i == 3) {
			curr->next = kmalloc(0, GFP_KERNEL);
		} else {
			curr->next = kmalloc(sizeof(struct head_list *), GFP_KERNEL);
		}
		if (curr->next == NULL) {
			while (head != NULL && repeats != 0) {
				node = head;
				head = node->next;
				kfree(node);
			}
			return -ENOMEM;
		}
		curr->time = ktime_get();
		previous = curr;
		curr = curr->next;
		pr_info("Hello, world!\n");
	}
	if (repeats != 0) {
		kfree(previous->next);
		previous->next = NULL;
	}
	return 0;
}

static void __exit exitter(void)
{
	struct head_list *node;

	while (head != NULL && repeats != 0) {
		node = head;
		pr_debug("Current time: %lld", node->time);
		head = node->next;
		kfree(node);
	}
}

module_init(initter);
module_exit(exitter);
