CC = g++
LD = g++

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %o, $(SRCS))

TARGET = listmgt

.PHONY:all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o hw1 $^

%.o:%.c
	$(CC) -c $^

clean:
	rm -f $(OBJS) $(TARGET)