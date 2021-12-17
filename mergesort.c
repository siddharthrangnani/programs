
#include <stdio.h>

void join(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void joinSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    joinSort(arr, l, m);
    joinSort(arr, m + 1, r);

    join(arr, l, m, r);
  }
}

void parr(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {69, 5, 112, 0, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  joinSort(arr, 0, size - 1);

  printf(" array: \n");
  parr(arr, size);
}
