CC = clang
LD = clang
CFLAGS =
LFLAGS = 
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

exec : $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@


%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm exec $(OBJ)
