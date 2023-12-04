#include <iostream>
#include <string>
#include <cctype>
#include <string.h>

using namespace std;
struct Names

{

   string first;

   string last;

};

int main ()

{

  Names customer = {"asdf", "aa"};

  cout << customer.first << endl;

  cout << customer.last << endl;

return 0;

}