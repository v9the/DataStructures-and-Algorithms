#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, vector<T>> adjList;
	void addEdge(T u, T v, bool isBiDir = false) {
		u--; v--;
		adjList[u].push_back(v);
		if (isBiDir) {
			adjList[v].push_back(u);
		}
	}
	// only in DAG
	// tls
	void tls() {
		vector<T> inorder(7, 0), ans;
		for (auto a : adjList) {
			for (auto b : a.second) {
				inorder[b]++;
			}
		}
		queue<T> q;
		for (T i = 0; i < 6; i++) {
			if (inorder[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			T u = q.front();
			q.pop();
			ans.push_back(u);
			for (auto a : adjList[u]) {
				if (--inorder[a] == 0) {
					q.push(a);
				}
			}
		}
		for (auto a : ans) {
			cout << a << ' ';
		}
	}
};

int main() {
	Graph<int> g;
	g.addEdge(1, 5);
	g.addEdge(2, 5);
	g.addEdge(5, 4);
	g.addEdge(5, 6);
	g.addEdge(4, 3);
	g.addEdge(4, 7);
	g.addEdge(6, 7);
	g.tls();
}