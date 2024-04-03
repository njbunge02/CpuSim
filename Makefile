CXX = g++
OPTIONS = -Wall
PROGRAM = a.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) test1.s output.dat

$(PROGRAM): main.cpp
	$(CXX) $(OPTIONS) main.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

