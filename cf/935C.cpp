//http://codeforces.com/problemset/problem/935/C

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
#define N 1005

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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    clock_t tStart = clock();

    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    double ansx = 0, ansy = 0, ansr = 0;
    double temp = pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2);
    temp = sqrt(temp);

    int mnum = y2 - y1;
    int dnum = x2 - x1;
    double theta;

    if(mnum == 0 && dnum == 0) {
        cout << sp(10) << (double)x1 << " " << (double)(y1 - (double)r / 2) << " ";
        cout << sp(10) << (double)r / 2 << "\n";
        return 0;
    }
    else if(temp >= r) {
        ansx = ansy = 0;
        cout << sp(10) << ansx + x1 << " " << ansy + y1 << " " << (double)r << "\n";
        return 0;
    }

    if(dnum == 0) {
        ansx = x1;
        ansy = (double)(y1 + y2 - r) / 2;
    }
    else if(mnum == 0) {
        ansy = y1;
        ansx = (double)(x1 + x2 - r) / 2;
    }
    else {
        theta = abs(atan((double) mnum / dnum));
        
        if(y1 > y2)
            ansy = sin(theta) * (double)(r - temp) / 2 + y1;
        else
            ansy = y1 - sin(theta) * (double)(r - temp) / 2;
        if(x1 > x2)
            ansx = cos(theta) * (double)(r - temp) / 2 + x1;
        else
            ansx = x1 - cos(theta) * (double)(r - temp) / 2;
    }

    cout << sp(10) << ansx << " " << ansy << " ";
    cout << sp(10) << (double)(r + temp) / 2 << "\n"; 

    cerr << "Execution time : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
    return 0;
}
