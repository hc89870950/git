FNAME = myapp
CC = gcc
OBJS = testxml.o
LDFLAGS = -L../lib/ -lxml2
CFLAGS += -I../include
#------------------------------------------------

$(FNAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(CFLAGS)

%.o: %.c $(CFLAGS)/%.h
	$(CC) -c $< -I $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(FNAME) $(OBJS)

