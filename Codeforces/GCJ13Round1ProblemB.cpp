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

int t;
int x,y;
string s;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char l[] = {'W','E','S','N'};

int dist(int a, int b) {
    return abs(a) + abs(b);
}

int main() {

    freopen("C:\\Users\\Alex\\Downloads\\B-large (1).in","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;

    for (int tt=0; tt<t; tt++) {
        cin>>x>>y;

        int k = dist(x,y);
        int p = 0;
        int i;

        for (i=1; i<=k; i++) {
            p += i;
            if (p>=k && p%2==k%2) break;
        }
        //cout<<i<<endl;

        int par = k%2;
        for (i; i>=1; i--) {
            for (int j=0; j<4; j++) {
                if (i%2==0 && dist(x+dx[j]*i,y+dy[j]*i)%2==par && dist(x+dx[j]*i,y+dy[j]*i)<=i*(i-1)/2) {
                    x += dx[j]*i;
                    y += dy[j]*i;
                    s = l[j]+s;
                    par = dist(x,y)%2;
                    break;
                }
                else if (i%2==1 && dist(x+dx[j]*i,y+dy[j]*i)%2!=par && dist(x+dx[j]*i,y+dy[j]*i)<=i*(i-1)/2) {
                    x += dx[j]*i;
                    y += dy[j]*i;
                    s = l[j]+s;
                    par = dist(x,y)%2;
                    break;
                }
            }
            //cout<<x<<" "<<y<<endl;
        }
        printf("Case #%d: ",tt+1);
        cout<<s;
        cout<<"\n";
        s = "";
    }


    return 0;

}
