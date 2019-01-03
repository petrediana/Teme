#include <iostream>

class Rectangle{
protected:
    int width;
    int height;

public:
    virtual void display(){
        std::cout << width << " " << height << std::endl;
    }

};

class RectangleArea : public Rectangle{
public:
    void read_input(){
        std::cin >> width;
        std::cin >> height;
    }

    void display(){
        std::cout << width * height << std::endl;
    }
};

int main(){
    RectangleArea r1;
    r1.read_input();
    r1.Rectangle::display();
    r1.display();


    return 0;
}