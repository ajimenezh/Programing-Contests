#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 3*3*3*3*3+1

int n,k;
char m[5][5];
char sol[MAXN][MAXN];

void fill_white(int i, int j, int c)
{
    //cout<<i<<" "<<j<<" "<<c<<endl;
    if (c==1) {sol[i][j] = m[i][j]; return;}
    if (c==2)
    {
        //cout<<i<<" "<<j<<endl;
        for (int a=i; a<i+n; a++) for (int b=j; b<j+n; b++) {
            //cout<<a<<" "<<b<<endl;
            sol[a][b] = m[a-i][b-j];
        }
        return;
    }

    int tmp = 1;
    c--;
    for (int a=0; a<c-1; a++) tmp *= n;

    for (int a=0; a<n; a++) for (int b=0; b<n; b++)
    {
        if (m[a][b]=='*')
        {
            for (int aa=i+tmp*a; aa<(i+tmp*a+tmp); aa++)
                for (int bb=j+tmp*b; bb<(j+tmp*b+tmp); bb++)
                    sol[aa][bb] = '*';
        }
        else fill_white(i+a*tmp,j+b*tmp,c);
    }
    return;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>k;
    int tmp = 1;
    for (int i=0; i<k-1; i++) tmp *= n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin>>m[i][j];

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (m[i][j]=='*')
        {
            for (int ii=i*tmp; ii<(i*tmp+tmp); ii++)
                for (int jj=j*tmp; jj<(j*tmp+tmp); jj++)
                    sol[ii][jj] = '*';
        }
        else fill_white(tmp*i,tmp*j,k);
    }

    fo(i,tmp*n) {fo(j,tmp*n) cout<<sol[i][j]; cout<<endl;}


	return 0;

}
