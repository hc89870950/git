FNAME = myapp
CC = gcc                             #C compiler
OBJS = height.o weight.o bmi.o #
#--------------------------------------------------------------------------

#$(FNAME): $(OBJS)
#	$(CC) -o $@ $(OBJS)
#%.o: %.c
#	$(CC) -c $<



#main.o: height.c weight.c bmi.c head.h

height.o: height.c
	$(CC) -c $<

weight.o: weight.c
	$(CC) -c $<

bmi.o: bmi.c
	$(CC) -c $<


.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS) libstatic.a
