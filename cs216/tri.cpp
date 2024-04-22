#include <iostream>
#include "Triangle.cpp"
using namespace std;

int main() {
   Triangle triangle1;
   Triangle triangle2;

    string tri1Base; 
    string tri1Height;
    string tri2Base;
    string tri2Height;

    cin >> tri1Base;
    cin >> tri1Height;
    cin.ignore();
    cin >> tri2Base;
    cin >> tri2Height;

    // getline(cin, tri1Base);
    // getline(cin, tri1Height);
    // getline(cin, tri2Base);
    // getline(cin, tri2Height);

    double t1Base, t1Height, t2Base, t2Height;

    t1Base = stod(tri1Base);
    t1Height = stod(tri1Height);
    t2Base = stod(tri2Base);
    t2Height = stod(tri2Height);

    triangle1.SetBase(t1Base);
    triangle1.SetHeight(t1Height);
    triangle2.SetBase(t2Base);
    triangle2.SetHeight(t2Height);

   cout << "Triangle with smaller area:" << endl;

    if (triangle1.GetArea() > triangle2.GetArea()) {
        triangle2.PrintInfo();
    }
    else {
        triangle1.PrintInfo();
    }
   return 0;
}