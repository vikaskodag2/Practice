//http://codeforces.com/problemset/problem/743/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair <int, int> >
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define f first
#define s second
#define mod 1e9+7
#define inf 100000000007
#define N 1005

int main(){
	ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n;
	if(n == 1) {
		cout << "-1";
		return 0;
	}
	cout << n << " " << n+1 << " " << n*(n+1) << "\n";
	return 0;
}
