# Dokumentasi Program "Warung Kang Roger"

## Requirement / Objective

Fungsi utama dari program ini adalah untuk membantu Kang Roger membuat sistem yang bisa mengambil pesanan dari pelanggan pada warungnya dan juga menyimpan riwayat pembelian yang dilakukan oleh pelanggan.

## Program Flow / Flowchart
Program dimulai dengan mendefinisikan variabel dan struktur data yang digunakan untuk menyimpan informasi tentang hal-hal yang dibutuhkan seperti menu, pelanggan, dan pesanannya. Terdapat 10 barang pada menu yang disimpan di dalam array `menu` di structure `menu_item`. Fungsi utama dari program adalah menampilkan tampilan menu untuk memasukan pesanan pelanggan dan riwayat dari transaksi.

## Function Description
1. `Show menu`: menampilkan menu yang terdiri dari ID, nama, kategori, dan harga.
2. `Place order`: menampilkan tampilan untuk pelanggan agar bisa memasukkan nama, ID barang, dan jumlah barang yang ingin dibeli. Informasi transaksi akan disimpan dalam array `orders` dalam structure `order`.
3. `Sale History`: menampilkan riwayat transaksi yang terdiri dari nama pelanggan, barang yang dia beli, total banyak pembelian, dan harga total tiap pembelian.

## Program Explanation
- Library: Program ini menggunakan library standar yaitu **stdio.h** dan **string.h** untuk operasi masukan/keluaran dan fungsi manipulasi string.
- Variabel : Program memiliki dua variabel konstanta `MAX_CUSTOMERS` dan `MAX_ORDERS` untuk menyimpan batas maksimum pelanggan dan pesanan yang dapat disimpan dalam sistem. Selain itu, `MAX_MENU_ITEMS` digunakan untuk menentukan jumlah maksimum item menu yang dapat disimpan dalam sistem. Batasan ini ditetapkan untuk mencegah *exploit* dan *bug* sederhana pada sisem. Program ini mendefinisikan dua variabel `num_customers` dan `num_orders` untuk menyimpan jumlah saat ini dari pelanggan dan pesanan.
- Struktur Data: Terdapat dua struktur data `menu_item` dan `order` untuk menyimpan informasi tentang item menu dan pesanan.
- Tampilan menu: Fungsi `show_menu()` akan menampilkan item menu yang dibuat dengan menggunakan loop melalui array menu dari struktur `menu_item` dan mencetak informasi untuk setiap item.
- Tempan pemesanan: Fungsi `place_order()` meminta informasi pelanggan. Fungsi ini pertama-tama memeriksa apakah pelanggan sudah memesan dan memperbarui variabel `num_customers` sesuai. Kemudian, fungsi membuat loop melalui array menu untuk menemukan item menu dengan ID yang dimasukkan dan menyimpan informasi pesanan dalam array pesanan dari struktur pesanan.
- Riwayat penjualan: Fungsi `sales_history()` menampilkan riwayat penjualan. Fungsi akan memeriksa apakah ada pesanan dan menampilkan pesan jika tidak ada. Kemudian, ia membuat loop melalui array pesanan dan mencetak informasi untuk setiap pesanan.

## Test Case
Program dites dengan menambahkan banyak pesanan untuk banyak pelanggan. Dokumentasi hasil tes dan penggunaan dapat dicek melalui lampiran berikut:

![menu utama](doc\menu.png)

![Proses Pemasukan Data Transaksi oleh Pelanggan](doc\customer_input.png)

![Riwayat Transaksi](doc\history.png)

## Kesimpulan dan Saran
Program ini memiliki fungsi untuk menampilkan menu, membuat pesanan, dan melihat riwayat penjualan. Fungsi-fungsi tersebut sudah berjalan dengan baik sesuai dengan *requirement* yang diterapkan.

Untuk saran, program bisa dikembangkan dengan menambah hal "bonus" yang dilampirkan pada tugas. Selain itu, berikut adalah beberapa saran pengembangan lainnya:
- Autentikasi akses untuk *sales history* agar hanya bisa dilihat oleh admin
- Menambah sistem pembayaran untuk menampilkan kembalian
- Menambah informasi stok barang dan fungsi pengurangan stok saat dilakukan pemesanan.