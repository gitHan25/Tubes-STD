#include"penulis.h"
#include"books.h"
#include"menu.h"


using namespace std;

int main()
{

    cout<<"---------------------------------------"<<endl;
    cout<<"-    Program data penulis dan buku     -"<<endl;
    cout<<"-            Dibuat oleh               -"<<endl;
    cout<<"-      Muhammad Farhan Editya          -"<<endl;
    cout<<"-                dan                   -"<<endl;
    cout<<"-    Valda Veisa Al Fatih Anandita     -"<<endl;
    cout<<"---------------------------------------"<<endl;

    list_penulis LP;
    List_books LB;

    create_list_books(LB);
    create_list_penulis(LP);

    menu(LP,LB);

    return 0;
}
