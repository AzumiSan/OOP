/*
2D shape- create Circle, Rectangle,Square shape
*1.Загвар(Template) ашиглан дурын төрөлтэй өгөгдөл хадгалдаг linked list өгөгдлийн бүтцийг зохион байгуул.
List класс нь дараах үйлдлүүдтэй байна:
void push(T e) - жагсаалтын эхэнд элемент нэмэх
void add(T e) - жагсаалтын төсгөлд элемент нэмэх
void insert(T e, int index) - жагсаалтын index дүгээр байранд шинэ элемент оруулах
T get(int index) - index дүгээр элементийг буцаах
int size() - жагсаалтад хэдэн элемент байгааг буцаах
2. Дээрх загвар класс ашигласан жагсаалт болон Lab12-т хийсэн дүрсүүдийг ашиглан дараах даалгаврыг гүйцэтгэнэ.
Үүнд: Санамсаргүй талын урттай, санамсаргүй тооны (20-30 орчим) гурвалжин, дөрвөлжин, тойргийн объектуудыг үүсгэ.
Үүсгэсэн гурвалжин дөрвөлжин тойрог дүрсүүдийг төрөл харгалзалгүйгээр талбайгаар нь эрмбэлж хэвлэ.
*/
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class shape
{
public:
    string name;
    //abstract class
    virtual string setname(string )=0;
    virtual double perimeter()=0;
};
class TwoDimShape// 2d shape's class
{
public:
    //absract class
    virtual double Area()=0;
    int x;
    int y;
};// base ba 2d class as udamshih
// davhtsal garahgui ujir ni virtual tusgai ug tavisan
class circle:virtual public shape,virtual public TwoDimShape
{
public:
    int r;
    double perimeter()
    {
        return this->r*3.14*2;
    }
    double Area()
    {
        return this->r*r*3.14;
    }
    string setname(string name)
    {
        return this->name=name;
    }
    circle(int r)
    {
        this->r=r;
    }
};
class square:virtual public shape,virtual public TwoDimShape
{
public:
    double taliinurt;
    double perimeter()
    {
        return this->taliinurt*4;
    }
    double Area()
    {
        return this->taliinurt*taliinurt;
    }
    string setname(string name)
    {
        return this->name=name;
    }
    square(double taliinurt)
    {
        this->taliinurt=taliinurt;
    }
};
class triangle:virtual public shape,virtual public TwoDimShape
{
public:
    double ab,bc,ca;// triangle's 3 taliin urt
    double perimeter()
    {
        return ab+bc+ca;
    }
    double Area()
    {
        return ab*ca/2;
    }
    string setname(string name)
    {
        return this->name=name;
    }
    triangle(double a,double b)
    {
        this->ab=a;
        this->ca=b;
    }
};
/*template classiin davyy tal ni ymap j ogogdliin topoltei bsan
 tuunii dahin programjlahguigeer ashiglaj boldog*/
template <class T> class List;
template <class T>
class Node//tyhain class Node iin butstsihee daguu ytguudaa zarlana
{
private:
    T ehlel; // tyhain llit iin ehle utga
    Node<T> *next;
public:
    Node(T d, Node<T>*n)
    {
        ehlel = d;
        next = n;
    }
    friend class List<T>;
};

template<class T>
class List// list end aguulagdah data member ba member function ytgyydaa todophoilno
{
private:
    Node<T> *head;
    int index=0;
public:
    List();
    ~List();
    bool add(T, int);//жагсаалтын төгсгөлд элемент нэмэх
    bool isEmpty();// жагсаалт хоосон эсэхийг шалгах
    void push(T);// жагсаалтын эхэнд элемент нэмэх
    T get(int);//index дүгээр элементийг буцаах
    bool del(int);// жагсаалт дах элементийг устгах
    void print();//үр дүнг хэвлэх
    void Sort();//жагсаалтын элементүүдийг эрэмблэх
    int Size();//жагсаалтад хэдэн элемент байгааг буцаах
};

template<class T>
//constructor function
List<T>::List()
{
    head = NULL;//hooson linked listee uusgej bgaa
}

template<class T>
//desctructor function
List<T>::~List()
{
    Node<T>* temp;
    while(head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

template<class T>
bool List<T>::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }else{
        return false;
    }
}
template<class T>
void List<T>::push(T e)
{
    Node<T>*k = new Node<T>(e,NULL);
    if(isEmpty())
    {
        head = k;
        index++;
    }
    else
    {
        Node<T>*i = head;
        while(i->next!=NULL)
        {
            i = i->next;
        }
        i->next = k;
        index++;
    }
}
template<class T>
void List<T>::print()
{
    for(Node<T>*i = head; i!=NULL; i=i->next)
    {
        cout << i->ehlel->Area() << " ";
    }
    cout << endl;
}
template<class T>
T List<T>::get(int p)
{
    Node<T>* cur = head;
    int i=0;
    while(cur != NULL && i<p)
    {
        cur=cur->next;
        i++;
    }
    return cur->ehlel;
}

template<class T>
bool List<T>::add(T e, int p)
{
    Node<T>*k = new Node<T>(e,NULL);
    if(isEmpty())
    {
        if(p<1)
        {
            head = k;
            index++;
            return true;

        }
        else
        {
            return false;
        }
    }
    Node<T>*cur=head;
    if(p==0)
    {
        k->next = cur;
        head = k;
        index++;
        return true;
    }

    Node<T>* prev = NULL;
    Node<T>* current = head;
    int i = 0;
    while(current != NULL && i<p)
    {
        prev = current;
        current = current->next;
        i++;
    }
    k->next = prev->next;
    prev->next = k;
    index++;
    return true;
}
template<class T>
void List<T>::Sort()
{
    for(int j=0; j<index*index; j++)
    {
        Node<T>*i=head;
        while(i!=nullptr)
        {
            if(i->next!=NULL)
            {
                if(i->ehlel->Area() <= i->next->ehlel->Area())
                {
                    T temp;
                    temp=i->ehlel;
                    i->ehlel=i->next->ehlel;
                    i->next->ehlel=temp;
                }
            }
            i=i->next;
        }
    }
}

template<class T>
int List<T>::Size()
{
    return index;
}
int main()
{
    List<TwoDimShape*> i;
    i.push(new circle(2));
    i.push(new square(2));
    i.push(new triangle(2,4));
    i.push(new circle(3));
    i.push(new square(5));
    i.push(new square(5));
    i.push(new square(7));
    i.push(new square(8));
    i.push(new circle(1));
    i.push(new square(2));
    i.push(new square(4));
    i.push(new square(1));
    i.push(new square(7));

    i.print();
    cout << "get 1: " << i.get(1)->Area() << endl;
    cout << "Size is: "<< i.Size() << endl;
    i.Sort();
    i.print();
}







