#include <vector>
#include <mountain_trail.h>

constexpr auto INF = 9999999;

Point findLowestNearPoint(const std::vector<std::vector<int>>& points, const Point& currentPoint)
{
	Point selectedPoint(0, 0);
	auto min = INF;
	auto x = currentPoint.x;
	auto y = currentPoint.y;
	for (auto dx = -1; dx <= 1; ++dx)
	{
		for (auto dy = -1; dy <= 1; ++dy)
		{
			auto xInBounds = x + dx >= 0 && x + dx < points.front().size();
			auto yInBounds = y + dy >= 0 && y + dy < points.size();
			if (xInBounds && yInBounds)
			{
				auto value = points[xInBounds][yInBounds];
				if (value < min)
				{
					min = value;
					selectedPoint = Point(xInBounds, yInBounds);
					x = xInBounds;
					y = yInBounds;
				}
			}
		}
	}
	return selectedPoint;
}

std::vector<Point> searchTrail(const std::vector<std::vector<int>>& points, const Point& startPoint)
{
	std::vector<Point> trail;
	trail.push_back(startPoint);
	auto currentPoint = trail.back();
	do {
		currentPoint = findLowestNearPoint(points, currentPoint);
		trail.push_back(currentPoint);
	} while (currentPoint.x != 1);

	return trail;
}
