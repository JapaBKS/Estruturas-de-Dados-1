all:
	gcc -o merge-sort merge-sort.c utils.c -lm
	gcc -o merge-debug merge-debug.c utils.c -lm
clean:
	rm merge-sort merge-debug  
