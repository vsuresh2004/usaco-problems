// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
	

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	string s;
	string t;

	cin >> s; 
	cin >> t;

	size_t i = 0;
	while(i < s.length()) {
		if(s.substr(i, t.length()) == t) {
			s.erase(i, t.length());
			i = max(0, (int)(i - t.length()));
		}
		i++;
	}

	cout << s << endl;

	return 0;
}
