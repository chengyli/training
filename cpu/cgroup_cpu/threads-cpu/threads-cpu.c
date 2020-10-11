#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *doSomeThing(void *arg)
{
	static unsigned long i = 0;
	pthread_t id = pthread_self();

	printf("Thread%d, %x\n", i++, id);
	while (1) {
		int sum;
		sum += 1;
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	int i;
	int total;
	pthread_attr_t tattr;
	int err;
	int stack_size = (20 * 1024 * 1024);

	if (argc < 2) {
		total = 1;
	} else {
		total = atoi(argv[1]);
	}

	err = pthread_attr_init(&tattr);
	if (err != 0) {
		printf("pthread_attr_init err\n");
	}

	err = pthread_attr_setstacksize(&tattr, stack_size);
	if (err != 0) {
		printf("Set stack to %d\n", stack_size);
	}

	printf("To create %d threads\n", total);

	for (i = 0; i < total; i++) {
		pthread_t tid;
		err = pthread_create(&tid, &tattr, &doSomeThing, NULL);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		else
			printf("\nThread %d created successfully\n", i);

	}

	usleep(1000000);
	printf("All threads are created\n");
	usleep(1000000000);

	return EXIT_SUCCESS;
}
