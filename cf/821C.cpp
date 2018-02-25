//http://codeforces.com/problemset/problem/821/C

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
//#define N 1000005

int main(){
	ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n;
	vpi op;
	stack<int> opp;
	for (int i = 0; i < 2*n; ++i) {
		int b=0,l=0;
		string c;
		cin >> c;
		if(c == "add"){
			l = 1;
			cin >> b;
		}
		op.pb(mp(l,b));
	}
	int topi = 0;
	int cnt = 1,ans = 0,sz=0;
	for(int i=0;i<2*n;i++){
		if(op[i].f == 1) {
			topi = op[i].s;
			opp.push(topi);
			//cout<<topi;
		}
		else {
			if(!opp.empty()){
				//cout << topi << " " << cnt << "\n";
				if(cnt == opp.top()){
					opp.pop();
				}
				else {
					ans++;
					//cout<<i<<"\n";
					while(!opp.empty())
						opp.pop();	
				}
			}
			cnt++;
		}
	}
	cout << ans << "\n";
	return 0;
}
