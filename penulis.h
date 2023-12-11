#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include <iostream>
#include "books.h"
#define first(L) L.first
#define firstR(P) P->firstR
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmPenulis *adrPenulis;
typedef struct elmRelation *adrRelation;

struct penulis
{
    string name;
    int Tahun_lahir;
    string gender;
};
typedef penulis infotype;

struct elmPenulis
{
    infotype info;
    adrPenulis next;
    list_relation books;
};
struct elmRelation
{
    adrRelation adrBooks;
    next adrRelation;
};
struct list_penulis
{
    adrPenulis first;
};
struct list_relation
{
    adrRelation first;
};

#endif // PENULIS_H_INCLUDED
