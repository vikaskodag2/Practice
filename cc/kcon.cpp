//https://www.codechef.com/JAN18/problems/KCON

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
             
vi a;
ll t, n, k, ans = 0, len = 0, temp;
bool flag = true;
             
ll maxSubArraySum(ll size) {
	ll max_so_far = (ll)a[0];
    ll curr_max = (ll)a[0];
    for (ll i = 1; i < size; i++) {
    	curr_max = max((ll)a[i], curr_max + (ll)a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
             
int main(){
ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
cin >> t;
while(t--) {
	cin >> n >> k;
    flag = true;
    ans = 0, len = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        a.pb(temp);
        len++;
        ans += temp;
        if(temp < 0) 
            flag = false;
    }
    if(flag) 
       	cout << ans * k << "\n";
    else {
        ll sum = 0;
        if(k == 1) {
            sum = maxSubArraySum(len);
            cout << sum << "\n";
        }
        else if(k == 2 || k == 3) {
            k--;
            for(int i = 0; i < k * len; i++)
            	a.pb(a[i]);         					          			
            	k++;
            	len *= k;
            	sum = maxSubArraySum(len);
            	cout << sum << "\n";
            }
            else {
            	if(ans > 0) 
            		sum += (k-2) * ans;
            	for(int i = 0; i < len; i++)
            		a.pb(a[i]);
            	len += len;	
            	sum += maxSubArraySum(len);
            	cout << sum << "\n";
            }
        }
        a.clear();
    }
    return 0;
}    
