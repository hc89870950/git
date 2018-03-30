LDFLAGS=-lm #連結器參數 
CFLAGS=-g -Wall -O2 #編譯器參數

hello: hello.c
	gcc -E -o hello.i hello.c #拉進include檔,刪除空白,註釋
	gcc -S -o hello.s hello.i #檢查語法,轉成組合語言
	gcc -c -o hello.o hello.s #轉成二進位檔
	gcc -o hello hello.o  #鏈結


.PHONY: clean
clean:
	rm -f hello hello.o hello.s hello.i


