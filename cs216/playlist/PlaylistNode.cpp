#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string aName, string sName, int sLen) {
    uniqueID = id;
    artistName = aName;
    songName = sName;
    songLength = sLen;
    nextNodePtr = 0;
}

string PlaylistNode::GetID() {
    return uniqueID;
}

string PlaylistNode::GetSongName() {
    return songName;
}

string PlaylistNode::GetArtistName() {
    return artistName;
}

int PlaylistNode::GetSongLength() {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* temp = nodePtr->GetNext();
    nodePtr->SetNext(this);
    this->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}