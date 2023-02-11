// Library
#include <stdio.h>
#include <string.h>

// Definisi Variabel Konstan
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 1000
#define MAX_MENU_ITEMS 10

// Struktur data menu
struct menu_item
{
    int id;
    char name[50];
    char category[20];
    int price;
};

// Struktur data pesanan
struct order
{
    char customer_name[50];
    char menu_name[50];
    int quantity;
    int total_price;
};

int num_customers = 0;
int num_orders = 0;

// Struktur Data Isi Menu
struct menu_item menu[MAX_MENU_ITEMS] = {
    {1, "Soto Betawi Ayam", "Makanan", 15000},
    {2, "Soto Semarang Ayam", "Makanan", 15000},
    {3, "Soto Bandung Ayam", "Makanan", 12000},
    {4, "Es Teh", "Minuman", 3000},
    {5, "Es Jeruk", "Minuman", 3000},
    {6, "Es Kopi", "Minuman", 4000},
    {7, "Teh Hangat", "Minuman", 3000},
    {8, "Jeruk Hangat", "Minuman", 3000},
    {9, "Kopi Hangat", "Minuman", 3000},
    {10, "Tempe Mendoan", "Makanan", 2000}};

struct order orders[MAX_ORDERS];

// Tampilan Menu
void show_menu()
{
    printf("\nDaftar Menu:\n");
    printf("ID\tNama\t\t\tKategori\tHarga\n");
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        printf("%d\t%s\t\t\t%s\t\t%d\n", menu[i].id, menu[i].name, menu[i].category, menu[i].price);
    }
}

// Tampilan Pesanan
void place_order()
{
    char customer_name[50];
    printf("\nMasukkan nama pelanggan: ");
    scanf("%s", customer_name);

    int found = 0;
    for (int i = 0; i < num_customers; i++)
    {
        if (strcmp(orders[i].customer_name, customer_name) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        strcpy(orders[num_customers].customer_name, customer_name);
        num_customers++;
    }

    int menu_id;
    int quantity;
    printf("\nMasukkan ID menu: ");
    scanf("%d", &menu_id);
    printf("Masukkan jumlah: ");
    scanf("%d", &quantity);

    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        if (menu[i].id == menu_id)
        {
            strcpy(orders[num_orders].menu_name, menu[i].name);
            orders[num_orders].quantity = quantity;
            orders[num_orders].total_price = menu[i].price * quantity;
            num_orders++;
            break;
        }
    }
}

void sales_history()
{
    if (num_orders == 0)
    {
        printf("Tidak Ada Penjualan\n");
    }
    else
    {
        printf("\nRiwayat Penjualan:\n");
        printf("Nama Pelanggan\tNama Menu\tJumlah\tTotal Harga\n");
        for (int i = 0; i < num_orders; i++)
        {
            printf("%s\t\t%s\t\t%d\t%d\n", orders[i].customer_name, orders[i].menu_name,
                   orders[i].quantity, orders[i].total_price);
        }
    }
}

// Kode utama
int main()
{
    int choice;
    while (1)
    {
        printf("\nMenu Pemilik Toko:\n");
        printf("1. Pelanggan Masuk\n");
        printf("2. Tutup\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char customer_choice;
            while (1)
            {
                printf("\nMenu Pelanggan:\n");
                printf("1. Lihat Menu\n");
                printf("2. Beli\n");
                printf("3. Keluar\n");
                printf("Pilihan: ");
                scanf(" %c", &customer_choice);

                if (customer_choice == '1')
                {
                    show_menu();
                }
                else if (customer_choice == '2')
                {
                    place_order();
                }
                else if (customer_choice == '3')
                {
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            sales_history();
            break;
        }
    }

    return 0;
}