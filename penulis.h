#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include <iostream>
#include "books.h"
#define first_P(L) L.first_P
#define child(P) P->child
#define next(P) P->next
#define info(P) P->info
#define nextRelation(p) p->nextRelation



//First_P == first dari list penulis
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
    adrBooks books;
    adrRelation nextRelation;
};
struct list_penulis
{
    adrPenulis first_P;
};


void create_list_penulis(list_penulis &L);
adrPenulis create_elm_penulis(infotype x);
bool is_emptyP(list_penulis L);
void insert_last_penulis(list_penulis &L,adrPenulis p);
void insert_first_penulis(list_penulis &L,adrPenulis p);
adrPenulis find_penulis(list_penulis L, string name);
void delete_penulis(list_penulis &L,adrPenulis p);
void delete_first_penulis(list_penulis &L,adrPenulis p);
void delete_last_penulis(list_penulis &L,adrPenulis p);
void delete_after_penulis(list_penulis &L,adrPenulis p);







#endif // PENULIS_H_INCLUDED
