#include <iostream>
using namespace std;
class shape{
    public:
    virtual float area()=0;
};
class Circle:public shape{
    private:
    float radius;
    public:
    Circle(float r){
        radius=r;
    }
    float area(){
        return 3.14*radius*radius;
    }
};
class Rectangle:public shape{
    private:
    float length;
    float breadth;
    public:
    Rectangle(float l,float b){
        length=l;
        breadth=b;
    }
    float area(){
        return length*breadth;
    }
};
class Triangle:public shape{
    private:
    float base;
    float height;
    public:
    Triangle(float b,float h){
        base=b;
        height=h;
    }
    float area(){
        return 0.5*base*height;
    }
};
int main(){
    shape  Circle(5);
    
    shape Rectangle(4,6);
   
    shape Triangle(3,4);
    shape *ptr;
    ptr=&Circle;
    cout<<"Area of Circle: "<<ptr->area()<<endl;
    ptr=&Rectangle;
    cout<<"Area of Rectangle: "<<ptr->area()<<endl;
    ptr=&Triangle;
    cout<<"Area of Triangle: "<<ptr->area()<<endl;
    return 0;
}