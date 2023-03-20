CC := /opt/rh/devtoolset-9/root/bin/gcc
GDB := gdb
CFLAGS :=-g
INCLUDE:=-I/usr/local/include
LD_LIBRARY_PATH=-L/usr/local/lib/vpp
LDFLAGS=-lvppinfra

test_vec:test_vec.o
  $(CC) $(LD_LIBRARY_PATH) $(LDFLAGS) test_vec.o -o test_vec
  
test_vec.o:tes_vec.h
  $(CC) $(INCLUDE) $(CFLAGS) -c test_vec.c
  
  
  .PHONY:clean
  clean:
    rm -rf *.o test_vec
