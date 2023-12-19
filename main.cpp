#include"penulis.h"
#include"books.h"

//MAIN DIGUNAKAN UNTUK DEBUG TERLEBIH DAHULU SEBELUM SEMUA FUNGSI SELESAI
using namespace std;

int main()
{
//   list_penulis L;
//
//   create_list_penulis(L);
//
//   infotype x;
//   x.name="raditya anto";
//   x.gender="binary";
//   x.Tahun_lahir=1984;
//
//   adrPenulis p = create_elm_penulis(x);
//   insert_last_penulis(L,p);
//
//   x.name="raditya dika";
//   x.gender="laki-laki";
//   x.Tahun_lahir=1984;
//
//    p = create_elm_penulis(x);
//   insert_last_penulis(L,p);
//
//
//   delete_last_penulis(L,p);
//
//  adrPenulis q = first_P(L);
//   if(first_P(L)==NULL){
//    cout<<"List kosong"<<endl;
//    }else{
//   }while(q!=NULL){
//
//    cout<<info(q).name<<endl;
//    q=next(q);
//   }

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

    return 0;
}
