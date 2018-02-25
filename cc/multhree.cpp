//https://www.codechef.com/problems/MULTHREE

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
#define N 501
 
int main(){
    ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
    	ll t;
    	cin >> t;
    	while(t--) {
    		ll k, d0, d1, cnt = 0;
    		cin >> k >> d0 >> d1;
    		cnt = 2;
    		ll ans = d0 + d1;
    		ll sum = ans;
    		bool flag = false;
    		while(cnt != k) {
    			sum = ans;
    			sum %= 10;
    			if(sum % 2 == 0) {
    				flag = true;
    				break;
    			}
    			ans += sum;
    			cnt++;
    		}
    		if(!flag) {
    			if(ans % 3 == 0) 
    				cout << "YES\n";
    			else 
    				cout << "NO\n";
    		}
    		else {
    			cnt++;
    			ll temp = sum;
    			ll tempsum = sum;
    			vi a;
    			a.pb(sum);
    			while(cnt != k) {
    				sum = ans + tempsum;
    				sum %= 10;
    				if(sum == temp) {
    					break;
    				}
    				a.pb(sum);
    				tempsum += sum;
    				cnt++;
    			}
    			if(cnt != k) {
    				ll rep = (k - cnt) / a.size() + 1;
    				ans += rep * tempsum;
    				rep = (k - cnt) % a.size();
    				for(int i = 0; i < rep; i++) 
    					ans += a[i];
    			}
    			else 
    				ans += tempsum;
    			if(ans % 3 == 0) 
    				cout << "YES\n";
    			else 
    				cout << "NO\n";
    		}
    	}
    return 0;
}  
