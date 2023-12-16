#include "penulis.h"

//MAIN DIGUNAKAN UNTUK DEBUG TERLEBIH DAHULU SEBELUM SEMUA FUNGSI SELESAI
using namespace std;

int main()
{
   list_penulis L;

   create_list_penulis(L);

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


   delete_last_penulis(L,p);

  adrPenulis q = first_P(L);
   if(first_P(L)==NULL){
    cout<<"List kosong"<<endl;
    }else{
   }while(q!=NULL){

    cout<<info(q).name<<endl;
    q=next(q);
   }

    return 0;
}
