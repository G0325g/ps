#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    
    vector <string> arr;
    for(int i=0; i<numbers.size();i++)
        arr.push_back(to_string(numbers[i]));
    
    sort(arr.begin(), arr.end(), compare);
    
    if(arr[0]=="0") return "0";
    for(int i=0; i<arr.size();i++)
        answer +=arr[i];
    
    
    return answer;
}