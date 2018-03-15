//http://codeforces.com/problemset/problem/915/D

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ld long double 
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair <int, int> >
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define all(p) (p).begin(), (p).end()
#define f first
#define s second
#define mod 1e9+7
#define inf 100000000007
#define N 501

int n, m, x, y, k;
vector<vi> g(N);
vi u(N); 

void dfs(int root) {
    u[root] = 1;
    for(int i = 0; i < g[root].size(); i++) {
        int index = g[root][i];
        if(u[index] == 1)
            k++;
        else{
            if(!u[index])
                dfs(index);
        }
    }
    u[root] = 2;
}

int main(){
    ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >>x >> y;
        x--, y--;
        g[x].pb(y);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            u[j] = 0;
        k = 0;
        dfs(i);
        for(int j = 0; j < n; j++) {
            if(!u[j])
                dfs(j);
        }
        if(k <= 1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
