#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include <vector>
#include <algorithm>

using namespace std;

struct bip_g {
	int V1, V2, *nuyn;
	vector<int> *L;
	bool *aycelats;

	bip_g(int MAX_V1, int MAX_V2) {
		L = new vector<int>[MAX_V1];
		aycelats = new bool[MAX_V2];
		nuyn = new int[MAX_V2];
	}

	void clear(int _V1, int _V2) {
		V1 = _V1; V2 = _V2;
		for (int i = 0; i<V1; ++i) L[i].clear();
	}

	void add_edge(int v1, int v2) {
		L[v1].push_back(v2);
	}

	bool dfs(int u) {
		for (int i = L[u].size() - 1; i >= 0; --i) {
			int v = L[u][i];
			if (!aycelats[v]) {
				aycelats[v] = true;
				if (nuyn[v] == -1 || dfs(nuyn[v])) {
					nuyn[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int max_match() {
		int ans = 0;
		fill(nuyn, nuyn + V2, -1);
		for (int i = 0; i<V1; ++i) {
			fill(aycelats, aycelats + V2, false);
			ans += dfs(i);
		}
		return ans;
	}
};

int main() {
	int T, n, r, c;
	bip_g G(120, 120);

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);

		G.clear(120, 120);

		for (int i = 0; i<n; ++i) {
			scanf("%d %d", &r, &c);
			G.add_edge(r, c);
		}

		printf("%d\n", G.max_match());
	}

	return 0;
}