#include"penulis.h"
#include"books.h"

void create_list_books(List_books &L){
    first_B(L)==NULL;
}

bool is_emptyB(List_books L){
    return first_B(L)==NULL;

}

adrBooks create_elm_books(infobooks x){
    adrBooks  p = new elmBooks;
    info(p)= x;
    next(p)=NULL;
    return p;
}

void insert_last_books(List_books &L,adrBooks p){
      if (is_emptyB(L)){
        first_B(L)=p;

    }else{
        adrBooks q = first_B(L);
            while(q!=NULL){
                q=next(q);
            }
            next(q)=p;
    }
}


