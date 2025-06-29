#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
// 1. Selection Sort
void selectionSort(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(&a[i], &a[min]);
    }
}
// 2. Insertion Sort
void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i]; j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j]; j--;
        }
        a[j+1] = key;
    }
}
// 3. Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1, j;
    for (j = low; j < high; j++) {
        if (a[j] < pivot) swap(&a[++i], &a[j]);
    }
    swap(&a[i+1], &a[high]);
    return i + 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
// 4. Merge Sort
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, i, j, k;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    i = j = 0; k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
// 5. Heap Sort
void heapify(int a[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {10,4,5,7,9,2,1,3,6,8};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Original: ");
    display(a, n);

    selectionSort(a, n);
    printf("Selection Sort: ");
    display(a, n);

    int b[] = {10,4,5,7,9,2,1,3,6,8};
    insertionSort(b, n);
    printf("Insertion Sort: ");
    display(b, n);

    int c[] = {10,4,5,7,9,2,1,3,6,8};
    quickSort(c, 0, n - 1);
    printf("Quick Sort: ");
    display(c, n);

    int d[] = {10,4,5,7,9,2,1,3,6,8};
    mergeSort(d, 0, n - 1);
    printf("Merge Sort: ");
    display(d, n);

    int e[] = {10,4,5,7,9,2,1,3,6,8};
    heapSort(e, n);
    printf("Heap Sort: ");
    display(e, n);

    return 0;
}
