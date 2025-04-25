Tugas 4 - Struktur Data dan Algoritma 2025

Nama : Tinsari Rauhana

NPM : 2308107010038

1. Deskripsi Tugas

Tugas ini bertujuan untuk mengevaluasi dan membandingkan performa enam algoritma sorting, yaitu:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Shell Sort

Setiap algoritma diimplementasikan untuk dua jenis data:
- Data bertipe integer (angka)
- Data bertipe string (kata)

Pengujian dilakukan terhadap data acak dalam skala besar, dari 10.000 hingga 2.000.000 entri. Program mengukur waktu eksekusi dan penggunaan memori dari setiap algoritma dalam berbagai ukuran data.

2. Struktur File

- main.c  
  Berisi fungsi utama dan logika untuk pembacaan data, pengujian performa algoritma, dan tampilan menu.

- sorting.h  
  Berisi implementasi dari semua algoritma sorting (angka dan string) dalam bentuk fungsi terpisah, lengkap dengan komentar penjelasan.

- data_angka.txt dan data_kata.txt  
  Berisi dataset acak yang digunakan dalam pengujian (tidak disertakan dalam repo karena ukuran besar, dapat digenerate ulang menggunakan kode dari instruksi tugas).

- 2308107010038_Tugas4_SDA.pdf
  Berisi laporan dan dokumentasi hasil pengujian, analisis, grafik, serta kesimpulan dari performa algoritma yang diuji.

3. Cara Menjalankan Program

- Generate data angka dan kata (jika belum dibuat).
- Kompilasi program:
   gcc main.c -o sorting
- Jalankan program:
./sorting
