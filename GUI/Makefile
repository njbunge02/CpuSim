## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
CPPFLAGS = -Wall
LFLAGS = -L/System/Library/Frameworks -framework GLUT -framework OpenGL

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
        main.cpp \
        $(NULL)

all: $(PROGFILES:.cpp=)

run: $(PROGFILES:.cpp=)
	./cg03

targets default: $(TARGETS)

$(PROGFILES:.cpp=): main.o
	$(CC) -o cg03 main.o ${LFLAGS}

depend :
	makedepend ${PROGFILES}
# DO NOT DELETE
