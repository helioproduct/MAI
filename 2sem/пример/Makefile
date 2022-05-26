CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

RELEASE_DIR  = .
RELEASE_FILE = compdb

db_obj     = db/clause.o db/io.o db/iterator.o db/table.o db/tuple.o
common_obj = structure.o

all: execute generate print input

execute:  $(db_obj) $(common_obj) printers.h execute.o
	@echo "Building 'execute'..."
	$(CC) $^ -o $@

generate: $(db_obj) $(common_obj) adders.o generate.o
	@echo "Building 'generate'..."
	$(CC) $^ -o $@

print:    $(db_obj) $(common_obj) printers.h print.o
	@echo "Building 'print'..."
	$(CC) $^ -o $@

input:  $(db_obj) $(common_obj) adders.o input.o
	@echo "Building 'input'..."
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o db/*.o

cleanall:
	rm -f execute generate print input *.o db/*.o db.bin

list:
	ls --format=single-column [Mm]akefile *.[hc] db/*.[hc]

dist:
	tar czf $(RELEASE_DIR)/$(RELEASE_FILE).tar.gz [Mm]akefile *.[hc] db/*.[hc]

