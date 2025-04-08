INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := mainsplay.o slay.o customErrorClass.o
DEPS 		 := customErrorClass.h splay.h

.PHONY: clean all

all: customErrorClass.o splay.o SlayOutput

clean:
	rm $(OBJS) SlayOutput

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

splay.o: splay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainsplay.o: mainsplay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

SlayOutput: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)