/*
실패

맞은 수에 따라 던지는 수가 달라지는데, 

생각해보면, 불린 값 배열을 키로 해서 같은 패턴이 나오는걸 감지하기가 귀찮은 일인데, 바로 이런 곳에 비트마스킹이 쓰일 수 있고, 그렇게 한다면 특정 패턴이 다시 나온 기준으로 합과 곱을 사용해서 답을 빠르게 구할 수 있을 것이다. 이론으로는 알겠는데 그래서 어떻게 구현?....

다음 패턴을 계산한 후, 그 패턴이 이미 있는지 조사해야 하는데,
패턴을 숫자 그대로 쓰면 숫자가 최대 20자리이므로 int범위를 초과한다.
그러면 패턴을 홀수인지 짝수인지만으로 바꾸어서 비트화한 후 그 수를 정수로 변환해서 검사를 해야 할 듯하다.

그리고 검사하고나서는 어떻게 하지? 현재까지 합 갖고 있다가, 주기 계산해서 더하되, 남은 부분에 대한 계산도 해야 한다.

1234라면
1010으로 변환.
수는 1,2,4,8
2+8=10이 된다.

*/

// NYAN NYAN
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
// ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
// ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
// ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
// ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
// ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
// ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
// ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░ 
// ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
// ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
// ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
// ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stack>
#include <random>
#include <queue>
#include <list>
#include <math.h>
#include <cstring>
#include <cstdio>
#include <iomanip> // std::setprecision
#include <cassert>
//#include <bits/stdc++.h>

using namespace std;
typedef long long ll1;
#define ll long long int
#define ld long double
//#define key pair<ld,ld>
#define ii pair<int, int>
#define iii pair<pair<int, int>, int>
//#define si set<int>
#define vii vector<pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvii(h, w, v) vvi(h, vi(w, v)); // initialize vvi
#define vs vector<string>
#define all(v) v.begin(), v.end()
#define pb emplace_back
//#define mp make_pair
#define fi first
#define se second
#define nu 100001
#define mod 998244353
#define mul(x, y) ((ll)(x) * (y)) % mod
#define tr(c, i) for (auto i = (c).begin(); i != (c).end(); i++)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(t, tmpv) \
    for (int tmpv = 0; tmpv < t; tmpv++)
#define rep1(t, tmpv) \
    for (int tmpv = 1; tmpv <= t; tmpv++)
#define reprange(s, e, tmpv) \
    for (int tmpv = s; tmpv < e; tmpv++)
#define writeLine(arg) cout << arg << '\n'
#define pairof(type) pair<type, type>
#define vit std::vector<int>::iterator
#define divby2 >> 1
#define mulby2 << 1
#define swapI(a, b) tmp = a; a = b; b = tmp;        
#define swapInline(a, b) \
    a ^= b;              \
    b ^= a;              \
    a ^= b;
#define isOdd(n) n & 1
#define it(msg) \
    if (Debug)  \
        cerr << msg << '\n';
#define pii pair<int, int>
#define piii pair<int, pair<int, int> >
using ds = ll;

//permanent constants
bool Debug = false;
//const double pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
//const ll INF = 1e18 + 239;
const ll prost = 239;
ll MOD = 998244353;
ll MOD2 = MOD * MOD;
int BIG = 987654321;
const int alf = 26;
const int dxd[4] = {-1, 0, 1, 0};
const int dyd[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digvec[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

void PrintString(string str){
    cout << str << '\n';
}
void print ( int x ) {
  printf("%d\n", x);
}
template<class T>
void PrintVector(vector<T>& t){
    for (int i = 0; i < t.size(); i++)
    {
        cout<< t[i] << ' ';
    }
    cout<<'\n';
}

// 수박 던지기 게임
// https://www.acmicpc.net/problem/2944

int n, h;
const int MAXN=22;

// deque<int> bits;

int fr[MAXN][MAXN];
// int ori[MAXN][MAXN];
int tmp[MAXN][MAXN];
int hit[MAXN];
int hit2[MAXN];

ll ans=0;
// void multiply(){
    
//     int i,j,k, q;
//     rep(bits.size(), q){
//         if(bits[q]==1){
//             rep(MAXN, i){
//                 rep(MAXN, j){
//                     rep(MAXN, k){
//                         tmp[i][k]+=fr[i][j]*fr[j][k];
//                     }
//                 }
//             }

//         }else{
//             rep(MAXN, i){
//                 rep(MAXN, j){
//                     rep(MAXN, k){
//                         tmp[i][k]+=fr[i][j]*ori[j][k];
//                     }
//                 }
//             }

//         }

//         rep(MAXN, i){
//             rep(MAXN, j){
//                 fr[i][j]=tmp[i][j];
//             }
//             ans+=fr[0][i];
//         }
//     }
// }

int start=0;
bool pat[1050000];

void solve(){
    cin>>n>>h;
    char cc;
    int i,j;
    // while(h>0){
    //     bits.emplace_front(h%2);
    //     h/=2;
    // }

    // rep(bits.size(), i){
    //     cout<< bits[i]<<endl;
    // }
    rep(n, i){
        rep(n ,j){
            cin>>cc;
            fr[i][j] = (cc=='1')? 1 : 0;
            // ori[i][j]=fr[i][j];
            // cout<<fr[i][j]<< ' ';
        }
        // cout<<endl;
    }

    rep(n, i){
        if(fr[i][0]==1) {
            hit[i]+=1;
            start++;
        }
    }

    // cout<<endl<<ans<<endl;
    int t=0;
    int pl=0;
    int left=0;
    bool found=false;
    rep(h-1, t){

        // string curpat="";
        int curp=0;
        rep(n, j){
            
            if(t%2==0){
                // curpat+=to_string(hit[j]%2);
                curp+=pow(2, (n-j-1))*(hit[j]%2);
                // cout<<curp<<endl;
            }else{
                
                // curpat+=to_string(hit2[j]%2);
                curp+=pow(2, (n-j-1))*(hit2[j]%2);
                // cout<<curp<<endl;
            }
            
        }
        if(found){
            left--;
        }
        if(found&& left<=0){
            break;
        }
        if(pat[curp] && !found){
            // cout<<left<< ' '<<ans<< ' '<<pl<<endl;
            left=(h-1)%pl;
            ans*=(h-1)/pl;
            found=true;
            // cout<<left<< ' '<<ans<< ' '<<pl<<' ' << (h-1)/pl<<endl;
        }
        pat[curp]=true;
        pl++;

        
        rep(n, i){
            rep(n, j){
                if(t%2==0)
                {
                    if(fr[i][j]==1){        
                        hit2[i]+=2 - (hit[j] % 2);
                    }
                } else {
                    if(fr[i][j]==1){        
                        hit[i]+=2 - (hit2[j] % 2);
                    }
                }
            }
        }

        // if(t%2==0)
        // {

        //     rep(n, i){
        //         cout<<hit2[i]<<' ';
        //     }
        //     cout<<endl;


        // } else {

        //     rep(n, i){
        //         cout<<hit[i]<<' ';
        //     }
        //     cout<<endl;
        // }
        rep(n, i){
            if(t%2==0)
            {      
                hit[i]=0;
                ans+=hit2[i];
            } else {
                hit2[i]=0;
                ans+=hit[i];
            }
        }

        // cout<<endl<<ans<<endl;
    }

    // multiply();

    // rep(n, i){
    //     rep(n, j){
    //         ans+=fr[i][j];
    //         cout<<fr[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    cout<<ans+start<<endl;

}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
