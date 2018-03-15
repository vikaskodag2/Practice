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

ll presum[N];
int a[N], ans[N];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	for(int i = 1; i <= n; i++)
    		cin >> a[i];
    	for(int i = 1; i <= n; i++)
    		presum[i] = presum[i - 1] + (ll)a[i];

    	memset(ans, 0, sizeof (int)*(n + 1));

    	for(int i = 1; i <= n; i++) {
    		int up = upper_bound(presum + i, presum + n, presum[i] + (ll)a[i]) - presum;
    		int lo = lower_bound(presum + 1, presum + i, presum[i - 1] - (ll)a[i]) - presum;
    		ans[up]++, ans[i]--;
    		ans[i - 1]++, ans[lo - 1]--;
    	}
    	for(int i = n; i > 0; i--) 
    		ans[i - 1] += ans[i];
    	for(int i = 1; i <= n; i++) 
    		cout << ans[i] << " ";
    	cout << "\n";
    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}