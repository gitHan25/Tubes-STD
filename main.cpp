#include "penulis.h"

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
   infobooks z;
   z.judul_buku = "Asiknya belajar C++";
   z.penerbit = "ALH";
   z.ISBN = "672547";
   z.tahun_terbit = 2020;

   adrBooks s = create_elm_books(z);
   insert_last_books(Lb,s);

   z.judul_buku = "Cara ampuh dapat A";
   z.penerbit = "ALH";
   z.ISBN = "645319";
   z.tahun_terbit = 2018;

   s = create_elm_books(z);
   insert_last_books(Lb,s);

   delete_last_books(Lb,s);

   adrBooks r = first_B(Lb);
   if(first_B(Lb)==NULL){
    cout<<"List kosong"<<endl;
    }else{
   }while(r!=NULL){

    cout<<info(r).judul_buku<<endl;
    r=next(r);
   }

    return 0;
}
