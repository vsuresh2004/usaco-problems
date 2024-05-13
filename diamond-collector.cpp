// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<int> diamonds;
	

	while(n--) {
		int newSize;
		cin >> newSize;
		diamonds.push_back(newSize);
	}

	sort(diamonds.begin(), diamonds.end());

	int maxDiamonds = INT_MIN;

	for(int i = 0; i < diamonds.size(); i++) {
		int j = i;
		while(j < diamonds.size() && diamonds[j] - diamonds[i] <= k) {
			j++;
		}

		maxDiamonds = max(maxDiamonds, j - i);
	}

	cout << maxDiamonds << endl;

	return 0;
}
