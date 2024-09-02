#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int test;
    pair <int, int> dp[40];

    dp[0].first = 0; dp[0].second = 1;
    dp[1].first = 1; dp[1].second =1;
    for(int i=2; i<40; i++)
    {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    scanf("%d",&n);
    for(int i=0; i<n;i++)
    {
        scanf("%d",&test);
        if(test == 0) printf("1 0\n");
        else printf("%d %d\n",dp[test-1].first, dp[test-1].second);
    }
}