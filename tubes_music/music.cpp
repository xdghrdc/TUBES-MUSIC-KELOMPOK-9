#include <iostream>
#include"music.h"

using namespace std;
void CreateTree(adrNode &root){
    root = nullptr;
}

adrNode createNode(infotype x) {
    adrNode P = new Node;
    P->info = x;
    P->left = nullptr;
    P->right = nullptr;
    return P;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->info.Id_lagu < root->info.Id_lagu) {
        insertNode(root->left, p);
    } else {
        insertNode(root->right, p);
    }
}

adrNode searchNodeID(adrNode root, string id) {
    if (root == nullptr) return nullptr;
    if (root->info.Id_lagu == id) return root;

    if (id < root->info.Id_lagu)
        return searchNodeID(root->left, id);
    else
        return searchNodeID(root->right, id);
}

adrNode searchNodeDurasi(adrNode root, int Durasi) {
    if (root == nullptr) return nullptr;
    if (root->info.durasi == Durasi) return root;

    if  (Durasi< root->info.durasi)
        return searchNodeDurasi(root->left, Durasi);
    else
        return searchNodeDurasi(root->right, Durasi);
}

//User area
void createList(list &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(list L) {
    return (L.first == nullptr);
}

addressDLL allocate(infotype x) {
    addressDLL P = new elmlist_DLL;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirst(list &L, addressDLL p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void deleteFirst(list &L, addressDLL &p) {
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

void deleteLast(list &L, addressDLL &p) {
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

void deletAfter(list &L, addressDLL Q, addressDLL &p) {
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

void printInfo(list L) {
    addressDLL P = L.first;
    if (P == nullptr) {
        cout << "(Playlist kosong)\n";
        return;
    }
    cout << "=== Playlist ===\n";
    while (P != nullptr) {
        cout << "- " << P->info.judul_lagu << " | "
             << P->info.penyanyi << " | "
             << P->info.genre_lagu << "\n";
        P = P->next;
    }
}

//admin
void createListSLL(SLL &L) {
    L.first = nullptr;
}

bool isEmptySLL(SLL L) {
    return (L.first == nullptr);
}

addressSLL allocateSLL(infotype x) {
    addressSLL P = new elmlist_SLL;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirstSLL(SLL &L, addressSLL p) {
    p->next = L.first;
    L.first = p;
}

void deleteFirstSLL(SLL &L, addressSLL &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        p->next = nullptr;
    }
}

void deleteLastSLL(SLL &L, addressSLL &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        addressSLL q = L.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

void deletAfterSLL(SLL &L, addressSLL Q, addressSLL &p) {
    if (Q != nullptr && Q->next != nullptr) {
        p = Q->next;
        Q->next = p->next;
        p->next = nullptr;
    }
}

void printInfoSLL(SLL L) {
    addressSLL P = L.first;
    if (P == nullptr) {
        cout << "(Library kosong)\n";
        return;
    }
    cout << "=== Library Lagu ===\n";
    while (P != nullptr) {
        cout << "- " << P->info.judul_lagu
             << " | " << P->info.penyanyi
             << " | " << P->info.genre_lagu << "\n";
        P = P->next;
    }
}

addressDLL currentPlay = nullptr;

void playLagu(addressDLL lagu){
    if (lagu == nullptr){
        cout << "Lagu tidak ditemukan." << endl;
        return;
    }
    currentPlay = lagu;
    cout << "Memutar: " << lagu->info.judul_lagu << endl;
}
void nextLagu(){
    if (currentPlay == nullptr){
        cout << "Tidak ada lagu yang sedang diputar." << endl;
        return;
    }
    if(currentPlay->next == nullptr){
        cout << "Tidak ada lagu setelah ini." << endl;
        return;
    }
    currentPlay = currentPlay->next;
    cout << "Next: " << currentPlay->info.judul_lagu << endl;
}
void prevLagu(){
     if (currentPlay == nullptr){
        cout << "Tidak ada lagu yang sedang diputar." << endl;
        return;
    }
    if(currentPlay->prev == nullptr){
        cout << "Tidak ada lagu sebelum ini." << endl;
        return;
    }
    currentPlay = currentPlay->prev;
    cout << "Prev: " << currentPlay->info.judul_lagu << endl;
}
void stopLagu(){
    if (currentPlay == nullptr){
        cout << "Tidak ada lagu yang sedang diputar." << endl;
        return;
    }
    cout << "Stop: " << currentPlay->info.judul_lagu << endl;
    currentPlay = nullptr;
}
