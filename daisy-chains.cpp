// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool isEquals(float a, int b) {
	return abs(a - b) < 0.01;
}

bool isValid(vector<int>& flowers, int i, int j) {
	double average = 0;

	for(int l = i; l <= j; l++) 
		average += flowers[l];

	average /= (j - i + 1);

	for(int l = i; l <= j; l++) 
		if(isEquals(average, flowers[l]))
			return true;
		
	return false;
}

int main() {
	int n;
	cin >> n;

	vector<int> flowers;
	int countAverageFlowers = 0;

	for(int i = 0; i < n; i++) {
		int flower;
		cin >> flower;
		flowers.push_back(flower);
	} 

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(isValid(flowers, i, j)) {
				countAverageFlowers++;
			}
				
		}
	}

	cout << countAverageFlowers << endl;

	return 0;
}
