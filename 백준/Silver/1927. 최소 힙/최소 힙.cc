#include <iostream>
using namespace std;
#include <queue>
int main()
{
  priority_queue<int,vector<int>, greater<int>> queue;

  int n;
  scanf("%d",&n);
  int x;

  for(int i=0; i<n; i++)
  {
    scanf("%d",&x);
    if(x>0)
    {
      queue.push(x);
    }
    else
    {
      if(queue.size()>0) 
      { 
        printf("%d\n",queue.top());
        queue.pop();
      }
      else printf("0\n");
    }
  }


}