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

    string judulBuku,Penerbit,isbn;
    int tahun_rilis;
        infobooks x;
    bool check=false;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Tambah buku"<<endl;
    cout<<"--------------------------------------"<<endl;
    while(!check){
            cout<<"Masukkan Judul buku(ketik 'stop' untuk berhenti): ";
            cin>>judulBuku;
        if(judulBuku == "stop"){
            check = true;
        }else{
            x.judul_buku = judulBuku;
            cout<<"Penerbit: ";
            cin>>Penerbit;
            x.penerbit=Penerbit;
            cout<<"Tahun terbit: ";
            cin>>tahun_rilis;
            x.tahun_terbit=tahun_rilis;
            cout<<"ISBN: ";
            cin>>isbn;
            x.ISBN=isbn;

            p = create_elm_books(x);
            insert_books(LB,p);
        }
        cout<<endl;
         show_books(LB);
        cout<<"-------------------------"<<endl;
    }

}

void hubungkan(list_penulis &LP,List_books LB){
    bool check = false;
    string nama, judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Connecting"<<endl;
    cout<<"--------------------------------------"<<endl;
    showPenulis(LP);
    cout<<"--------------------------------------"<<endl;
    show_books(LB);
    cout<<"Masukkan nama penulis dan buku: "<<endl;

        while(!check){
            cout<<"Nama penulis: ";
            cin>>nama;
                if(nama=="stop"){
                    check = true;
                }else{

                    adrPenulis P = find_penulis(LP,nama);
                    cout<<"Judul buku: ";
                    cin>>judul;
                    adrBooks Q = find_books(LB,judul);

                        if(P!=NULL && Q!=NULL){
                            adrRelation f = findRelation(P,info(Q).judul_buku);
                                if(f!=NULL){
                                    cout<<"Penulis dan buku sudah terhubung!"<<endl;
                                }else{
                                    adrRelation R = create_elm_relation(Q);
                                    connect(P,R);
                                    cout<<"Terhubung"<<endl;
                                }
                        }else if(P==NULL && Q!=NULL){
                            cout<<"Penulis belum terdaftar, ayo daftarkan terlebih dahulu!"<<endl;

                        }else if(P!=NULL && Q==NULL){
                            cout<<"Buku belum terdaftar, ayo daftarkan terlebih dahulu!"<<endl;

                        }else{
                            cout<<"Penulis dan buku belum terdaftar, ayo daftarkan terlebih dahulu!"<<endl;
                        }
                }

        }
         cout<<"______________________________________"<<endl;


}


void deleteP(list_penulis &LP,List_books LB,adrPenulis P){
     string nama;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Hapus penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    showPenulis(LP);

    if(first_P(LP)!=NULL){
        cout<<"Masukkan nama penulis yang akan dihapus: ";
        cin>>nama;
         P = find_penulis(LP,nama);
            if(P!=NULL){
                delete_penulis(LP,P);
                cout<<nama<<" "<<"Telah dihapus!"<<endl;
                showPenulis(LP);
            }else{
                cout<<"Penulis tidak ditemukan!"<<endl;
            }
    }else{

        cout<<"Data penulis kosong"<<endl;
        cout<<endl;
    }





}
