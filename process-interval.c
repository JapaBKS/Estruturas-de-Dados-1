#include "utils.h"

/* */
int* process_interval (int *A, int n, int range) {
  int i, j;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/

  /*Inicializando o contador:*/
  for (i = 0; i <= range; i++) 
    C[i] = 0;
  
  /*Contagem de valores: */
  for (j = 0; j < n; j++) 
    C[A[j]] = C[A[j]] + 1;
  
  print (C, range, "Contagem: ");
  
  /*Soma acumulada: */
  for (i = 1; i <= range; i++) 
    C[i] = C[i] + C[i-1];
  
  print (C, range, "Soma acumulada: ");
 
  return C; 
}

int query (int *C, int n, int i, int j) {
  if ( (i < 0) || (i > n) || (j < 0) || (j > n) || (i > j) ) {
    printf("Intervalo incorreto %d > %d\n", i, j);
    exit(1);
  }
  else if (i != 0) {
    return C[j] - C[i-1];    
  }
  else {
    return C[j];    
  }
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

