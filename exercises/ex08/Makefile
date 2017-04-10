CC=gcc
PROGRAM=word_count
FLAGS=-Wall `pkg-config --cflags --libs glib-2.0`
VALGRIND=for_valgrind

$(PROGRAM): $(PROGRAM).c
	$(CC) $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	rm -f ./$(PROGRAM)

.PHONY: valgrind
valgrind:
	$(CC) $(PROGRAM).c -o $(VALGRIND) $(FLAGS) -g && \
	valgrind --leak-check=full ./$(VALGRIND)
