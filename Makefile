CC = g++
CFLAGS = -I.
LIB = cppunit

DEPS = Solutions.h \
	   MyUnitTests.h

OBJ = $(patsubst %.cc, %.o, $(wildcard *.cc))

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

leetcode_unit: $(OBJ)
	$(CC) -o $@ -l $(LIB) $^

.PHONY: clean

clean:
	rm -f ./*.o *~ ./*~
	rm leetcode_unit
