  #include <stdio.h>

  void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void heapify(int arr[], int n, int i) {
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[large])
      large = left;

    if (right < n && arr[right] > arr[large])
      large = right;

    if (large != i) {
      swap(&arr[i], &arr[large]);
      heapify(arr, n, large);
    }
  }


  void heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

     heapify(arr, i, 0);
    }
  }


  void printarr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }


  int main() {
    int arr[] = {11, 2, 8, 55, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap(arr, n);

    printf("Sorted array is \n");
    printarr(arr, n);
  }
