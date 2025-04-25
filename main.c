#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

// Maksimal jumlah data yang akan digunakan untuk pengujian.
#define MAX_SIZE 2000000
// Ukuran ini akan digunakan untuk mengukur performa algoritma sorting di berbagai skala.
const int TEST_SIZES[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
int NUM_TESTS = sizeof(TEST_SIZES)/sizeof(TEST_SIZES[0]);

// Fungsi untuk membaca data bertipe integer dari file.
// Data akan dibaca sebanyak 'n' elemen dan disimpan ke dalam array 'data'.
void read_int_data(const char* filename, int* data, int n) {
    FILE* file = fopen(filename, "r");
    for (int i = 0; i < n; i++) fscanf(file, "%d", &data[i]);
    fclose(file);
}

// Fungsi untuk membaca data bertipe string dari file.
// Setiap kata memiliki panjang maksimal 20 karakter.
// Data disimpan dalam array dua dimensi 'data'.
void read_str_data(const char* filename, char data[][21], int n) {
    FILE* file = fopen(filename, "r");
    for (int i = 0; i < n; i++) fscanf(file, "%s", data[i]);
    fclose(file);
}

// Fungsi untuk mengukur waktu dan penggunaan memori saat menjalankan algoritma sorting integer.
// Fungsi ini menerima pointer ke fungsi sorting, data asli, jumlah elemen, dan nama algoritma.
void benchmark_int(void (*sort_fn)(int*, int), int* data, int n, const char* name) {
    int* tmp = malloc(n * sizeof(int));                  // Buat salinan data
    memcpy(tmp, data, n * sizeof(int));
    clock_t start = clock();                             // Mulai pencatatan waktu
    sort_fn(tmp, n);                                     // Jalankan algoritma
    clock_t end = clock();                               // Selesai pencatatan waktu
    printf("%-20s : %.6f detik | Memori digunakan: %ld KB\n", 
        name, (double)(end - start)/CLOCKS_PER_SEC, n * sizeof(int) / 1024);
    free(tmp);
}

// Fungsi benchmark khusus untuk algoritma merge sort dan quick sort yang bersifat rekursif.
// Parameter dan logikanya mirip dengan benchmark_int.
void benchmark_merge_quick(void (*sort_fn)(int*, int, int), int* data, int n, const char* name) {
    int* tmp = malloc(n * sizeof(int));
    memcpy(tmp, data, n * sizeof(int));
    clock_t start = clock();
    sort_fn(tmp, 0, n - 1);
    clock_t end = clock();
    printf("%-20s : %.6f detik | Memori digunakan: %ld KB\n", 
        name, (double)(end - start)/CLOCKS_PER_SEC, n * sizeof(int) / 1024);
    free(tmp);
}

// Fungsi benchmark untuk sorting string.
// Data kata disalin ke array pointer sebelum dilakukan sorting.
void benchmark_str(void (*sort_fn)(char**, int), char data[][21], int n, const char* name) {
    char **ptrs = malloc(n * sizeof(char*));             // Buat array pointer ke string
    for (int i = 0; i < n; i++) ptrs[i] = data[i];       // Inisialisasi pointer
    clock_t start = clock();
    sort_fn(ptrs, n);
    clock_t end = clock();
    printf("%-20s : %.6f detik | Memori digunakan: %d KB\n", 
        name, (double)(end - start)/CLOCKS_PER_SEC, n * 21 / 1024);
    free(ptrs);
}

// Menu untuk pengujian sorting data angka.
// Menampilkan pilihan ukuran data dan menjalankan semua algoritma sorting angka.
void int_sort_menu() {
    int choice;
    int* data = malloc(MAX_SIZE * sizeof(int));              // Alokasi array besar
    read_int_data("data_angka.txt", data, MAX_SIZE);         // Baca data dari file

    while (1) {
        printf("\n--- Sorting Data Angka ---\n");
        for (int i = 0; i < NUM_TESTS; i++)
            printf("%d. Sorting %d\n", i+1, TEST_SIZES[i]);
        printf("%d. Kembali\n", NUM_TESTS+1);
        printf("Pilih: "); scanf("%d", &choice);

        if (choice < 1 || choice > NUM_TESTS) break;
        int n = TEST_SIZES[choice-1];
        printf("\nMemproses %d data...\n", n);
        benchmark_int(bubble_sort, data, n, "Bubble Sort");
        benchmark_int(selection_sort, data, n, "Selection Sort");
        benchmark_int(insertion_sort, data, n, "Insertion Sort");
        benchmark_merge_quick(merge_sort, data, n, "Merge Sort");
        benchmark_merge_quick(quick_sort, data, n, "Quick Sort");
        benchmark_int(shell_sort, data, n, "Shell Sort");
    }
    free(data);
}

// Menu untuk pengujian sorting data kata.
// Sama seperti menu angka, tapi memakai algoritma sorting string.
void str_sort_menu() {
    int choice;
    char (*data)[21] = malloc(MAX_SIZE * sizeof(*data));     // Alokasi array string
    read_str_data("data_kata.txt", data, MAX_SIZE);          // Baca data dari file

    while (1) {
        printf("\n--- Sorting Data Kata ---\n");
        for (int i = 0; i < NUM_TESTS; i++)
            printf("%d. Sorting %d\n", i+1, TEST_SIZES[i]);
        printf("%d. Kembali\n", NUM_TESTS+1);
        printf("Pilih: "); scanf("%d", &choice);

        if (choice < 1 || choice > NUM_TESTS) break;
        int n = TEST_SIZES[choice-1];
        printf("\nMemproses %d data...\n", n);
        benchmark_str(bubble_sort_str, data, n, "Bubble Sort (Str)");
        benchmark_str(selection_sort_str, data, n, "Selection Sort (Str)");
        benchmark_str(insertion_sort_str, data, n, "Insertion Sort (Str)");
        benchmark_str(shell_sort_str, data, n, "Shell Sort (Str)");
        benchmark_str(merge_sort_str, data, n, "Merge Sort (Str)");
        benchmark_str(quick_sort_str, data, n, "Quick Sort (Str)");
    }
    free(data);
}

// Fungsi utama program.
// Menampilkan menu utama untuk memilih jenis data yang akan diuji (angka/kata/keluar).
int main() {
    int pilihan;
    while (1) {
        printf("\nPilih Jenis Data:\n1. Data Angka\n2. Data Kata\n3. Keluar\nPilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) int_sort_menu();
        else if (pilihan == 2) str_sort_menu();
        else break;
    }
    return 0;
}
