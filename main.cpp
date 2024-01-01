#include"penulis.h"
#include"books.h"
#include"menu.h"

//MAIN DIGUNAKAN UNTUK DEBUG TERLEBIH DAHULU SEBELUM SEMUA FUNGSI SELESAI
using namespace std;

int main()
{
    list_penulis LP;
    List_books LB;

    create_list_books(LB);
    create_list_penulis(LP);

    menu(LP,LB);

    return 0;
}
