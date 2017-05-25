CC = clang
LD = clang
DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS=-g -Wall -Wextra -I$(DIRSDL)/include -I$(DIRSDL)/include/SDL -I/usr/local/include -I/usr/local/include/SDL -I/usr/include/SDL
LDFLAGS=-L$(DIRSDL)/lib -lm -libm.a -lSDL -lSDL_ttf -lSDL_sound -lSDL_phelma -lSDL_image  -lSDL_draw -lX11
TST = $(wildcard src/[a-nq-z]*.c)
SRC = $(wildcard src/[a-su-z]*.c src/tsp.c)
OBJ = $(SRC:.c=.o)
OBJTST = $(TST:.c=.o)
all : test exec

test : $(OBJTST)
	$(LD) $(LFLAGS) -lm $^ -o $@

exec : $(OBJ)
	$(LD) $(LFLAGS) -lm -lSDL $^ -o $@ 
%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm test exec $(OBJ)
