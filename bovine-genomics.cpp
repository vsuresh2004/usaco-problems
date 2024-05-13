// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool intersect(unordered_set<string>& a, unordered_set<string>& b) {
	for(auto it = a.begin(); it != a.end(); it++) {
		if(b.find(*it) != b.end())
			return true;
	}

	return false;
}

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<string> genomes;

	for(int i = 0; i < 2 * n; i++) {
		string a;
		cin >> a;
		genomes.push_back(a);
	}

	int valid = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++)
			for(int k = j + 1; k < m; k++) {
				unordered_set<string> spottyGenomes;
				unordered_set<string> plainGenomes;

				for(int a = 0; a < n; a++) {
					string s = {genomes[a][i], genomes[a][j], genomes[a][k]};
					spottyGenomes.insert(s);
				}

				for(int a = n; a < 2 * n; a++) {
					string s = {genomes[a][i], genomes[a][j], genomes[a][k]};
					plainGenomes.insert(s);
				}


				if(!intersect(spottyGenomes, plainGenomes)) 
					valid++;
			}
	}

	cout << valid << endl;
	return 0;
}
