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


int n,k;
int d[100010];
pair<int,int> all[100010];
vector<int> e[100010];

int main() {

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d", d+i);

    int p = -1;

    for (int i=0; i<n; i++) {
        if (d[i]==0) {
            if (p==-1) p = i;
            else {
                cout<<-1;
                return 0;
            }
        }
    }

    if (p==-1) {
        cout<<-1;
       return 0;
    }

    for (int i=0; i<n; i++) all[i] = make_pair(d[i], i);
    sort(all, all+n);

    p = 0;
    int tot = 0;
    for (int i=1; i<n; i++) {
        int j = i;
        while (j<n && all[j].first==all[i].first) {
            //cout<<all[i].second<<" "<<e[all[p].second].size()<<endl;
            if (p==0 && e[all[p].second].size()==k) {
                cout<<-1;
                return 0;
            }
            else if (p!=0 && e[all[p].second].size()==k-1) {
                p++;
                if (p==i) {
                    cout<<-1;
                    return 0;
                }
            }
            e[all[p].second].push_back(all[j].second);
            tot++;
            j++;
        }
        if (j==n) break;
        else {
            p = i;
            i = j-1;
        }
    }

    cout<<tot<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<e[i].size(); j++) printf("%d %d\n", i+1, e[i][j]+1);
    }

    return 0;

}
