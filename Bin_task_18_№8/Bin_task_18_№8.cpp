#define _USE_MATH_DEFINES //в трапеции задать 3 стороны и угол// принята
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Geom.h"

using namespace std;

int main()
{
    int n = 0;
    while(n == 0 || n > 4)
    {   
        std::cout << "Choose the figuire:\n1)Trapeze\n2)Trapeze with painted parts\n3)Parallelogram with diagonales\n4)Parallelogram with painted triangle" << std::endl;
        std::cin >> n;
        n > 4 ? std::cout << "Please choose one more time" << std::endl : std::cout << "";
    }
    if(n == 1)
    {
        int x = 0, y = 0; double a, b, c, d, alpha, aAngle = 0; string conditional;
        std::cout << "Enter information about trapeze:\n1)lenght of A, B, C and D: "; std::cin >> a >> b >> c >> d;
        std::cout << "2)alpha between A and B: "; std::cin >> alpha;
        std::cout << "Continue to enter information or enter by defolt(yes or any click): "; std::cin >> conditional;
        if(conditional == "yes"){std::cout << "3)position of center(by defolt x = 0, y = 0): "; std::cin >> x >> y;
        std::cout << "4)angle between one side and OX(by defolt aAngle = 0): "; std::cin >> aAngle; aAngle *= M_PI / 180; std::cout << std::endl;}
        KTrapeze xpl(std::cout, a, b, c, d, alpha, x, y, aAngle);
        xpl.Show();
        while(1)
        {
            std::cout << "Choose actions for trapeze:\n1)Show\n2)Hide\n3)Shift\n4)MoveTo\n5)Rotate\n6)Expand\n7)Exit" << std::endl;
            std::cin >> n;
            if(n == 1){ xpl.Show();}
            if(n == 2){ xpl.Hide();}
            if(n == 3){ int dx, dy; std::cout << "Enter dx and dy: "; std::cin >> dx >> dy; xpl.Shift(dx, dy);}
            if(n == 4){ int x_, y_; std::cout << "Enter x' and y': "; std::cin >> x_ >> y_; xpl.MoveTo(x_, y_);}
            if(n == 5){ double angle; std::cout << "Enter angle: "; std::cin >> angle; xpl.Rotate(M_PI * angle / 180);}
            if(n == 6){ double koef; std::cout << "Enter koef: "; std::cin >> koef; xpl.Expand(koef);}
            if(n == 7){ xpl.Show(); std::cout << "Exit" << std::endl; return 0;}
        }
    }
    if(n == 2)
    {
        int x = 0, y = 0; double a, b, c, d, alpha, aAngle = 0; string color1 = "black", position1 = "right", color2 = "black", position2 = "left", conditional;
        std::cout << "Enter information about painted trapeze:\n1)lenght of A, B, C and D: "; std::cin >> a >> b >> c >> d;
        std::cout << "2)alpha between A and B: "; std::cin >> alpha;
        std::cout << "Continue to enter information or enter by defolt(yes or any click): "; std::cin >> conditional;
        if(conditional == "yes"){std::cout << "3)position of center(by defolt x = 0, y = 0): "; std::cin >> x >> y;
        std::cout << "4)angle between one side and OX(by defolt aAngle = 0): "; std::cin >> aAngle; aAngle *= M_PI / 180;
        std::cout << "5)color of painted parts(by defolt color1 = color2 = black): "; std::cin >> color1 >> color2;
        std::cout << "6)position of painted parts(by defolt position1 = right, position2 = left): "; std::cin >> position1 >> position2; std::cout << std::endl;}
        KPaintTrapeze xpl(std::cout, a, b, c, d, alpha, color1, position1, color2, position2, x, y, aAngle);
        xpl.Show();
        while(1)
        {
            std::cout << "Choose actions for trapeze:\n1)Show\n2)Hide\n3)Shift\n4)MoveTo\n5)Rotate\n6)Expand\n7)Paint\n8)Exit" << std::endl;
            std::cin >> n;
            if(n == 1){ xpl.Show();}
            if(n == 2){ xpl.Hide();}
            if(n == 3){ int dx, dy; std::cout << "Enter dx and dy: "; std::cin >> dx >> dy; xpl.Shift(dx, dy);}
            if(n == 4){ int x_, y_; std::cout << "Enter x' and y': "; std::cin >> x_ >> y_; xpl.MoveTo(x_, y_);}
            if(n == 5){ double angle; std::cout << "Enter angle: "; std::cin >> angle; xpl.Rotate(M_PI * angle / 180);}
            if(n == 6){ double koef; std::cout << "Enter koef: "; std::cin >> koef; xpl.Expand(koef);}
            if(n == 7){ int k; std::cout << "Enter number of part(first - 1, second - 2 or both - 3): "; std::cin >> k; 
                        if(k == 3){ std::cout << "Enter two colors and positions(col1, pos1, col2, pos2): "; std::cin >> color1 >> position1 >> color2 >> position2;}
                        if(k == 2){ std::cout << "Enter color and position(col2, pos2): "; std::cin >> color2 >> position2; color1 = ""; position1 = "";}
                        if(k == 1){ std::cout << "Enter color and position(col1, pos1): "; std::cin >> color1 >> position1, color2 = ""; position2 = "";}
                        xpl.Paint(position1, position2, color1, color2);
                      }
            if(n == 8){ xpl.Show(); std::cout << "Exit" << std::endl; return 0;}
        }
    }
    if(n == 3)
    {
        int x = 0, y = 0; double a, b, alpha, aAngle = 0; string conditional;
        std::cout << "Enter information about parallelogram:\n1)lenght of A and B: "; std::cin >> a >> b;
        std::cout << "2)alpha between A and B: "; std::cin >> alpha;
        std::cout << "Continue to enter information or enter by defolt(yes or any click): "; std::cin >> conditional;
        if(conditional == "yes"){std::cout << "3)position of center(by defolt x = 0, y = 0): "; std::cin >> x >> y;
        std::cout << "4)angle between one side and OX(by defolt aAngle = 0): "; std::cin >> aAngle; aAngle *= M_PI / 180; std::cout << std::endl;}
        KParallelogram xpl(std::cout, a, b, alpha, x, y, aAngle);
        xpl.Show();
        while(1)
        {
            std::cout << "Choose actions for parallelogram:\n1)Show\n2)Hide\n3)Shift\n4)MoveTo\n5)Rotate\n6)Expand\n7)Exit" << std::endl;
            std::cin >> n;
            if(n == 1){ xpl.Show();}
            if(n == 2){ xpl.Hide();}
            if(n == 3){ int dx, dy; std::cout << "Enter dx and dy: "; std::cin >> dx >> dy; xpl.Shift(dx, dy);}
            if(n == 4){ int x_, y_; std::cout << "Enter x' and y': "; std::cin >> x_ >> y_; xpl.MoveTo(x_, y_);}
            if(n == 5){ double angle; std::cout << "Enter angle: "; std::cin >> angle; xpl.Rotate(M_PI * angle / 180);}
            if(n == 6){ double koef; std::cout << "Enter koef: "; std::cin >> koef; xpl.Expand(koef);}
            if(n == 7){ xpl.Show(); std::cout << "Exit" << std::endl; return 0;}
        }
    }
    if(n == 4)
    {
        int x = 0, y = 0; double a, b, alpha, aAngle = 0; string color = "black", position = "top", conditional;
        std::cout << "Enter information about painted parallelogram:\n1)lenght of A and B: "; std::cin >> a >> b;
        std::cout << "2)alpha between A and B: "; std::cin >> alpha;
        std::cout << "Continue to enter information or enter by defolt(yes or any click): "; std::cin >> conditional;
        if(conditional == "yes"){std::cout << "3)position of center(by defolt x = 0, y = 0): "; std::cin >> x >> y;
        std::cout << "4)angle between one side and OX(by defolt aAngle = 0): "; std::cin >> aAngle; aAngle *= M_PI / 180;
        std::cout << "5)color of painted part(by defolt color = black): "; std::cin >> color;
        std::cout << "6)position of painted part(by defolt position = top): "; std::cin >> position; std::cout << std::endl;}
        KPaintParallelogram xpl(std::cout, a, b, alpha, position, color, x, y, aAngle);
        xpl.Show();
        while(1)
        {
            std::cout << "Choose actions for parallelogram:\n1)Show\n2)Hide\n3)Shift\n4)MoveTo\n5)Rotate\n6)Expand\n7)Paint\n8)Exit" << std::endl;
            std::cin >> n;
            if(n == 1){ xpl.Show();}
            if(n == 2){ xpl.Hide();}
            if(n == 3){ int dx, dy; std::cout << "Enter dx and dy: "; std::cin >> dx >> dy; xpl.Shift(dx, dy);}
            if(n == 4){ int x_, y_; std::cout << "Enter x' and y': "; std::cin >> x_ >> y_; xpl.MoveTo(x_, y_);}
            if(n == 5){ double angle; std::cout << "Enter angle: "; std::cin >> angle; xpl.Rotate(M_PI * angle / 180);}
            if(n == 6){ double koef; std::cout << "Enter koef: "; std::cin >> koef; xpl.Expand(koef);}
            if(n == 7){ std::cout << "Enter color and position of painted part: "; std::cin >> color >> position; xpl.Paint(position, color);}
            if(n == 8){ xpl.Show(); std::cout << "Exit" << std::endl; return 0;}
        }
    }
    return 0;
}