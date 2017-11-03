#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define nmax 100005
queue <int> q;
vector <int> adiacenta[nmax];
pair <int,int> dist[nmax];
int n,m,x,r;
void input(){
    ifstream fin("reinvent.in");
    fin>>n>>m>>x;
    int i,a,b;
    for(i=1;i<=m;i++){
        fin>>a>>b;
       adiacenta[a].push_back(b);
       adiacenta[b].push_back(a);
    }
    for(i=1;i<=x;i++){
        fin>>a;
        q.push(a);
        dist[a].second = a;
    }
    fin.close();
}

void bfs(){
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(auto i : adiacenta[nod]){
            if((dist[i].first == 0) && (dist[i].second == 0) ){
                dist[i].first = dist[nod].first + 1;
                dist[i].second = dist[nod].second;
                q.push(i);
            }
            else {
                if(dist[i].second != dist[nod].second){
                    r = dist[i].first + dist[nod].first + 1;
                    return;
                }
            }
        }

    }

}

int main()
{
    ofstream fout("reinvent.out");
    input();
    bfs();
    fout<<r;
    fout.close();
    return 0;
}
