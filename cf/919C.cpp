//http://codeforces.com/problemset/problem/919/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vpi vector<pair <int, int> >
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define ms(s, n) memset(s, n, sizeof(s))
#define f first
#define s second
#define MOD 1e9 + 7
#define INF 1e12 + 7
#define N 10000005

ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
vl prime(N + 1);
void sieve() {
    prime[0] = prime[1] = 1;
    for(ll i = 2; i <= N; i++) {
        if(!prime[i]) {
            prime[i] = i;
            for(ll j = i * i; j <= N; j += i) 
                if(!prime[j]) 
                    prime[j] = i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
    int n, m, k, cnt = 0;
    cin >> n >> m >> k;
    vector<vector<char> > s(n);
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            char temp;
            cin >> temp;
            if(temp == '.')
                cnt++;
            s[i].pb(temp);
        }
    }
    if(k == 1) {
        cout << cnt << "\n";
    }
    else {
        vi v;
    	int temp;
   		for(int i = 0; i < n; i++) {
       		for(int j = 0; j < m; j++) {
        	    if(s[i][j] == '*')
                	temp = 0;
            	else
                	temp++;
            	if(temp >= k) 
                	v.pb(1);
        	}
        	temp = 0;
    	}
    	for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
            	if(s[j][i] == '*')
                	temp = 0;
            	else
                	temp++;
            	if(temp >= k) 
                	v.pb(1);
        	}
        	temp = 0;
    	}

    	cout << v.size() << "\n";
    }

    return 0;
}
