/*
* Calculating three dimensional shape coordinate, perimeter, area, volume
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//base class
class Shape
{
public:
    string name;
    float Length;
    // shape name of abstract
    void setName()
    {
        cout << this->name << endl;
    }// abstract
    virtual float Peremeter() = 0;
};
// public gopimoop ydamshij bgaa
class ThreeDimesionalShape : public Shape
{
    /* tyhain ydamshliin gopim ni shineer uusj bgaa
    class ni ali classaas ydamshij bgaag ni zaah yypegtei*/
public:
    vector<float> coorX;
    vector<float> coorY;
    vector<float> coorZ;
    float Area= 0;
    float Volume = 0;
    void getCoor(float x, float y, float z)
    {
        this->coorX.push_back(x);
        this->coorY.push_back(y);
        this->coorZ.push_back(z);
    }
    void setCoor()
    {
        for(int i=0; i<coorX.size(); i++)
        {
            cout << "X: "<<coorX[i]<<" Y: "<<coorY[i]<<" Z: "<<coorZ[i]<<endl;
        }
    }
    virtual float VolumeS() = 0;
};
/*public gopimoop udamshih ni protected ba public handaltiin tyvshintei
shinj chanart ni huuhed classt ydamshhad public handaltin tuvshintei  bolno.
*/

// public gopimoop ydamshij bgaa
class TwoDimesionalShape : public Shape
{
public:
    vector<float> coorX;
    vector<float> coorY;
    float Area = 0;
    float length = 0;// 2d urt

void getCoor(float x, float y)
    {
        coorX.push_back(x);
        coorY.push_back(y);
    }
    void setCoor()
    {
        for(int i=0; i<coorX.size(); i++)
        {
            cout << "X: "<<coorX[i]<<" Y: "<<coorY[i]<<endl;
        }
    }
    virtual float AreaS() = 0;
};
// public gopimoop ydamshij bgaa
class Circle : public TwoDimesionalShape
{
public:
    void getCoor(float x, float y)
    {
        if(coorX.size()<1)
        {
            TwoDimesionalShape::getCoor(x,y);
        }
        else
        {
            coorX[0]=x;
            coorY[0]=y;
        }
    }
    float Peremeter()
    {
        return this->length = 3.14 * 2 * Length;// Length yponhii  shape class's length
    }
    float AreaS()
    {
        return this->Area = 3.14*Length*Length;
    }
};

// public gopimoop ydamshij bgaa
class Square : public TwoDimesionalShape
{
public:
    float Peremeter()
    {
        return this->length = 4*Length;
    }
    float TalbaiS()
    {
        this->Area = Length*Length;
    }
    void CoorCalc(float x, float y)
    {
        if(coorX.size() < 1)
        {
            TwoDimesionalShape::getCoor(x, y);
            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0]);

            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0] + Length);

            this->coorX.push_back(coorX[0]);
            this->coorY.push_back(coorY[0] + Length);
        }
        else
        {
            this->coorX[0] = x;
            this->coorY[0] = y;
            this->coorX[1] = (coorX[0] + Length);
            this->coorY[1] = (coorY[0]);

            this->coorX[2] = (coorX[0] + Length);
            this->coorY[2] = (coorY[0] + Length);

            this->coorX[3] = (coorX[0]);
            this->coorY[3] = (coorY[0] + Length);
        }

        for(int i=0; i<coorX.size(); i++)
        {
            cout << "X: "<<this->coorX[i]<<" Y: "<<this->coorY[i]<<endl;
        }
    }
};

// public gopimoop ydamshij bgaa
class Traingle : public TwoDimesionalShape
{
public:
    float Peremeter()
    {
        return this->length = 3*Length;
    }
    float AreaS()
    {
        return this->Area= 0.5*Length*Length*sin(60 * 3.14 /180);
    }
    void CoorCalc(float x, float y)
    {
        if(coorX.size() < 1)
        {
            TwoDimesionalShape::getCoor(x, y);
            this->coorX.push_back(coorX[0] - Length/2);
            this->coorY.push_back(coorY[0] - sqrt(Length*Length - (Length/2)*(Length/2)));

            this->coorX.push_back(coorX[0] + Length/2);
            this->coorY.push_back(coorY[0] + sqrt(Length*Length - (Length/2)*(Length/2)));
        }
        else
        {
            this->coorX[0] = x;
            this->coorY[0] = y;
            this->coorX[1] = (coorX[0] - Length/2);
            this->coorY[1] = (coorY[0] - sqrt(Length*Length - (Length/2)*(Length/2)));

            this->coorX[2] = (coorX[0] + Length/2);
            this->coorY[2] = (coorY[0] + sqrt(Length*Length- (Length/2)*(Length/2)));
        }


        for(int i=0; i<coorX.size(); i++)
        {
            cout << "X: "<<this->coorX[i]<<" Y: "<<this->coorY[i]<<endl;
        }
    }
};
// public gopimoop ydamshij bgaa
class Sphere : public ThreeDimesionalShape
{
public:
    void getCoor(float x, float y, float z)
    {
        if(coorX.size()<1)
        {
            ThreeDimesionalShape::getCoor(x,y,z);
        }
        else
        {
            coorX[0]=x;
            coorY[0]=y;
            coorZ[0] =z;
        }
    }
    float Peremeter()
    {
        return this->Area = 4 * 3.14*Length*Length;
    }
    float VolumeS()
    {
        return this->Volume= (4 * 3.14*Length*Length*Length)/3;
    }
};

// public gopimoop ydamshij bgaa
class Cube : public ThreeDimesionalShape
{
public:
    float Peremeter()
    {
        return this->Area = 6*Length*Length;
    }
    float VolumeS()
    {
        return this->Volume = pow(Length, 3);
    }
    void CoorCalc(float x, float y, float z)
    {
        if(coorX.size() < 1)
        {
            ThreeDimesionalShape::getCoor(x, y, z);
            // neg talin koor
            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0]);
            this->coorZ.push_back(coorZ[0]);
            // 2 talin koor
            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0]);
            this->coorZ.push_back(coorZ[0] - Length);

            // 3 talin koor
            this->coorX.push_back(coorX[0]);
            this->coorY.push_back(coorY[0]);
            this->coorZ.push_back(coorZ[0] - Length);

            // 4 talin koor
            this->coorX.push_back(coorX[0]);
            this->coorY.push_back(coorY[0] +Length);
            this->coorZ.push_back(coorZ[0]);

            // 5 talin koor
            this->coorX.push_back(coorX[0]);
            this->coorY.push_back(coorY[0] + Length);
            this->coorZ.push_back(coorZ[0] - Length);

            // 6 talin koor
            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0] + Length);
            this->coorZ.push_back(coorZ[0] - Length);

            // 7 talin koor
            this->coorX.push_back(coorX[0] + Length);
            this->coorY.push_back(coorY[0] + Length);
            this->coorZ.push_back(coorZ[0]);
        }
        else
        {
            this->coorX[0] = x;
            this->coorY[0] = y;
            this->coorZ[0] = z;
            // 1 talin koor
            this->coorX[1] = (coorX[0] + Length);
            this->coorY[1] = (coorY[0]);
            this->coorZ[1] = (coorZ[0]);
            // 2 talin koor
            this->coorX[2] = (coorX[0] + Length);
            this->coorY[2] = (coorY[0]);
            this->coorZ[2] = (coorZ[0] - Length);

            // 3 talin koor
            this->coorX[3] = (coorX[0]);
            this->coorY[3] = (coorY[0]);
            this->coorZ[3] = (coorZ[0] - Length);

            // 4 talin koor
            this->coorX[4] = (coorX[0]);
            this->coorY[4] = (coorY[0] + Length);
            this->coorZ[4] = (coorZ[0]);

            // 5 talin koor
            this->coorX[5] = (coorX[0]);
            this->coorY[5] = (coorY[0] + Length);
            this->coorZ[5] = (coorZ[0] - Length);

            // 6 talin koor
            this->coorX[6] = (coorX[0] + Length);
            this->coorY[6] = (coorY[0] + Length);
            this->coorZ[6] = (coorZ[0] - Length);

            // 7 talin koor
            this->coorX[7] = (coorX[0] + Length);
            this->coorY[7] = (coorY[0] + Length);
            this->coorZ[7] = (coorZ[0]);
        }

        for(int i=0; i<coorX.size(); i++)
        {
            cout <<"X: "<<this->coorX[i]<<" Y: "<<this->coorY[i]<<" Z: "<<this->coorZ[i]<<endl;
        }
    }
};
// public gopimoop ydamshij bgaa
class Tetrahedron : public ThreeDimesionalShape
{
public:
    float Peremeter()
    {
        return this->Area = sqrt(3)*pow(Length, 2);
    }
    float VolumeS()
    {
        return this->Volume = pow(Length, 3)/6*sqrt(2);
    }
    void CoorCalc(float x, float y, float z)
    {
        if(coorX.size() < 1)
        {
            ThreeDimesionalShape::getCoor(x, y, z);
            //1 talin koor
            this->coorX.push_back(coorX[0]);
            this->coorY.push_back(coorY[0] - Length*sqrt(6) / 3);
            this->coorZ.push_back(coorZ[0] - sqrt(Length*Length - (Length/2) * (Length/2))*2/3);

            //2 talin koor
            this->coorX.push_back(coorX[0] - Length/2);
            this->coorY.push_back(coorY[0] - Length*sqrt(6) / 3);
            this->coorZ.push_back(coorZ[0] - sqrt(Length*Length - (Length/2) * (Length/2))/3);

            //3 talin koor
            this->coorX.push_back(coorX[0] +Length/2);
            this->coorY.push_back(coorY[0] - Length*sqrt(6) / 3);
            this->coorZ.push_back(coorZ[0] - sqrt(Length*Length- (Length/2) * (Length/2))/3);
        }
        else
        {

            this->coorX[0] = x;
            this->coorY[0] = y;
            this->coorZ[0] = z;
            //1 talin koor
            this->coorX[1] = (coorX[0]);
            this->coorY[1] = (coorY[0] - Length*sqrt(6) / 3);
            this->coorZ[1] = (coorZ[0] - sqrt(Length*Length - (Length/2) * (Length/2))*2/3);

            //2 talin koor
            this->coorX[2] = (coorX[0] - Length/2);
            this->coorY[2] = (coorY[0] - Length*sqrt(6) / 3);
            this->coorZ[2] = (coorZ[0] - sqrt(Length*Length - (Length/2) * (Length/2))/3);

            //3 talin koor
            this->coorX[3] = (coorX[0] + Length/2);
            this->coorY[3] = (coorY[0] - Length*sqrt(6) / 3);
            this->coorZ[3] = (coorZ[0] - sqrt(Length*Length - (Length/2) * (Length/2))/3);

        }
        for(int i=0; i<coorX.size(); i++)
        {
            cout << "X: "<<this->coorX[i]<<" Y: "<<this->coorY[i]<<" Z: "<<this->coorZ[i]<<endl;
        }
    }
};
int main()
{
    // Circle
    /*cout << "***** Circle****"<<endl;
    Circle c;
    c.name = "circle";
    c.Length = 5;
    c.getCoor(10.0, 12.5);
    c.setName();
    c.setCoor();
    cout << "Peremeter: "<< c.Peremeter() << " Area: "<<c.AreaS()<<endl;
    // Square
    /* cout << "*******Square*****"<<endl;
     Square s;
     s.name = "square";
     s.Length = 5;
     s.setName();
     cout << "Peremeter: "<< s.Peremeter() << " Area: "<<s.AreaS()<<endl;
     s.CoorCalc(0.0, .0);*/
    //Triangle
    cout << "****Triangle *****"<<endl;
    Traingle T;
    T.name = "Triangle";
    T.Length = 5;
    cout << "Peremeter: "<< T.Peremeter() << " Area: "<<T.AreaS()<<endl;
    T.CoorCalc(2.5, 2.1);

    //Sphere
    cout << "************ Sphere******************"<<endl;
    Sphere k;
    k.name = "Sphere";
    k.Length = 10;
    k.getCoor(3.0, 3.0, 1.5);
    k.setName();
    k.setCoor();
    cout << "Peremeter: "<< k.Peremeter() << " Area: "<<k.VolumeS()<<endl;

    //Cube
    cout << "***********Cube *******************"<<endl;
    Cube C;
    C.name = "Cube";
    C.Length = 5;
    C.setName();
    cout << "Peremeter: "<< C.Peremeter() << " Area: "<<C.VolumeS()<<endl;
    C.CoorCalc(0, 0, 5);

    //Tetrahedron
    cout <<"*******************Tetrahedron ******************"<<endl;
    Tetrahedron R;
    R.name = "Tetrahedron";
    R.Length = 5;
    R.setName();
    cout << "Peremeter: "<< R.Peremeter() << " Area: "<<R.VolumeS()<<endl;
    R.CoorCalc(2., 5.0, 10.0);
}
