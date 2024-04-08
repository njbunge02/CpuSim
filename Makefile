## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
PROGRAM = CpuSim
OBJECTS = Controllers/main.o Views/GUI.o
CPPFLAGS = -Wall
LFLAGS = -L/System/Library/Frameworks -framework GLUT -framework OpenGL

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
        Controllers/main.cpp Views/GUI.cpp\
        $(NULL)


all: $(PROGFILES:.cpp=)

run:
	./$(PROGRAM)

targets default: $(TARGETS)

$(PROGFILES:.cpp=): $(OBJECTS)
	$(CC) -o CpuSim $(OBJECTS) ${LFLAGS}

depend :
	makedepend ${PROGFILES}

clean:
	rm -f $(PROGRAM) $(OBJECTS)

