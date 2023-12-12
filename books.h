#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

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
    infobook info;
    adrBooks next;
};

struct List_books
{
    adrBooks first;
};

void create_list_books(List_books &L);
adrBooks create_elm_books(infobooks x);
bool is_empty(List_books L);
void insert_last(List_books &L,adrBooks p);


#endif // BOOKS_H_INCLUDED
