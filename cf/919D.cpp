//http://codeforces.com/problemset/problem/919/D

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
#define MOD 1e9 + 7
#define INF 1e12 + 7
#define N 300005

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

vector<vi> g(N);
vi visited(N, -1);
bool cycle = false;
int dp[N][26];
int deg[N];
queue<int> foo;

// -1 = Not explored,0 = being explored,1 = Fully explored
bool iscyclic(int root) {
    if(cycle)
        return true;
    visited[root] = 0;
    for(auto e : g[root]) {
        if(visited[e] == -1) 
            iscyclic(e);
        else if(visited[e] == 0) { //came across a vertex with 0 value representing cycle.
            cycle = true;
            return true;
        }
    }
    visited[root] = 1; // root is completely visited with no cycle.
}



int main(){
    ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();
    int n, m, x, y;
    string s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        deg[y]++;
        if(x == y)
            cycle = true;
    }
    for(int i = 0; i < n && !cycle; i++)
        iscyclic(i);
    if(cycle){
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n; i++) { 
        if(!deg[i]) {
            foo.push(i);
            dp[i][s[i] - 'a']++;
        }
    }

    while(!foo.empty()) {
        int cur = foo.front();
        foo.pop();
        for(auto e : g[cur]) {
            for(int j = 0; j < 26; j++) {
                dp[e][j] = max(dp[e][j], dp[cur][j] + (s[e] - 'a' == j));
            }
            deg[e]--;
            if(!deg[e])
                foo.push(e);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    cerr << "Execution time : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}
