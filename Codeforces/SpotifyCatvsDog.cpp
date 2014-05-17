#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, d, c;
bool done[510];
pair<int,int> choice[510];
bool bad[510];
bool good[510];
int cnt[210];

int main() {

    int cases;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d%d%d",&c,&d,&n);
        for (int i=0; i<n; i++) done[i] = 0;
        for (int i=0; i<c+d; i++) bad[i] = 0;
        for (int i=0; i<c+d; i++) good[i] = 0;
        for (int i=0; i<n; i++) {
            string s1,s2;
            int id1, id2;
            cin>>s1>>s2;
            id1 = atoi(s1.substr(1,s1.length()-1).c_str());
            id2 = atoi(s2.substr(1,s2.length()-1).c_str());
            id1--; id2--;
            if (s1[0]=='C') {
                choice[i] = make_pair(d+id1,id2);
            }
            else {
                choice[i] = make_pair(id1,id2+d);
            }
        }

        int ans = 0;
        while (true) {
            for (int i=0; i<c+d; i++) cnt[i] = 0;
            for (int i=0; i<n; i++) if (!done[i]) {
                if (!bad[choice[i].first] && !good[choice[i].second]) cnt[choice[i].first]++;
            }
            int best = 0;
            int w = -1;
            for (int i=0; i<c+d; i++) {
                if (cnt[i]>best) {
                    best = cnt[i];
                    w = i;
                }
            }
            if (best==0) break;
            for (int i=0; i<n; i++) if (!done[i]) {
                if (!bad[choice[i].first] && !good[choice[i].second]) {
                    if (w==choice[i].first) {
                        bad[choice[i].second] = 1;
                        done[i] = 1;
                        ans++;
                    }
                }
            }
            good[w] = 1;
        }

        printf("%d\n",ans);
    }

    return 0;

}
