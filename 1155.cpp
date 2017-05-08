//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155


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
         
    }
     
    int minus(int i){
        assert(i>=0 && i<=2);
        int ans[3] = {2,1,0};
        return ans[i];
    }
    int prod(int i,int j){
        int ans[3][3] = {{0,0,0},{0,1,1},{0,1,2}};
        return ans[i][j];
    }
    int plus(int i , int j ){
        int ans[3][3] = {{0,1,2},{1,1,2},{2,2,2}};
        return ans[i][j];
    }
     
     
    int interpret(string query, int p , int q, int r){
        //regex match ??????????????§?????????????????´???????????°?????\??????????????????
        if(query == "P") return p;
        if(query == "Q") return q;
        if(query == "R") return r;
        if(query == "1") return 1;
        if(query == "2") return 2;
        if(query == "0") return 0;
        if(query.at(0) == '-') return minus(interpret(query.substr(1),p,q,r));
         
         
        assert(query.at(0) == '(');
        int kcount = 1; //??¬??§?????\???????????????????????????????????????kcount = 1 ???????????????????????????????§£?????????????????????
         
        string formula1 = "", formula2 = "";
        int i = 1;
        while(kcount !=1 ||(query.at(i)!= '+' && query[i]!= '*')){
            formula1+=query.at(i);
            if(query.at(i) == '(') kcount++;
            if(query.at(i) == ')') kcount--;
            i++;
        }
        bool isplus = query.at(i) == '+';
        i++;
        while(i<query.size() -1){
            formula2+=query.at(i);
            i++;
        }
        if(isplus) return plus(interpret(formula1, p, q, r),interpret(formula2, p, q, r));
        else return( prod(interpret(formula1, p, q, r),interpret(formula2, p, q, r)));
    }
     
    void run(){
        while(true){
            string s; cin>>s;
            if(s == "." ) return;
            int p[27] = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
            int q[27] = {0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2};
            int r[27] = {0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};
            int sum = 0;
            for(int i = 0; i<27;i++){
                if(interpret(s,p[i],q[i],r[i])==2) sum++;
            }
            cout<<sum<<endl;
        }
         
    }
};
 
int main(){
    omajinai();
    Main().run();
}
