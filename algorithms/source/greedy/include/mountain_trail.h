#pragma once

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

std::vector<Point> searchTrail(const std::vector<std::vector<int>>& points, const Point& startPoint);
