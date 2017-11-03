#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define nmax 100001
#define conex 100001
vector <int> adiacenta[conex];
queue <int> q;
int dist[nmax];
int n,m,s;
ofstream fout("bfs.out");

void input(){
    ifstream fin("bfs.in");
    fin>>n>>m>>s;
    int x,y;
    while(fin>>x>>y){
        adiacenta[x].push_back(y);
    }
    fin.close();
}

void bfs(){
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(auto i: adiacenta[nod]){
            if(dist[i] == 0 && i != s){
                dist[i] = dist[nod] + 1;
                q.push(i);
            }
        }

    }
}

int main()
{
    input();
    q.push(s);
    bfs();
    for(int i=1;i<=n;i++)
        if(dist[i] != 0)
            fout<<dist[i]<<" ";
        else if(i == s)
                fout<<0<<" ";
            else fout<<-1<<" ";
    return 0;
}
