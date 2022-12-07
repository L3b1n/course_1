#include <string>
#include <iomanip>
#include <iostream>

char getChar() 
{
    static char buffer[1024*1024];
    static int pos = 0;
    static int size = 0;
    if(pos == size) 
    {
        size = fread(buffer, 1, 1024*1024, stdin);
        pos = 0;
    }
    if(pos == size){ return EOF;}
    return buffer[pos++];
}

int getInt() 
{
    char c = '?';
    while(!(c == '-' || ('0' <= c && c <= '9'))){ c = getChar();}
    int sign = 1;
    if(c == '-') 
    {
        sign = -1;
        c = getChar();
    }
    int answ = 0;
    while('0' <= c && c <= '9') 
    {
        (answ *= 10) += (c - '0');
        c = getChar();
    }
    return sign * answ;
}

void putChar(char c) 
{
    static char buffer[1024*1024];
    static int size = 0;
    if(size == 1024*1024 || c == -1) 
    {
        fwrite(buffer, 1, size, stdout);
        size = 0;
    }
    if(c != -1){ buffer[size++] = c;}
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    std::cin.tie(0);
    std::cout.tie(0);
    int test = getInt();
    std::cout << test << "\n";
    return 0;
}