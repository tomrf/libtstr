NAME = libtstr.so.0.1
CFLAGS = -fpic -Wall -ggdb
LDFLAGS = 

CC = gcc

OBJS = debug.o wrappers.o tstr_create.o tstr_free.o tstr_strlen.o \
       tstr_vaprintf.o tstr_resize.o tstr_string.o tstr_sprintf.o \
       tstr_copy.o tstr_strcmp.o tstr_strreplace.o tstr_chr.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) -shared -Wl,-soname,libtstr.so.0 $^ -o $@

test.o: test.c
	$(CC) -Wall -c $^ -o $@
test: test.o
	$(CC) $^ $(NAME) -o $@
	
clean:
	rm -f *.o $(NAME) test
