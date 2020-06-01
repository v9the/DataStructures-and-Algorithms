//Prim’s Minimum Spanning Tree O((V+E)logV) for Sparse Graph

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T, typename T2>
class Graph {
public:
	vector<vector<pair<T, T2>>> adjList;
	vector<T> vis;
	vector<T> parent;
	vector<T2> key;
	Graph(T V) {
		adjList = vector<vector<pair<T, T2>>>(V);
		vis = vector<T>(V, 0);
		parent = vector<T>(V, -1);
		key = vector<T2>(V, INT_MAX);
	}
	void addEdge(T u, T v, T2 w) {
		adjList[u].push_back({ v,w });
		adjList[v].push_back({ u,w });
	}
	T2 prim(T src) {
		priority_queue<pair<T2, T>> pq;
		T2 weight = 0;
		key[src] = 0;
		pq.push({ key[src], src });
		while (!pq.empty()) {
			pair<T2, T> p = pq.top();
			pq.pop();
			T2 w = -p.first;
			T v = p.second;
			if (!vis[v]) {
				vis[v] = true;
				weight += w;
				for (auto a : adjList[v]) {
					if (!vis[a.first] && key[a.first] > a.second) {
						key[a.first] = a.second;
						parent[a.first] = v;
						pq.push({ -a.second, a.first });
					}
				}
			}
		}
		return weight;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, e;
	cin >> n >> e;
	Graph<int, ll> g(n);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	ll w = g.prim(0);	//	we can select any vertex
	cout << w;
}