//Vjezba 10.
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

struct Point {
    double x;
    double y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
    friend std::istream& operator>>(std::istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

void processFile() {
    std::ifstream file("points.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        exit(1);
    }

    std::istream_iterator<Point> pointIterator(file);
    std::istream_iterator<Point> endOfFile;
    std::vector<Point> points(pointIterator, endOfFile);
    file.close();

    std::sort(points.begin(), points.end(),
        [](const Point& p1, const Point& p2) {
            return distance(Point(0, 0), p1) < distance(Point(0, 0), p2);
        });

    double radius = 5.0;
    int countInsideCircle = std::count_if(points.begin(), points.end(),
        [radius](const Point& p) {
            return distance(Point(0, 0), p) < radius;
        });

    double replaceDistance = 3.0;
    Point replacementPoint(10.0, 10.0);

    std::replace_if(points.begin(), points.end(),
        [replaceDistance](const Point& p) {
            return std::abs(distance(Point(0, 0), p) - replaceDistance) < 1e-6;
        },
        replacementPoint);

    std::vector<Point> reversedPoints(points.rbegin(), points.rend());

    std::cout << "Broj tocaka unutar kruga: " << countInsideCircle << std::endl;
    std::cout << "Tocke nakon zamjene i ispisivanja u obrnutom redoslijedu:" << std::endl;
    std::copy(reversedPoints.begin(), reversedPoints.end(), std::ostream_iterator<Point>(std::cout, "\n"));
}

int main() {
    processFile();

    return 0;
}