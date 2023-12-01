#include "utils.h"

/*Função para intercalar dois subvetores em um conjunto 
 ordenado. O vetor O é utilizado como memória auxiliar. */
int merge (int A[], int l, int m, int r, int O[], int rlevel) {
  /*Inicialização dos índices com os limites A:*/	
  int i = l;
  int j = m + 1;
  int k = l;
  /*Intercalando as duas sequências:*/
  while ( (i <= m) && (j <= r) ) {
    if (A[i] <= A[j]) 
      O[k++] = A[i++];
    else 
      O[k++] = A[j++];
  }
  /*Copiando elementos não intercalados na parte esquerda de A:*/ 
  while (i <= m) { O[k++] = A[i++]; }
  /*Copiando elementos não intercalados na parte direita de A:*/ 
  while (j <= r) { O[k++] = A[j++]; }
  /*Movendo os elementos intercalados de O (vetor auxiliar) para A:*/
  for (i = l; i <= r; i++) { A[i] = O[i]; }
  partition_print (A, l, r, rlevel);
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int rlevel) {
  int i;
  for (i = 0; i < rlevel; i++) { printf("    "); }   
  int m = (l + r)/2;
  printf ("Merge-Sort (%d,%d,%d)\n", l, m, r);
  if (l < r) {
    merge_sort (A, l, m, O, rlevel+1);
    merge_sort (A, m+1, r, O, rlevel+1); 
    merge (A, l, m, r, O, rlevel+1);
  }
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

