#ifndef SORTING_H
#define SORTING_H

#include <string.h>
#include <stdlib.h>

// ======================== SORTING ANGKA ========================

// Bubble Sort
// Prinsip: Bandingkan dua elemen yang bersebelahan dan tukar kalau salah urutan.
// Diulang terus sampai semua elemen sudah pada tempatnya.
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

// Selection Sort
// Prinsip: Cari elemen terkecil dari sisa data, lalu tukar dengan posisi sekarang.
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

// Insertion Sort
// Prinsip: Ambil satu per satu data, lalu sisipkan ke posisi yang tepat di bagian data yang sudah terurut.
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
// Prinsip: Pecah array jadi dua bagian, urutkan masing-masing, lalu gabung jadi satu secara berurutan.
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
// Prinsip: Pilih satu elemen sebagai pivot, bagi data jadi dua (lebih kecil dan lebih besar),
// lalu urutkan keduanya secara rekursif.
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            int tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;
    return i+1;
}
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

// Shell Sort
// Prinsip: Urutkan data yang jaraknya jauh dulu, lalu kurangi jaraknya perlahan hingga jadi 1.
void shell_sort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// ======================== SORTING KATA ========================

// Bubble Sort (String)
// Prinsip: Bandingkan dua kata bersebelahan, tukar kalau urutan abjadnya salah.
void bubble_sort_str(char **arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

// Selection Sort (String)
// Prinsip: Cari kata terkecil (secara abjad), tukar dengan posisi sekarang.
void selection_sort_str(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[min]) < 0)
                min = j;
        char *tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

// Insertion Sort (String)
// Prinsip: Ambil satu kata, lalu sisipkan ke posisi yang tepat di bagian yang sudah urut.
void insertion_sort_str(char **arr, int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Shell Sort (String)
// Prinsip: Bandingkan kata yang jaraknya jauh dulu, lalu makin dekat hingga jaraknya 1.
void shell_sort_str(char **arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char *temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Merge Sort (String)
// Prinsip: Pecah daftar kata menjadi bagian kecil, urutkan, lalu gabungkan lagi secara terurut.
void merge_str(char **arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char **L = malloc(n1 * sizeof(char*));
    char **R = malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (strcmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}
void merge_sort_str(char **arr, int n) {
    for (int curr_size = 1; curr_size <= n-1; curr_size *= 2) {
        for (int left_start = 0; left_start < n-1; left_start += 2*curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2*curr_size - 1 < n-1) ? (left_start + 2*curr_size - 1) : (n-1);
            if (mid < right_end)
                merge_str(arr, left_start, mid, right_end);
        }
    }
}

// Quick Sort (String)
// Prinsip: Pilih kata sebagai pivot, pisahkan yang lebih kecil dan lebih besar dari pivot, urutkan pakai stack.
void quick_sort_str(char **arr, int n) {
    int *stack = malloc(n * sizeof(int));
    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        char *pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (strcmp(arr[j], pivot) < 0) {
                i++;
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        char *tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;

        int pi = i + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
    free(stack);
}

#endif
