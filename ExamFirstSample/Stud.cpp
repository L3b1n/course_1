#include "Stud.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void Stud::push(int num) 
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

void Stud::pop() 
{ 
    if (head == tail) 
    { 
        cout << "очередь пуста" << endl; 
        return ;
    } 
    head++; 
    if(head == SIZE) head = 0; 
  
} 

int Stud::size()
{   
    int s=0;
    for(int i = head; i < tail; i++)
    {
        s++;
    }
    return s;
}

int& Stud::operator [] (const int i)
{
    return queue[i];
}

void Stud::read()
{
    int i = 0, j = 0;
    int temp;
    char *buf;
    char str1[256];
    string s;
    string temp1;
    const char *sf = " ;:,.";
    const char ch = '\n';
    std::ifstream file("Input.txt", ios::in);
    while(!file.eof())
    {
        getline(file, s, ch);
        strcpy(str1, s.c_str());
        buf = strtok(str1, sf);
        temp1 = string(buf);
        while(buf)
        {
            temp += atoi(buf);
            buf = strtok(NULL, sf);
        }
        i++;
        if(temp >= ball){ str[j] = temp1; queue[j++] = temp;}
        temp = 0;
    }
    file.close();
    tail = j;
}

void Stud::GetSorted()
{
    for(int i = 0; i <= tail - 1; i++)
    {
		for(int j = 0; j < tail - i - 1; j++)
		{
			if(queue[j] < queue[j + 1])
			{	swap(queue[j], queue[j + 1]); swap(str[j], str[j + 1]);}
		}
    }
}

int Stud::back()
{
    return queue[tail];
}

int Stud::front()
{
    return queue[head];
}