#include<iostream>
using namespace std;
class Circle{
    float r;
    public:
    void init(float x) /* Inline function */
    {
        r = x;
    }
    float area();
};
float Circle::area()
{
    return 3.14*r*r;
}
int main(int argc, char **argv)
{
    float radius;
    Circle circle;
    cout << "Enter the radius of the circle:: ";
    cin >> radius;
    circle.init(radius);
    cout << "Area of the Circle:: "<<circle.area()<<"n";
    return 0;
}
