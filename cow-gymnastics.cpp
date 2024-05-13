// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int k, n;
	cin >> k >> n;

	vector<vector<int>> rankings;

	for(int i = 0; i < k; i++) {
		vector<int> newVector;
		for(int j = 0; j < n; j++) {
			int val;
			cin >> val;
			newVector.push_back(val);
		}
		rankings.push_back(newVector);
	}
/*
	for(auto rank : rankings) {
		for(auto element : rank) 
			cout << element << " ";
		cout << endl;
	}
	*/

	unordered_set<string> consistentPairs;
	for(int a = 0; a < rankings.size(); a++) {
		auto rank = rankings[a];
		for(int i = 0; i < rank.size(); i++) {
			for(int j = i + 1; j < rank.size(); j++) {
				string order = to_string(rank[i]) + "," + to_string(rank[j]);
				string reverse = to_string(rank[j]) + "," + to_string(rank[i]);

				if(consistentPairs.find(order) == consistentPairs.end() && consistentPairs.find(reverse) != consistentPairs.end()) {
					consistentPairs.erase(reverse);
				} else if(a == 0 && consistentPairs.find(order) == consistentPairs.end()){
					consistentPairs.insert(order);
				}
			}

			
		}
		/*
		for(auto it = consistentPairs.begin(); it != consistentPairs.end(); it++) {
				cout << *it << " ";
			}
			cout << endl;
		*/
	}

	cout << consistentPairs.size() << endl;
	return 0;
}
