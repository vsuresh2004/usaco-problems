// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool sortPoints(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

bool processPoints(vector<pair<int, int>>& points) {
	sort(points.begin(), points.end(), sortPoints);
	if(points[0].second != points[1].second && points[1].second != points[2].second)
		return false;

	if(points[0].second != points[1].second) 
		rotate(points.begin(), points.begin() + 1, points.end());

	if(points[2].first != points[1].first)
		return false;
	
	return true;

}

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int n;
	cin >> n;

	vector<pair<int, int>> points;

	for(int i = 0; i < n; i++) {
		int x;
		int y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	int maxArea = INT_MIN;

	for(auto point1 : points)
		for(auto point2 : points) 
			for(auto point3 : points) {
				vector<pair<int, int>> newPoints;
				if(point1 != point2 && point2 != point3 && point1 != point3) {
					newPoints.push_back(point1);
					newPoints.push_back(point2);
					newPoints.push_back(point3);

					if(!processPoints(newPoints))
						continue;

					int area = abs(newPoints[1].first - newPoints[0].first) * abs(newPoints[2].second - newPoints[1].second);
					maxArea = max(area, maxArea);

				}
			}


	cout << maxArea << endl;
	return 0;
}
