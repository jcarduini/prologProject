CCPP := g++
CSOURCES := iterateSearch.cpp
OBJECTS := $(CSOURCES:.cpp=.o)
EXEC := exercicio1

all:
	$(CCPP) -c $(CSOURCES) 
	$(CCPP) -o $(EXEC) $(OBJECTS)

clean:
	rm *.o $(EXEC)
