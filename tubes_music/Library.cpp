#include <iostream>
#include"music.h"

using namespace std;

// Admin Song Library

void createLibrary(list &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyInLibrary(list L) {
    return (L.first == nullptr);
}

addressDLL allocateLibrary(music x) {
    addressDLL P = new elmlist_DLL;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstInLibrary(list &L, addressDLL p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastInLibrary(list &L, addressDLL p){
    if(L.first == nullptr){
        L.first = p;
        L.last = p;
    }
    else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void deleteFirstInLibrary(list &L, addressDLL &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteLastInLibrary(list &L, addressDLL &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.last;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}

void deletAfterInLibrary(list &L, addressDLL Q, addressDLL &p) {
    if (Q != nullptr && Q->next != nullptr) {
        p = Q->next;
        Q->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = Q;
        } else {
            L.last = Q;
        }
        p->next = nullptr;
        p->prev = nullptr;
    }
}

addressDLL searchSongInLibrary(list L, string Id_lagu){
    addressDLL p = L.first;
    while (p != nullptr){
        if (p->info.Id_lagu == Id_lagu){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteSongByID(list &L, string Id_Lagu){
    addressDLL p = searchSongInLibrary(L, Id_Lagu);
    if (p == nullptr){
        cout << "Lagu dengan ID: " << Id_Lagu << " tidak ditemukan." << endl;
        return;
     }
     addressDLL hapus;
     if(p == L.first){
        deleteFirstInLibrary(L, hapus);
     }else if(p == L.last){
        deleteLastInLibrary(L, hapus);
     }else{
        deletAfterInLibrary(L, p->prev, hapus);
     }
     cout << "Lagu: " << hapus->info.judul_lagu << " berhasil dihapus." << endl;
     delete hapus;
}

void printInfoLibrary(list L) {
    addressDLL P = L.first;
    if (P == nullptr) {
        cout << "(Library kosong)\n";
        return;
    }
    cout << "=== Library ===\n";
    while (P != nullptr) {
        cout << "[" << P->info.Id_lagu << "] "
             << P->info.judul_lagu << " - "
             << P->info.penyanyi << " ("
             << P->info.genre_lagu << ")\n";
        P = P->next;
    }
}
