#include"books.h"

void create_list_books(List_books &L){
    first_B(L)=NULL;
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
      if (first_B(L)==NULL){
        first_B(L)=p;

    }else{
        adrBooks q = first_B(L);
            while(next(q)!=NULL){
                q=next(q);
            }
            next(q)=p;
    }
}
void insert_first_books(List_books &L,adrBooks p){
    if (first_B(L)==NULL){
        first_B(L)=p;

    }else{
    next(p)=first_B(L);
        first_B(L)=p;
    }
}
adrBooks find_books(List_books L, string judul_buku){
    adrBooks q = first_B(L);
        while(q!=NULL){
            if(info(q).judul_buku == judul_buku){
                return q;
            }
            q=next(q);

        }
        return NULL;
};
void delete_books(List_books &L,adrBooks p){
    if(p!=NULL){

        if(p==first_B(L)){
            delete_first_books(L,p);
        }else if(next(p)==NULL){
            delete_last_books(L,p);


    }else{
        adrBooks prec = first_B(L);
            while(next(prec) !=p){
                prec = next(prec);
            }
           delete_after_books(L,prec);
    }

    }else{
        cout<<"Buku tidak ditemukan"<<endl;
    }
};
void delete_first_books(List_books &L,adrBooks p){
    if(first_B(L)==NULL){
        cout<<"List buku kosong"<<endl;

    }else if(next(first_B(L))==NULL){

        p = first_B(L);
        first_B(L)=NULL;
    }else{
        p =first_B(L);
        first_B(L)=next(p);
        next(p)=NULL;
    }
};
void delete_last_books(List_books &L,adrBooks p){
    if(first_B(L)==NULL){
        cout<<"List buku kosong"<<endl;

    }else if(next(first_B(L))==NULL){

        p = first_B(L);
        first_B(L)=NULL;
    }else{
        adrBooks q = first_B(L);
        p=first_B(L);

            while(next(p)!=NULL){
                q=p;
                p=next(p);

            }
            next(q)=NULL;
        }
};
void delete_after_books(List_books &L,adrBooks p){
    adrBooks q =first_B(L);
    adrBooks prec;
        while(q!=NULL){
            if(info(q).judul_buku == info(p).judul_buku){
                prec=next(q);
                next(q)=next(prec);
                next(prec)=NULL;
            }
            q=next(q);
        }
};
