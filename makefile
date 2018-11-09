all : signals.c
	gcc signals.c

run : all
	./a.out
