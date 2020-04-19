main_exe : main.o base.o extras.o
	gcc -o main_exe main.o base.o extras.o

main.o : main.c
	gcc -c -o main.o main.c

base.o : base.c
	gcc -c -o base.o base.c

extras.o : extras.h
	gcc -c -o extras.o extras.c

clean :
	rm *.o main_exe
