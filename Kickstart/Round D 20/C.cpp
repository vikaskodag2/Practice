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
const ll N = 5e5 + 10;

ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll add(ll a, ll b, ll p = MOD) {a += b; if(a > p) a -= p; return a;}
ll mul(ll a, ll b, ll p = MOD) {return (ll)((a % p) * (b % p))% p;}
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

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd

struct Tree {
    ll cntA = 0;
    ll cntB = 0;
};

ld ans;
ll n, a, b, par;
vector<ll> adj[N], v;
vector<Tree> tree(N);

void dfs(int cur, int par) {
    tree[cur].cntA = 1;
    tree[cur].cntB = 1;
    v.pb(cur);
    for (auto &it : adj[cur]) {
        if (it == par) continue;
        dfs(it, cur);
    }
    v.pop_back();   

    if (v.size() >= a) tree[v[v.size() - a]].cntA += tree[cur].cntA;
    if (v.size() >= b) tree[v[v.size() - b]].cntB += tree[cur].cntB;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    #ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> a >> b;
        
        v.clear();
        for (int i = 0; i <= n; i++) {
            tree[i].cntA = 0;
            tree[i].cntB = 0;
            adj[i].clear();
        }
        ans = 0;

        for (int i = 2; i <= n; i++) {
            cin >> par;
            adj[par].pb(i);
        }

        dfs(1, 0);

        for (int i = 1; i <= n; i++) {
            ans += (tree[i].cntA + tree[i].cntB) * 1.0 / n;
            ans -= (tree[i].cntA * tree[i].cntB * 1.0) / n / n;    
        }

        cout << "Case #" << t << ": " << sp(8) << ans << "\n";
    }

    cerr << "Time Elapsed : " << sp(8) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}