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
		Node* node = getNode(x);
		root = node;
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

void inOrder(Node* root) {
	if (root == NULL)
		return;
	inOrder((*root).ff);
	cout << (*root).data << ' ';
	inOrder((*root).ss);
}

int findMax(Node* root) {
	if ((*root).ss == NULL)
		return (*root).data;
	else
		return findMax((*root).ss);
}

Node* Delete(Node* root, int x) {
	if (root == NULL)
		return root;
	if (x < (*root).data)
		(*root).ff = Delete((*root).ff, x);
	else
		if (x > (*root).data)
			(*root).ss = Delete((*root).ss, x);
		else {
			if ((*root).ff == NULL && (*root).ss == NULL) {
				delete root;
				return NULL;
			}
			else
				if ((*root).ff == NULL) {
					Node* temp = (*root).ss;
					delete root;
					return temp;
				}
				else
					if ((*root).ss == NULL) {
						Node* temp = (*root).ff;
						delete root;
						return temp;
					}
					else {
						int val = findMax((*root).ff);
						(*root).data = val;
						(*root).ff = Delete((*root).ff, val);
						return root;
					}
		}
	return root;
}

int main() {
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 1);
	root = Insert(root, 9);
	root = Insert(root, 25);
	root = Insert(root, 2);
	inOrder(root);
	cout << '\n';
	root = Delete(root, 5);
	inOrder(root);
}