#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    multimap<string, string> clo;
    vector <string> key;
    for(int i=0; i<clothes.size();i++)
    {
        clo.insert(make_pair(clothes[i][1],clothes[i][0]));
        key.push_back(clothes[i][1]);
    }
    
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()),key.end());

    int s=0;
    for(int i=0; i<key.size();i++)
    {
        s = clo.count(key[i])+1;
        answer *= s;
    }
    answer -=1;
    return answer;
}