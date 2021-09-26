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
const ll N = 2e5 + 10;

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

// Problem: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d#problem

int T;
ll n, q, ans, x, val;
ll A[N], V[N], ST1[4 * N], ST2[4 * N];

ll leftchild(ll p) { return p << 1; }
ll rightchild(ll p) { return (p << 1) + 1;}

void build(ll node, ll left, ll right, ll segtree[], ll a[]) {  //Time : O(n)
    if (left == right)
		segtree[node] = a[left];
	else {
		build(leftchild(node), left, (left + right) / 2, segtree, a);
		build(rightchild(node), (left + right) / 2 + 1, right, segtree, a);
		segtree[node] = (segtree[leftchild(node)] + segtree[rightchild(node)]);
	}
    // cout << node << " " << segtree[node] << "\n";
}

ll query(ll node, ll left, ll right, ll i, ll j, ll segtree[]) {	//Time : O(logn)
	if (left > j || right < i) 
		return 0;
	if(left >= i && right <= j)
		return segtree[node];
	else
		return (query(leftchild(node), left, (left + right) / 2, i, j, segtree) + query(rightchild(node), (left + right) / 2 + 1, right, i, j, segtree));
}

void update(ll node, ll left, ll right, ll index, ll value, ll segtree[], ll a[]) {	//Time : O(logn)
	if (left == right)
		segtree[node] = a[index] = value;
	else {
		if (left <= index && index <= (left + right) / 2)
			update(leftchild(node), left, (left + right) / 2, index, value, segtree, a);
		else
			update(rightchild(node), (left + right) / 2 + 1, right, index, value, segtree, a);
		segtree[node] = (segtree[leftchild(node)] + segtree[rightchild(node)]);
	}
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
      freopen("out.txt", "w", stdout);
    #endif

    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(A, 0, sizeof(A));
        memset(V, 0, sizeof(V));
        memset(ST1, 0, sizeof(ST1));
        memset(ST2, 0, sizeof(ST2));
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            V[i] = i * A[i];
            if (i % 2 == 0) {
                A[i] *= -1;
                V[i] *= -1;
            }
            // cout << i << " " << A[i] << " " << V[i] << "\n";
        }

        build(1LL, 1LL, n, ST1, A);
        build(1LL, 1LL, n, ST2, V);
        // for (int i = 0; i <= 4 * n; i++) cout << ST2[i] << " ";
        // cout << "\n";
        
        ans = 0;
        for (int i = 0; i < q; i++) {
            char type;
            ll x, y;
            cin >> type >> x >> y;
            if (type == 'U') {
                A[x] = y;
                V[x] = x * y;
                if (x % 2 == 0) {
                    A[x] *= -1;
                    V[x] *= -1;
                }
                update(1LL, 1LL, n, x, A[x], ST1, A);
                update(1LL, 1LL, n, x, V[x], ST2, V);
            } else {
                ll temp = query(1LL, 1LL, n, x, y, ST2);
                temp -= (x - 1) * query(1LL, 1LL, n, x, y, ST1);
                if (x % 2 == 0)
                    temp *= -1;
                ans += temp;
                // cout << "Q[l, r] = " << ans << " " << temp << " " << query(1LL, 1LL, n, x, y, ST1) << "\n";
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    cerr << "Time Elapsed : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}