#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
ll inf = 1e15;
#define deci(n) fixed << setprecision(n)
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define umll unordered_map<ll, ll>
#define mll map<ll, ll>
#define ld long double
ld e = 0.00001;

#define pll pair <ll, ll>
using namespace std;

ll p =  998244353;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

ll t; cin >> t;

while(t--){
    ll n, m; cin >> n >> m;
    string grid[n];

    for(ll i=0; i<n; i++)cin >> grid[i];
    
    for(ll j=0; j<m; j++){
        if(grid[0][j] != '#')grid[0][j] = 'r';
        else break;
    }

    ll ans = 0;

    for(ll i=1; i<n; i++){
        ll cnt = 0;
        for(ll j=0; j<m; j++){
            if(grid[i-1][j]=='r' && grid[i][j]!='#'){grid[i][j] = 'r'; cnt++;}
        }

        for(ll j=1; j<m; j++){
            if(grid[i][j-1] == 'r' && grid[i][j]!='#')grid[i][j] = 'r';
        }

        for(ll j=m-2; j>=0; j--){
            if(grid[i][j+1] == 'r' && grid[i][j]!='#')grid[i][j] = 'r';
        }

        if(cnt == 0){
            ans++;
            for(ll j=0; j<m; j++)grid[i][j] = 'r';
        }
    }

    if(grid[n-1][m-1] != 'r')ans++;
    cout << ans << "\n";
}
