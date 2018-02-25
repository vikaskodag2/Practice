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
#define N 1e6

ll n, q, l, r, x, y;
vector<vl> segTree(4 * N + 1);
vb isprime(N + 1, true);
vl a(N), firstpr(N + 1);

void sieve() {
	firstpr[0] = firstpr[1] = 1;
	for(ll i = 2; i <= N; i++) {
		if(isprime[i]) {
			firstpr[i] = i;
			for(ll j = i * i; j <= N; j += i) {
				if(isprime[j]) {
					firstpr[j] = i;
					isprime[j] = false;
				}
			}
		}
	}
}

vl factors(ll n) {
	vl fac;
	while(n > 1) {
		fac.pb(firstpr[n]);
		n /= firstpr[n];
	}
	return fac;
}

vl mergeArray(int index1, int index2) {
	vl ar;
	ll size1 = segTree[index1].size(), size2 = segTree[index2].size(), i = 0, j = 0;
	while(i < size1 && j < size2) {
		if(segTree[index1][i] < segTree[index2][j])
			ar.pb(segTree[index1][i++]);
		else 
			ar.pb(segTree[index2][j++]);
	}
	while(i < size1) 
		ar.pb(segTree[index1][i++]);
	while(j < size2)
		ar.pb(segTree[index2][j++]);
	return ar;
}

void build(ll node, ll left, ll right) {
	if(left > right)
		return;
	else if(left == right) {
		segTree[node] = factors(a[left]);
		return;
	}
	build(node * 2, left, (left + right) / 2);
	build(node * 2 + 1, (left + right) / 2 + 1, right);
	segTree[node] = mergeArray(node * 2, node * 2 + 1);
}

ll query(ll node, ll left, ll right) {
	if(left > right || left > r || right < l)
		return 0;
	else if(left >= l && right <= r) 
		return upper_bound(all(segTree[node]), y) - lower_bound(all(segTree[node]), x); 
	return query(node * 2 + 1, (left + right)/2 + 1, right) + query(node * 2, left, (left + right)/2);
}

int main(){
	ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
	sieve();
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	build(1, 0, n - 1);
	cin >> q;
	for(int i = 0; i < q; i++) {	
		cin >> l >> r >> x >> y;
		l--, r--;
		cout << query(1, 0, n - 1) << "\n";
	}
	return 0;
}
