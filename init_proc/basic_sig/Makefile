all: basic-sig reg-sigkill

basic-sig: basic-sig.c
	gcc -o basic-sig basic-sig.c

reg-sigkill: reg-sigkill.c
	gcc -o reg-sigkill reg-sigkill.c

clean:
	rm -f *.o basic-sig reg-sigkill
