#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/

  /*Inicializando o contador:*/
  for (i = 0; i <= range; i++) 
    C[i] = 0;
  
  /*Análise de frequência de caracteres: */
  while (!feof(f)) {
    char c;
    fscanf (f, "%c", &c);
    if (isalpha(c)) {
      c = tolower(c);
      C[c - 'a']++;
      total++;
    }
  }
  
  for (i = 0; i <= range; i++) 
    printf("%c - %d - %2.4f\n", i + 'a', C[i], (double)(C[i])/total);
  
  free (C);
}

/* */
int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

