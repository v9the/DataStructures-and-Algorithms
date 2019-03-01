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

bool priority(char ch, char ch2) {
	if (ch == '/') {
		return true;
	}
	else 
		if (ch == '*' && ch2 != '/') {
			return true;
		}
		else
			if (ch == '+' && ch2 == '-') {
				return true;
			}
			else {
				return false;
			}
}

int main() {
	string str, temp, temp2 = "";
	getline(cin, str);
	str = str + ' ';
	stack<char> arr;
	rep(i, l(str)) {
		temp = "";
		while (str[i] != ' ') {
			temp = temp + str[i];
			i++;
		}
		if (temp == "*" || temp == "/" || temp == "+" || temp == "-") {
			while (!arr.empty() && priority(arr.top(), temp[0])) {
				temp2 = temp2 + arr.top() + " ";
				arr.pop();
			}
			arr.push(temp[0]);
		}
		else {
			temp2 = temp2 + temp + " ";
		}
	}
	while (!arr.empty()) {
		temp2 = temp2 + arr.top() + " ";
		arr.pop();
	}
	cout << temp2;
}
//for prefix: reverse the string str.