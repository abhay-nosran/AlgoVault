#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);
    long long sum = 0;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        pq.push({a[i], i});
    }

    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    while (k-- && !pq.empty()) {
        int num = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        sum -= num;

        int bestReduction = num;
        for (int j = 0; j < m; j++) {
            int reduced = num & b[j];
            if (reduced < bestReduction) {
                bestReduction = reduced;
            }
        }

        if (bestReduction < num) {
            sum += bestReduction;
            pq.push({bestReduction, index});
        } else {
            sum += num;
        }
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
