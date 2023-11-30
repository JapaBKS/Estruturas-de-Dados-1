all:
	gcc -o insertion insertion.c utils.c
	gcc -o insertion-rec insertion-rec.c utils.c
	gcc -o ruido ruido.c utils.c 
clean:
	rm insertion insertion-rec ruido
