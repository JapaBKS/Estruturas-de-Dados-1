all:
	gcc -o bubble bubble.c utils.c
	gcc -o bubble-rec bubble-rec.c utils.c
	gcc -o selection selection.c utils.c
	gcc -o selection-rec selection-rec.c utils.c
	gcc -o cocktail cocktail.c utils.c
clean:
	rm game bubble bubble-rec selection selection-rec cocktail 
