#include <iostream>
#include <fstream>
#include <iomanip>

void ReadPhoto() {
    std::fstream fs;
    fs.open("./Cat03.jpg");
    int i = 0;
    int val = 0;
    while (i < 10) {
        val = fs.get();
        std::cout << std::hex << val << std::endl;
        i++;
    }
    
}

int main() {
    ReadPhoto();
    return 0;
}