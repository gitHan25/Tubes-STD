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
    menu(LP,LB);


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

    }
        cout<<endl;
        show_books(LB);
        cout<<"-------------------------"<<endl;
        menu(LP,LB);

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
                cout<<endl;

        }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);


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
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}
void deleteB(List_books &LB,list_penulis &LP,adrBooks p,adrRelation r){

    string judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Hapus buku"<<endl;
    cout<<"--------------------------------------"<<endl;
    show_books(LB);

    if(first_B(LB)!=NULL){
        cout<<"Masukkan judul buku yang akan dihapus: ";
        cin>>judul;

            p = find_books(LB,judul);
            if(p!=NULL){
                    r = findRelationInList(LP,judul);
                    deleteR(LP,r);
                    delete_books(LB,p);
                    cout<<"Buku "<<judul<<" telah dihapus"<<endl;
                    show_books(LB);
            }else{
        cout<<"Buku tidak ditemukan, coba lagi!"<<endl;
            }
    }else{
    cout<<"Data buku kosong!"<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);
}



void show_penulis_with_books(list_penulis LP,List_books LB){

   adrPenulis p;
   if(is_emptyP(LP)){
    cout<<"List kosong"<<endl;
   }else{
        p =first_P(LP);

            while(p!=NULL){
                    cout<<"Nama penulis: "<<info(p).name<<endl;
                    cout<<"Buku yang ditulis: "<<endl;
                 adrRelation r = child(p);
                    if(r!=NULL){
                    while(r!=NULL){
                        cout<<"-"<<info(books(r)).judul_buku<<endl;
                        r=nextRelation(r);
                    }
                }else{
                    cout<<"Belum ada buku yang terdaftar!"<<endl;
                }
                    p=next(p);
            }
   }

    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);

}

void show_books_with_penulis(List_books LB,list_penulis LP){

    cout<<"--------------------------------------"<<endl;
    cout<<"            Buku dan penulis "<<endl;
    cout<<"--------------------------------------"<<endl;

    if(is_emptyB(LB)&&is_emptyP(LP)){

        cout<<"Data kosong"<<endl;
    }else{
        adrBooks q = first_B(LB);

                while(q!=NULL){
                        cout<<"Buku "<<info(q).judul_buku<<" ditulis oleh: "<<endl;

                            adrPenulis p = first_P(LP);
                            if(p!=NULL){
                                while(p!=NULL){
                                    adrRelation r = child(p);

                                        while(r!=NULL){
                                            if(info(books(r)).judul_buku == info(q).judul_buku){
                                                cout<<"-"<<info(p).name<<endl;
                                            }
                                            r=nextRelation(r);
                                        }
                                        p=next(p);
                                    }
                                }else{
                                    cout<<"Belum ada penulis yang terdaftar!"<<endl;
                                }
                           q=next(q);
                }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);

}

void show_specific_penulis(list_penulis LP,List_books LB){
    string nama;
    cout<<"--------------------------------------"<<endl;
    cout<<"   Cari penulis dan buku yang ditulis "<<endl;
    cout<<"--------------------------------------"<<endl;

    showPenulis(LP);

    if(is_emptyP(LP) &&is_emptyB(LB)){
        cout<<"data kosong!"<<endl;
    }else{
    cout<<"Masukkan nama penulis yang ingin dicari: ";
    cin>>nama;

    adrPenulis p = find_penulis(LP,nama);

        if(p!=NULL){
            cout<<"Nama: "<<info(p).name<<endl;
            adrRelation r = child(p);
                if(r!=NULL){
                         cout<<"Buku yang ditulis oleh "<<nama<<":"<<endl;
                    while(r!=NULL){

                        cout<<"-"<<info(books(r)).judul_buku<<endl;
                        r=nextRelation(r);
                    }
                }else{
                    cout<<"Buku tidak dapat ditemukan!"<<endl;
                }
        }else{
            cout<<"Penulis belum terdaftar!"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);
}


void show_specific_book(List_books LB,list_penulis LP){

    string judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"              Cari buku "<<endl;
    cout<<"--------------------------------------"<<endl;

    if(is_emptyB(LB) && is_emptyP(LP)){
        cout<<"List kosong"<<endl;
    }else{

            cout<<"Masukkan judul buku yang akan dicari: ";
            cin>>judul;;
            adrBooks q = find_books(LB,judul);

            if(q!=NULL){
                cout<<"Buku "<<judul<<" ditulis oleh: "<<endl;

                adrPenulis p = first_P(LP);
                    while(p!=NULL){
                        adrRelation r = findRelation(p,info(q).judul_buku);
                            if(r!=NULL){
                                cout<<"-"<<info(p).name<<endl;
                        }
                    p=next(p);
                    }

                }else{

                    cout<<"Data buku tidak ditemukan!"<<endl;
                }

    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);
}



void show_most_active_penulis(list_penulis LP,List_books LB){

    cout<<"---------------------------------------"<<endl;
    cout<<" Penulis yang menulis buku paling banyak "<<endl;
    cout<<"---------------------------------------"<<endl;
    int i;
    int maks = 0;
    adrPenulis temp= NULL;

    if(is_emptyB(LB) && is_emptyP(LP)){
        cout<<"List kosong"<<endl;
    }else{
        adrPenulis p = first_P(LP);

            while(p!=NULL){
                i = 0;
                adrRelation r = child(p);
                    while(r!=NULL){
                        i++;
                        r=nextRelation(r);
                    }
                    if(maks<i){
                        temp = p;
                        maks =i;
                    }
                    p=next(p);
            }

            if (maks > 0 || maks == i) {
            cout << "Penulis yang menulis buku paling banyak adalah: " << info(temp).name << ", menulis sebanyak " << maks << " buku" << endl;
        } else {
            cout << "Tidak ada buku yang ditulis oleh penulis" << endl;
        }

    }
     cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP,LB);
}


void show_less_active_penulis(list_penulis LP, List_books LB) {
    cout << "---------------------------------------" << endl;
    cout << " Penulis yang menulis buku paling sedikit " << endl;
    cout << "---------------------------------------" << endl;
    int i;
    int mins = 0;
    adrPenulis temp = NULL;

    if (is_emptyB(LB) && is_emptyP(LP)) {
        cout << "List kosong" << endl;
    } else {
        adrPenulis p = first_P(LP);

        while (p != NULL) {
             i = 0;
            adrRelation r = child(p);

            while (r != NULL) {
                i++;
                r = nextRelation(r);
            }

            if (mins == 0 || mins > i) {
                temp = p;
                mins = i;
            }

            p = next(p);
        }

        if(mins == i || mins > 0){
             cout << "Penulis yang menulis buku paling sedikit adalah: " << info(temp).name << ", menulis sebanyak " << mins << " buku" << endl;
        }else{

            cout << "Tidak ada buku yang ditulis oleh penulis" << endl;

        }
    }

    cout << endl;
    cout << "______________________________________" << endl;
    menu(LP, LB);
}



void menu(list_penulis &LP,List_books &LB){

    int input;
    adrPenulis p;
    adrBooks q;
    adrRelation r;



    cout<<"Fitur program: "<<endl;
	cout<<"1. Tambah penulis"<<"                                 "<<"7.  Tampilkan buku dan penulisnya"<<endl;
	cout<<"2. Tambah buku"<<"                                    "<<"8.  Cari penulis"<<endl;
	cout<<"3. Hubungkan"<<"                                      "<<"9.  Cari buku"<<endl;
	cout<<"4. Hapus penulis"<<"                                  "<<"10. Tampilkan penulis yang paling banyak menulis "<<endl;
	cout<<"5. Hapus buku"<<"                                     "<<"11. Tampilan penulis yang paling sedikit menulis "<<endl;
	cout<<"6. Tampilkan penulis dan buku yang ditulis"<<"        "<<"12. Exit"<<endl;

	cout<<endl;
	cout<<"Pilih fitur: ";
	cin>>input;
    system("CLS");

	switch(input){
    case 1:
        add_penulis(LP,p,LB);
        break;
    case 2:
        add_books(LB,q,LP);
        break;
    case 3:
        hubungkan(LP,LB);
        break;
    case 4:
        deleteP(LP,LB,p);
        break;
    case 5:
        deleteB(LB,LP,q,r);
        break;
    case 6:
        show_penulis_with_books(LP,LB);
        break;
    case 7:
        show_books_with_penulis(LB,LP);
        break;
    case 8:
        show_specific_penulis(LP,LB);
        break;
    case 9:
        show_specific_book(LB,LP);
        break;
    case 10:
        show_most_active_penulis(LP,LB);
        break;
    case 11:
        show_less_active_penulis(LP,LB);
        break;
    default:
        cout<<"Close Program"<<endl;
	}

}





