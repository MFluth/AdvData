INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := bst.o mainbst.o
DEPS 		 := customErrorClass.h bst.h

.PHONY: clean all

all: bst.o mainbst.o

clean:
	rm $(OBJS) output

bst.o: bst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainbst.o: mainbst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<