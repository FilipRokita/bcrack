CC = clang
CFLAGS = -Wall -Wextra -g -lcrypt

SRCS = main.c file1.c file2.c
OBJS = $(SRCS:.c=.o)
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)