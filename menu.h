#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include"penulis.h"
#include"menu.h"


void add_penulis(list_penulis &LP,adrPenulis p,List_books LB);
void add_books(List_books &LB,adrBooks p,list_penulis LP);
void hubungkan(list_penulis &LP,List_books &LB);
void deleteP(list_penulis &LP,List_books LB,adrPenulis p);



#endif // MENU_H_INCLUDED
