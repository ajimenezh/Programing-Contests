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
string s[4];

bool _find(char c) {
    for (int i=0; i<4; i++) {
        int cnt = 0;
        for (int k=0; k<4; k++) if (s[i][k]==c || s[i][k]=='T') cnt++;
        if (cnt==4) return 1;
        cnt = 0;
        for (int k=0; k<4; k++) if (s[k][i]==c || s[k][i]=='T') cnt++;
        if (cnt==4) return 1;
    }
    int cnt = 0;
    for (int i=0; i<4; i++) if (s[i][i]==c || s[i][i]=='T') cnt++;
    if (cnt == 4) return 1;
    cnt = 0;
    for (int i=0; i<4; i++) if (s[i][3-i]==c || s[i][3-i]=='T') cnt++;
    if (cnt==4) return 1;
    return 0;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;
    for (int i=0; i<t; i++) {
        for (int j=0; j<4; j++) cin>>s[j];
        printf("Case #%d: ",i+1);
        if (_find('X')) {
            cout<<"X won"<<endl;
        }
        else if (_find('O')) {
            cout<<"O won"<<endl;
        }
        else {
            bool some = 0;
            for (int j=0; j<4; j++) {
                for (int k=0; k<4; k++) {
                    if (s[j][k]=='.') {
                        some = 1;
                        break;
                    }
                }
            }
            if (some) {
                cout<<"Game has not completed"<<endl;
            }
            else {
                cout<<"Draw"<<endl;
            }
        }
    }

    return 0;

}
