#include <bits/stdc++.h>
#define ull long long

using namespace std;


int main() 
{
    ull n , a;
    cin >> n >> a;
    
    vector<int>v(n+1 , 0);
    
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> v[i];
    }
    
    ull count = 0;
    
    for ( int i = 1 ; i <= n ; i++)
    {
        if ( v[i] )
        {
            int tmpdif = (int)abs(a-i);
            // cout << tmpdif << '\n';
            if( i < a )
            {
                if( a+tmpdif <= n )
                {
                    if( v[a+tmpdif] )
                    {
                        // cout << i << " " << a+tmpdif << '\n';
                        count += 2;
                    }
                }
                else
                {
                        // cout << i << " " << a+tmpdif << '\n';
                    count++;
                }
            }
            if( i == a )
            {
                if( v[i] )
                {
                    count++;
                }
            }
            if( i > a )
            {
                if( a-tmpdif < 1 )
                {
                        // cout << i << " " << a-tmpdif << '\n';
                    count++;
                }
            }
        }
    }
    
    cout << count;
    
	return 0;
}
