#include <QApplication>
#include <QtWidgets>

class Function : public QWidget
{
public:
    Function(QWidget* w = 0) : QWidget(w) 
    {
        resize(1000, 600);
        QPushButton* b1 = new QPushButton(this);
        QPushButton* b2 = new QPushButton(this);
        QPushButton* b3 = new QPushButton(this);
        b1->setText("y = x^2");
        b1->setFixedSize(100, 50);
        b1->move(10, 10);
        b2->setText("y = cos(x)");
        b2->setFixedSize(100, 50);
        b2->move(10, 70);
        b3->setText("y = e^x");
        b3->setFixedSize(100, 50);
        b3->move(10, 130);
        connect(b1, &QPushButton::clicked, this, &Function::onButtonClicked1);
        connect(b2, &QPushButton::clicked, this, &Function::onButtonClicked2);
        connect(b3, &QPushButton::clicked, this, &Function::onButtonClicked3);
    }
protected:
    virtual void paintEvent(QPaintEvent*) 
    {
        QPainter painter(this);
        if(!flagFunc) return;
        if(flagWindow) 
        {
            this->setGeometry(0, 50, 1920, 950);
            flagWindow = false;
        }
        double OX = 960, OY = 540;
        painter.setPen(QPen(Qt::red, 3));
        painter.drawLine(0, OY, 2 * OX, OY);
        painter.drawLine(OX, 0, OX, 2 * OY);
        for(int i = 60; i < OX * 2; i += 100) 
        {
            painter.drawLine(i, OY - 5, i, OY + 5);
            if(i < OX){ painter.drawText(i - 6, OY + 22, QString::number((-OX + i) / 100));}
            else if(i == OX){ painter.drawText(i - 11, OY + 16, QString::number((-OX + i) / 100));}
            else{ painter.drawText(i - 3, OY + 22, QString::number((-OX + i) / 100));}
        }
        for(int i = 40; i < OY * 2; i += 100) 
        {
            painter.drawLine(OX - 5, i, OX + 5, i);
            if(i < OY){ painter.drawText(OX - 18, i + 5, QString::number((OY - i) / 100));}
            else if(i > OY){ painter.drawText(OX - 23, i + 5, QString::number((OY - i) / 100));}
        }
        painter.setPen(QPen(Qt::blue, 3));
        switch(flagFunc)
        {
            case 1: 
            {
                double dx = 0.5, x = OX - 250, x0 = (x - 960) / 100;
                for(int i = 0; i < 1000; ++i) 
                {
                    double y0 = x0 * x0;
                    double y = OY - y0 * 100;
                    painter.drawPoint(x, y);
                    x += dx;
                    x0 += dx / 100;
                }
                break;
            }
            case 2: 
            {
                double dx = 1, x = 0, x0 = (x - 960) / 100;
                for(int i = 0; i < 1920; ++i) 
                {
                    double y0 = cos(x0);
                    double y = OY - y0 * 100;
                    painter.drawPoint(x, y);
                    x += dx;
                    x0 += dx / 100;
                }
                break;
            }
            case 3: 
            {
                double dx = 0.5, x = 0, x0 = (x - 960) / 100;
                for(int i = 0; i < 2260; ++i) 
                {
                    double y0 = pow(M_E, x0);
                    double y = OY - y0 * 100;
                    painter.drawPoint(x, y);
                    x += dx;
                    x0 += dx / 100;
                }
                break;
            }
        }
    }
private:
    void onButtonClicked1() 
    {
        flagFunc = 1;
        flagWindow = true;
        this->update();
    }
    void onButtonClicked2() 
    {
        flagFunc = 2;
        flagWindow = true;
        this->update();
    }
    void onButtonClicked3() 
    {
        flagFunc = 3;
        flagWindow = true;
        this->update();
    }
    int flagFunc = false;
    bool flagWindow = false;
};

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    Function f;
    f.show();
    return app.exec();
}
