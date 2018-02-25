//http://codeforces.com/contest/385/problem/C

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
#define sp fixed << setprecision
#define f first
#define s second
#define MOD (int) 1e9 + 7
#define INF (ll) 1e12 + 7
#define N 10000005

ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll mult(ll a, ll b, ll p = MOD) {return (ll)((a % p) * (b % p))% p;}

vl prime(N + 1);
vl query(N), presum(N);
int n, temp, q;
vi x;

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

vl factors(ll n) {
    vl fac;
    while(n > 1) {
        ll temp = prime[n];
        fac.pb(temp);
        while(n > 1 && prime[n] == temp)
            n /= prime[n];
    }
    return fac;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    sieve();

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        vl tempfac = factors(temp);
        for(auto e : tempfac)
            query[e]++;
    }

    presum[0] = query[0];
    for(int i = 1; i < N; i++)
        presum[i] = presum[i - 1] + query[i];

    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        l = min(l, (int)1e7);
        r = min(r, (int)1e7);
        cout << presum[r] - presum[l] << "\n";
    }


    cerr << "Execution time : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}
