#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pair <int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define allr(p) (p).rbegin(), (p).rend()
#define sp fixed << setprecision
#define f first
#define s second
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 7;
const ll N = 1e6;

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

int t;
int n, h;
vi a;

int gethr(int gg) {
	int t = 0;
	for(int i = 0; i < n; i++)
		t += ceil((double)a[i] / gg);
	return t;
}

int solve() {
	int lo = 1, hi = 1e9, ans = 0, mid = 0;
	int temp = 0;
	while(hi - lo > 1) {
		mid = (lo + hi) >> 1;
		temp = gethr(mid);
		if(temp > h)
			lo = mid;
		else
			hi = mid;
	}
	temp = gethr(lo);
	if(temp <= h)
		return lo;
	else
		return hi;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    cin >> t;
    while(t--) {
    	cin >> n >> h;
    	int co;
    	a.clear();
    	for(int i = 0; i < n; i++)
    		cin >> co, a.pb(co);

    	cout << solve() << "\n";

    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}