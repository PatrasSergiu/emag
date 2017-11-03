#include <fstream>
#include <queue>
using namespace std;
#define nmax 1005
int n,m,a[nmax][nmax],b[nmax][nmax];
char t[nmax][nmax];
queue <pair <int,int> > q;
ifstream fin("barbar.in");
ofstream fout("barbar.out");
const int di[] = { -1, 0, 1, 0 },
          dj[] = { 0, 1, 0, -1 };
pair<int,int> start;
pair<int,int> finish;
#define INF 0x3f3f3f3
bool ok(int i,int j){
    if(i > n || i < 1 || j > m || j < 1)
        return false;
return true;
}

void input(){
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            fin>>t[i][j];
            if(t[i][j] == 'D'){
                a[i][j] = 0;
                q.push({i,j});
            }
            else a[i][j] = INF;
            if(t[i][j] == 'I'){
                start.first = i;
                start.second = j;
            }
            if(t[i][j] == 'O'){
                finish.first = i;
                finish.second = j;
            }
        }
}

void drakeReach(){
    for(int i,j,iv,jv;!q.empty();){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int d= 0; d < 4;d++){
            iv = i + di[d];
            jv = j + dj[d];
            if(ok(iv,jv) && t[iv][jv] != '*')
            if(a[iv][jv] > a[i][j] + 1){
                a[iv][jv] = a[i][j] + 1;
                q.push({iv,jv});
            }
        }
    }
}

bool possiblePath(int min){
     fill(b[0] + 0, b[n+1] + m+1, INF);
     if(a[start.first][start.second] < min)
        return false;
     else {
        b[start.first][start.second] = 0;
        q.push({start.first,start.second});
     }
        for(int i,j,iv,jv;!q.empty();){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                iv = i + di[d];
                jv = j + dj[d];
                if(ok(iv,jv) && t[iv][jv] != '*')
                    if(a[iv][jv] >= min && b[iv][jv] > b[i][j] + 1){
                        b[iv][jv] = b[i][j] + 1;
                        q.push({iv,jv});
                    }
            }
        }
    if(b[finish.first][finish.second] == INF)
        return false;
    else return true;


}

int binarySearch(){
    int st=0,dr=max(n,m)+1,mij;
    while(st<dr){
        mij = (st+dr+1)/2;
        if(possiblePath(mij))
            st = mij;
        else
            dr = mij-1;
    }
return st;
}

int main()
{
    input();
    drakeReach();
    int i,j;
    int r = binarySearch();
    if(r == 0){
        if(possiblePath(r))
            fout<<0;
        else
            fout<<-1;
    }
    else
        fout<<r;

    fin.close();
    fout.close();
    return 0;
}
