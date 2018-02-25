//http://codeforces.com/problemset/problem/764/C

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
#define inf 100000000007
vector<vi> a(100005);
vi c(100005);
int cnt[100005];
int tot;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int p,q;
		cin >> p >> q;
		a[p].pb(q);
		a[q].pb(p);
	}

	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
		
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size(); j++){
			if(c[i] != c[a[i][j]]){
				cnt[i]++;
				cnt[a[i][j]]++;
				tot++;
			}
		}
	}

	for(int i=1; i<=n; i++){
		//cout<<"cnt["<<i<<"] : "<<cnt[i]<<"\n";
		if(cnt[i] == tot){
			cout << "YES\n" << i;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
