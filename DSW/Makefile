INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := main.o dsw.o customErrorClass.o
DEPS 		 := $(INCLUDE_DIRS)/dsw.h $(INCLUDE_DIRS)/customErrorClass.h 

.PHONY: clean all

all: dsw.o customErrorClass.o main.o output

clean:
	rm $(OBJS) output

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

dsw.o: dsw.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)