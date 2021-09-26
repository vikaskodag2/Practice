#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 10;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174

int dp[N][5];
int a[N];
int tans = INT_MAX, n;

int recur(int cur, int cur_char) {
    int &ans = dp[cur][cur_char];
    
    if (ans != INT_MAX) return ans;

    if (cur > n - 2) return ans = 0;

    int nxt = cur + 1;
    for (int i = 0; i < 4; i++) {
        if (a[cur] > a[nxt] && cur_char > i)
            ans = min(ans, recur(nxt, i));
        else if (a[cur] < a[nxt] && cur_char < i)
            ans = min(ans, recur(nxt, i));
        else if (a[cur] == a[nxt] && cur_char == i)
            ans = min(ans, recur(nxt, i));
        else
            ans = min(ans, 1 + recur(nxt, i));
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 5; j++) 
                dp[i][j] = INT_MAX;
            
        tans = INT_MAX;

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < 4; i++) {
            tans = min(tans, recur(0, i));
        }
        cout << "Case #" << t << ": " << tans << "\n";
    }

    return 0;
}