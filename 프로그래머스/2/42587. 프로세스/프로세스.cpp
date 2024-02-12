#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector <pair<int,int>> p;
    
    for(int i=0; i<priorities.size();i++)
        p.push_back({priorities[i],i});


    while(1)
    {
        int flag=1;
        for(int i=1; i<p.size(); i++)
        {
            if(p[0].first < p[i].first)
            {
                p.push_back(p[0]);
                p.erase(p.begin());
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            answer++;
            if(p[0].second == location) return answer;
            p.erase(p.begin());
        }
        
    }
    
    return answer;
}