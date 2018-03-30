FNAME = myapp
CC = gcc
OBJS = testjson.o
LDFLAGS = -L../lib -ljson-c
CFLAGS += -I../include/json-c

#------------------------------------------------

$(FNAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(CFLAGS)

%.o: %.c $(CFLAGS)/%.h
	$(CC) -c $< -I $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS)

