CXX = g++
OPTIONS = -Wall
PROGRAM = a.out
EXEC = main.cpp

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) test4.s output.dat

$(PROGRAM): $(EXEC)
	$(CXX) $(OPTIONS) $(EXEC) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

