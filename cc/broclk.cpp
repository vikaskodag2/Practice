//https://www.codechef.com/FEB18/problems/BROCLK

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
#define sp fixed << setprecision
#define f first
#define s second
#define MOD (int) 1e9 + 7
#define INF (ll) 1e12 + 7
#define N 1005
#define pll pair<ll, ll>
 
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll fpow(ll n, ll k, ll p = 1000000007) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(ll a, ll p = 1000000007) {return fpow(a, p - 2, p);}
ll mult(ll a, ll b, ll p = 1000000007) {return (ll)((a % p) * (b % p))% p;}
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
 
ll l, d, t, p, base;
ll st[2] = {0, 0};
 
void multiply(ll a[2][2], ll b[2][2]) {
    ll mul[2][2];
    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            mul[i][j] = 0;
            for (ll k = 0; k < 2; k++) {
                mul[i][j] = (mul[i][j] + mult(a[i][k], b[k][j])) % 1000000007;
            }
        }
    }
    for (ll i=0; i<2; i++)
        for (ll j=0; j<2; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
 
ll power(ll F[2][2], ll n) {
    ll M[2][2] = {{mult(2, base), -1}, {1, 0}};
    if (n==1) 
        return mult(F[0][0], st[0]) + mult(F[0][1], st[1]);
    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0)
        multiply(F, M);
    return mult(F[0][0], st[0]) + mult(F[0][1], st[1]);
}
 
ll findNthTerm(ll n) {
    ll F[2][2] = {{mult(2, base), -1}, {1, 0}};
    if(n == 1) {
        return base;
    }
    else if(n == 2) {
        return mult(2, fpow(base, 2)) - 1;
    }
    return power(F, n-2);
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();
    int T;
    cin >> T;
    while(T--) {
        cin >> l >> d >> t;
        {
            base = mult(d, inv(l));
            st[0] = mult(2, fpow(base, 2)) - 1;
            st[1] = base;
            ll p = findNthTerm(t);
            ll fina = (p * l) % 1000000007;
            if(fina < 0) {
                fina = (fina + 1000000007) % 1000000007;
            }
            cout << fina << "\n";
        }
    }
 
    cerr << "Execution time : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
} 
