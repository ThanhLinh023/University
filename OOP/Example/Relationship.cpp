#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private:
    int x;
    int y;
public:
    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX() {return x;}
    int getY() {return y;}
};
class Line
{
private:
    Point begin;
    Point end;
public:
    Line(Point begin, Point end)
    {
        this->begin = begin;
        this->end = end;
    }
    Line(int x1, int y1, int x2, int y2)
    {
        begin.setX(x1);
        begin.setY(y1);
        end.setX(x2);
        end.setY(y2);
    }
    void setBegin(Point begin)
    {
        this->begin = begin;
    }
    void setEnd(Point end)
    {
        this->end = end;
    }
    Point getBegin() {return begin;}
    Point getEnd() {return end;}
    double getLength()
    {
        return sqrt(pow(begin.getX() - end.getX(), 2) + pow(begin.getY() - end.getY(), 2));
    }
};
int main() 
{
	Point begin(1, 1);
	Point end(2, 2);
	Line line1(begin, end);
	cout << line1.getLength() << endl;
    Line line2(2, 3, 5, 4);
	cout << line2.getLength() << endl;
	return 0;
}