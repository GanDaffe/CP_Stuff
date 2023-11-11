#include <bits/stdc++.h>

#define ll long long
#define FORL(i, a, b) for(int i = a; i <= b; i++)
#define FORG(i, a, b) for(int i = a; i >= b; i--)

using namespace std; 

int n, m; 
int G[1001][1001];

int BFS(int i, int j, int val) 
{
    if(i >= 0 && j >= 0 && val == 0 && i <  n && j < m)
        G[i][j] = 1; 
    else 
        return 0; 

    return 1 + BFS(i + 1, j, G[i + 1][j]) + BFS(i - 1, j, G[i - 1][j]) + BFS(i, j + 1, G[i][j + 1]) + BFS(i, j - 1, G[i][j - 1]); 
}

int main() 
{
    cin >> n >> m; 
    char x; 
    
    FORL(i, 0, n - 1)
    {
        FORL(j, 0, m - 1)
        {
            cin >> x; 
            if(x == '.')
                G[i][j] = 0; 
            else
                G[i][j] = 1; 
        }
    }

    int res = 0;
    FORL(i, 0, n - 1)
    {
        FORL(j, 0, m - 1)
        {
            if(BFS(i, j, G[i][j]) >= 1) 
                res += 1; 
        }
    }

    cout << res;
    return 0; 
}