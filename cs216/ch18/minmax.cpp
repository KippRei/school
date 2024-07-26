#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // to use sort()
using namespace std;

const int NUM_VALUES = 5;

// Input NUM_VALUES of TheType into the vector parameter
template<typename TheType> void Read(vector<TheType>& list) {
   for (int j = 0; j < NUM_VALUES; ++j) {
      cin >> list.at(j);
   }
}

// Output the elements of the vector parameter
template<typename TheType> void Write(vector<TheType>& list) {
   long unsigned int j;
   for (j = 0; j < list.size(); ++j) {
      cout << list.at(j) << " ";
   }
}

// Return the min, median, and max of the vector parameter in a new vector
template<typename TheType> vector<TheType> GetStatistics(vector<TheType>& list) {
   /* Type your code here. */
   vector<TheType> retList;
   retList.push_back(list.at(0));
   int median = list.size() / 2;
   retList.push_back(list.at(median));
   retList.push_back(list[list.size()-1]);
   //cout << retList[0] << " " << retList[1] << " " << retList[2];
   return retList;
}

// Read values into a vector, sort the vector, output the sorted vector,
// then output the min, median, and max of the sorted vector
template<typename TheType> void Run(vector<TheType>& list) {
   /* Type your code here. */
   Read(list);
   sort(list.begin(), list.end());
   Write(list);
   cout << endl;
   vector<TheType> list2 = GetStatistics(list);
   Write(list2);  
   cout << endl << endl;
}

int main() {
   vector<int> integers {1, 3, 5, 9, 7};
   Run(integers);
   cout << endl;

   vector<double> doubles(NUM_VALUES);
   Run(doubles);
   cout << endl;

   vector<string> strings(NUM_VALUES);
   Run(strings);

   return 0;
}
