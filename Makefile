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
