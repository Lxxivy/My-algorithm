#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n);
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>>
        q;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
        d[i] = 1;
        q.push({3 * a[i], i});
    }
    for (int i = 0; i < n - 2; i++)
    {
        auto [cost, id] = q.top();
        q.pop();
        ans += cost;
        d[id]++;
        q.push({(2 * d[id] + 1) * a[id], id});
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
