//http://codeforces.com/problemset/problem/745/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define vpi vector<pair <int, int> >
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pair<ll, ll> >
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define inf 100000000007
#define N 1005

vector<int> gr[N];
int visited[N] = {}, colour=1;

void dfs(int v) {
    visited[v] = colour; 
    for(int i = 0; i < gr[v].size(); i++) {
        int to = gr[v][i];
        if(!visited[to])
        dfs(to);
    }
}

int total(int n) {
    return (n*(n-1))/2;
}

int main()  {
    int n, k, gov[N], u, v, m, i;
    cin >> n >> m >> k;

    for(i = 0; i < k; i++)  
    	cin >> gov[i];    
    
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for(i = 0; i < k; i++){
        dfs(gov[i]);
        colour++;
    }
   
    int untouched=0, maxsize=0;
    sort(visited+1, visited+n+1);

    i = 1;
    while(!visited[i]) {
        untouched++;
        i++;
    }
    int ans = 0, size = 0;
    colour = 1;
    
    for(; i<= (n+1); i++) {
        if(i <= n && visited[i] == colour)
    	    size++;
        else {
            ans += total(size);
            maxsize = max(maxsize,size);
            size = 0;
            colour++;
            if(i == n+1)
            	break;
            i--;
        }
    }
    
    ans += total(untouched);
    ans += (untouched*maxsize);
    ans -= m;
    cout << ans;
    return 0;
}
