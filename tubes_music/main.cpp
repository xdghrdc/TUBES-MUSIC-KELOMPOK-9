#include <iostream>
#include"music.h"
using namespace std;

void loadPlaylistToPlayer(list &playerQueue, addressPlaylist UserPlaylist){
    addressDLL temp;
    while (!isEmptyInLibrary(playerQueue)){
        deleteFirstInLibrary(playerQueue, temp);
        delete temp;
    }
    stopLagu();

    addresslagu q = UserPlaylist->firstlagu;
    if (q==nullptr){
        cout << "Playlist ini kosong." << endl;
        return;
    }
    while (q != nullptr){
        insertLastInLibrary(playerQueue, allocateLibrary(q->lagu));

        q = q->next;
    }
    cout << ">> Berhasil memuat playlist " << UserPlaylist->info.namaplaylist << " ke player." << endl;
}

// --- MENU ---

void menuAdmin(list &masterLibrary){
    int pilihan;
    music data;
    string HapusId;
    adrNode rootTree = nullptr;
    addressDLL tempDLL;

    do{
        cout <<"\n=== MENU ADMIN (LIBRARY MASTER) ===" << endl;
        cout <<"1. Tambah Lagu Baru" << endl;
        cout <<"2. Hapus Lagu (dengan ID)" << endl;
        cout <<"3. Tampilkan Library" << endl;
        cout <<"4. Tampilkan Library (Urutan Durasi)" << endl;
        cout <<"0. Kembali" << endl;
        cout <<"Pilihan: ";
        cin >> pilihan;

        switch (pilihan){
        case 1:
            cout << "ID Lagu        :"; cin >> data.Id_lagu;
            cout << "Judul Lagu     :"; cin.ignore();getline(cin, data.judul_lagu);
            cout << "Penyanyi       :"; getline(cin, data.penyanyi);
            cout << "Durasi (menit) :"; cin >> data.durasi;
            cout << "Genre          :"; cin >> data.genre_lagu;
            insertLastInLibrary(masterLibrary, allocateLibrary(data));
            cout << "Lagu berhasil ditambahkan ke Library. " << endl;
            break;
        case 2:
            printInfoLibrary(masterLibrary);
            cout << "Masukkan ID Lagu yang ingin dihapus: "; cin >> HapusId;
            deleteSongByID(masterLibrary, HapusId);
            break;
        case 3:
            printInfoLibrary(masterLibrary);
            break;
        case 4:
            CreateTree(rootTree);
            if(isEmptyInLibrary(masterLibrary)){
                cout << "Library kosong." << endl;
            }else{
                tempDLL = masterLibrary.first;
                while(tempDLL != nullptr){
                    adrNode newNode = createNode(tempDLL->info);
                    insertBerdasarkanDurasi(rootTree, newNode);
                    tempDLL = tempDLL->next;
                }
                cout << "\n=== DAFTER LAGU (URUTAN DURASI) ===" <<endl;
                printTreeInOrder(rootTree);
                cout << "====================================" << endl;
            }
            break;
        }
    } while (pilihan != 0);
}

void menuUser(list &masterLibrary, ListPlaylist &UserPlaylist, list &PlayerQueue, list &FavList){
    int pilihan;
    string namaPlaylist, user, idLagu, cariPlaylist;

    do{
        cout << "\n=== MENU USER ===" << endl;
        cout << "   --- PLAYLIST ---" << endl;
        cout << "1. Buat Playlist Baru" << endl;
        cout << "2. Tambah lagu ke playlist" << endl;
        cout << "3. Lihat semua playlist" << endl;
        cout << "4. LOAD playlist ke player" << endl;
        cout << "   --- FAVORITES ---" << endl;
        cout << "5. Tambah ke favorit" << endl;
        cout << "6. Lihat Favorit" << endl;
        cout << "7. Mainkan Favorit" << endl;
        cout << "   --- PLAYER CONTROLS ---" << endl;
        cout << "8. Play lagu dari library" << endl;
        cout << "9. Play lagu dari playlist" << endl;
        cout << "10. Next lagu" << endl;
        cout << "11. Prev lagu" << endl;
        cout << "12. Stop lagu" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilihan: " << endl;
        cin >> pilihan;

        switch (pilihan){
        case 1:
            cout << "Nama Playlist :"; cin.ignore(); getline(cin, namaPlaylist);
            cout << "Pemilik       :"; getline(cin, user);
            addPlaylist(UserPlaylist, allocatePlaylist(namaPlaylist, user));
            cout << "Playlist berhasil dibuat." << endl;
            break;

        case 2:
            displayPlaylist(UserPlaylist);
            if (isEmptyPlaylist(UserPlaylist)) break;

            cout << "Masukkan nama Playlist tujuan: "; cin.ignore();getline(cin, cariPlaylist);
            {
                addressPlaylist p = searchPlaylist(UserPlaylist, cariPlaylist);
                if (p != nullptr){
                    printInfoLibrary(masterLibrary);
                    cout << "Masukkan ID lagu dari library: "; cin >> idLagu;

                    addressDLL laguDitemukan = searchSongInLibrary(masterLibrary, idLagu);
                    if (laguDitemukan != nullptr){
                        addLaguToPlaylist(p, allocateLagu(laguDitemukan->info));
                        cout << "Lagu berhasil ditemukan." << cariPlaylist << endl;
                    }else{
                        cout << "ID lagu tidak ditemukan." << endl;
                    }
                }else{
                    cout << "Playlist tidak ditemukan." << endl;
                }
            }
            break;

        case 3:
            displayPlaylist(UserPlaylist);
            break;

        case 4:
            cout << "Masukkan nama playlist yang akan diputar: "; cin.ignore();getline(cin, cariPlaylist);
            {
                addressPlaylist p = searchPlaylist(UserPlaylist, cariPlaylist);
                if (p!= nullptr){
                    loadPlaylistToPlayer(PlayerQueue, p);
                }else{
                    cout << "Playlist tidak ditemukan." << endl;
                }
            }
            break;

        case 5:
            printInfoLibrary(masterLibrary);
            cout << "Masukkan ID lagu favorit: "; cin >> idLagu;
            {
                addressDLL Ketemu = searchSongInLibrary(masterLibrary, idLagu);
                if (Ketemu != nullptr){
                    addToFavorites(FavList, Ketemu->info);
                }else{
                    cout << "Lagu tidak ditemukan." << endl;
                }
            }
            break;
        case 6:
            showFavorites(FavList);
            break;

        case 7:
            loadFavoritesToPlayer(PlayerQueue, FavList);
            break;

        case 8:
            cout << "\n=== DAFTAR SEMUA LAGU ==="<<endl;
            printInfoLibrary(masterLibrary);

            cout << "Masukkan ID Lagu yang ingin diputar: "; cin >> idLagu;
            {
                addressDLL laguKetemu = searchSongInLibrary(masterLibrary, idLagu);
                if (laguKetemu != nullptr){
                    playLagu(laguKetemu);
                    cout << "Memuat dari Library." << endl;
                }else{
                    cout << "Lagu tidak ditemukan." << endl;
                }
            }
            break;
        case 9:
            if (!isEmptyInLibrary(PlayerQueue)){
                playLagu(PlayerQueue.first);
            }else{
                cout << "Player kosong. Silahkan LOAD playlist dulu (Menu no. 4)" << endl;
            }
            break;

        case 10:
            nextLagu();
            break;
        case 11:
            prevLagu();
            break;
        case 12:
            stopLagu();
            break;
        }
    } while (pilihan != 0);
}

int main()
{
    list MasterLibrary;
    createLibrary(MasterLibrary);

    ListPlaylist MyPlaylist;
    CreatePlaylist(MyPlaylist);

    list playerQueue;
    createLibrary(playerQueue);

    list Favorites;
    createLibrary(Favorites);

    music m1 = {"1", "Hati-Hati", "Tulus", 4, "Pop"};
    music m2 = {"2", "Sial", "Mahalini", 3, "Pop"};
    music m3 = {"3", "Numb", "LinkinPark", 4, "Rock"};

    insertLastInLibrary(MasterLibrary, allocateLibrary(m1));
    insertLastInLibrary(MasterLibrary, allocateLibrary(m2));
    insertLastInLibrary(MasterLibrary, allocateLibrary(m3));
    insertLastInLibrary(MasterLibrary, allocateLibrary(m4));

    addressPlaylist pl1 = allocatePlaylist("Galau", "User 1");
    addPlaylist(MyPlaylist, pl1);

    int PilihanUtama;
    do{
        cout << "\n===================================" << endl;
        cout << "      APLIKASI MUSIC PLAYER        " << endl;
        cout << "===================================" << endl;
        cout << "1. Masuk sebagai ADMIN " << endl;
        cout << "2. Masuk sebagai USER " << endl;
        cout << "0. KELUAR " << endl;
        cout << "Pilihan: " << endl;
        cin >> PilihanUtama;

        switch(PilihanUtama){
        case 1:
            menuAdmin(MasterLibrary);
            break;
        case 2:
            menuUser(MasterLibrary, MyPlaylist, playerQueue, Favorites);
            break;
        case 0:
            cout << "Terima kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak ada." << endl;
        }
    }while (PilihanUtama != 0);

    return 0;
}

