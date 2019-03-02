#include <bits/stdc++.h>

using namespace std;

#define rep(i, n)	for(int i = 0; i < (n); ++i)
#define repA(i, a, n)	for(int i = a; i <= (n); ++i)
#define repD(i, a, n)	for(int i = a; i >= (n); --i)
#define trav(a, x)	for(auto& a : x)
#define fast	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define clr(A)	memset(A, 0, sizeof(A))
#define all(x)	(x).begin(), (x).end()
#define l(x)	((int)(x).size())
#define vi	vector<int>
#define vl	vector<ll>
#define ff	first
#define ss	second
#define mp	make_pair
#define pb	push_back

typedef long double ld;
typedef long long int ll;

const int MOD = 1000000007;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

class Node {
public:
	int data;
	Node* ff;
	Node* ss;
};

Node* getNode(int x) {
	Node* node = new Node();
	(*node).data = x;
	(*node).ff = NULL;
	(*node).ss = NULL;
	return node;
}

Node* Insert(Node* root, int x) {
	if (root == NULL) {
		root = getNode(x);
	}
	else
		if (x <= (*root).data) {
			(*root).ff = Insert((*root).ff, x);
		}
		else {
			(*root).ss = Insert((*root).ss, x);
		}
	return root;
}

bool Search(Node* root, int x) {
	if (root == NULL) {
		return false;
	}
	else
		if ((*root).data == x) {
			return true;
		}
		else
			if ((*root).data > x) {
				return Search((*root).ff, x);
			}
			else {
				return Search((*root).ss, x);
			}
}

int main() {
	Node* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 5);
	root = Insert(root, 25);
	root = Insert(root, 20);
	root = Insert(root, 1);

	cout << Search(root, 1);
}