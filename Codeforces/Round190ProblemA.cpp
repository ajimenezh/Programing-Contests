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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b;
    string s;
    cin>>a>>b;
    cin>>s;

    int x = 0;
    int y = 0;

    for (int i=0; i<s.length(); i++) {
        if (s[i]=='U') y++;
        else if (s[i]=='D') y--;
        else if (s[i]=='L') x--;
        else x++;
    }
    int tx = 0;
    int ty = 0;
    for (int i=0; i<s.length()+1; i++) {

        if (x!=0 && y!=0 && (a-tx)%x==0 && (b-ty)%y==0) {
            if ((a-tx)/x == (b-ty)/y) {
                cout<<"Yes";
                return 0;
            }
        }
        else if (x==0 || y==0) {
            if (x==0 && y==0) {
                if (a==tx && b==ty) {
                    cout<<"Yes";
                    return 0;
                }
            }
            else if (x==0 && (b-ty)%y==0) {
                cout<<"Yes";
                return 0;
            }
            else if (y==0 && (a-tx)%x==0) {
                cout<<"Yes";
                return 0;
            }
        }

        if (i==s.length()) break;
        if (s[i]=='U') ty++;
        else if (s[i]=='D') ty--;
        else if (s[i]=='L') tx--;
        else tx++;
    }

    cout<<"No"<<endl;

    return 0;

}
