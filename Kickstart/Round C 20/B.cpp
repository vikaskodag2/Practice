#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 30;

int T;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb


int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    #endif

    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, len;

        cin >> n >> len;

        vector<string> A(n);
        unordered_map<char, int> indeg;
        unordered_map<char, set<char>> graph;
        set<char> char_set;

        for (int i = 0; i < n; i++) {
            cin >> A[i];
            for (char c : A[i]) char_set.insert(c);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < len; j++) {
                auto start = A[i + 1][j];
                auto end = A[i][j];
                
                if (start == end) continue;
                // cout << "start " << start << " " << end << "\n";
                if (graph[start].find(end) == graph[start].end()) indeg[end]++;
                graph[start].insert(end);
            }
        }

        // for (auto i : indeg) {
        //     cout << i.first << " indeg " << i.second << "\n";
        // }

        vector<char> ans_seq;
        queue<char> q;
        set<char> visited;
        
        for (char c : char_set) 
            if (indeg[c] == 0) 
                q.push(c), visited.insert(c);
        
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            ans_seq.push_back(cur);
            for (char i : graph[cur]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    q.push(i);
                    visited.insert(i);
                }
            }
        }

        cout << "Case #" << t + 1 << ": ";
        // cout << visited.size() << " sz " << char_set.size();
        if (visited.size() != char_set.size()) 
            cout << "-1" << "\n";
        else {
            for (char c : ans_seq) cout << c;
            cout << "\n";
        }
    }

    return 0;
}