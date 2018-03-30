FNAME = staticapp sharedapp
CC = gcc
OBJS = height.o weight.o bmi.o
LIBDIR = /mnt/sdb1/home/nelson_tang/Homework/3/all/lib/
HDIR = /mnt/sdb1/home/nelson_tang/Homework/3/all/hfile/
HFILE = head.h

all : staticapp sharedapp
#static-------------------------------------------------------------------------

staticapp: libstatic.a main.o
	$(CC) -o staticapp main.o -L$(LIBDIR) -lstatic

libstatic.a: $(OBJS)
	ar rcs $(LIBDIR)libstatic.a $(OBJS)

%.o: %.c $(HDIR)$(HFILE)
	$(CC) -c $< -I$(HDIR)
#shared--------------------------------

sharedapp: libshared.so.1 main.o
	$(CC) -o sharedapp main.o -L$(LIBDIR) -lshared

libshared.so.1: libshared.so
	ln -s $(LIBDIR)libshared.so.1.0.0 $(LIBDIR)libshared.so.1

libshared.so: libshared.so.1.0.0
	ln -s $(LIBDIR)libshared.so.1.0.0 $(LIBDIR)libshared.so

libshared.so.1.0.0: $(OBJS)
	$(CC) -shared -Wl,-soname,libshared.so.1 -o $(LIBDIR)libshared.so.1.0.0 $(OBJS)

%.o: %.c $(HDIR)$(HFILE)
	$(CC) -c -fPIC $< -I$(HDIR)

#---------------------------------------------

.PHONY: clean
clean:
	rm -f $(FNAME) *.o $(LIBDIR)libstatic.a $(LIBDIR)libshared.*
