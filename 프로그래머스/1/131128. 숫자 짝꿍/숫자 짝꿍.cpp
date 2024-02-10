#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    int xrr[10]={0,};
    int yrr[10]={0,};
    
    for(int i=0; i<X.length(); i++)
    {
        int num = X[i]-'0';
        xrr[num]++;
    }
    for(int i=0; i<Y.length();i++)
    {
        int num = Y[i]-'0';
        yrr[num]++;
    }
    
    for(int i=9; i>=0; i--)
    {
        if(xrr[i]>0 && yrr[i]>0)
        {
            int key = min(xrr[i],yrr[i]);
            for(int k=0; k<key;k++) answer +=to_string(i);
        }
    }
    if(answer=="") answer = "-1";
    else if(answer[0]=='0') answer ="0";
    return answer;
}