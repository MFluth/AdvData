INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := main.o customErrorClass.o
DEPS 		 := customErrorClass.h hash.h

.PHONY: clean all

all: customErrorClass.o Output

clean:
	rm $(OBJS) SlayOutput

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)