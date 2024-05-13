// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = n;

	vector<int> greaterThan;
	vector<int> lessThan;

	while(n--) {
		char inequality;
		int p;

		cin >> inequality >> p;

		if(inequality == 'L')
			lessThan.push_back(p);
		else if(inequality == 'G')
			greaterThan.push_back(p);
	}

	sort(greaterThan.begin(), greaterThan.end());
	sort(lessThan.begin(), lessThan.end());

	int countLying = 0;

	if(greaterThan.empty() || lessThan.empty()) {
		cout << countLying << endl;
	}
		
	else {
		
		int l = greaterThan.size() - 1;
		int r = 0;

		while(lessThan[r] < greaterThan[l]) {
			if(l == 0 && r == lessThan.size() - 1) {
				countLying++;
				break;
			} else if(l == 0){
				r++;
				countLying++;
			} else if(r == lessThan.size() - 1) {
				l--;
				countLying++;
			} else {
				r++;
				countLying++;
			}
		}
	}

	cout << countLying << endl;
	return 0;
}
