CC = clang
LD = clang
CFLAGS = -g
LFLAGS = -lm
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

exec : $(OBJ)
	$(LD) $(LFLAGS) $^ -o $@


%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm exec $(OBJ)
