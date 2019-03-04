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
	(*node).ff = (*node).ss = NULL;
	return node;
}

Node* Insert(Node* root, int x) {
	Node* node = getNode(x);
	Node* temp = root;
	Node* temp2 = NULL;
	while (temp != NULL) {
		temp2 = temp;
		if (x <= (*temp).data) {
			temp = (*temp).ff;
		}
		else {
			temp = (*temp).ss;
		}
	}
	if (root == NULL) {
		root = node;
	}
	else
		if (x <= (*temp2).data) {
			(*temp2).ff = node;
		}
		else {
			(*temp2).ss = node;
		}
	return root;
}

int findMin(Node* temp) {
	if (temp == NULL) {
		return -1;
	}
	while ((*temp).ff != NULL) {
		temp = (*temp).ff;
	}
	return (*temp).data;
}

int findMax(Node* temp) {
	if (temp == NULL) {
		return -1;
	}
	while ((*temp).ss != NULL) {
		temp = (*temp).ss;
	}
	return (*temp).data;
}

int main() {
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 15);
	root = Insert(root, 1);

	cout << findMin(root);
	cout << '\n';
	cout << findMax(root);
}