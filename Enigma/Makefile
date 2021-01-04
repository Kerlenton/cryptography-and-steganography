output: main.o enigma.o
	gcc -o enigma main.o enigma.o
	del *.o
	enigma

main.o: main.c
	gcc -c main.c
	
enigma.o: enigma.c
	gcc -c enigma.c