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
   
   int lowest = userInts[0];
   int secondLowest = userInts[1];
   
   for (int i = 2; i < numInt; i++) {
    cout << userInts[i] << endl;
      if (userInts[i] < lowest) {
        secondLowest = lowest;
        lowest = userInts[i];
      }
      else if (userInts[i] < secondLowest) {
         secondLowest = userInts[i];
      }
   }
   cout << lowest << " and " << secondLowest << endl;


   return 0;
}
