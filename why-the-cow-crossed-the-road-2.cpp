// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findInString(string& s, char c) {
	pair<int, int> positions;
	bool flag = false;

	for(int i = 0; i < s.length(); i++) {
		auto character = s[i]; 
		if(character == c) {
			if(flag)
				positions.second = i; 
			else {
				positions.first = i;
				flag = true;
			}
		}		
	}

	return positions;
}

bool cross(string& s, char a, char b) {
	pair<int, int> positionsA = findInString(s, a);
	pair<int, int> positionsB = findInString(s, b);

	return positionsA.first < positionsB.first && positionsB.first < positionsA.second && positionsA.second < positionsB.second;  
}

int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	string s;
	cin >> s;

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int crossingPairs = 0;

	for(auto c : alphabet)
		for(auto otherC : alphabet){
			if(c == otherC)
				continue;

			if(cross(s, c, otherC))
				crossingPairs++;
		}

	cout <<  crossingPairs << endl;
	return 0;
}
