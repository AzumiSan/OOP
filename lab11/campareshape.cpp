#include <iostream>
#include <cmath>

using namespace std;

class Shape  //base class;
{
private:
    float width;
    float heigth;

public:
    virtual float area(void) = 0;
    virtual float perimeter(void) = 0;
};

/*Base class - aas ydamshij byi square*/

class Square: public Shape
{
private:
    float length;
public:
    int length;
    float area_of_square;
    void area()
    {
        area_of_square = length*length;
        return area_of_square;
    }
    float area_of_perimeter;

    void perimeter()
    {
        area_of_perimeter = 4*length;
        return area_of_perimeter;
    }
};
/*Base class aas udamshij bui circle*/

class Circle: public Shape
{
private:
    float radius;
public:
    float area_of_circle;
    const float PI = 3.14;
    void area()
    {
        circle_of_area = radius*radius*PI;
        return circle_of_area;
    }
    void perimeter()
    {
        float perimeter_of_circle;
        const float PI = 3.14;
        circle_of_perimeter = 2*radius*PI;
        return circle_of_perimeter;
    }
};
/*Base class aas udamshij bui triangle*/

class Triangle : public Shape
{
private:
    double edgeA;
    double edgeB;
    double edgeC;
public:
    void area()
    {
        float temp;
        float triangle_of_area;
        float triangle_of_perimeter;
        temp = (edgeA+edgeB+edgeC)*(edgeA+edgeB-edgeC)*(edgeA-edgeB+edgeC)*(-edgeA+edgeB+edgeC);
        area sqrt(temp);
        triangle_of_area = area*0.25;
        return triangle_of_area;
    }

    void perimeter()
    {
        return edgeA+edgeB+edgeC;
    }
};
int main()
{
    Square S;
    Circle C;
    Triangle T;

    S.length = 4;

    C.radius= 3;

    T.edgeA = 3;
    T.edgeB = 4;
    T.edgeC = 6;

    cout <<"Then name of shape S "<< endl;
    cout <<"\nThe area of square is: "<<S.square_of_area();
    cout<<"\nThe perimeter of square is:"<<S.square_of_perimeter();

    cout<<"\n\n*****************************";

    cout <<"\n\nThen name of shape C"<<endl;
    cout <<"\nThe area of circle is: "<<C.circle_of_area();
    cout <<"\nThe perimeter of circle is: "<<C.circle_of_perimeter();

    cout<<"\n\n*****************************";

    cout <<"\n\nThen name of shape T "<<endl;
    cout <<"\nThe area of circle is: "<<T.triangle_of_area();
    cout <<"\nThe perimeter of circle is: "<<T.triangle_of_perimeter();
}



