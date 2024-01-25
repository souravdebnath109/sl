#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class shape{
    
public:
    virtual void draw()=0;
};

class rectangle : public shape{
public:
    void draw()
    {
        cout<<"Inside Rectangle"<<endl;
    }
};

class circle : public shape{
public:
    void draw()
    {
        cout<<"Inside circle"<<endl;
    }
};

class shapefactory{
    static shapefactory *ins;
    shapefactory() {}
public:
    // Eager Initialization
    static shapefactory* getinstance()
    {
        return ins;
    }

    static void initialize()
    {
        if(ins == nullptr)
        {
            ins = new shapefactory();
        }
    }

    shape* getshape(string shapetype)
    {
        if(shapetype=="rectangle")
        {
            return new rectangle();
        }
        else if(shapetype=="circle")
        {
            return new circle();
        }
        else return nullptr;
    }
};

// Eager Initialization
shapefactory* shapefactory::ins = new shapefactory();

int main()
{
    // Eager Initialization
    shapefactory::initialize();

    shapefactory* shapefactory1 = shapefactory::getinstance();
    shapefactory* shapefactory2 = shapefactory::getinstance();
    cout<<"Address of shapefactory 1 : "<<shapefactory1<<endl;
    cout<<"Address of shapefactory 2 : "<<shapefactory2<<endl;

    shape *shape1 = shapefactory1->getshape("rectangle");
    shape1->draw();

    shape *shape2 = shapefactory1->getshape("circle");
    shape2->draw();
}
