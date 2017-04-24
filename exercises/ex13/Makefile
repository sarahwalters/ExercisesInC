CC = gcc
CFLAGS = -g -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBS = -lglib-2.0

word_count: word_count.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: valgrind_mem_errors
valgrind_mem_errors:
	$(CC) mem_errors.c -o for_valgrind_mem_errors $(CFLAGS) -g && \
	valgrind --leak-check=full ./for_valgrind_mem_errors

.PHONY: valgrind_list_errors
valgrind_list_errors:
	$(CC) list_errors.c -o for_valgrind_list_errors $(CFLAGS) -g && \
	valgrind --leak-check=full ./for_valgrind_list_errors
