#include <iostream>
#include"music.h"

using namespace std;

//Player
addressDLL currentPlay = nullptr;

void playLagu(addressDLL lagu){
    if (lagu == nullptr){
        cout << "Lagu tidak ditemukan." << endl;
        return;
    }
    currentPlay = lagu;
    cout << "Memutar: " << lagu->info.judul_lagu << " - " << lagu->info.penyanyi << endl;
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
    cout << "Next: " << currentPlay->info.judul_lagu << " - " << currentPlay->info.penyanyi << endl;
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
    cout << "Prev: " << currentPlay->info.judul_lagu << " - " << currentPlay->info.penyanyi << endl;
}
void stopLagu(){
    if (currentPlay == nullptr){
        cout << "Tidak ada lagu yang sedang diputar." << endl;
        return;
    }
    cout << "Stop: " << currentPlay->info.judul_lagu << " - " << currentPlay->info.penyanyi << endl;
    currentPlay = nullptr;
}
