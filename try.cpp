#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e9;

void solve()
{
    int n;
    cin >> n;
    auto ask = [&](int i, int j) -> void
    {
        cout << i << " " << j << "\n";
        cout.flush();
        string res;
        cin >> res;
        if (res == "WIN")
        {
            exit(0);
        }
    };
    int ops = 0;
    while (ops < 10000)
    {

        for (int i = 1; i <= n - 1 && ops < 10000; i++)
        {
            ask(i, i + 1);
            ops++;
        }
        for (int i = n - 1; i >= 1 && ops < 10000; i--)
        {
            ask(i, i + 1);
            ops++;
        }
    }
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
