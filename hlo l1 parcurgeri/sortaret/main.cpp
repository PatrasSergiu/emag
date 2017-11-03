#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sortaret.in");
ofstream fout("sortaret.out");
#define NMAX 50005
vector<int> adiacenta[NMAX];
bool viz[NMAX];
int sol[NMAX],nr;

void dfs(int x){
    viz[x] = true;
    for(auto i: adiacenta[x]){
        if(viz[i] == 0)
            dfs(i);
    }
    sol[++nr] = x;
}

int main()
{
    int n,m,x,y,i;
    fin>>n>>m;
    for(i=1;i<=m;i++){
        fin>>x>>y;
        adiacenta[x].push_back(y);
    }
    dfs(1);
    for(i=1;i<=n;i++)
        if(!viz[i])
            dfs(i);
    for(i=nr;i>=1;i--)
        fout<<sol[i]<<" ";

    fin.close();
    fout.close();

    return 0;
}
