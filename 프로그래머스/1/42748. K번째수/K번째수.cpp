#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>arr;
    for(int p=0; p<commands.size();p++)
    {
        int i = commands[p][0]-1;
        int j = commands[p][1]-1;
        int k = commands[p][2]-1;
    
        for(int q = i; q<=j; q++)  arr.push_back(array[q]);
        sort(arr.begin(),arr.end());
        answer.push_back(arr[k]);
        arr.erase(arr.begin(), arr.end());
        
    }
    return answer;
}