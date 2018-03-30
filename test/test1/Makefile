SRCS = $(wildcard *.c ./sub/*.c)
FILES = $(notdir $(SRCS))
OBJS = $(patsubst %.c, %.o, $(FILES))

all:
	@echo "test start..."
	@echo $(SRCS)
	@echo $(FILES)
	@echo $(OBJS)
	@echo "test end..."

