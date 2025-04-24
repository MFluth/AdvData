INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := main.o kruskalV1.o kruskalV2.o customErrorClass.o
DEPS 		 := customErrorClass.h quick_union.h union_find.h BinomialHeap.h edge.h

.PHONY: clean all

all: binomial.o customErrorClass.o Output

clean:
	rm $(OBJS) SlayOutput

kruskalV1.o: binomial.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

kruskalV2.o: binomial.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)