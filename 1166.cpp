//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166

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
     
    int N;
    vector<char> s;
    Main(){
         
    }
     
    void run(){
        while(true){
            int w,h; //w,h<=100
            cin>>w>>h;
            bool dataset_ends  = w == h && w == 0;
            if(dataset_ends) return;
            vector<vector<int> > v(h,vector<int>(w,0));
                /* v:?£??????¶????????¨?????????
                    ?????????????????? 1bit?????????????£???????????????????2bit??????????????? 3bit??? ??? , 4bit?????????
                 */
            const int MAX_ANS = 30*30;
            const int NO_ANS = MAX_ANS + 2;
            vector<vector<int> > ansvec(h,vector<int>(w,NO_ANS)); //0,0 ????????????????§?????????¢?????¨???
            for(int i = 0; i<h;i++){
                int kari;
                v[i][0]+=1; //??????????????????????£??????????
                v[i][w-1]+=1<<1; //????????????????£??????????
                for(int j = 1; j<= w-1;j++){
                    cin>>kari;
                    v[i][j-1]+=kari<<1 , v[i][j]+= kari;
                }
                if(i == h-1 ) break;
                for(int j = 0; j<w;j++){
                    cin>>kari;
                    v[i][j]+=  kari<<3;
                    v[i+1][j] += kari<<2;
                }
            }
            for_each(v[0].begin(),v[0].end() , [](int &i){ i+=1<<2;});
            for_each(v[h-1].begin(),v[h-1].end() , [](int &i){ i+=1<<3; });
                               
             
            queue<pair<int , int> > q;
            ansvec[0][0] = 1;
            q.push(make_pair(0,0));
            while(!q.empty()){
                pair<int,int> p = q.front(); q.pop();
                if(!(v[p.first][p.second]&1)){
                    if(ansvec[p.first][p.second-1] > ansvec[p.first][p.second] + 1){
                        ansvec[p.first][p.second-1] = ansvec[p.first][p.second] + 1;
                        q.push(make_pair(p.first, p.second-1));
                    };
                }
                if(!(v[p.first][p.second]&(1<<1))){
                    if(ansvec[p.first][p.second+1] > ansvec[p.first][p.second] + 1){
                        ansvec[p.first][p.second+1] = ansvec[p.first][p.second] + 1;
                        q.push(make_pair(p.first, p.second+1));
                    };
                }
                if(!(v[p.first][p.second]&(1<<2))){
                    if(ansvec[p.first-1][p.second] > ansvec[p.first][p.second] + 1){
                        ansvec[p.first-1][p.second] = ansvec[p.first][p.second] + 1;
                        q.push(make_pair(p.first - 1, p.second));
                    };
                }
                if(!(v[p.first][p.second]&1<<3)){
                    if(ansvec[p.first +1 ][p.second] > ansvec[p.first][p.second] + 1){
                        ansvec[p.first +1 ][p.second] = ansvec[p.first][p.second] + 1;
                        q.push(make_pair(p.first +1 , p.second));
                    };
                }
            }
            int ans = ansvec[h-1][w-1];
            if(ans == NO_ANS) ans = 0;
            cout<<ans<<endl;
        }
    }
};
 
int main(){
    omajinai();
    Main().run();
}
