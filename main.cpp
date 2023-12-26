#include"penulis.h"
#include"books.h"

//MAIN DIGUNAKAN UNTUK DEBUG TERLEBIH DAHULU SEBELUM SEMUA FUNGSI SELESAI
using namespace std;

int main()
{
   list_penulis L;

   create_list_penulis(L);
//
   infotype x;
   x.name="raditya anto";
   x.gender="binary";
   x.Tahun_lahir=1984;

   adrPenulis p = create_elm_penulis(x);
   insert_last_penulis(L,p);

   x.name="raditya dika";
   x.gender="laki-laki";
   x.Tahun_lahir=1984;

    p = create_elm_penulis(x);
   insert_last_penulis(L,p);
    x.name="bangor";
   x.gender="laki-laki";
   x.Tahun_lahir=1984;

    p = create_elm_penulis(x);
   insert_last_penulis(L,p);


//
//   delete_last_penulis(L,p);
//

   x.name="anto dika";
   x.gender="laki-laki";
   x.Tahun_lahir=1984;

    p = create_elm_penulis(x);
   insert_last_penulis(L,p);

   adrPenulis b = find_penulis(L,"bangor");

  adrPenulis q = first_P(L);

 showPenulis(L);



cout<<"-----------------------"<<endl;
    List_books Lb;

    create_list_books(Lb);
    infobooks y;
    y.judul_buku="Harry potter";
    y.ISBN="123123";
    y.penerbit="radit";
    y.tahun_terbit=2012;


    adrBooks z = create_elm_books(y);

    insert_last_books(Lb,z);


    y.judul_buku="Harry roller";
    y.ISBN="123123";
    y.penerbit="radit";
    y.tahun_terbit=2012;

 z = create_elm_books(y);

    insert_first_books(Lb,z);

    adrBooks v = first_B(Lb);

    if(first_B(Lb)==NULL){
        cout<<"list kosong"<<endl;

    }else{
        while(v!=NULL){
            cout<<info(v).judul_buku<<endl;
            v=next(v);
        }
    }

adrPenulis u = find_penulis(L,"raditya dika");
adrBooks c = find_books(Lb,"Harry roller");

adrRelation t = create_elm_relation(c);
addRelation(u,t);
 u = find_penulis(L,"raditya anto");
  c = find_books(Lb,"Harry roller");
 adrRelation r=  create_elm_relation(c);
if (u != NULL && c != NULL) {
    // Allocate memory for child(u) if it is NULL

   addRelation(u,r);
} else {
    cout << "Buku dan penulis belum terdaftar" << endl;
}

// u = find_penulis(L,"raditya anto");
//  c = find_books(Lb,"Harry potter");
// r=  create_elm_relation(c);
//if (u != NULL && c != NULL) {
//    // Allocate memory for child(u) if it is NULL
//
//   addRelation(u,r);
//} else {
//    cout << "Buku dan penulis belum terdaftar" << endl;
//}

deleteR(L,r);
adrPenulis k = first_P(L);


while (k != NULL) {
    cout << "Penulis: " << info(k).name << endl;

    adrRelation n = child(k);

if(n==NULL){
    cout<<"belum diinput"<<endl;
}else{
    while (n != NULL) {


        cout << "Buku: " <<info(books(n)).judul_buku << endl;
        n = nextRelation(n);
    }
}

    k = next(k);
}



cout<<endl;
adrRelation o = findRelation(u,"Harry potter");
int l = 1;
//show parent of child
    q = first_P(L);
        while(q!=NULL){
                adrRelation i = child(q);
                    while(i!=NULL){
                            if(info(books(i)).judul_buku=="Harry potter"){
                                cout<<l<<info(q).name<<endl;
                                l++;
                            }
                            i=nextRelation(i);

                    }
            q=next(q);
        }



    return 0;
}
