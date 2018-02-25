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


int n, q, nodes;
int a[N], root[N];
vi v;

struct node {
    int val, lt, rt;
}st[8 * N];

int Insert(int &n, int p, int l, int r, int pos) {
    n = ++nodes;
    st[n] = st[p];
    if(l == r) {
        st[n].val++;
        st[n].lt = st[n].rt = 0;
        return 0;
    }

    if(pos <= (l + r) / 2 )
        Insert(st[n].lt, st[p].lt, l, (l + r) / 2, pos);
    else
        Insert(st[n].rt, st[p].rt, (l + r) / 2 + 1, r, pos);
    st[n].val = st[st[n].lt].val + st[st[n].rt].val;
}

int query(int pst1, int pst2, int l, int r, int k) {
    if(l == r)
        return l;
    int tempk = st[st[pst1].lt].val - st[st[pst2].lt].val;
    if(tempk >= k)
        return query(st[pst1].lt, st[pst2].lt, l, (l + r) / 2, k);
    else
        return query(st[pst1].rt, st[pst2].rt, (l + r) / 2 + 1, r, k - tempk);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i], v.pb(a[i]);

    sort(all(v));

    for(int i = 0; i < n; i++)
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;

    Insert(root[1], 0, 1, n, a[0]);
    for(int i = 1; i < n; i++)
        Insert(root[i + 1], root[i], 1, n, a[i]);

    for(; q; q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = query(root[r], root[l - 1], 1, n, k);
        cout << v[ans - 1] << "\n";
    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}
