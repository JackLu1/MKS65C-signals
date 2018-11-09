all : signals.c
	gcc signals.c

run : all
	./a.out

clean : a.out
	rm a.out
