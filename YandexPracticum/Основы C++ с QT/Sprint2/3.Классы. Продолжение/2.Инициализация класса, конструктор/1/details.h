#pragma once

struct Point {
    double x = 0;
    double y = 0;

    Point() = default;
    Point(int tmp_x,int tmp_y){
        x = tmp_x;
        y = tmp_y;
    }
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;

    Triangle(){
        p1 = Point();
        p2 = Point();
        p3 = Point();
    }
    Triangle(Point tmp_p1, Point tmp_p2, Point tmp_p3){
        p1 = tmp_p1;
        p2 = tmp_p2;
        p3 = tmp_p3;
    }
};