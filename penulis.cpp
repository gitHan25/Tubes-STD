#include"penulis.h"
#include"books.h"


//Initiate list
void create_list_penulis(list_penulis &L){

    first_P(L)=NULL;
}

//Buat elm penulis baru dengan parameter infotype x
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


//Insert element berdasarkan kondisi list
void insert_penulis(list_penulis &L,adrPenulis p){
    adrPenulis check =find_penulis(L,info(p).name);

        if (check !=NULL){
            cout<<"Penulis sudah pernah terdaftar!"<<endl;
        }else{
            if(first_P(L)==NULL){
                insert_first_penulis(L,p);
            }else{
                insert_last_penulis(L,p);
            }
            cout<<"Penulis berhasil terdaftar!"<<endl;
        }
}

//Menambahkan elemen di akhir list
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

//cari penulis berdasarkan namanya
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

//Menghapus element pertama dari list penulis
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

//Menghapus element terakhir dari list penulis
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

//Hapus next element pada dari parameter
void delete_after_penulis(list_penulis &L,adrPenulis p){

    adrPenulis prec;

        prec=next(p);
        next(p)=next(prec);
        next(prec)=NULL;
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


//Membuat elm relasi dengan parameter x sebagai alamat buku
adrRelation create_elm_relation(adrBooks x){
    adrRelation p = new elmRelation;
    books(p) = x;
    nextRelation(p)=NULL;
    return p;
}




void addRelation(adrPenulis P,adrRelation R){

    if(child(P)==NULL){
        child(P)=R;

    }else{

        adrRelation q = child(P);
            while(nextRelation(q)!=NULL){
                q=nextRelation(q);
            }
            nextRelation(q)=R;

    }

}


void connect(adrPenulis p,adrRelation q){

    if(p!=NULL && q!=NULL){
        addRelation(p,q);
    }else{
        cout<<"Penulis belum terdaftar"<<endl;
    }
}
adrRelation findRelationInList(list_penulis L,string judul){
 adrPenulis p = first_P(L);

    while (p != NULL) {
        adrRelation q = child(p);

        while (q != NULL) {
            if (info(books(q)).judul_buku == judul) {
                return q;
            }
            q = nextRelation(q);
        }

        p = next(p);
    }

    return NULL;
}

adrRelation findRelation(adrPenulis p,string judul_buku){

    adrRelation q = child(p);
        while(q!=NULL){
            if(info(books(q)).judul_buku == judul_buku){
                return q;
            }
            q=nextRelation(q);
        }
        return NULL;

}

void showPenulis(list_penulis L){
    adrPenulis q = first_P(L);
    int i = 1;
    if(first_P(L)==NULL){
        cout<<"List penulis kosong"<<endl;
    }else{
        while(q!=NULL){

            cout<<i<<"."<<"Nama: "<<info(q).name<<endl;
            cout<<"Tahun lahir: "<<info(q).Tahun_lahir<<endl;
            cout<<"Jenis kelamin: "<<info(q).gender<<endl;
            i++;
            q=next(q);
        }
    }

}

void deleteR(list_penulis &L, adrRelation R) {
        adrPenulis p;

        adrRelation prec;

        if (R != NULL) {
                p =first_P(L);
            while (p != NULL) {
                adrRelation q = child(p);

                while (q != NULL) {
                    if (info(books(q)).judul_buku == info(books(R)).judul_buku) {
                        if (q == child(p)) {

                            delete_first_relation(L, p, q);
                        } else if (nextRelation(q) == NULL) {

                            delete_last_relation(L, p,q);
                        } else {

                            prec = child(p);
                           while (nextRelation(prec) != R) {
                                prec = nextRelation(prec);
                            }
                            delete_after_relation(L, p, prec);
                        }
                    }

                    q = nextRelation(q);
                }

                p = next(p);
            }
        } else {
            cout << "List kosong" << endl;
        }
    }


    void delete_first_relation(list_penulis &L,adrPenulis P,adrRelation R){

        if(nextRelation(child(P))==NULL){
            R = child(P);
            child(P)=NULL;
        }else{

       child(P)=nextRelation(R);
       nextRelation(R)=NULL;
        }

    }

    void delete_last_relation(list_penulis &L,adrPenulis P,adrRelation R){

        adrRelation q =child(P);

            while(nextRelation(nextRelation(q))!=NULL){
                    q=nextRelation(q);
                }
                    R=nextRelation(q);
                    nextRelation(R)=NULL;
                    nextRelation(q)=NULL;

    }

    void delete_after_relation(list_penulis &L,adrPenulis P,adrRelation R){

           adrRelation prec;

           prec =nextRelation(R);
           nextRelation(R)=nextRelation(prec);
           nextRelation(prec) =NULL;


    }

int count_books(adrPenulis p){
    int i = 0;
    adrRelation r = child(p);

    while (r != NULL) {
        i++;
        r = nextRelation(r);
    }

    return i;
}



