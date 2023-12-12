#include"penulis.h"
#include"books.h"

void create_list_books(List_books &L){
    first(L)==NULL;
}

bool is_empty(List_books L){
    return first(L)==NULL;

}

adrBooks create_elm_books(infobooks x){
    adrBooks  p = new elmBooks;
    info(p)= x;
    next(p)=NULL;
}

void insert_last(List_books &L,adrBooks p){
      if (is_empty(L)){
        first_P(L)=p;

    }else{
        adrPenulis q = first_P(L);
            while(q!=NULL){
                q=next(q);
            }
            next(q)=p;
    }
}


