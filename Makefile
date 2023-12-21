# Make File


main: main.c drw.h
	gcc -o bin main.c

tests: test.c drw.h
	gcc -o tests test.c


clean:
	rm bin
