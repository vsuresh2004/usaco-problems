// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int countIntersection(unordered_set<string>& a, unordered_set<string>& b) {
	int count = 0;
	for(auto it = a.begin(); it != a.end(); it++) {
		if(b.find(*it) != b.end())
			count++;
	}

	return count;
}

int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int n;
	cin >> n;

	vector<unordered_set<string>> animalCharacteristics;

	while(n--) {
		string name;
		int len;
		
		cin >> name >> len;
		unordered_set<string> characteristics;

		for(int i = 0; i < len; i++) {
			string characteristic;
			cin >> characteristic;
			characteristics.insert(characteristic);
		}

		animalCharacteristics.push_back(characteristics);
	}

	int maxIntersection = INT_MIN;

	for(auto characteristics : animalCharacteristics)
		for(auto otherCharacteristics : animalCharacteristics) {
			if(characteristics == otherCharacteristics)
				continue;

			maxIntersection = max(maxIntersection, countIntersection(characteristics, otherCharacteristics));
		}

	cout << maxIntersection + 1 << endl;
	return 0;
}
