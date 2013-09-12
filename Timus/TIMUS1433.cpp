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

string s1,s2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s1>>s2;

    for (int i=0; i<4; i++) {
        if (i==0) {
            if (s1==s2) {cout<<"equal"; return 0;}
            for (int j=0; j<2; j++) {
                int c = s1[1];
                s1[1] = s1[2];
                s1[2] = s1[3];
                s1[3] = c;
                if (s1==s2) {cout<<"equal"; return 0;}
            }
        }
        else {
            for (int k=1; k<4; k++) {
                string t1 = s1;
                char c = t1[0];
                t1[0] = t1[k];
                t1[k] = c;
                if (k==1) {
                    char c = t1[2];
                    t1[2] = t1[3];
                    t1[3] = c;
                }
                if (k==2) {
                    char c = t1[1];
                    t1[1] = t1[3];
                    t1[3] = c;
                }
                if (k==3) {
                    char c = t1[1];
                    t1[1] = t1[2];
                    t1[2] = c;
                }
                if (t1==s2) {cout<<"equal"; return 0;}
                for (int j=0; j<2; j++) {
                    int c = t1[1];
                    t1[1] = t1[2];
                    t1[2] = t1[3];
                    t1[3] = c;
                    if (t1==s2) {cout<<"equal"; return 0;}
                }
            }
        }
    }

    cout<<"different";

    return 0;

}
