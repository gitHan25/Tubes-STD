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
typedef books infobook;
struct elmBooks
{
    infobook info;
    adrBooks next;
};

struct List_books
{
    adrBooks first;
};

#endif // BOOKS_H_INCLUDED
