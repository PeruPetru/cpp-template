main: main.c
	gcc -o main main.c

clean:
	rm -f main

run: main
	./main $(ARGS)
