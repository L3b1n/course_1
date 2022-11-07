#include <QApplication>
#include <QtWidgets>
#include <QFile>
#include <QTextStream>

class Gistogram : public QWidget 
{
protected:
    virtual void paintEvent(QPaintEvent*) 
    {
        QFile f("input.txt");
        f.open(QIODevice::ReadOnly);
        if(!f.isOpen()) return;
        QTextStream in(&f);
        QPainter painter(this);
        painter.setPen(QPen(Qt::red, 3));
        int OX = 40, OY = height() - 30;
        painter.drawLine(OX, OY, OX, 0);
        painter.drawLine(OX, OY, width(), OY);
        int x = OX + width() / 30, y, x_size = width() / 10, y_size;
        while(!in.atEnd()) 
        {
            in >> y_size;
            y = OY - y_size;
            painter.drawLine(OX - 5, y, OX + 5, y);
            painter.drawText(OX - 30, y + 5, QString::number(y_size));
            QRect rect(QPoint(x, y), QSize(x_size, y_size));
            x += x_size;
            painter.drawRect(rect);
        }
    }
public:
    Gistogram(QWidget* pwgt = 0) : QWidget(pwgt) {}
};


int main(int argc, char** argv) 
{
    QApplication app(argc, argv);
    Gistogram g;
    g.resize(1000, 700);
    g.show();
    return app.exec();
}

