//http://codeforces.com/problemset/problem/911/C

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
	int k1, k2, k3, flag = 0;
	cin >> k1 >> k2 >> k3;
	if(k1 == 1 or k2 == 1 or k3 == 1){
		cout << "YES\n";
		return 0;
	}
	if(k1 == 2)
		flag++;
	if(k2 == 2)
		flag++;
	if(k3 == 2)
		flag++;
	if(flag >= 2){
		cout << "YES\n";
		return 0;
	}
	if(k1 == k2 && k2 == k3 && k3 == 3) {
		cout << "YES\n";
		return 0;
	}
	vi a;
	a.pb(k1);
	a.pb(k2);
	a.pb(k3);
	sort(all(a));
	if(a[0] == 2 && a[1] == 4 && a[2] == 4){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
	
}
