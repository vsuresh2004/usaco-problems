// Source: https://usaco.guide/general/io
#include <stdio.h>
#include <stdint.h>
 
#include <vector>
#include <algorithm>
using namespace std;
 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = n;

	vector<pair<int, char>> values;

	while(m--) {
		char inequality;
		int p;

		cin >> inequality >> p;

		values.push_back(make_pair(p, inequality));
	}

	sort(values.begin(), values.end());

	int minNumLiars = n;
	for(int i = 0; i < n; i++) {
		int countLiars = 0;
		for(int j = 0; j < i; j++) {
			if(values[j] != values[i] && values[j].second == 'L')
				countLiars++;
		}

		for(int j = i + 1; j < n; j++)
			if(values[j] != values[i] && values[j].second == 'G')
				countLiars++;

		minNumLiars = min(minNumLiars, countLiars);
	}

	cout << minNumLiars << endl;

	return 0;
}