ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
   TARGET = functions.exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
      TARGET = functions
   endif
endif

SOURCES = main.c help.c root.c integral.c
HEADERS = help.h root.h integral.h
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS=-Wall
REBUILDABLES = $(OBJECTS) $(TARGET)

default: $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	$(RM) $(REBUILDABLES)
	$(info Clean done)
