#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> G;
    queue<string> card1;
    queue<string> card2;
    
    for(int i=0; i<goal.size();i++) G.push(goal[i]);
    for(int i=0; i<cards1.size();i++) card1.push(cards1[i]);
    for(int i=0; i<cards2.size();i++) card2.push(cards2[i]);
    
    while(!G.empty())
    {
        string g = G.front();
        string c1 = card1.front();
        string c2 = card2.front();
        
        if(g == c1) card1.pop();
        else if(g == c2)card2.pop();
        else 
        {
            answer = "No";
            return answer;
        }
        G.pop();
    }
    return answer;
}