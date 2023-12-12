#include"penulis.h"
#include"books.h"

void create_list_penulis(list_penulis &L){

    first_P(L)=NULL;
}


adrPenulis create_elm_penulis(infotype x){
    adrPenulis p = new elmPenulis;
    info(p)=x;
    next(p)=NULL;
    child(p)=NULL;
    return p;
}

bool is_emptyP(list_penulis L){
    return first_P(L)==NULL;
}


void insert_last_penulis(list_penulis &L,adrPenulis p){

    if (is_emptyP(L)){
        first_P(L)=p;

    }else{
        adrPenulis q = first_P(L);
            while(q!=NULL){
                q=next(q);
            }
            next(q)=p;
    }
}




