//http://codeforces.com/problemset/problem/915/C

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ld long double 
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair <int, int> >
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define allr(p) (p).rbegin(), (p).rend()
#define f first
#define s second
#define mod 1e9+7
#define inf 100000000007
#define N 1005

string a, b;

int main(){
	ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
	cin >> a >> b;
	
	if(b.length() > a.length()) {
	    sort(allr(a));
	    cout << a << "\n";
	}
	else {
	    sort(all(a));
	    for(int i = 0; i < a.length(); i++) {
	        for(int j = i + 1; j < a.length(); j++) {
	            if(a[i] < a[j]) {
	                swap(a[i], a[j]);
	                if(a > b) 
	                    swap(a[i], a[j]);
	            }
	        }
	    }
	    cout << a << "\n";
	}
	
	return 0;
}
