all: libminmax.so libfileread.so test init

libfileread.so: fileread.c
	gcc -Wall -c fileread.c -fPIC 
	gcc -shared fileread.o -o libfileread.so
	ar rcs libfileread.a fileread.o

libminmax.so: minmax.c
	gcc -Wall -c minmax.c -fPIC -g
	gcc -shared minmax.o -o libminmax.so
	ar rcs libminmax.a minmax.o


test: test.c
	gcc -Wall test.c -o test -lfileread -L. -lminmax -I. -ljansson

init: init.c
	gcc -Wall init.c -o init

clean:
	rm -rf *.o *.so *.a test test_static init
