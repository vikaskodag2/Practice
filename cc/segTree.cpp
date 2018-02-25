#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vpi vector<pair <int, int> >
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define ms(s, n) memset(s, n, sizeof(s))
#define f first
#define s second
#define MOD 1e9 + 7
#define INF 1e12 + 7
#define N 1000005

ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
vl prime(N + 1);
void sieve() {
	prime[0] = prime[1] = 1;
	for(ll i = 2; i <= N; i++) {
		if(!prime[i]) {
			prime[i] = i;
			for(ll j = i * i; j <= N; j += i) 
				if(!prime[j]) 
					prime[j] = i;
		}
	}
}

//Range minimum query.

vi segtree(4 * N), a(N);

int leftchild(int p) { return p << 1; }
int rightchild(int p) { return (p << 1) + 1;}

void build(int node, int left, int right) {  //Time : O(n)
	if(left == right)
		segtree[node] = a[left];
	else {
		build(leftchild(node), left, (left + right) / 2);
		build(rightchild(node), (left + right) / 2 + 1, right);
		segtree[node] = min(segtree[leftchild(node)], segtree[rightchild(node)]);
	}
}

int query(int node, int left, int right, int i, int j) {	//Time : O(logn)
	if(left > j || right < i) 
		return MOD;
	if(left >= i && right <= j)
		return segtree[node];
	else
		return min(query(leftchild(node), left, (left + right) / 2, i, j), query(rightchild(node), (left + right) / 2 + 1, right, i, j));
}

void update(int node, int left, int right, int index, int value) {	//Time : O(logn)
	if(left == right)
		segtree[node] = a[index] = value;
	else {
		if(left <= index && index <= (left + right) / 2)
			update(leftchild(node), left, (left + right) / 2, index, value);
		else
			update(rightchild(node), (left + right) / 2 + 1, right, index, value);
		segtree[node] = min(segtree[leftchild(node)], segtree[rightchild(node)]);
	}
}


int main(){
	ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for(int i = 0; i < q; i++) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		//x--, y--;
		if(c == 'q')
			cout << query(1, 1, n, x, y) << "\n";
		else
			update(1, 1, n , x, y);
	}
	return 0;
}
