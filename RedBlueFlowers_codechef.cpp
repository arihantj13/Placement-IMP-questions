#include <bits/stdc++.h>
#define ull long long int

using namespace std;

void solve();
void recur(vector<vector<int>>& arr,vector<int>& red, vector<int>& blue, int n, int &res, int i, int x , int y);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
	return 0;
}

void solve()
{
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(102, vector<int>(20001, 0));
    
    vector<int> red(102 , 0);
    vector<int> blue(102 , 0);
    
    for(int i = 1 ; i <= n ; i++) {
        cin >> red[i];
    }
    
    for(int i = 1 ; i <= n ; i++) {
        cin >> blue[i];
    }
    
    int res = 0;
    
    recur(arr, red, blue, n+1, res, 1, 0, 0);
    
    cout << res << '\n';
}

void recur(vector<vector<int>>& arr, vector<int>& red, vector<int>& blue, int n, int &res, int i, int x , int y) {
    if(i == n) {
        res = max(res, min(x,y));
    }
    else {
        if(arr[i][x] >= y && arr[i][x] != 0) {
            return;
        }
        
        arr[i][x] = y;
        recur(arr, red, blue, n, res, i+1, x + red[i], y);
        recur(arr, red, blue, n, res, i+1, x, y + blue[i]);
    }
}
