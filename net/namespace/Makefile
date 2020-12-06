all: clone-ns unshare-ns

clone-ns: clone-ns.c
	gcc -o clone-ns clone-ns.c

unshare-ns: unshare-ns.c
	gcc -o unshare-ns unshare-ns.c

clean:
	rm -f *.o clone-ns unshare-ns
