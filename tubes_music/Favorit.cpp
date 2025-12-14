#include <iostream>
#include"music.h"

using namespace std;

bool isFavorite(list Fav, string idLagu){
    addressDLL p = Fav.first;
    while (p != nullptr){
        if(p->info.Id_lagu == idLagu){
            return true;
        }
        p = p->next;
    }
    return false;
}
void addToFavorites(list &Fav, music lagu){
    if(isFavorite(Fav, lagu.Id_lagu)){
        cout << "Lagu ini sudah ada di dafter Favorit." << endl;
        return;
    }
    insertLastInLibrary(Fav, allocateLibrary(lagu));
    cout << "Berhasil menambahkan " << lagu.judul_lagu << " ke Favorit <3" << endl;
}
void showFavorites(list Fav){
    if(isEmptyInLibrary(Fav)){
        cout << "Daftar Favorit masih kosong." << endl;
        return;
    }
    cout << "\n=== MY FAVORITE SONGS <3 ===" << endl;
    addressDLL p = Fav.first;
    int i = 1;
    while(p!=nullptr){
        cout << i << ". " << p->info.judul_lagu
             << " - " << p->info.penyanyi
             << " [" << p->info.genre_lagu << "] " << endl;
        p = p->next;
        i++;
    }
    cout << "============================" << endl;
}
void loadFavoritesToPlayer(list &PlayerQueue, list Fav){
    addressDLL temp;
    while(!isEmptyInLibrary(PlayerQueue)){
        deleteFirstInLibrary(PlayerQueue, temp);
        delete temp;
    }
    stopLagu();
    if(isEmptyInLibrary(Fav)){
        cout << "Favorit kosong." << endl;
        return;
    }
    addressDLL p = Fav.first;
    while(p!= nullptr){
        insertLastInLibrary(PlayerQueue, allocateLibrary(p->info));
        p = p->next;
    }
    cout << ">> Memutar Daftar Favorit." << endl;
}
