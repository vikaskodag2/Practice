//http://codeforces.com/problemset/problem/845/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, ll > > lr(n);
	for(ll i=0; i<n ;i++)
		cin >> lr[i].first >> lr[i].second;
	
	sort(lr.begin(), lr.end());
	{
		ll pos1,pos2;
		pos1 = lr[0].second;
		pos2 = lr[1].second;
		for(ll i=2;i<n;i++){
			if(lr[i].first > pos1){
				pos1 = lr[i].second;
			}
			else if(lr[i].first > pos2){
				pos2 = lr[i].second;
			}
			else{
				cout<< "NO";
				return 0;
			}
		}
		cout<< "YES";
	}
	return 0;
}
