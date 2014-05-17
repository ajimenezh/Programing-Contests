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

int beta;
double yaw;
vector<double> ret;

double alpha_tmp;
double beta_tmp;
double yaw_tmp;
double SARJ_angle_tmp[2];
double BGA_angle_tmp[8];

double SARJ_vel_tmp[2];
double BGA_vel_tmp[8];

double parameters[92][20];

double blanket_orientation_tmp[8];
double shadow_fraction_string[656];
double shadow_fraction_longeron[32];

void call_shadowing() {
    printf("2\n");
    printf("1\n");

    for (int i=0; i<2; i++) {
        printf("%.f\n",SARJ_angle_tmp[i]);
    }
    for (int i=0; i<8; i++) {
        printf("%.f\n",BGA_angle_tmp[i]);
    }

    cout.flush();
}

void read_shadowing() {
    for (int i=0;  i<8; i++) {
        scanf("%.f",blanket_orientation_tmp[i]);
    }
    for (int i=0;  i<656; i++) {
        scanf("%.f",shadow_fraction_string[i]);
    }
    for (int i=0;  i<32; i++) {
        scanf("%.f",shadow_fraction_longeron[i]);
    }
}

double power() {

    double p = 0.0;

    for (int i=0; i<8; i++) {
        for (int j=0; j<82; j++) {

            p += 1371.3*blanket_orientation_tmp[i]*0.1*2.56*max(0.0, 1.0-5.0*shadow_fraction_string[j]);

        }
    }

    return p;
}


double evaluate(int minute) {

    double res = 0.0;

    yaw_tmp = yaw;

    beta_tmp = beta;


    alpha_tmp = (1.0*minute)/92.0*360.0;

    call_shadowing();

    read_shadowing();

    double p = power();

    res += p;


    return  res/92.0;
}


void ternary_search() {
    double left = 0.0;
    double right = 7.0;

    for (int i=0; i<100; i++) {

        double leftThird = (2.0*left + right)/3.0;
        double rightThird = (left + 2*right)/3.0;

        if (evaluate(leftThird) < evaluate(rightThird) ) {
            left = leftThird;
        }
        else {
            right = rightThird;
        }
    }
}

void solve(int minute, vector<double> d) {

    vector<double> g(10,0);
    vector<double> x(10,0);

    //*****************************
         yaw_tmp = _yaw;

        beta_tmp = beta;

        for (int i=0; i<2; i++) {
            x[i] = d[2*i];
        }
        for (int i=0; i<8; i++) {
            x[i] = d[4+2*i];
        }
    //****************************

    for (int k=0; k<100; k++) {
        //*****************************
         yaw_tmp = _yaw;

        beta_tmp = beta;

        for (int i=0; i<2; i++) {
            SARJ_angle_tmp[i] = d[2*i];
        }
        for (int i=0; i<8; i++) {
            BGA_angle_tmp[i] = d[4+2*i];
        }
        //****************************

        double now = evaluate(minute);

        for (int i=0; i<2; i++) {

            double tmp = 0;

            SARJ_angle_tmp[i] -= eps;

            tmp = evaluate(minute);

            SARJ_angle_tmp[i] += eps;

            g[i] = (now - tmp)/eps;
        }

        for (int i=0; i<8; i++) {

            double tmp = 0;

            BGA_angle_tmp[i] -= eps;

            tmp = evaluate(minute);

            BGA_angle_tmp[i] += eps;

            g[i+2] = (now - tmp)/eps;
        }

        //***********************************************
        // MINIMIZE DE CONSTANT OF THE GRADIENT

        double left = -500.0;
        double right = 500.0;

        for (int i=0; i<20; i++) {

            double leftThird = (2.0*left + right)/3.0;
            double rightThird = (left + 2*right)/3.0;

            for (int j=0; j<10; j++) {
                x[j] -= leftThird*g[j];
            }

            for (int i=0; i<2; i++) {
                SARJ_angle_tmp[i] = x[i];
            }
            for (int i=0; i<8; i++) {
                BGA_angle_tmp[i] = x[i+2];
            }

            double val_left = evaluate(minute);

            for (int j=0; j<10; j++) {
                x[j] += leftThird*g[j];
                x[j] -= rightThird*g[j];
            }

            for (int i=0; i<2; i++) {
                SARJ_angle_tmp[i] = x[i];
            }
            for (int i=0; i<8; i++) {
                BGA_angle_tmp[i] = x[i+2];
            }

            double val_right = evaluate(minute);

            if (val_left(leftThird) > val_right ) {
                left = leftThird;
            }
            else {
                right = rightThird;
            }

            for (int j=0; j<10; j++) {
                x[j] += rightThird*g[j];
            }
        }

        //**************************************************

        double mi = (left + right)/2;

        for (int j=0; j<10; j++) {
            x[j] -= mi*g[j];
        }

    }

    //*****************************

    for (int i=0; i<2; i++) {
        d[i] = x[2*i];
    }
    for (int i=0; i<8; i++) {
        d[i] = x[4+2*i];
    }
    //****************************

    //Once we have calculated the needed angles for the local
    //optimization of the power, calculate the angular velocity
    //


}

class ISS{

public:

    double getInitialOrientation (double _beta) {
        beta = _beta;

        solve();

        return yaw;
    };


    vector<double> getStateAtMinute (int minute) {
        vector<double> res;
//        for (int i=0; i<20; i++) {
//            res.push_back(parameters[minute][i]);
//        }
//        res = vector<double>(20,0);

        vector<double> d;
        if (minute == 0) {
            d = vector<double> (20,0);
        }
        else {
            for (int j=0; j<n; j++) {
                d[j] = parameters[minute-1][j];
            }
        }

        solve(minute, d) ;

        return res;
    };
};

int main() {

    //freopen("log.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin>>beta;
    ISS obj;

    cout<<0.0<<endl;
    cout.flush();

    //yaw = obj.getInitialOrientation (beta);

    solve();

    for (int i=0; i<92; i++) {
        //ret = obj.getStateAtMinute(i);
        cout<<1<<endl;
        cout.flush();
        for (int j=0; j<20; j++) {
            cout<<0<<endl;
            cout.flush();
        }
    }

    return 0;

}
