INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := geneBank.o mainSamples.o
DEPS 		 := customErrorClass.h geneBank.h

.PHONY: clean all

all: geneBank.o mainSamples.o customErrorClass.o Output

clean:
	rm $(OBJS) SlayOutput

geneBank.o: geneBank.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainSamples.o: mainSamples.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)