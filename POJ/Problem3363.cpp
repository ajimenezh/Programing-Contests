// Ulm Local 2007
// Problem: Annoying painting tool

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
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m,r,c;
string board[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>m>>r>>c && n!=0) {

        for (int i=0; i<n; i++) cin>>board[i];

        int ans = 0;
        for (int i=0; i<n-r+1; i++) {
            for (int j=0; j<m-c+1; j++) {
                if (board[i][j]=='1') {
                    ans ++;
                    for (int ii=i; ii<i+r; ii++) {
                        for (int jj=j; jj<j+c; jj++) {
                            if (board[ii][jj]=='1') board[ii][jj] = '0';
                            else board[ii][jj] = '1';
                        }
                    }
                }
            }
        }

        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (board[i][j]=='1') ans = -1;

        cout<<ans<<endl;
    }

    return 0;

}
