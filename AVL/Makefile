INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := mainavl.o avl.o customErrorClass.o
DEPS 		 := customErrorClass.h avl.h

.PHONY: clean all

all: mainavl.o avl.o customErrorClass.o output

clean:
	rm $(OBJS) output

mainavl.o: mainavl.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

avl.o: avl.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)