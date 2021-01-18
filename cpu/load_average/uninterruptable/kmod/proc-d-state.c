#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/version.h>
#define BUFSIZE  100

MODULE_LICENSE("GPL");

static struct proc_dir_entry *ent;

static ssize_t mywrite(struct file *file, const char __user * ubuf,
		       size_t count, loff_t * ppos)
{
	printk(KERN_DEBUG "write handler\n");
	return 0;
}

static ssize_t myread(struct file *file, char __user * ubuf, size_t count,
		      loff_t * ppos)
{
	printk(KERN_DEBUG "read handler\n");
	/* The process is in UNINTERRUPTIBLE state */
	msleep(300000);
	printk(KERN_DEBUG "read exit\n");
	return 0;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
static struct proc_ops myops = {
        .proc_read     = myread,
        .proc_write    = mywrite,
};
#else
static struct file_operations myops = {
	.owner = THIS_MODULE,
	.read = myread,
	.write = mywrite,
};
#endif

static int simple_init(void)
{
	ent = proc_create("mydev", 0660, NULL, &myops);
	return 0;
}

static void simple_cleanup(void)
{
	proc_remove(ent);
}

module_init(simple_init);
module_exit(simple_cleanup);
