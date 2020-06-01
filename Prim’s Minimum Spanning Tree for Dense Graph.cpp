//Prim’s Minimum Spanning Tree O(n^2) for Dense Graph

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T, typename T2>
class Graph {
public:
	vector<vector<T2>> adjMatrix;
	vector<bool> vis;
	vector<T> parent;
	vector<T2> key;
	T N;
	Graph(T V) {
		adjMatrix = vector<vector<T2>>(V, vector<T2>(V, 0));
		vis = vector<bool>(V, false);
		parent = vector<T>(V, -1);
		key = vector<T2>(V, INT_MAX);
		N = V;
	}
	void addEdge(T u, T v, T2 w) {
		adjMatrix[u][v] = w;
		adjMatrix[v][u] = w;
	}
	T2 prim(T src) {
		key[src] = 0;
		T2 weight = 0;
		for (T j = 0; j < N; j++) {
			T2 minVertex = -1;
			for (T i = 0; i < N; i++)
				if (!vis[i] && (minVertex == -1 || key[minVertex] > key[i]))
					minVertex = i;
			if (minVertex != -1) {
				weight += key[minVertex];
				vis[minVertex] = true;
				for (T i = 0; i < N; i++)
					if (adjMatrix[minVertex][i] != 0 && !vis[i] && adjMatrix[minVertex][i] < key[i]) {
						key[i] = adjMatrix[minVertex][i];
						parent[i] = minVertex;
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