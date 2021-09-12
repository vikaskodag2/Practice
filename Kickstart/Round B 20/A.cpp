#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n, ans, A[100];

//Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 1; i + 1 < n; i++) 
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) ans++;

        cout << "Case #" << t << ": " << ans << "\n";
    }
}