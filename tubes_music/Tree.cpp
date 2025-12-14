#include <iostream>
#include"music.h"

using namespace std;

void CreateTree(adrNode &root){
    root = nullptr;
}

adrNode createNode(music x) {
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

void insertBerdasarkanDurasi(adrNode &root, adrNode p){
    if (root == nullptr){
        root = p;
    }else if(p->info.durasi < root->info.durasi){
        insertBerdasarkanDurasi(root->left, p);
    }else{
        insertBerdasarkanDurasi(root->right, p);
    }
}
void printTreeInOrder(adrNode root){
    if (root != nullptr){
        printTreeInOrder(root->left);
        cout << "- [" << root->info.durasi << " menit] "
             << root->info.judul_lagu << " - "
             << root->info.penyanyi << endl;

        printTreeInOrder(root->right);
    }
}

