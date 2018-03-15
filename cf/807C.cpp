//http://codeforces.com/problemset/problem/807/C

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

int main(){
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t--){
		ld x,y,p,q;
		cin >> x >> y >> p >> q;
		if((x/y) == (p/q)){
			cout<<"0"<<"\n";
		}
		else{
			if(!p and !x)
				cout << 0<<"\n";
			else if(!p and x)
				cout << -1<<"\n";
			else if((p==1) and (q==1)){
				//cout<<"hey am here!!\n";
				if (!(x-y))
					cout<<0<<"\n";
				else
					cout << -1<<"\n";
			}
			else{
				//cout<<"where u lookin!!\n";
				ll t,t1;
				t = ceil((y-x) / (q-p));
				t1 = ceil(x/p);
				t = max(t,t1);
				//ll ans = q*t -y;
				cout<<(ll)(q*(ll)t -y)<<"\n";
			}	 
		}
	}
 	return 0;
}
