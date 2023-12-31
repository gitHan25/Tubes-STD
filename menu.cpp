#include"menu.h"
#include"penulis.h"
#include"books.h"

void add_penulis(list_penulis &LP,adrPenulis p,List_books LB){

    string nama,gender;
    int tahun_lahir;
    infotype x;
    bool check=false;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Tambah penulis"<<endl;
    cout<<"--------------------------------------"<<endl;


  ;

    while(!check){
            cout<<"Masukkan nama penulis (ketik 'stop' untuk berhenti): ";
            cin>>nama;
        if(nama == "stop"){
            check = true;
        }else{
        x.name = nama;
        cout<<"Tahun lahir penulis: ";
        cin>>tahun_lahir;
        x.Tahun_lahir=tahun_lahir;
        cout<<"Gender penulis: ";
        cin>>gender;
        x.gender=gender;

        p = create_elm_penulis(x);
        insert_penulis(LP,p);

        }


    }
    showPenulis(LP);
    cout<<"-------------------------"<<endl;


}

void add_books(List_books &LB,adrBooks p,list_penulis LP){


}
