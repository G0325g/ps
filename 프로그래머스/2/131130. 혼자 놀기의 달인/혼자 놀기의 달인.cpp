#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> cards) {
    int answer = 0;
    vector <int> arr;
    int visit[101]={0,};
    for(int i=0; i<cards.size();i++)
    {
        int num = cards[i];
        int cnt=0;
        while(1)
        {
            if(visit[num]==1) break;
            visit[num]=1;
            num = cards[num-1];
            cnt++;
        }
        arr.push_back(cnt);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    
    answer = arr[0] * arr[1];
    return answer;
}