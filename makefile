CC = gcc
SRCS = lexer.c parser.c main.c
TARGET = parser

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean :
	rm -f $(TARGET)