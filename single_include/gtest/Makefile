CC = g++
LD = g++

TARGET = test

INCLUDES = -I ./..  
INCLUDES += -I /usr/local/googletest/include/ 
INCLUDES += -I /usr/local/glog/include/
INCLUDES += -I ../

LIB = -L /usr/local/googletest/lib64/

CFLAGS = -c -g -O0 -std=c++17 -Wall

LDFLAGS = -lgtest -lpthread /usr/local/glog/lib/libglog.a

SRC_C := $(wildcard *.c)
SRC_CPP := $(wildcard *.cc)

OBJS_C=$(SRC_C:.c=.o)
OBJS_CPP=$(SRC_CPP:.cc=.o)

#$(warning $(OBJS_C))

.PHONY:all clean

all: $(TARGET)
$(TARGET): $(OBJS_C) $(OBJS_CPP)
	$(LD) $^ -o $@ $(LDFLAGS) $(LIB) 

%.o:%.c
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

%.o:%.cc
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

clean:
	rm -rf $(TARGET) $(OBJS_C) $(OBJS_CPP)

