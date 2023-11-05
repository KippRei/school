#include <iostream>

int main() {
    int i = 1;
    for ( ; i <= 10; i++) {
        int j = 0;
        while (j < i) {
            std::cout<<"+";
            j++;
        }
        std::cout<<std::endl;
    }

    for (i = 10 ; i >=1 ; i--) {
        int j = 0;
        while (j < i) {
            std::cout<<"+";
            j++;
        }
        std::cout<<std::endl;
    }
    return 0; 
}