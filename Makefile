CC = cc -Wall
LIBS = -lSDL2 -lGL -lGLEW

BINNAME = start

HEADERS = $(shell find ./src -type f -name *.h)
SRCS = $(shell find ./src -type f -name *.c)

$(BINNAME): $(SRCS) $(HEADERS)
	$(CC) -o $@ $(SRCS) $(LIBS)

clean:
	rm $(BINNAME)
