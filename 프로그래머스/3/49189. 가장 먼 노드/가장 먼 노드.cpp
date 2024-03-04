#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visit[20001]={0,};
vector<int>graph[20001];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visit[start]=1;
    
    int cnt=0;
    while(!q.empty()) //큐가 빌 때까지
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size();i++)
        {
            int next = graph[cur][i];
            if(visit[next]==0) //방문하지 않은 정점
            {
                visit[next]=visit[cur]+1; // 이전 정점까지의 거리 +1
                q.push(next); //다음정점 큐에 넣기
                 
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0; i<edge.size();i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1);
    int max = *max_element(visit+1,visit+1+n);
    for(int i=1; i<=n;i++) if(visit[i]==max) answer++;
    
    
    
    return answer;
}