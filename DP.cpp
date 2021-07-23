#include <iostream>
#include <vector>
using namespace std;
/*斐波那契数列*/
int Fib(int n)
{
    if (n < 1)
    {
        return 0;
    }
    //base case
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    //状态转移
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
/*零钱兑换*/
int coinChange(vector<int> &coins, int amount)
{
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < (int)coins.size(); ++j)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
/*挖金矿
发现的金矿数目N
提供的工人数目W
各座金矿的黄金量G[]
各座金矿的用人量P[]

状态转移方程
F(n,w)=0(n<=1,w<p[0]);
F(n,w)=g[0](n==1,w>=p[0]);
F(n,w)=F(n-1,w)(n>1,w<p[n-1]);
F(n,w)=Max(F(n-1,W),F(n-1,W-p[n-1])+G[n-1])(n>1,W>=p[n-1]);
*/
int getMostGold(int n, int w, int g[], int p[])
{
    int *preResults = new int[w + 1];
    int *Results = new int[w + 1];

    for (int i = 0; i < w + 1; ++i)
    {
        if (i < p[0])
        {
            preResults[i] = 0;
        }
        else
        {
            preResults[i] = g[0];
        }
        cout << "\t" << preResults[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (j < p[i])
            {
                Results[j] = preResults[j];
            }
            else
            {
                Results[j] = max(preResults[j], preResults[j - p[i]] + g[i]);
            }

            cout << "\t" << Results[j] << " ";
        }

        for (int j = 0; j < w + 1; j++)
        {
            preResults[j] = Results[j];
        }
        cout << endl;
    }
    cout << "\t" << Results[w] << endl;
    return Results[w];
}
int main()
{
    int g[5] = {400, 500, 200, 300, 350};
    int p[5] = {5, 5, 3, 4, 3};
    getMostGold(5, 10, g, p);
    system("pause");
    return 0;
}