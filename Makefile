# This Makefile is configured for building under Linux (using MinGW-w64).
# If you do not use Linux, you can rewrite CC inside "win32" and "win64" targets into your own
# (in example, just "gcc") ;)

CC=gcc
SOURCE=KeyGotta.c
OUT=KeyGotta.exe
CCFLAGS=-O2 -Wl,-s -static

all: win32 win64

keygotta:
	$(CC) $(SOURCE) $(CCFLAGS) -o $(OUT)

win32:
	make keygotta CC=i686-w64-mingw32-gcc OUT=KeyGotta.exe

win64:
	make keygotta CC=x86_64-w64-mingw32-gcc OUT=KeyGotta64.exe

.PHONY: all keygotta win32 win64
