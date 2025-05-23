#include "../headers/manager.hpp"

void clearScreen();
void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    clearScreen();

    cout << "Creating figures..." << endl;
    
    Point p(0, 0);
    Circle c(p, static_cast<float>(1 + rand() % 50));
    Ellipse e(p, static_cast<float>(1 + rand() % 50), static_cast<float>(1 + rand() % 50));
    Rectangle r(p, static_cast<float>(1 + rand() % 50), static_cast<float>(1 + rand() % 50));

    cout << "Calculating areas..." << endl << endl;
    cout << "Point area: " << Manager<Point>::calculateArea(p) << endl;
    cout << "Circle area: 3.14 * " << c.getRadius() << " * " << c.getRadius() << " = " << Manager<Circle>::calculateArea(c) << endl;
    cout << "Ellipse area: 3.14 * " << e.getLongD() << " * " << e.getShortD() << " = " << Manager<Ellipse>::calculateArea(e) << endl;
    cout << "Rectangle area: " << r.getWidth() << " * " << r.getHeight() << " = " << Manager<Rectangle>::calculateArea(r) << endl;
    cout << endl;

    return 0;
}
