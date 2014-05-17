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
    int k = 1;
    string str;
    int j = 1;
    int last = s.length()-1;

    for (int i=s.length()-1; i>0; i--) {
        if (s[i]=='0') {
            j++;
            continue;
        }
        else {
            if (j<i) {
                k++;
                j = 1;
                last = i-1;
            }
            else if (j==i) {
                bool greater = 1;
                for (int p=last-j+1; p<=last; p++) {
                    //cout<<s[p-(last-j+1)]<<" "<<s[p]<<endl;
                    if (s[p-(last-j+1)]>s[p]) {
                        break;
                    }
                    else if (s[p-(last-j+1)]<s[p]) {
                        greater = 0;
                        break;
                    }
                }
                if (greater) {
                    k++;
                    j = 1;
                    last = i-1;
                }
            }
            else j++;
        }

        //cout<<i<<" "<<last<<" "<<k<<endl;
    }
    cout<<k<<endl;

    return 0;

}
