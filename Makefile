all: BSTDemo

BSTDemo: BSTree.o BSTDemo.o
	cc -o $@ $^

BSTree.o: BSTree.c BSTree.h
	cc -c $(CFLAGS) BSTree.c

BSTDemo.o: BSTDemo.c BSTree.h
	cc -c $(CFLAGS) BSTDemo.c

clean:
	rm -f *.o BSTDemo

demo: BSTDemo
	./BSTDemo

