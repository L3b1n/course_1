#include "Queue.h"

void QueueOnNodes::fill(std::string path) 
{
  std::ifstream file(path);
  QueueOnNodes answer;
  std::string buffer;
  int num0;
  int num1;
  while (!file.eof()) 
  {
    getline(file, buffer);
    for (int i = 0; i < buffer.size(); i++) 
    {
      if (isdigit(buffer[i])) 
      {
        num0 = buffer[i] - 48;
        num1 = (num1 * 10) + num0;
      }
      if (isdigit(buffer[i]) && !isdigit(buffer[i + 1])) 
      {
        // num1 - отделенное число
        push(num1);
        num0 = 0;
        num1 = 0;
      }
    }
  }
  file.close();
}

void QueueOnNodes::push(int value) 
{
  Node *a = new(Node);
  a->next_ = nullptr;
  a->value_ = value;
  if (size_ != 0) 
    tail_->next_ = a;
  tail_ = a;
  if (size_ == 0) 
    head_ = tail_;
  size_++;
}

int QueueOnNodes::pop() 
{
  if (head_ != nullptr) 
  {
    Node *tmp = head_;
    head_ = tmp->next_;
    int answer = tmp->value_;
    size_--;
    if (tmp == nullptr) return 0;
    delete tmp;
    return answer;
  }
}

int QueueOnNodes::front() 
{
  return head_->value_;
}

int QueueOnNodes::back() 
{
  return tail_->value_;
}

bool QueueOnNodes::isEmpty() 
{
  return !bool(size_);
}

int QueueOnNodes::size() const 
{
  return size_;
}

QueueOnNodes QueueOnNodes::operator=(const QueueOnNodes &old) 
{
  if (this == &old)
    return *this;
  head_ = old.head_;
  tail_ = old.tail_;
  return *this;
}

std::vector<int> QueueOnNodes::getNumbers() const 
{
  Node *tmp = head_;
  std::vector<int> answer;
  for (int i = 0; i < size(); i++) 
  {
    answer.push_back(tmp->value_);
    tmp = tmp->next_;
  }
  return answer;
}