#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sp fixed << setprecision
const int N = 1e5 + 7;

int T;
double ans;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {

        cout << "Case #" << t + 1 << ": " << sp(5) << ans << "\n";
    }
}

/*
W - Columns (numbered 1 to W from left to right)
H - Rows (numbered 1 to H from top to bottom)
(L, U) - top-left square 
(R, D) - bottom-right square

W, H, L, U, R, D - 5 3 1 2 4 2
(W, H) = (5,3) = rectangle
(L, U) = (1, 2)
(R, D) = (4, 2)

0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
*/