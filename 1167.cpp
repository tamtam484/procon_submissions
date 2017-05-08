//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167


#define _USE_MATH_DEFINES
#include <sstream> //string stream its useful!
#include<string>
#include<iostream>
#include<utility> //pair
#include <vector> // vector
#include <algorithm>    // swap,sort,binary_search
#include <functional>   // std::greater
#include <map> //map
#include<set> //set
#include<queue> //queue
#include<list> //list
#include<cmath>
#include<numeric>
#include<cassert>
#include <iomanip> //cout<<setprecision
#include <regex>
 
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
ll W = 1000000007;
 
 
using namespace std;
void omajinai() {
     
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(15);
    //freopen("txt.csv","r",stdin);
}
 
class Main{
public:
    vector<int> dp;
    vector<int> dpo;
    long pollock(int n){
        return n * (n+1) * (n+2)/6;
        //pollock(1000) > 10^6
    }
     
    Main(){
        dp = vector<int>(1000000,1000000);
        dpo= vector<int>(1000000,1000000);
        dp[0] = 0; dpo[0] = 0;
        for(long i = 1; i <= 1000000;i++){
            for(int j = 1; j<1000;j++){
                long p = pollock(j);
                if(p>i) break;
                dp[i] = min(dp[i],dp[i - p] + 1);
                if(p%2) dpo[i] = min(dpo[i],dpo[i-p] + 1);
            }
        }
    }
     
    void run(){
        long n;
        while(true){
            cin>>n;
            if(n==0) return;
            cout<<dp[n]<<" "<<dpo[n]<<endl;
        }
    }
};
 
int main(){
    omajinai();
    Main().run();
}
