#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include <iostream>
#include "books.h"
#define first_P(L) L.first_P
#define child(P) P->child
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
    adrRelation child;
};
struct elmRelation
{
    adrRelation adrBooks;
    adrRelation next;
};
struct list_penulis
{
    adrPenulis first_P;
};


void create_list_penulis(list_penulis &L);
adrPenulis create_elm_penulis(infotype x);
bool is_emptyP(list_penulis L);
void insert_last_penulis(list_penulis &L,adrPenulis p);



#endif // PENULIS_H_INCLUDED
