#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int T;
int n, k, ans;
string a;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3

struct Trie {
    Trie* child[26];
    int cnt = 0;
};

void insert(Trie* head, string s) {
    for (auto c : s) {
        int val = c - 'A';
        
        if (head -> child[val] == NULL) 
            head -> child[val] = new Trie(); 
        
        head -> child[val] -> cnt++;
        head = head -> child[val];
    }
}


/*
{FIREF, ., .} => 5
{FIREB, FIREW, FIREW} => 4
ans = 9

n = 8, k = 2
G
G
GO
GO
GOO
GOO
GOOO
GOOO

head - G(8) - O(6) - O(4) - O(2)
O(2) = ans = 1;
O(4) = ans = 1 + 4 / 2 = 3
O(6) = ans = 3 + 6 / 2 = 6
G(8) = ans = 6 + 8 / 2 = 10

taking (cnt / k) at every lvl solves the problem of depth in trie tree as the char
will be counted that many times
*/
int query(Trie* head) {
    if (head == NULL) return 0;

    int temp_ans = 0;

    for (int i = 0; i < 26; i++) 
        temp_ans += query(head -> child[i]);
    
    temp_ans += head -> cnt / k;
    return temp_ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> k;
        auto* head = new Trie();

        for (int i = 0; i < n; i++) {
            cin >> a;
            insert(head, a);
        }

        ans = query(head);

        cout << "Case #" << t + 1 << ": " << ans << "\n";
    }
}