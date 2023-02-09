#include "Tqueue.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>

void Tqueue::push(int num) 
{ 
   if (tail + 1 == head || (tail + 1 == SIZE && !head)) 
   { 
        cout << "очередь полна" << endl; 
        return ; 
   } 
   tail++; 
   if(tail == SIZE) tail = 0;
   queue[tail] = num; 
} 

void Tqueue::pop() 
{ 
    if (head == tail) 
    { 
        cout << "очередь пуста" << endl; 
        return ;
    } 
    head++; 
    if(head == SIZE) head = 0; 
  
} 

int Tqueue::size()
{   
    int s=0;
    for(int i = head; i < tail; i++)
    {
        s++;
    }
    return s;
}

int& Tqueue::operator [] (const int i)
{
    return queue[i];
}

void Tqueue::read()
{
    int i = 0;
    char *buf;
    char str[256];
    string s;
    const char *sf = " ;:,.";
    const char ch = '\n';
    std::ifstream file("Input.txt", ios::in);
    while(!file.eof())
    {
        getline(file, s, ch);
        strcpy(str, s.c_str());
        buf = strtok(str, sf);
        while(buf)
        {
            queue[i] = atoi(buf);
            buf = strtok(NULL, sf);
            i++;
        }
    }
    file.close();
    tail = i;
}

int Tqueue::back()
{
    return queue[tail];
}

int Tqueue::front()
{
    return queue[head];
}