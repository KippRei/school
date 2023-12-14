#include <iostream>

int main() {
  float finalScr = 0;

  for (float i = 70; i < 90; i += 0.5) {
    float exam1 = 97;
    float exam2 = 95;
    float exam3 = 78.5;
    finalScr = i;
    float avg = (exam1 + exam2 + exam3) / 3;
    if (finalScr > exam3) {
      exam3 = (exam1 + exam2 + finalScr)/3;
      avg = (exam1 + exam2 + exam3) / 3;
    }
    else {
      finalScr = avg;
    }
    std::cout << "Final Score: " << finalScr << "\tTest Average: " << avg << "\t3rd Exam: " << exam3 << std::endl;
  }

  return 0;
}