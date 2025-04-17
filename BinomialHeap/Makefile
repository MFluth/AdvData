INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := main.o binomial.o customErrorClass.o
DEPS 		 := customErrorClass.h binomial.h

.PHONY: clean all

all: binomial.o customErrorClass.o Output

clean:
	rm $(OBJS) SlayOutput

binomial.o: binomial.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)