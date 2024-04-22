#include <iostream>
#include <vector>

using namespace std;

void dispMenu();
void menuChoice(char);
void dispRoster(vector<int>, vector<int>);
void addPlayer();
void deletePlayer();
void updateRoster();
void ratingFilter();
   
vector<int> playerRating;
vector<int> jerseyNumber;


int main() {
   int jerseyNum, rating;

   for (int i = 1; i < 6; i++) {
    cout << "Enter player " << i << "'s jersey number:" << endl;
    cin >> jerseyNum;
    jerseyNumber.push_back(jerseyNum);
    cin.ignore();
    cout << "Enter player " << i << "'s rating:" << endl;
    cin >> rating;
    playerRating.push_back(rating);
    cin.ignore();
    cout << endl;
   }
    dispRoster(jerseyNumber, playerRating);
   dispMenu();

   return 0;
}

void dispMenu() {
    char option;
    cout << "MENU\n\
a - Add player\n\
d - Remove player\n\
u - Update player rating\n\
r - Output players above a rating\n\
o - Output roster\n\
q - Quit\n\n\
Choose an option:\n";

    cin >> option;
    menuChoice(option);
}

void menuChoice(char opt) {
    switch(opt) {
        case 'a':
            addPlayer();
            break;
        case 'd':
            deletePlayer();
            break;
        case 'u':
            updateRoster();
            break;
        case 'r':
            ratingFilter();
            break;
        case 'o':
            dispRoster(jerseyNumber, playerRating);
            break;
        case 'q':
            exit(0);
        default:
            dispMenu();
    }
}

void addPlayer() {
    int num, rating;
    cout << "Enter a new player's jersey number:" << endl;
    cin >> num;
    cin.ignore();
    cout << "Enter the player's rating:" << endl;
    cin >> rating;
    cin.ignore();
    jerseyNumber.push_back(num);
    playerRating.push_back(rating);

    cout << endl;
    dispMenu();
}

void deletePlayer() {
    int num;
    cout << "Enter a jersey number:" << endl;
    cin >> num;
    cin.ignore();
    for (int i = 0; i < jerseyNumber.size(); i++) {
        if (jerseyNumber[i] == num) {
            jerseyNumber.erase(jerseyNumber.begin() + i);
            playerRating.erase(playerRating.begin() + i);
            break;
        }
    }
    cout << endl;
    dispMenu();
}

void updateRoster() {
    int num;
    cout << "Enter a jersey number:" << endl;
    cin >> num;
    cin.ignore();
    for (int i = 0; i < jerseyNumber.size(); i++) {
        if (jerseyNumber[i] == num) {
            cout << "Enter a new rating for player:" << endl;
            cin >> num;
            playerRating[i] = num;
        }
    }
    cout << endl;
    dispMenu();
}

void ratingFilter() {
    int num;
    cout << "Enter a rating:" << endl;
    cin >> num;
    cout << "\nABOVE " << num << endl;
    for (int i = 0; i < jerseyNumber.size(); i++) {
        if (playerRating[i] > num) {
            cout << "Player " << i+1 << " -- Jersey number: " << jerseyNumber[i] << ", Rating: " << playerRating[i] << endl;
        }
    }
    cout << endl;
    dispMenu();
}

void dispRoster(vector<int> jerseys, vector<int> ratings) {
    cout << "ROSTER" << endl;
    for (int i = 0; i < jerseys.size(); i++) {
        cout << "Player " << i+1 << " -- Jersey number: " << jerseys[i] << ", Rating: " << ratings[i] << endl;
    }
    cout << endl;
    dispMenu();
}