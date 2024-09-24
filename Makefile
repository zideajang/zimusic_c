CC = gcc
CFLAGS += -I$(CURDIR)/raylib/include 
CFLAGS += -I$(CURDIR)/include

LDFLAGS += -L$(CURDIR)/raylib/lib 
LDLIBS += -lraylib 
LDLIBS += -lm -lwinmm -lgdi32

OBJ_DIR = obj
TARGET = prog.exe

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# all:
# 	@echo $(OBJS)
prog.exe: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS) 

# gcc -c src/main.c -o obj/main.o -Iraylib/include -Iinclude
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@



# CFLAGS += -std=c11

# LDLIBS += -mwindows 

# main.exe: $(OBJS)
# 	$(CC)  $^ -o main.exe $(CFLAGS) $(LDFLAGS) $(LDLIBS) 



# .PHONY: run clean

# run: main.exe
# 	$<

# clean:
# 	del *.exe *.o

