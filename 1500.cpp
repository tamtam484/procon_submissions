//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1500

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
    string id;
    int m;
    vector<int> a;
    const int even_score[10] = {0,2,4,6,8,1,3,5,7,9};
    Main(){
        cin>>n>>id>>m;
        a = vector<int>(m);
        REP(i,m) cin>>a[i];
        
    }
    
    int factorial(int n){
        return n ? n* factorial(n-1):1;
    }
    
    void run(){
        vector<int> v;
        vector<bool> is_nth_ast_odd;
        REP(i,id.size()){
            char c = id.at(i);
            if(c== '*') v.push_back(0),is_nth_ast_odd.push_back(((id.size() - i)%2)); else v.push_back(c - '0');
        }
        
        int ast_length = (int)is_nth_ast_odd.size();
        int now_point = 0;
        REP(i,v.size()){
            now_point+= (v.size() - i )%2 ? v[i] : even_score[v[i]];
        }
        vector<int> dp(10,0);
        dp[now_point%10]++;
        REP(i,ast_length){
            vector<int> nextdp(10,0);
            for(int j :a) REP(k,10){
                int ncursor = (k + (is_nth_ast_odd[i]?j:even_score[j]))%10;
                nextdp[ncursor]+= dp[k];
            }
            dp = nextdp;
        }
        cout<<dp[0]<<endl;
    }
};

int main(){
    omajinai();
    Main().run();
}

