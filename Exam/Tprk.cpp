#include "Tprk.h"
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include "Queue.h"

using namespace std;

bool isdigit(char a) {
  return (a >= '0' && a <= '9');
}

vector<int> getKprNumbers(const QueueOnNodes &queue) {
  vector<int> answer;
  vector<int> raw = queue.getNumbers();
  for (int i = 0; i < queue.size(); i++) {
    if (isNumberKpr(raw[i])) {
      answer.push_back(raw[i]);
    }
  }
  return answer;
}

bool isNumberWithEqual(const int number) {
  return (number / 1000 == number / 100 % 10) && (number / 100 % 10 == number / 10 % 10)
      && (number / 10 % 10 == number % 10);
}

bool isNumberKpr(const int number) {
  return (number / 10000 == 0 && number / 1000 != 0) && !isNumberWithEqual(number);
}

int sorting(const int number) {
  int digit;
  vector<int> digits;
  for (int i = 0; i < 4; i++) {
    digit = number / (int(pow(10, i))) % 10;
    digits.push_back(digit);
  }
  for (int i = 0; i < digits.size() - 1; i++) {
    for (int j = 0; j < digits.size() - i - 1; j++) {
      if (digits[j] < digits[j + 1]) {
        swap(digits[j], digits[j + 1]);
      }
    }
  }
  return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

int overturnNumber(const int number) {
  if (number == 0) {
    return 0;
  }
  int max = 0;
  while (number / int(pow(10, max)) != 0) {
    max++;
  }
  return number % 10 * int(pow(10, max - 1)) + overturnNumber(number / 10);
}

vector<int> algorithm(const int number) {
  int tmp = number;
  int steps = 0;
  vector<int> answer;
  answer.push_back(steps);
  while (tmp != 6174) {
    answer.push_back(sorting(tmp));
    answer.push_back(overturnNumber(sorting(tmp)));
    tmp = abs(sorting(tmp) - overturnNumber(sorting(tmp)));
    answer.push_back(tmp);
    steps++;
  }
  answer[0] = steps;
  return answer;
}

vector<vector<int>> createMatrix(const vector<int> &numbers) {
  vector<vector<int>> matrix;
  for (int i = 0; i < numbers.size(); i++) {
    matrix.push_back(algorithm(numbers[i]));
  }
  return matrix;
}

void Tprk::add(const int number) {
  if (isNumberKpr(number)) {
    amountOfInterestingNumbers++;
    vector<int> a = algorithm(number);
    matrix.push_back(a);
  }
}
void Tprk::sort() {
  std::sort(matrix.begin(), matrix.end());
}

Tprk Tprk::operator=(const Tprk &old) {
  if (this == &old)
    return *this;
  amountOfInterestingNumbers = old.amountOfInterestingNumbers;
  amountOfNumbers = old.amountOfNumbers;
  interestingNumbers = old.interestingNumbers;
  matrix = old.matrix;
  return *this;
}

ostream &operator<<(ostream &out, const Tprk &a) {
  for (int i = 0; i < a.matrix.size(); i++) {
    for (int j = 0; j < a.matrix[i].size(); j++) {
      out << a.matrix[i][j] << " ";
    }
    out << "\n";
  }
  out << "\n";
  return out;
}

vector<int> Tprk::operator[](const int index) {
  return matrix[index];
}