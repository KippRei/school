#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void InsertAfter(PlaylistNode*);
        void InsertAfter2(PlaylistNode*);
        void SetNext(PlaylistNode*);
        void PrintPlaylistNode();

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};