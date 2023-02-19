#ifndef LABA__TPRK_H_
#define LABA__TPRK_H_

#include <vector>
#include <cmath>
#include <string>
#include "Queue.h"
#include <algorithm>

using namespace std;

bool isdigit(char a);

vector<int> getKprNumbers(const QueueOnNodes &queue);

bool isNumberWithEqual(const int number);

bool isNumberKpr(const int number);

int sorting(const int number);

int overturnNumber(const int number);

vector<int> algorithm(const int number);

vector<vector<int> > createMatrix(const vector<int> &numbers);

class Tprk {
 private:
  int amountOfNumbers;
  int amountOfInterestingNumbers;
  vector<int> interestingNumbers;
  vector<vector<int> > matrix;
 public:
  Tprk() : amountOfInterestingNumbers(0), amountOfNumbers(0) {}

  Tprk(int number) : amountOfNumbers(1) {
    if (isNumberKpr(number)) {
      amountOfInterestingNumbers++;
      interestingNumbers.push_back(number);
      matrix = createMatrix(interestingNumbers);
    }
  }

  Tprk(string path) {
    QueueOnNodes numbers;
    numbers.fill(path);
    amountOfNumbers = numbers.size();
    interestingNumbers = getKprNumbers(numbers);
    amountOfInterestingNumbers = interestingNumbers.size();
    matrix = createMatrix(interestingNumbers);
  }

  void add(const int number);

  ~Tprk() = default;

  void sort();

  Tprk operator=(const Tprk &old);

  friend ostream &operator<<(ostream &out, const Tprk &a);

  vector<int> operator[](const int index);
};

#endif //LABA__TPRK_H_
