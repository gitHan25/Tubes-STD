#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED
#include <iostream>
#define first_B(L) L.first_B
#define next(P) P->next
#define info(P) P->info

//First_B == first dari list buku
using namespace std;

typedef struct elmBooks *adrBooks;


struct books
{
    string judul_buku;
    string penerbit;
    string ISBN;
    int tahun_terbit;
};
typedef books infobooks;
struct elmBooks
{
    infobooks info;
    adrBooks next;
};

struct List_books
{
    adrBooks first_B;
};

void create_list_books(List_books &L);
adrBooks create_elm_books(infobooks x);
bool is_emptyB(List_books L);
void insert_books(List_books &L,adrBooks p);
void insert_last_books(List_books &L,adrBooks p);
void insert_first_books(List_books &L,adrBooks p);
void insert_after_books(List_books &L,adrBooks prec,adrBooks p);
adrBooks find_books(List_books L, string judul_buku);
void delete_books(List_books &L,adrBooks p);
void delete_first_books(List_books &L,adrBooks p);
void delete_last_books(List_books &L,adrBooks p);
void delete_after_books(List_books &L,adrBooks p);
void show_books(List_books L);


#endif // BOOKS_H_INCLUDED
