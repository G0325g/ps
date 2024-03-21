#include <iostream>
using namespace std;
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sik;
    cin>>sik;

    string s_num="";
    int isMinus=false;
    int sum =0;
    for(int i=0; i<sik.length()+1;i++)
    {
       if(sik[i]=='-' || sik[i]=='+' || i == sik.length())
       {    //연산자를 만났거나 식이 끝났을때
        
        if(isMinus ==true)  //-를 만난적있으면
        {
            sum-= stoi(s_num);
            s_num="";
        }
        else   // -를 만난적 없으면 
        {
            sum+=stoi(s_num);
            s_num="";
        }

       }  
       else s_num +=sik[i]; //숫자일때

       if(sik[i]=='-') isMinus=true;
    }
    cout<<sum;
    
    
   
}
 