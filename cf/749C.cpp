//http://codeforces.com/problemset/problem/749/C

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
#define all(p) (p).begin(), (p).end()
#define f first
#define s second
#define mod 1e9+7
#define inf 100000000007

int main(){
	int n;
	cin >> n;
	string c;
	cin >> c;
	queue<int> d,r;
	int len = c.length();
	
	for(int i=0;i<len;i++){
		if(c[i] == 'D')
			d.push(i);
		else
			r.push(i);
	}

	while(!d.empty() && !r.empty()){
		int dp = d.front();
		int rp = r.front();
		d.pop();
		r.pop();
		if(dp > rp) {
			r.push(rp+n);
		} 
		else{
			d.push(dp+n);
		}
	}	
	if(d.empty())
		cout<<"R\n";
	else 
		cout<<"D\n";
	return 0;
}
