#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <string>
using namespace std;

typedef struct elmlist_DLL* addressDLL;
typedef struct elmPlaylsit* addressPlaylist;
typedef struct elmlagu* addresslagu;
typedef struct Node* adrNode;

struct music{
    string Id_lagu;
    string judul_lagu;
    string penyanyi;
    int durasi;
    string genre_lagu;
};
struct playlist{
    string namaplaylist;
    string user;
};
// DLL (Library lagu & Player)
struct elmlist_DLL{
    music info;
    addressDLL next;
    addressDLL prev;
};
// Playlist (Header Playlist User)
struct elmPlaylsit{
    playlist info;
    addressPlaylist next;
    addressPlaylist prev;
    addresslagu firstlagu;

};
// Lagu (Isi Playlist user)
struct elmlagu{
    music lagu;
    addresslagu next;
    addresslagu prev;
};

struct ListPlaylist{
    addressPlaylist first;
    addressPlaylist last;
};


struct list{
    addressDLL first;
    addressDLL last;
};

struct Node{
    music info;
    adrNode left;
    adrNode right;
};

extern addressDLL currentPlay;

//sorting
void CreateTree(adrNode &root);
adrNode createNode(music x);
void insertNode(adrNode &root, adrNode p);
adrNode searchNodeID(adrNode root, string x);
adrNode searchNodeDurasi(adrNode root, music x);
void insertBerdasarkanDurasi(adrNode &root, adrNode p);
void printTreeInOrder(adrNode root);

//Admin (DLL)
void createLibrary(list &L);
bool isEmptyInLibrary(list L);
addressDLL allocateLibrary(music x);
void insertFirstInLibrary(list &L, addressDLL p);
void insertLastInLibrary(list &L, addressDLL p);
void deleteFirstInLibrary(list &L, addressDLL &p);
void deleteLastInLibrary(list &L, addressDLL &p);
void deletAfterInLibrary(list &L, addressDLL Q, addressDLL &p);
void deleteSongByID(list &L, string Id_lagu);
addressDLL searchSongInLibrary(list L, string Id_lagu);
void printInfoLibrary(list L);


//User
void CreatePlaylist(ListPlaylist &l);
bool isEmptyPlaylist(ListPlaylist l);
bool isEmptyLagu(addresslagu p);
addressPlaylist allocatePlaylist(string namaplaylist, string user);
addresslagu allocateLagu(music dataLagu);
void addPlaylist(ListPlaylist &l, addressPlaylist p);
void addLaguToPlaylist(addressPlaylist &p, addresslagu q);
addressPlaylist searchPlaylist(ListPlaylist l, string namaplaylist);
void displayPlaylist(ListPlaylist l);

// Favorit
bool isFavorite(list Fav, string idLagu);
void addToFavorites(list &Fav, music lagu);
void showFavorites(list Fav);
void loadFavoritesToPlayer(list &PlayerQueue, list Fav);

//Player
void playLagu(addressDLL currentPlay);
void nextLagu();
void prevLagu();
void stopLagu();

#endif // MUSIC_H_INCLUDED
