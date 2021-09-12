#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    int T;
    int n, k, p;
    // sum[i][j] = sum of all plates till j in stack i.
    // dp[i][p] = ans, when taking p plates in i stacks.
    int A[50][30], sum[50][31], dp[51][1501];

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> k >> p;
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) {
            for (int j = 0, s = 0; j < k; j++) {
                cin >> A[i][j];
                s += A[i][j];
                sum[i][j + 1] = s;
            }
        }

        /*
            You will either pickup : 
            a. n plates from i - 1 stack and o plates from current stack
            b. n - 1 plates from i - 1 stack and 1 plate from current stack
            c. n - 2 plates from i - 1 stack and 2 plates from current stack
            .
            .
            .
            find out the maximum value among (a, b, c, ...)
        */
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= p; j++)
                for (int l = 0; l <= min(j, k); l++) 
                    dp[i][j] = max(dp[i][j], sum[i - 1][l] + dp[i - 1][j - l]);

        cout << "Case #" << t + 1 << ": " << dp[n][p] << "\n";
    }

    return 0;
}