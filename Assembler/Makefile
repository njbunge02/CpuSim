CXX = g++
OPTIONS = -Wall
PROGRAM = assembler.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) test5.s output.bin

$(PROGRAM): assembler.cpp
	$(CXX) $(OPTIONS) assembler.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

