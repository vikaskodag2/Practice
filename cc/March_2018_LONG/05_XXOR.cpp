#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pair <int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;
#define pb emplace_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define allr(p) (p).rbegin(), (p).rend()
#define sp fixed << setprecision
#define f first
#define s second
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 7;
const ll N = 1e5 + 7;

ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll mult(ll a, ll b, ll p = MOD) {return (ll)((a % p) * (b % p))% p;}
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

int pp[N][31];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    int n, q, temp;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
    	cin >> temp;
    	for(int j = 0; j < 31; j++) 
    		pp[i][j] = pp[i - 1][j] + (temp >> j & 1);
    }

    while(q--) {
    	int l, r, ans = 0;
    	cin >> l >> r;
    	for(int i = 30; i >= 0; i--) 
    		ans = ans * 2 + ((pp[r][i] - pp[l - 1][i]) * 2 < (r - l + 1));
    	cout << ans << "\n";
    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}