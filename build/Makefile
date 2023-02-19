#
# Makefile for the udputil -tool.
#
		 
INCLUDE_PLATH		= -I../src/
CFLAGS			= -g -Wall -std=gnu99
CC			= gcc

all:	udputil

udputil: udputil.o
	$(CC) -o ../bin/udputil.exe $< $(INCLUDE_PATH) 

udputil.o: ../src/udputil.c ../src/udputil.h
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

test:	all
	../bin/udputil.exe -t
help:
	@echo ""
	@echo "   Makefile options"
	@echo "   ------------------------------------------------"
	@echo ""
	@echo "   make help     - print this text"
	@echo "   make <all>    - build udputil"
	@echo "   make test     - build all and run some tests"	
	@echo "   make clean    - delete generated files"	
	@echo ""

clean:
	-rm -f *.o ../bin/udputil.exe

