#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string str = to_string(x);
    int num=0;
    for(int i=0; i<str.length();i++)
    {
        num+= str[i]-'0';
    }
    if(x%num!=0) answer = false;
        
    return answer;
}