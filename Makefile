EXEC_SRCS = find.c exec.c builtin.c
EXEC_DIR = exec/
EXEC_SRCS := $(EXEC_SRCS:%=$(EXEC_DIR)%)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

OBJS += $(EXEC_OBJS)

PARSE_SRCS = parse.c jobs.c misc.c err.c shell_stuff.c
PARSE_DIR = parse/
PARSE_SRCS := $(PARSE_SRCS:%=$(PARSE_DIR)%)
PARSE_OBJS = $(PARSE_SRCS:.c=.o)

OBJS += $(PARSE_OBJS)

DATA_SRCS = input.c env.c
DATA_DIR = data/
DATA_SRCS := $(DATA_SRCS:%=$(DATA_DIR)%)
DATA_OBJS = $(DATA_SRCS:.c=.o)

OBJS += $(DATA_OBJS)

CFLAGS = -g -Iinc -Llibft -lft -Ilibft
CFLAGS = -g -Iinc -Ilibft

all: libft a.out

%.o: %.c
	cc -c $(CFLAGS) $^ -o $@

libft: libft/libft.a

libft/libft.a:
	make -C libft bonus

a.out : $(OBJS) main.c
	cc $^ $(CFLAGS) -Llibft -lft -o $@

echo:
	echo $(OBJS)

clean:
	-rm $(OBJS)

fclean: clean
	-rm -rf a.out*
	-make -C libft fclean

dump:
	make fclean
	tar cvf minishell.tar *
	make all
