// author:Chinmay Lohani
// date:9-3-2022
// problemName:B. Avoid Local Maximums
// problemLink:https://codeforces.com/contest/1635/problem/B
// memoryLimit: 256
// timeLimit:2000

#include <bits/stdc++.h>

using namespace std;

#define mod 998244353
#define lli long long int
#define ll long long
#define li long int
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)

void printArray(vector<ll> &, ll);
void fillArray(vector<ll> &ar, ll n);
void solve();
int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> ans(n);

    fillArray(ans, n);

    ll sum_n = (n * (n + 1)) / 2;

    // cout << sum_n << " ";

    float frac_x = sum_n / float(x + y);

    // cout << frac_x;

    bool possible = true;

    if ((x * frac_x) != float(int(x * frac_x)) || (y * frac_x) != float(int(y * frac_x)))
    {
        possible = false;
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << "POSSIBLE";

    int xn = floor((sqrt(4 * frac_x * x * 2 + 1) - 1) / 2);

    cout << "#" << xn << "#";

    for (ll i = xn; i < n; i++)
    {
        ans[i] = -1;
    }

    ll sum_x = (xn * (xn + 1)) / 2;

    // xn++;
    cout << "*" << sum_x << "*";

    while (sum_x < (x * frac_x) && xn < n)
    {
        ll diff = (frac_x * x) - sum_x;
        cout << "-" << diff << "-";

        if (xn + 1 - diff < 1 || ans[xn - diff] == -1)
        {
            break;
        }

        ans[xn - diff] = -1;
        ans[xn] = xn + 1;
        sum_x += xn - diff;
        xn++;
    }

    cout << '\n';

    printArray(ans, n);
}

void printArray(vector<ll> &ar, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        if (ar[i] != -1)
            cout << ar[i] << " ";
    }
}

void fillArray(vector<ll> &ar, ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        ar[i - 1] = i;
    }
}