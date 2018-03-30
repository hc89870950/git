FNAME = myapp
CC = gcc                             #C compiler
OBJS = main.o hello.o hello2.o bmi.o #
#--------------------------------------------------------------------------

$(FNAME): $(OBJS)
	$(CC) -o $@ $(OBJS)
#%.o: %.c head.h
#	$(CC) -c $< 


main.o: hello.c hello2.c bmi.c head.h

hello.o: hello.c

hello2.o: hello2.c

bmi.o: bmi.c

.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS)
	echo ${1}
