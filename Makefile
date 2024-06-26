## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
PROGRAM = CpuSim
OBJECTS = Controllers/main.o Controllers/CPU.o Views/GUI.o Models/ALU.o Models/Instruction.o Models/Memory.o Models/Registers.o
CPPFLAGS = -Wall -g -DLINUX
LFLAGS = -lglut -L/usr/lib -L/usr/X11R6/lib -lXi -lXmu -lGL -lGLU -lm

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
        Controllers/main.cpp Controllers/CPU.cpp Views/GUI.cpp Models/ALU.cpp Models/Instruction.cpp Models/Memory.cpp Models/Registers.cpp\
        $(NULL)


all: $(PROGFILES:.cpp=)

run:
	./$(PROGRAM) Assembler/output.bin

targets default: $(TARGETS)

$(PROGFILES:.cpp=): $(OBJECTS)
	$(CC) -o CpuSim $(OBJECTS) ${LFLAGS}

depend :
	makedepend ${PROGFILES}

clean:
	rm -f $(PROGRAM) $(OBJECTS)