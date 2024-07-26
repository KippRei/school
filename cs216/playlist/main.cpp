#include <iostream>
#include "PlaylistNode.h"

void Testing(PlaylistNode*);
void SimpleOutput(PlaylistNode*, int);

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
    cout << endl;

    PlaylistNode* newNode = new PlaylistNode(newID, newSongName, newArtistName, newSongLength);
    if (headNode == 0) {
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
    Testing(headNode);

   return headNode;
}

// Removes song with ID provided by user
PlaylistNode* RemoveSong(PlaylistNode* headNode) {
    cin.ignore();
    string remID = "-";
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline(cin, remID);

    if (headNode != 0) {
        if (headNode->GetID().compare(remID) == 0) {
            PlaylistNode* newHead = headNode->GetNext();
            cout << "\"" << headNode->GetSongName() << "\" removed." << endl << endl;
            delete(headNode);
            return newHead;
        }
        else {
            PlaylistNode* lastNode = headNode;
            PlaylistNode* currNode = headNode->GetNext();
            while (currNode != 0) {
                if (currNode->GetID().compare(remID) == 0) {
                    cout << "\"" << currNode->GetSongName() << "\" removed." << endl << endl;
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
    Testing(headNode);

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
    while (true) {
        cout << "Enter new position for song:" << endl;
        getline(cin, newPos);
        try {
            newPosInt = stoi(newPos);
            break;
        } catch (...) {
            cout << "Please enter an integer." << endl;
        }
    }


    // First "cut" selected node out of list
    PlaylistNode* prevNode = headNode;
    PlaylistNode* currNode = headNode; 
    PlaylistNode* nodeToSwap = 0;
    
    //TODO: NO EXCEPTION HANDLING (OUT OF RANGE POSSIBLE)
    for (int i = 0; i < currPosInt - 1; i++) {
        prevNode = currNode;
        currNode = currNode->GetNext();
        if (currNode == 0) {
            cout << "Invalid selection." << endl;
            return headNode;
        }
    }
    
    // "Cut" node out of list
    if (currPosInt <= 1) {
        nodeToSwap = headNode;
        headNode = headNode->GetNext();
    }
    else {
        nodeToSwap = currNode;
        prevNode->SetNext(currNode->GetNext());
    }


    // Then put node in proper position in list
    if (newPosInt <= 1) {
        nodeToSwap->SetNext(headNode);
        headNode = nodeToSwap;
    }
    else {
        PlaylistNode* moveTo = headNode;
        for (int i = 0; i < newPosInt - 2; i++) {
            if (moveTo->GetNext() == 0) {
                break;
            }
            else {
                moveTo = moveTo->GetNext();
            }
        }
        nodeToSwap->InsertAfter2(moveTo);
    }

    cout << "\"" << nodeToSwap->GetSongName() << "\" moved to position " << newPos << endl << endl;
    
    // For testing
    Testing(headNode);

    return headNode;
}

PlaylistNode* OutputFullPlaylist(PlaylistNode* headNode, string playlistTitle) {
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

    if (headNode == 0) {
        cout << "Playlist is empty" << endl << endl;
        return headNode;
    }

    int counter = 1;
    PlaylistNode* currNode = headNode;
    while (currNode != 0) {
        SimpleOutput(currNode, counter);
        counter++;
        currNode = currNode->GetNext();
    }

    return headNode;
}

PlaylistNode* OutputSongsByArtist(PlaylistNode* headNode) {
   cin.ignore();
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl << endl;
    string artistName;
    getline(cin, artistName);
    int counter = 1;
    PlaylistNode* currNode = headNode;
    while(currNode != 0) {
        if (artistName.compare(currNode->GetArtistName()) == 0) {
            SimpleOutput(currNode, counter);
        }
        currNode = currNode->GetNext();
        counter++;
    }
    return headNode;
}

PlaylistNode* TotalTime(PlaylistNode* headNode) {
    PlaylistNode* currNode = headNode;
    int total = 0;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    while (currNode != 0) {
        total += currNode->GetSongLength();
        currNode = currNode->GetNext();
    }
    cout << "Total time: " << total << " seconds" << endl << endl;
    return headNode;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    switch (option) {
        case 'a':
            return AddSong(headNode);
        case 'd':
            return RemoveSong(headNode);
        case 'c':
            return ChangeSongPos(headNode);
        case 'o':
            return OutputFullPlaylist(headNode, playlistTitle);
        case 's':
            return OutputSongsByArtist(headNode);
        case 't':
            return TotalTime(headNode);
        default:
            return headNode;
    }
}

int main() {
   PlaylistNode* head = 0;
   string playlistTitle = "none";
   char option;

   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   cout << endl;

   while (option != 'q') {
        PrintMenu(playlistTitle);         
        cout << endl << "Choose an option:" << endl;
        cin >> option;
        head = ExecuteMenu(option, playlistTitle, head);
   }

   return 0;
}

void SimpleOutput(PlaylistNode* currNode, int counter) { 
        cout << counter << "." << endl;
        currNode->PrintPlaylistNode();
        // cout << "Unique ID: " << currNode->GetID() << endl;
        // cout << "Song Name: " << currNode->GetSongName() << endl;
        // cout << "Artist Name: " << currNode->GetArtistName() << endl;
        // cout << "Song Length (in seconds): " << currNode->GetSongLength() << endl;
        cout << endl;
}

void Testing(PlaylistNode *headNode)
{
   //  PlaylistNode *currNode1 = headNode;
   //  while (true)
   //  {
   //     cout << currNode1->GetID() << endl;
   //     if (currNode1->GetNext() == 0)
   //     {
   //          break;
   //     }
   //     else
   //     {
   //          currNode1 = currNode1->GetNext();
   //     }
   //  }
}