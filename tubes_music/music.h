#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <string>
using namespace std;

typedef struct music infotype;
typedef struct elmlist_DLL *addressDLL;
typedef struct elmlist_SLL *addressSLL;
typedef struct Node* adrNode;

struct music{
    string Id_lagu;
    string judul_lagu;
    string penyanyi;
    int durasi;
    string genre_lagu;
};
struct elmlist_DLL{
    music info;
    addressDLL next;
    addressDLL prev;
};

struct elmlist_SLL{
    infotype info;
    addressSLL next;
};

struct SLL{
    addressSLL first;
};


struct list{
    addressDLL first;
    addressDLL last;
};

struct Node{
    infotype info;
    adrNode left;
    adrNode right;
};

extern addressDLL currentPlay;

//sorting
void CreateTree(adrNode &root);
adrNode createNode(infotype x);
void insertNode(adrNode &root, adrNode p);
adrNode searchNodeID(adrNode root, infotype x);
adrNode searchNodeDurasi(adrNode root, infotype x);

//user
void createList(list &L);
void createPlaylist(list &L);
bool isEmpty(list L);
addressDLL allocate(infotype x);
void printInfo(list L);
void insertFirst(list &L, addressDLL p);
void deleteFirst(list &L, addressDLL p);
void deleteLast(list &L, addressDLL p);
void deletAfter(list &L, addressDLL Q, addressDLL p);
void printInfo(list L);
void playLagu(addressDLL currentPlay);
void nextLagu();
void prevLagu();
void stopLagu();


//admin
void createListSLL(SLL &L);
bool isEmptySLL(SLL L);
addressSLL allocateSLL(infotype x);
void insertFirstSLL(SLL &L, addressSLL p);
void deleteFirstSLL(SLL &L, addressSLL p);
void deleteLastSLL(SLL &L, addressSLL p);
void deletAfterSLL(SLL &L, addressSLL Q, addressSLL p);
void printInfoSLL(SLL L);

#endif // MUSIC_H_INCLUDED
