#include"penulis.h"
#include"books.h"

void create_list_penulis(list_penulis &L){

    first_P(L)=NULL;
}


adrPenulis create_elm_penulis(infotype x){
    adrPenulis p = new elmPenulis;
    info(p)=x;
    next(p)=NULL;
    child(p)=NULL; //element child dalam list parent
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
            while(next(q)!=NULL){
                q=next(q);
            }
            next(q)=p;
    }
}

//First_P = first dari list penulis
void insert_first_penulis(list_penulis &L,adrPenulis p){

    if (is_emptyP(L)){
        first_P(L)=p;

    }else{

        next(p)=first_P(L);
        first_P(L)=p;

    }

}


adrPenulis find_penulis(list_penulis L,string name){

    adrPenulis q = first_P(L);
        while(q!=NULL){
            if(info(q).name == name){
                return q;
            }
            q=next(q);

        }
        return NULL;
}

void delete_first_penulis(list_penulis &L,adrPenulis p){
    if(is_emptyP(L)){
        cout<<"List penulis kosong"<<endl;

    }else if(next(first_P(L))==NULL){

        p = first_P(L);
        first_P(L)=NULL;
    }else{
        p =first_P(L);
        first_P(L)=next(p);
        next(p)=NULL;
    }


}
void delete_last_penulis(list_penulis &L,adrPenulis p){

    if(is_emptyP(L)){
        cout<<"List penulis kosong"<<endl;

    }else if(next(first_P(L))==NULL){

        p = first_P(L);
        first_P(L)=NULL;
    }else{
        adrPenulis q = first_P(L);
        p=first_P(L);

            while(next(p)!=NULL){
                q=p;
                p=next(p);

            }
            next(q)=NULL;
        }
}

void delete_after_penulis(list_penulis &L,adrPenulis p){

    adrPenulis q =first_P(L);
    adrPenulis prec;
        while(q!=NULL){
            if(info(q).name == info(p).name){
                prec=next(q);
                next(q)=next(prec);
                next(prec)=NULL;
            }
            q=next(q);
        }
}
//p disini merupakan alamat yang terlebih dahulu akan dicari menggunakan fungsi find_penulis
void delete_penulis(list_penulis &L,adrPenulis p){

    if(p!=NULL){

        if(p==first_P(L)){
            delete_first_penulis(L,p);
        }else if(next(p)==NULL){
            delete_last_penulis(L,p);


    }else{
        adrPenulis prec = first_P(L);
            while(next(prec) !=p){
                prec = next(prec);
            }
           delete_after_penulis(L,prec);
    }

    }else{
        cout<<"Penulis tidak ditemukan"<<endl;
    }

}





