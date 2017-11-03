#include <iostream>
#include <fstream>
#define nmax 100005
using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int p[nmax],n,m;

int parinte(int nod){
    if(p[nod] == nod)
        return nod;
    else return p[nod] = parinte(p[nod]);
}

void unite(int x, int y){
    p[parinte(x)] = parinte(y);
}

int main()
{
    int a,b,c;
     fin>>n>>m;
    for(a=1;a<=n;a++)
        p[a] = a;
    for(int i=1;i<=m;i++){
        fin>>c>>a>>b;
        if(c==1)
            unite(a,b);
        else {
            if(parinte(a) == parinte(b))
                fout<<"DA";
            else
                fout<<"NU";
        fout<<'\n';
        }
    }
    return 0;
}
