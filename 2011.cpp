//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2011

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
    int n;
    vector<int> uf;
    vector<int> sum;
    vector<ll> schedule;
     
    Main(){
        cin>>n;
        if(n == 0) exit(0);
        schedule = vector<ll>(n,0);
        for(int i = 0; i<n; i++){
            int fi;
            cin>>fi;
            for(int j = 0 ; j<fi ; j++){
                int x; cin>>x;  //????????????????????±?????\??????
                schedule[i] += 1<<x;
            }
        }
        uf = vector<int>(n);
        sum = vector<int>(n);
    }
     
    void uf_init(){
        for(int i = 0; i<n;i++) uf[i] = i;
        for(int i = 0;i<n;i++) sum[i] = 1;
    }
     
     
    int find(int i){
        if(uf[i]!=i) uf[i] = find(uf[i]);
        return uf[i];
    }
     
    void unite(int i , int j){
        int s = find(i), t = find(j);
        if (s == t) return;
        uf[max(s,t)] = min(s,t);
        sum[min(s,t)] += sum[max(s,t)];
    }
     
    void run(){
        vector<int> ans(n);
        for(int center = 0;center<n;center++){
            ans[center] = 31;
            for(int i = 30; i>0;i--){
                uf_init();
                for(int j = i;j>0;j--){
                    bool canunite = false;
                    for(int k = 0; k<n;k++){
                        canunite |= schedule[k] & 1<<j && find(k) == find(center);
                    }
                    if(canunite){
                        for(int k = 0; k<n;k++){
                            if(schedule[k] & 1<<j) unite(center,k);
                        }
                    }
                }
                if(sum[find(center)]== n) ans[center] = i; else break;
            }
        }
        int answer = *min_element(ans.begin(),ans.end());
        if(answer == 31) answer = -1;
        cout<<answer<<endl;
    }
};
 
int main(){
    omajinai();
    while(true)
        Main().run();
}
