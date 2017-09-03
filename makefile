# make the objects
OBJECTS = main.o Autocomplete.o Term.o
# make the headers
HEADERS = Autocomplete.h Term.h

# make objects with g++
PA4: $(OBJECTS)
	g++ $^ -o PA4
# compile the header and cpp files
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
# make clean by removing object file
clean:
	rm -i *.o PA4

