#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {
   vector<int> userInts; // A vector to hold the user's input integers

   /* Type your code here. */
   string num;
   getline(cin, num);
   int numInt = stoi(num);
   int toPush;
   for (int i = 0; i < numInt; i++) {
      cin >> toPush;
      userInts.push_back(toPush);
   }
    string searchNum;
    cin.ignore();
   getline(cin, searchNum);
   int searchNumInt = stoi(searchNum);
   for (int i = 0; i < numInt; i++) {
      if (userInts[i] < searchNumInt) {
        cout << userInts[i] << ",";
      }
   }
   cout << endl;


   return 0;
}
