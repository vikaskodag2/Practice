//http://codeforces.com/problemset/problem/822/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define vpi vector<pair <int, int> >
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define inf 100000000000000000

vl cost(200500,inf);

int main(){
	ios_base::sync_with_stdio(0);
	int n,x;
	cin >> n >> x;
	int days = x;
	vector<pair<pair<int, int>, pair<int, ll> > > op;

	for(int i=0; i<n; i++){
		int l,r;
		ll c;
		cin >> l >> r >> c;
		op.pb(mp(mp(l,-1), mp(r,c)));
		op.pb(mp(mp(r,1), mp(l,c)));
	}

	sort(op.begin(), op.end());

	ll len = op.size();
	ll ans = inf;
	for(ll i=0; i<len; i++){
		if(op[i].f.s == -1){
			int l = op[i].s.f-op[i].f.f+1;
			if(l<=x){
				ans = min(ans, cost[x-l]+op[i].s.s);
			}
		}
		else if(op[i].f.s == 1){
			int l = op[i].f.f-op[i].s.f+1;
			cost[l] = min(cost[l], op[i].s.s);
		}
	}
	if(ans == inf)cout<<-1;
	else
		cout<<ans;
	return 0;
}
