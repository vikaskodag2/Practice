#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

//Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    int t;
    int A[N];
    int n, b, ans = 0;

    cin >> t;
    for (int y = 0; y < t; y++) {
        cin >> n >> b;
        ans = 0;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        sort(A, A + n);

        for (int i = 0; i < n; i++) {
            b -= A[i];
            if (b >= 0) ans++;
            else break;
        }

        cout << "Case #" << y + 1 << ": " << ans << "\n";
    }

    return 0;
}