EXEC_SRCS = find.c
EXEC_DIR = exec/
EXEC_SRCS := $(EXEC_SRCS:%=$(EXEC_DIR)%)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

OBJS += $(EXEC_OBJS)

CFLAGS = -g -Iinc -Llibft -lft -Ilibft

all: libft a.out

libft: libft/libft.a

libft/libft.a:
	make -C libft bonus

a.out : $(OBJS) main.c
	cc $^ $(CFLAGS)  -o $@

echo:
	echo $(OBJS)
