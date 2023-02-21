#include <iostream>
#include <vector>
#include "Tprk.h"

using namespace std;

int main() {
  QueueOnNodes queue;
  queue.fill("input.txt");
  vector<int> num = queue.getNumbers();
  fstream out("out.txt");
  out << "Numbers:\n";
  for (int i = 0; i < queue.size(); i++) {
    out << num[i] << " ";
  }
  out << "\n";
  Tprk l("input.txt");
  out << "Matrix:\n";
  out << l;
  l.sort();
  out << "Sorted Matrix:\n";
  out << l;
  out.close();
  return 0;
}
