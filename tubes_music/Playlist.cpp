#include <iostream>
#include"music.h"

using namespace std;

// Playlist User
void CreatePlaylist(ListPlaylist &l){
    l.first = nullptr;
    l.last = nullptr;
}

bool isEmptyPlaylist(ListPlaylist l){
    return(l.first == nullptr && l.last ==nullptr);
}

bool isEmptyLagu(addressPlaylist p){
    return(p->firstlagu == nullptr);
}

addressPlaylist allocatePlaylist(string namaplaylist, string user){
    addressPlaylist p = new elmPlaylsit;
    p->info.namaplaylist = namaplaylist;
    p->info.user = user;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstlagu = nullptr;

    return p;
}

addresslagu allocateLagu(music dataLagu){
    addresslagu p = new elmlagu;
    p->lagu = dataLagu;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

void addPlaylist(ListPlaylist &l, addressPlaylist p){
    if(isEmptyPlaylist(l)){
        l.first = p;
        l.last = p;
    }else{
        l.last->next = p;
        p->prev = l.last;
        l.last = p;
    };
}

void addLaguToPlaylist(addressPlaylist &p, addresslagu q){
    if(isEmptyLagu(p)){
        p->firstlagu = q;
    }else{
        addresslagu r = p->firstlagu;
        while(r->next != nullptr){
            r=r->next;
        };
        r->next = q;
        q->prev = r;
    };
}

addressPlaylist searchPlaylist(ListPlaylist l, string namaplaylist){
    addressPlaylist p = l.first;
    while (p!=nullptr){
        if(p->info.namaplaylist == namaplaylist){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void displayPlaylist(ListPlaylist l){
    addressPlaylist p = l.first;
    if (isEmptyPlaylist(l)) {
        cout << "========================================" << endl;
        cout << "          DATA PLAYLIST KOSONG          " << endl;
        cout << "========================================" << endl;
        return;
    }

    cout << "========================================" << endl;
    cout << "        DAFTAR SELURUH PLAYLIST         " << endl;
    cout << "========================================" << endl;
    while(p!= nullptr){
        cout << "Nama Playlist: " << p->info.namaplaylist << endl;
        cout << "Dibuat oleh: " << p->info.user << endl;
        cout << "Daftar lagu: " << endl;

        addresslagu q = p->firstlagu;
        if(q == nullptr){
            cout << "Belum ada lagu." << endl;
        }else{
            int no = 1;
            while (q != nullptr){
                cout << no << ". " << q->lagu.judul_lagu << " - " << q->lagu.penyanyi << " [" << q->lagu.genre_lagu << "]" << " (" << q->lagu.durasi << " menit)" << endl;
                q = q->next;
                no++;
            }
        }
        cout << "----------------------------------------" << endl;
        p = p->next;
    }
}
