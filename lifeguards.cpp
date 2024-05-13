// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int findTimeSupported(vector<pair<int, int>>& times, pair<int, int> avoid) {
	array<int, 1001> lifeguards{};

	for(auto time : times) {
		if(time == avoid)
			continue;
	
		int a = time.first;
		int b = time.second;

		for(int i = a; i < b; i++) {
			lifeguards[i] = 1;
		}
	}

	int count = 0;
	for(auto x : lifeguards){
		if(x == 1)
			count++;
	}

	return count;
}

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n;
	cin >> n;

	vector<pair<int, int>> times;
	while(n--) {
		int a, b;
		cin >> a >> b;
		times.push_back(make_pair(a, b));
	}

	int maxTime = INT_MIN;

	for(auto time : times) {
		maxTime = max(maxTime, findTimeSupported(times, time));
	}

	cout << maxTime << endl;
	return 0;
}
