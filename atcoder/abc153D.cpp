/*
source: ABC 153 D Caracal vs Monster
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

LL sol(LL x)
{
    if(x == 1)
    {
        return 1;
    }
    return 2 * sol(x / 2) + 1;
}

int main()
{
    IOS;
    LL h;
    cin >> h;
    cout << sol(h) << '\n';
}
