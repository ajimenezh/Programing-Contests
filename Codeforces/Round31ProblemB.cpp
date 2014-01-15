#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

    string s;
    cin>>s;
    int last = -1;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='@') {
            if (last==-1) {
                if (i==0) {
                    cout<<"No solution";
                    return 0;
                }
                last = i;
            }
            else {
                if (last == i-1 || last==i-2) {
                    cout<<"No solution";
                    return 0;
                }
                s = s.substr(0,i-1) + "," + s.substr(i-1, s.length()-i+1);
                i++;
                last = i;
            }
        }
    }
    if (last==s.length()-1 || last==-1) cout<<"No solution";
    else cout<<s<<endl;

    return 0;

}
