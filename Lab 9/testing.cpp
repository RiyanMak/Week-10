#include <iostream>
#include <iomanip>

using namespace std;

// Function to get song data from the user
void getSongData(string artists[], string titles[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter artist for song " << i + 1 << ": ";
        getline(cin, artists[i]);

        cout << "Enter title for song " << i + 1 << ": ";
        getline(cin, titles[i]);
    }
}

// Function to swap two strings
void swapStrings(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Function to sort the playlist using bubble sort
void sortPlaylist(string artists[], string titles[], int size) {
    bool madeAswap = true;
    for (int maxElement = size - 1; maxElement > 0 && madeAswap; maxElement--) {
        madeAswap = false;
        for (int i = 0; i < maxElement; i++) {
            if (artists[i] > artists[i + 1]) {
                swapStrings(artists[i], artists[i + 1]);
                swapStrings(titles[i], titles[i + 1]); // Swap titles along with artists
                madeAswap = true;
            }
        }
    }
}

// Function to display the sorted playlist
void displayPlaylist(const string artists[], const string titles[], int size) {
    cout << "Playlist";
    cout << "Artist                        Title";
    cout << "======================================";
    for (int i = 0; i < size; i++) {
        cout << setw(30) << left << artists[i]
                  << setw(20) << left << titles[i] << endl;
    }
}

int main() {
    const int PLAYLIST_SIZE = 10;
    string artists[PLAYLIST_SIZE];
    string titles[PLAYLIST_SIZE];

    // Get song data from the user
    getSongData(artists, titles, PLAYLIST_SIZE);

    // Sort the playlist
    sortPlaylist(artists, titles, PLAYLIST_SIZE);

    // Display the sorted playlist
    displayPlaylist(artists, titles, PLAYLIST_SIZE);

    return 0;
}