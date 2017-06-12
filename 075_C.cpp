//http://arc075.contest.atcoder.jp/tasks/arc075_a



/** 
 *@file Main.c++
 *プロコンの回答兼ねてきれいめコードの練習
 *@brief  class coding_ans::Ans 標準入力からテストケースを受け取ってansで回答を返すclass 
 *@name tamtam484
 * main() メイン
 **
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<utility>
#include<numeric>
#include<stdexcept>

namespace coding_ans {
    typedef long long ll; //namespaceのなかなら大丈夫だ。
    class Ans{
        int _N;
        std::multiset<ll> _s;
        
    public:
        static const Ans Constructforcin(){
            /**
             *@brief 標準入力から問題を受け取る。
            **/
            int N;
            std::cin>>N;
            std::multiset<ll> s;
            for(int i = 0 ; i<N;i++){
                int kari;
                std::cin>>kari;
                s.insert(kari);
            }
            return Ans(N,s);
        }
        
        Ans(const Ans &a):_N(a._N) , _s(a._s){}
            /**
             *@brief コピーコンストラクタ
            **/
        
        Ans& operator=(const Ans &a){
            /**
             *@brief コピー代入演算子
            **/
            //FIXME ポインタで管理されてるものはこれでdeep copyにできるからあり難い???
            //FIXME 多分デフォルトコンストラクタもこの例ではdeep copyのはず。
            Ans a2(a);
            std::swap(*this,a2);
            return *this;
        }
        
    private:
        Ans(const int N,const std::multiset<ll> s): _N(N), _s(s){}
        /**
         *@brief デフォルトコンストラクタ
         **/
        
        
    private:
        const ll getans() const{
            /** 
             *@brief 答えを得る
             *@detail 
                合計が10で割り切れなければそれが答え。そうでなければ10で割り切れない一番小さなものをけす。 全部10で割れるなら , 0を返す。
             **/
             
            const ll MAXANS = std::accumulate(this->_s.begin(), this->_s.end(),0LL);
            
            if(MAXANS % 10){
                return MAXANS;
            }else{
                const std::multiset<ll>::iterator i = std::find_if(this->_s.begin(), this->_s.end() ,
                                                                   [](int a){return (a%=10);});
                
                return (i!=this->_s.end()) ? MAXANS - *i : 0;
            }
        }
    public:
        void solve() const{
            /**
             *@brief 出力
             **/
            std::cout<<this->getans()<<std::endl;
        }
    };
}

int main(){
    coding_ans::Ans::Constructforcin().solve();
    return 0;
}
