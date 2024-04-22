#include "Artwork.h"
#include <iostream>

// TODO: Define default constructor
Artwork::Artwork() {
    title = "None";
    yearCreated = 0;
}
// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork(string t, int y, Artist a) {
    title = t;
    yearCreated = y;
    artist = a;
}
// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle() {
    return title;
}

int Artwork::GetYearCreated() {
    return yearCreated;
}

// TODO: Define PrintInfo() function
void Artwork::PrintInfo() {
    artist.PrintInfo();
    cout << "Title: " << title << ", " << yearCreated;
}