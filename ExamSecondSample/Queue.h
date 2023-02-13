#ifndef LABA__QUEUE_H_
#define LABA__QUEUE_H_

#include <vector>
#include<string>
#include <fstream>

struct Node {
  int value_;
  Node *next_;
};

class QueueOnNodes {
 private:
  Node *head_;
  Node *tail_;
  int size_;
 public:
  QueueOnNodes() : size_(0) {
    head_ = nullptr;
    tail_ = nullptr;
  }
  void fill(std::string path);

  ~QueueOnNodes() {
    while (size_ != 0) {
      pop();
    }
  };

  void push(int value);

  int pop();

  int front();

  int back();

  bool isEmpty();

  int size() const;

  QueueOnNodes operator=(const QueueOnNodes &old);

  std::vector<int> getNumbers() const;
};

#endif //LABA__QUEUE_H_
