CC = clang
LD = clang
CFLAGS = -g
LFLAGS = -lm
TST = $(wildcard src/[a-nq-z]*.c)
SRC = $(wildcard src/[a-su-z]*.c)
OBJ = $(SRC:.c=.o)
OBJTST = $(TST:.c=.o)
all : test exec

test : $(OBJTST)
	$(LD) $(LFLAGS) $^ -o $@

exec : $(OBJ)
	$(LD) $(LFLAGS) $^ -o $@


%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm test exec $(OBJ)
