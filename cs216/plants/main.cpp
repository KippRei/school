#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints a vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> plants) {
   int count = 1;
   for (Plant* p: plants) {
      cout << "Plant " << count << " Information:" << endl;
      p->PrintInfo();
      cout << endl;
      count++;
   }
}

int main() {
   // TODO: Declare a vector called myGarden that can hold object of type plant pointer
   vector<Plant*> myGarden;
   // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
   //       colorOfFlowers, isAnnual
   string plantName, flowerName, colorOfFlowers, plantCost, flowerCost;
   bool isAnnual;
   string input;

   cin >> input;

   while(input != "-1") {
   // TODO: Check if input is a plant or flower
   //       Store as a plant object or flower object
   //       Add to the vector myGarden
      if (input.compare("plant") == 0) {
         cin >> plantName;
         cin >> plantCost;
         cin.ignore();
         Plant* p = new Plant();
         p->SetPlantName(plantName);
         p->SetPlantCost(stoi(plantCost));
         myGarden.push_back(p);
      }
      else {
         string chkAnnual;
         cin >> flowerName;
         cin >> flowerCost;
         cin >> chkAnnual;
         cin >> colorOfFlowers;
         
         if (chkAnnual.compare("true") == 0) {
            isAnnual = true;
         }
         else {
            isAnnual = false;
         }

         cin.ignore();
         Flower* f = new Flower();
         f->SetPlantName(flowerName);
         f->SetPlantCost(stoi(flowerCost));
         f->SetPlantType(isAnnual);
         f->SetColorOfFlowers(colorOfFlowers);
         myGarden.push_back(f);
      }
      cin >> input;
   }

   // TODO: Call the method PrintVector to print myGarden
   PrintVector(myGarden);

   for (size_t i = 0; i < myGarden.size(); ++i) {
      delete myGarden.at(i);
   }
   
   return 0;
}