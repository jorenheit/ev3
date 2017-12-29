# CC=arm-linux-gnueabi-g++
# CFLAGS=-c -Wall -O2 --std=c++14 -I/host/ev3dev_lib
# LDFLAGS=-L/host/ev3dev_lib -lev3dev
CC=g++
CFLAGS=-c -Wall -O2 --std=c++14 -I/home/joren/Dropbox/ev3/ev3dev_lib
LDFLAGS=

SOURCES=main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=test

EV3IP=192.168.1.18
UNAME=robot
PASSWD=maker
FOLDER=/home/robot

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)

upload: $(EXECUTABLE)
	./upload.sh $(PASSWD) $(EXECUTABLE) $(UNAME) $(EV3IP) $(FOLDER)


