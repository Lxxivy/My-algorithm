#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto deal = [&](char even, char odd) -> int
    {
        vector<int> end0, end1;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            char tar = (i % 2 == 0) ? even : odd;
            if (s[i] == tar)
            {
                continue;
            }
            if (s[i] == '0')
            {
                if (!end1.empty())
                {
                    int p = end1.back();
                    end1.pop_back();
                    end0.push_back(p);
                }
                else
                {
                    ++cur;
                    end0.push_back(cur);
                }
            }
            else
            {
                if (!end0.empty())
                {
                    int p = end0.back();
                    end0.pop_back();
                    end1.push_back(p);
                }
                else
                {
                    ++cur;
                    end1.push_back(cur);
                }
            }
        }
        return cur;
    };
    int ans1 = deal('0', '1');
    int ans2 = deal('1', '0');
    cout << min(ans1, ans2) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
