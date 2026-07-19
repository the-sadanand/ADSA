#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> dp(1 << 16, -1);
vector<ll> sums(1 << 16, 0);

ll calc(vector<vector<ll>> &compt, int mask, int n)
{
    ll sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(!(mask & (1 << i))) continue;

        for(int j = i + 1; j < n; j++)
        {
            if(mask & (1 << j))
                sum += compt[i][j];
        }
    }

    return sum;
}

void precompute(vector<vector<ll>> &compt, int n)
{
    for(int mask = 1; mask < (1 << n); mask++)
    {
        sums[mask] = calc(compt, mask, n);
    }
}

ll f(vector<vector<ll>> &compt, int mask)
{
    if(mask == 0)
        return 0;

    if(dp[mask] != -1)
        return dp[mask];

    ll ans = 0;

    for(int g = mask; g; g = (g - 1) & mask)
    {
        ans = max(ans, sums[g] + f(compt, mask ^ g));
    }

    return dp[mask] = ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<ll>> compt(n, vector<ll>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> compt[i][j];
        }
    }

    precompute(compt, n);

    cout << f(compt, (1 << n) - 1);

    return 0;
}