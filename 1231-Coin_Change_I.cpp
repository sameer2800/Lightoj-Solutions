/*
user: php
time: 0.436 sec
link: http://www.lightoj.com/volume_showproblem.php?problem=1231
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#define MOD 100000007
#define get(n) scanf("%d", &n)
#define loop(n) for(int i=0; i<n; i++)
#define MAXX 1001
#define mem(x, y) memset(x, y, sizeof(x))
#define loopi(i,n) for(int i=0; i<n; i++)
#define lld long long int
using namespace std;

lld dp[MAXX][51];
int coin[51];
int countCoin[51];
int target, n;

lld rec(int amount, int index)
{
  if (index == n)
  {
    if (amount == 0) return 1;

    return 0;
  }

  if (amount == 0)
  {
    return 1;
  }

  if (amount < 0)
  {
    return 0;
  }

  if (dp[amount][index] != -1)
  {
    return dp[amount][index];
  }

  lld result = 0;

  for (int i = 0; i <= countCoin[index]; i++)
  {
    result = (result + rec(amount - coin[index] * i, index + 1)) % MOD;
  }

  dp[amount][index] = result;
  return result;
}



int main()
{
  int cases, caseno = 0;
  get(cases);

  while (cases--)
  {
    loopi(i, MAXX)
    {
      loopi(j, 51)
      {
        dp[i][j] = -1;
      }
    }
    get(n);
    get(target);
    loopi(i, n)     get(coin[i]);
    loopi(i, n)     get(countCoin[i]);
    printf("Case %d: %lld\n", ++caseno, rec(target, 0));
  }

  return 0;
}