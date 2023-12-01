#include "utils.h"

/* */
int partition (int A[], int left, int right) {
  int pivot = A[right];
  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (A[j] <= pivot) {
      i += 1;
      swap (A, i, j);
    }
  }
  swap (A, i+1, right);
  return i+1;
}

/* */
int random_partition (int A[], int left, int right) {
  int rand_pivot = rand() % (right - left + 1) + left;
  if ((rand_pivot < left) || (rand_pivot > right)) {
    printf("error: pivot out of interval!\n");
    exit(1);
  }
  swap (A, rand_pivot, right);   
  return partition (A, left, right);
}

/* */
void quick_find (int *A, int left, int right, int k) {
  if (left <= right) {
    int pivot = random_partition (A, left, right);
    if (pivot == k) {
      printf("O elemento procurado na posição %d é %d\n", k, A[k]);     
    }
    else if (pivot > k) {
      quick_find (A, left, pivot-1, k);
    }  
    else {
      quick_find (A, pivot+1, right, k); 
    }  
  }
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  quick_find (A, 0, n-1, 4);
  print (A, n, "Partial sorted");
  return 0;
}
