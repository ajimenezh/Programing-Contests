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

int t;
int w,h,s,c,g;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>w>>h>>s>>c>>g;

        if (g/s>=w) {
            cout<<-1<<endl;
            continue;
        }

        int res = 0;
        for (int i=0; i*s<=g; i++) {
            int k = (g - i*s)/c;
            if ((g-k*c-i*s)>=s) i += (g-k*c-i*s)/s;
            int now = w;
            int d = 1;
            int f = 0;
            int p;
            //cout<<i<<" "<<k<<endl;
            while (d<=h) {
                f++;
                if (now>=i) {
                    if (now==i) {
                        now = w;
                    }
                    else {
                        if (i==0) d++;
                        else {
                            p = (now-1)/i;
                            p = min(p,h-d);
                            if (p<=0) {
                                d++;
                                now = now-i;
                            }
                            else {
                                d += p;
                                f += p-1;
                                now = now - i*p;
                            }
                        }
                    }
                }
                else if (now<i) {
                    now = w - (i-now);
                }
                if (k>0 && d==h && now>i) {
                    now = w;
                    d = 1;
                    f += (k-1)*(f+1);
                    k = 0;
                    f++;
                }
                //cout<<d<<" "<<now<<endl;
            }
            //cout<<i<<" "<<f+1<<endl;
            res = max(res,f);
        }
        cout<<res<<endl;
    }

    return 0;

}
