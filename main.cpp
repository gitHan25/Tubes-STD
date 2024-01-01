#include"penulis.h"
#include"books.h"
#include"menu.h"

//MAIN DIGUNAKAN UNTUK DEBUG TERLEBIH DAHULU SEBELUM SEMUA FUNGSI SELESAI
using namespace std;

int main()
{
   list_penulis L;

   create_list_penulis(L);
//
   infotype x;


   adrPenulis p;







    List_books Lb;

    create_list_books(Lb);
    infobooks y;

    adrBooks z;






cout<<endl;
//adrRelation o = findRelation(u,"Harry potter");
//int l = 1;
//show parent of child
//    q = first_P(L);
//        while(q!=NULL){
//                adrRelation i = child(q);
//                    while(i!=NULL){
//                            if(info(books(i)).judul_buku=="Harry roller"){
//                                cout<<l<<info(q).name<<endl;
//                                l++;
//                            }
//                            i=nextRelation(i);
//
//                    }
//            q=next(q);
//        }

adrRelation r;

    add_penulis(L,p,Lb);
    add_books(Lb,z,L);
    hubungkan(L,Lb);
    deleteP(L,Lb,p);
    show_penulis_with_books(L);
    deleteB(Lb,L,z,r);
    show_penulis_with_books(L);
    show_books_with_penulis(Lb,L);
    show_specific_penulis(L,Lb);
    show_specific_book(Lb,L);
    return 0;
}
