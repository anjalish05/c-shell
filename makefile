all:
	gcc -c -o display.o display.c
	gcc -c -o pwd.o pwd.c
	gcc -c -o echo.o echo.c
	gcc -c -o cd.o cd.c
	# gcc -c -o history.o history.c
	gcc -c -o main.o main.c
	gcc -o shell main.o display.o pwd.o echo.o cd.o  
	rm -rf *.o