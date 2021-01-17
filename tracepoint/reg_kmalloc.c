#include <linux/module.h>
#include <trace/events/kmem.h>

static void probe_kmalloc(void *ignore, unsigned long call_site, const void *ptr,
                 size_t bytes_req, size_t bytes_alloc, gfp_t gfp_flags)
{
	printk("probe_kmalloc, bytes_alloc: %ld\n", bytes_alloc);
}

static int __init tp_sample_trace_init(void)
{
	int ret;

	ret = register_trace_kmalloc(probe_kmalloc, NULL);
	WARN_ON(ret);

	return 0;
}


static void __exit tp_sample_trace_exit(void)
{
	unregister_trace_kmalloc(probe_kmalloc, NULL);
	tracepoint_synchronize_unregister();
}

module_init(tp_sample_trace_init);
module_exit(tp_sample_trace_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Tracepoint Probes Samples");
