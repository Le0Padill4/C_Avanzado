#include <iostream>
#include <iomanip>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double valorX = 0, double valorY = 0) {
        x = valorX;
        y = valorY;
    }

    Vector2D operator+(Vector2D otro) {
        Vector2D resultado;

        resultado.x = x + otro.x;
        resultado.y = y + otro.y;

        return resultado;
    }

    double operator*(Vector2D otro) {
        return x * otro.x + y * otro.y;
    }

    friend std::ostream& operator<<(std::ostream& salida, Vector2D v) {
        salida << "(" << v.x << ", " << v.y << ")";
        return salida;
    }
};

int main() {
    double x1, y1;
    double x2, y2;

    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    Vector2D v1(x1, y1);
    Vector2D v2(x2, y2);

    Vector2D suma = v1 + v2;
    double productoEscalar = v1 * v2;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << "v1 + v2 = " << suma << std::endl;
    std::cout << "v1 · v2 = " << productoEscalar << std::endl;

    return 0;
}