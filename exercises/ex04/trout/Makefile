# main: trout.h main.c trout.c util.c
# 	gcc -g -o main main.c trout.c util.c

main: main.o trout.o util.o
	gcc -g $^ -o $@

main.o: main.c trout.h util.h
	gcc -g -c $< -o $@

trout.o: trout.c trout.h util.h
	gcc -g -c $< -o $@

util.o: util.c util.h
	gcc -g -c $< -o $@

clean:
	rm -f *.o && rm -f main
