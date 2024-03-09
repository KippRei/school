#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;   
}

// Adds song at end of list
PlaylistNode* AddSong(PlaylistNode* headNode) {
    cin.ignore();
    string newID = "-";
    string newSongName = "-";
    string newArtistName = "-";
    int newSongLength = -1;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline(cin, newID);
    cout << "Enter song's name:" << endl;
    getline(cin, newSongName);
    cout << "Enter artist's name:" << endl;
    getline(cin, newArtistName);
    while (newSongLength < 0) {
        string convertToInt;
        cout << "Enter song's length (in seconds):" << endl;
        getline(cin, convertToInt);
        try {
            newSongLength = stoi(convertToInt);
        } catch(...) { 
            cout << "Please enter a number greater than 0." << endl;
        }
    }

    PlaylistNode* newNode = new PlaylistNode(newID, newArtistName, newSongName, newSongLength);
    if (headNode == nullptr) {
        headNode = newNode;
    }
    else {
        PlaylistNode* currNode = headNode;
        while (currNode->GetNext() != 0) {
            currNode = currNode->GetNext();
        }
            currNode->SetNext(newNode);
    }

    
    // For testing
    PlaylistNode* currNode = headNode;
    while (true) {
        cout << currNode->GetID() << endl;
        if (currNode->GetNext() == 0) {
            break;
        }
        else {
            currNode = currNode->GetNext();
        }
    }

   return headNode;
}

// Removes song with ID provided by user
PlaylistNode* RemoveSong(PlaylistNode* headNode) {
    cin.ignore();
    string remID = "-";
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline(cin, remID);

    if (headNode != nullptr) {
        if (headNode->GetID().compare(remID) == 0) {
            return headNode->GetNext();
        }
        else {
            PlaylistNode* lastNode = headNode;
            PlaylistNode* currNode = headNode->GetNext();
            while (currNode != nullptr) {
                if (currNode->GetID().compare(remID) == 0) {
                    lastNode->SetNext(currNode->GetNext());
                    delete(currNode);
                    break;
                }
                lastNode = currNode;
                currNode = currNode->GetNext();
            }   
        }
    }
    
    // For testing
    PlaylistNode* currNode = headNode;
    while (true) {
        cout << currNode->GetID() << endl;
        if (currNode->GetNext() == nullptr) {
            break;
        }
        else {
            currNode = currNode->GetNext();
        }
    }

   return headNode;
}

// Change position of song in playlist
PlaylistNode* ChangeSongPos(PlaylistNode* headNode) {
    cin.ignore();
    string currPos, newPos;
    int currPosInt = -1;
    int newPosInt = -1;
    cout << "CHANGE POSITION OF SONG" << endl;
    while (currPosInt < 0) {
        cout << "Enter song's current position:" << endl;
        getline(cin, currPos);
        try {
            currPosInt = stoi(currPos);
        } catch (...) {
            cout << "Please enter a positive, integer." << endl;
        }
    }
    while (newPosInt < 0) {
        cout << "Enter new position for song:" << endl;
        getline(cin, newPos);
        try {
            newPosInt = stoi(newPos);
        } catch (...) {
            cout << "Please enter a positive, integer." << endl;
        }
    }

    PlaylistNode* prevNode = nullptr;
    PlaylistNode* currNode = headNode; 
    PlaylistNode* nodeToSwap = nullptr;
    int count = 0; // Counts number of nodes (like index)
    //TODO: NO EXCEPTION HANDLING (OUT OF RANGE POSSIBLE)
    for (int i = 0; i < currPosInt; i++) {
        prevNode = currNode;
        currNode = currNode->GetNext();
    }
    // "Cut" node out of list
    nodeToSwap = currNode;
    prevNode->SetNext(currNode->GetNext());

    if (newPosInt < 1) {
        nodeToSwap->SetNext(headNode->GetNext());
        headNode = nodeToSwap;
    }
    else {
        PlaylistNode* moveTo = headNode;
        for (int i = 0; i < newPosInt - 1; i++) {
            moveTo = moveTo->GetNext();
        }
        nodeToSwap->InsertAfter(moveTo);
    }
    
    // For testing
    PlaylistNode* currNode = headNode;
    while (true) {
        cout << currNode->GetID() << endl;
        if (currNode->GetNext() == nullptr) {
            break;
        }
        else {
            currNode = currNode->GetNext();
        }
    }

   return headNode;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    if (option == 'a') {
        return AddSong(headNode);
    }
    else if (option == 'd') {
        return RemoveSong(headNode);
    }
    else if (option == 'c') {
        return ChangeSongPos(headNode);
    }
    else {
        return headNode;
    }
}

int main() {
   PlaylistNode* head = nullptr;
   string playlistTitle = "none";
   char option;

   cout << "Enter playlist's title:" << endl;
   cin >> playlistTitle;

   while (option != 'q') {
        PrintMenu(playlistTitle);
        cout << endl << "Choose an option:" << endl;
        cin >> option;
        head = ExecuteMenu(option, playlistTitle, head);
   }

   return 0;
}

