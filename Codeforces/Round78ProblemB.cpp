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

int n;
int a[1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    int c = a[0];
    bool good = 1;
    for (int i=0; i<n; i++) if (a[i]!=c) good = 0;
    if (good) cout<<"Exemplary pages."<<endl;
    else {
        int sum = 0;
        for (int j=0; j<n; j++) {
            sum += a[j];
        }

        if (sum%n==0) {
            sum /= n;

            vector<int> m;
            vector<int> l;
            int sm = 0, sl = 0;
            for (int j=0; j<n; j++) {
                if (a[j]>sum) {
                    m.push_back(j);
                    sm += a[j];
                }
                if (a[j]<sum) {
                    l.push_back(j);
                    sl += a[j];
                }
                if (m.size()>1 && l.size()>1) break;
            }
            if (m.size()==1) {
                if (l.size()>=1) {
                    if ((sm+sl)%sum==0 && (sm+sl)/sum==(m.size()+l.size())) {
                        for (int j=0; j<l.size(); j++) {
                            if (a[m[0]]>sum) {
                                printf("%d ml. from cup #%d to cup #%d.\n",sum - a[l[j]], l[j]+1,m[0]+1);
                            }
                            else {
                                printf("%d ml. from cup #%d to cup #%d.\n",a[l[j]] - sum, m[0]+1, l[j]+1);
                            }
                        }
                        return 0;
                    }
                }
            }
            if (l.size()==1) {
                if (m.size()>1) {
                    cout<<(sm+sl)<<" "<<sm<<" "<<sl<<endl;
                    if ((sm+sl)%sum==0 && (sm+sl)/sum==(m.size()+l.size())) {
                        for (int j=0; j<m.size(); j++) {
                            if (a[l[0]]<sum) {
                                printf("%d ml. from cup #%d to cup #%d.\n",a[m[j]] - sum, l[0]+1,m[j]+1);
                            }
                            else {
                                printf("%d ml. from cup #%d to cup #%d.\n",sum - a[m[j]], m[j]+1, l[0]+1);
                            }
                        }
                        return 0;
                    }
                }
            }
        }

        cout<<"Unrecoverable configuration.";
    }

    return 0;

}
