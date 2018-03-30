FNAME = myapp
CC = gcc                             #C compiler
OBJS = main.o height.o weight.o bmi.o #
#--------------------------------------------------------------------------

$(FNAME): $(OBJS)
	$(CC) -o $@ $(OBJS)
#%.o: %.c
#	$(CC) -c $<



main.o: height.c weight.c bmi.c head.h

height.o: height.c

weight.o: weight.c

bmi.o: bmi.c


.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS) libstatic.a libshared.so.1.0.0 libshared.so.1 libshared.so
