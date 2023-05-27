#include <bits/stdc++.h>

#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll N = 1e5 + 5;

struct input
{
    int one;
    int two;
};

vector<int> a;

bool check(int i)
{
    return (a[i] > a[i - 1]);
}

void solve()
{
    int n, t, m, k;
    int i, j;
    int q;

    cin >> n >> q;
    a.resize(n);
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int lo = 1, hi = n - 1, max_index = 0, max;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            max_index = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    max = a[max_index];

    for (i = 0; i < q; ++i)
    {
        cin >> k;
        if(k  == max)
        {
            cout << max_index << '\n';
            continue;
        }

        int ans;
        ans = lower_bound(a.begin(), a.begin() + max_index, k) - a.begin();
        if (ans != max_index && a[ans] == k)
            cout << ans << ' ';

        ans = lower_bound(a.begin() + max_index + 1, a.end(), k, [] (int a, int b) { return (a > b); }) - a.begin();
        if (ans != (n + 1) && a[ans] == k)
            cout << ans;

        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}