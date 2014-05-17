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

string a,b;
int dp[2][34010];
int v[34010];

int main() {

    freopen("C:\\Users\\Alex-User\\Downloads\\input20.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //for (int i=0; i<34000; i++) cout<<char('a'+rand()%26); cout<<endl;
    //for (int i=0; i<34000; i++) cout<<char('a'+rand()%26); cout<<endl;

    while (true) {
        getline(cin,a);
        getline(cin,b);

        for (int i=0; i<=a.length(); i++) {
            dp[0][i] = 0;
        }

        for (int i=0; i<b.length(); i++) {
            int cur = i%2;
            int next = 1 - cur;
            for (int j=0; j<=a.length(); j++) dp[next][j] = -1000;
            for (int j=0; j<=a.length(); j++) if (dp[cur][j]>=0) {

                if (a[j]==b[i]) {
                    dp[next][j+1] = max(dp[next][j+1], dp[cur][j] + 1);
                }
                dp[next][j] = max(dp[next][j], dp[cur][j]);
                if (j!=a.length()) dp[cur][j+1] = max(dp[cur][j+1], dp[cur][j]);
            }
        }

        int res = 0;
        for (int i=0; i<=a.length(); i++) res = max(dp[b.length()%2][i], res);
        printf("%d\n", a.length()+b.length()-2*res);

        getline(cin,a);
        if (a[0]==';') printf(";\n");
        else break;
    }

    return 0;

}
