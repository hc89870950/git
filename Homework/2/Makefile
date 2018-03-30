FNAME = myapp
CC = gcc
OBJS = mac.o
LDFLAGS = -L../lib -ljson-c
CFLAGS += -I../include/json-c

#------------------------------------------------

$(FNAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c 
	$(CC) -c $< 

.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS)

