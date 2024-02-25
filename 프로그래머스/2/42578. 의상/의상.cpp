#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    multimap<string, string> clo; //키 중복을 허용하는 맵
    vector <string> key; //키를 저장할 벡터
    for(int i=0; i<clothes.size();i++)
    {
        clo.insert(make_pair(clothes[i][1],clothes[i][0])); //키: 종류, 값 : 이름
        key.push_back(clothes[i][1]); //벡터에 키 넣기
    }
    
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()),key.end()); //벡터 중복값 삭제

    int s=0;
    for(int i=0; i<key.size();i++)
    {
        s = clo.count(key[i])+1; //키가 key[i]인 값의 개수 +1
        answer *= s; 
    }
    answer -=1; //전부 안입는 경우 제외
    return answer;
}