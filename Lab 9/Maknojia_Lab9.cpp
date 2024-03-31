//******************************************************************
// Binary String Search
// Programmer: Riyan Maknojia
// Completed : 03/31/24
// Status    : Completed
//
// This program demonstrates the use of sort and store it in a array
// and display it to the user.
//******************************************************************


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to represent a song
struct Song {
    string artist;
    string title;
};

// Function to get song data from the user
void getSongData(Song playlist[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter artist for song " << i + 1 << ": ";
        getline(cin, playlist[i].artist);

        cout << "Enter title for song " << i + 1 << ": ";
        getline(cin, playlist[i].title);
    }
}

// Function to swap two songs
void swapSongs(Song &a, Song &b) {
    Song temp = a;
    a = b;
    b = temp;
}

// Function to sort the playlist using bubble sort
void sortPlaylist(Song playlist[], int size) {
    bool madeAswap = true;
    for (int maxElement = size - 1; maxElement > 0 && madeAswap; maxElement--) {
        madeAswap = false;
        for (int i = 0; i < maxElement; i++) {
            if (playlist[i].artist > playlist[i + 1].artist) {
                swapSongs(playlist[i], playlist[i + 1]);
                madeAswap = true;
            }
        }
    }
}

// Function to display the sorted playlist
void displayPlaylist(const Song playlist[], int size) {
    cout << "Playlist\n";
    cout << "Artist                        Title \n";
    cout << "======================================\n";
    for (int i = 0; i < size; i++) {
        cout << setw(30) << left << playlist[i].artist
             << setw(20) << left << playlist[i].title << endl;
    }
}

int main() {
    const int PLAYLIST_SIZE = 4;
    Song playlist[PLAYLIST_SIZE];

    // Get song data from the user
    getSongData(playlist, PLAYLIST_SIZE);

    // Sort the playlist
    sortPlaylist(playlist, PLAYLIST_SIZE);

    // Display the sorted playlist
    displayPlaylist(playlist, PLAYLIST_SIZE);

    return 0;
}