main: main.o trout.o util.o
	gcc -g $^ -o $@

%.o: %.c trout.h util.h
	gcc -g -c $< -o $@

clean:
	rm -f *.o && rm -f main
