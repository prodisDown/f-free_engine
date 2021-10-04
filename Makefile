CC ::= gcc -Wall -Wextra -Werror
LIBS ::= -lSDL2 -lGL -lGLEW
BINNAME ::= game

DEBUG_CC ::= gcc -Wall -Wextra -Werror -g
DEBUG_BINNAME ::= debug

# Directories config
build-dir ::= build/
bin-dir ::= bin/
data-dir ::= data/

FOLDERS ::= -DBIN_DIR="$(bin-dir)" -DDATA_DIR="$(data-dir)"
HEADERS ::= $(shell find ./src -type f -name *.h)
SRCS ::= $(shell find ./src -type f -name *.c)


# Do stuff

build: $(SRCS) $(HEADERS)
	$(CC) -o ./$(build-dir)/$(bin-dir)/$(BINNAME) $(SRCS) $(LIBS) $(FOLDERS)

debug:
	$(DEBUG_CC) -o "./$(build-dir)/$(bin-dir)/$(DEBUG_BINNAME)" $(SRCS) $(LIBS) $(FOLDERS)

clean:
	rm $(BINNAME)
