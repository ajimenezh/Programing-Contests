#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define N 65
#define M 500000

int n,m;
int c[2*N+5][2*N+5];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int q[M];
int in,fn;
bool vis[M];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    c[N][N] = n;
    int cn = 0;
    int cnt = 0;
    if (n>=4) q[fn++] = ((N<<10) + N);

        while (in!=fn) {
                int ii = q[in%M]>>10;
                int jj = q[in%M]%1024;
                vis[q[in%M]] = 0;
                in++;

                    for (int k=0; k<4; k++) {
                        cnt++;
                        c[ii+dx[k]][jj+dy[k]] += c[ii][jj]>>2;

                        if (c[ii+dx[k]][jj+dy[k]]>>2 && !vis[((ii+dx[k])<<10) + jj + dy[k]]) {
                            q[(fn)%M] = ((ii+dx[k])<<10) + jj + dy[k];
                            fn++;
                            vis[((ii+dx[k])<<10) + jj + dy[k]] = 1;
                        }
                    }
                    c[ii][jj] = c[ii][jj]%4;

        }

//        for (int ii=-10; ii<=10; ii++) {for (int jj=-10; jj<=10; jj++) cout<<c2[ii+10][jj+10]<<" "; cout<<endl; }
        //cout<<c[N+1][N]<<endl;


    //for (int ii=-18; ii<=18; ii++) {for (int jj=-18; jj<=18; jj++) cout<<c[ii+N][jj+N]<<" "; cout<<endl; }
    //cout<<cnt<<endl;

    int t;
    cin>>t;

    for (int i=0; i<t; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (abs(a)>N || abs(b)>N) printf("0\n");
        else printf("%d\n",c[N+a][N+b]);
    }

    return 0;

}
