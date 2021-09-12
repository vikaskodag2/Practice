#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int T;
int n, k, ans;
int A[N];

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b

/*
    Check if d (mi here) is feasible for all possible values.
    min no of session required to make d = dfinal.
    dreqd = summation over all differences (A[i] - A[i - 1]) / d
    if dreqd is greater than given k, move to next value of dfinal.
*/
int binary(int lo, int hi) {
    while(lo < hi) {
        int mi = (lo + hi) / 2;
        int r = 0;
        bool cut = false;
        for (int i = 1; i < n; i++) {
            int d = A[i] - A[i - 1];
            r += (d - 1) / mi;
            if (r > k) break;
        }
        if (r <= k) hi = mi;
        else lo = mi + 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        /*
            lets say final ans is dfinal.
            binary search over all possible values[1, 1e9] of dfinal and check for feasibility.
            the min dfinal is the answer.
        */
        int ans = binary(1, 1e9);
        
        cout << "Case #" << t + 1 << ": " << ans << "\n";
    }
}