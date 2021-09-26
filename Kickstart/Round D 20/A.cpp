#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;

//Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
      freopen("out.txt", "w", stdout);
    #endif
    
    int T;
    int n, A[N], MA[N], ans;
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            if (i == 0) MA[i] = A[i];
            else MA[i] = max(A[i], MA[i - 1]);
        }    
        for (int i = 0; i < n; i++) {
            if (i == 0) ans += A[1] < A[0];
            else if (i < n - 1) {
                if (MA[i - 1] < A[i] && A[i] > A[i + 1]) ans++;
            }
            else ans += (MA[i - 1] < A[i]);
        }
        if (n == 1) ans = 1;

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}