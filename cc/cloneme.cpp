#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
#define ms(p) memset((p), 0, sizeof((p)))
#define f first
#define s second
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 7;
const ll N = 1e5 + 10;
const ll P = 324683;

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

ll seed[N], has[N * 30], sum[N * 30];
int t, n, q, tcnt, m, ls[N * 30], rs[N * 30], key[N], rt[N];
int a, b, c, d;

void add_tree(int &p, int l, int r, int pos) {
    ls[++tcnt] = ls[p];
    rs[tcnt] = rs[p];
    sum[tcnt] = sum[p];
    has[tcnt] = has[p];
    p = tcnt;
    if(l == r) 
        return (void)(has[p] = ++sum[p]);
    int mid = ((l + r) >> 1);
    if(pos <= mid) 
        add_tree(ls[p], l, mid, pos);
    else
        add_tree(rs[p], mid + 1, r, pos);

    sum[p] = sum[ls[p]] + sum[rs[p]];
    has[p] = has[ls[p]] + seed[mid - l + 1] * has[rs[p]];
}

ll left_value(int a, int b, int c, int d, int l, int r) {
    if(has[b] - has[a] == has[d] - has[c])
        return sum[b] - sum[a];
    if(l == r) 
        return min(sum[b] - sum[a], sum[d] - sum[c]);
    int mid = ((l + r) >> 1);
    if(has[ls[b]] - has[ls[a]] != has[ls[d]] - has[ls[c]])
        return left_value(ls[a], ls[b], ls[c], ls[d], l, mid);
    else
        return (sum[ls[b]] - sum[ls[a]] + left_value(rs[a], rs[b], rs[c], rs[d], mid + 1, r));
}

ll right_value(int a, int b, int c, int d, int l, int r) {
    if(has[b] - has[a] == has[d] - has[c])
        return sum[b] - sum[a];
    if(l == r) 
        return min(sum[b] - sum[a], sum[d] - sum[c]);
    int mid = ((l + r) >> 1);
    if(has[rs[b]] - has[rs[a]] != has[rs[d]] - has[rs[c]])
        return right_value(rs[a], rs[b], rs[c], rs[d], mid + 1, r);
    else
        return (sum[rs[b]] - sum[rs[a]] + right_value(ls[a], ls[b], ls[c], ls[d], l, mid));   
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    seed[0] = 1;
    for(int i = 1; i <= 1e5; i++)
        seed[i] = seed[i - 1] * P;

    cin >> t;
    while(t--) {
        cin >> n >> q;
        tcnt = 0;
        ms(has);
        ms(sum);
        ms(ls);
        ms(rs);
        m = 0;
        for(int i = 1; i <= n; i++) {
            cin >> key[i];
            m = max(m, key[i]);
        }

        for(int i = 1; i <= n; i++) {
            rt[i] = rt[i - 1];
            add_tree(rt[i], 1, m, key[i]);
        }

        for(;q;q--) {
            cin >> a >> b >> c >> d;
            int lefty = left_value(rt[a - 1], rt[b], rt[c - 1], rt[d], 1, m);
            int righty = right_value(rt[a - 1], rt[b], rt[c - 1], rt[d], 1, m);
            if((lefty == b - a + 1) || (lefty + righty == b - a))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}
