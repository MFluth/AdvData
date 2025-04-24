INCLUDE_DIRS := folder
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := main.o AVLTree.o DSWTree.o Intersection.o TrafficNetwork.o UnionFind.o customErrorClass.o
DEPS 		 := customErrorClass.h AVLTree.h DSWTree.h Intersection.h TrafficNetwork.h UnionFind.h

.PHONY: clean all

all: main.o AVLTree.o DSWTree.o Intersection.o TrafficNetwork.o UnionFind.o customErrorClass.o Output

clean:
	rm $(OBJS) SlayOutput

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

AVLTree.o: AVLTree.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

DSWTree.o: DSWTree.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Intersection.o: Intersection.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

TrafficNetwork.o: TrafficNetwork.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

UnionFind.o: UnionFind.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)