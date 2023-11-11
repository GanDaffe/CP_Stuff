#include <bits/stdc++.h> 
 
using namespace std; 
 
const int N = 4e5;  
vector<long long> tree(2 * N); 
long long n, q; 
 
void build(long long arr[]) 
{
    for(long long i = 0; i < n; i++) 
        tree[n + i] = arr[i]; 
    
    for(long long i = n - 1; i > 0; i--)
        tree[i] = tree[i << 1] + tree[i << 1 | 1]; 
}
 
void update(long long p, long long val) 
{
    tree[p + n] = val;
    p = p + n; 
 
    for(long long i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] +  tree[i ^ 1]; 
}
 
long long query(long long l, long long r) 
{
    long long res = 0; 
 
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) 
    {
        if(l & 1)    
            res += tree[l++]; 
 
        if(r & 1)
            res += tree[--r]; 
    }
 
    return res; 
}
 
int main() 
{       
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);
 
    cin >> n >> q; 
    long long arr[n];
 
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
 
    build(arr);
    while(q--)
    {
        int a, b, c; 
        cin >> c >> a >> b; 
        if(c == 1)
            update(a - 1, b); 
        else 
            cout << query(a - 1, b) << '\n';
    } 
    return 0; 
}
