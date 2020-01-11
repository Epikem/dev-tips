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
void printString(string str){
    cout << str << '\n';
}

using namespace std;

// https://www.acmicpc.net/problem/1269

struct node{
  node* left;
  node* right;
  char value;
};

void preorder(node* n){
  if(n->value=='.') return;
  cout<<n->value;
  preorder(n->left);
  preorder(n->right);
}

void inorder(node* n){
  if(n->value=='.') return;
  inorder(n->left);
  cout<<n->value;
  inorder(n->right);
}

void postorder(node* n){
  if(n->value=='.') return;
  postorder(n->left);
  postorder(n->right);
  cout<<n->value;
}


void solve(){
  int n;cin>>n;
  int t;
  char a,b,c;
  // std::set<char> names;
  node* root=new node();
  root->value='A';
  root->left=NULL;
  root->right=NULL;
  map<char,node*> nodes;
  nodes.insert({'A', root});

  rep(n, t){
    cin>>a>>b>>c;
    // cout<<"start\n";
    // cout << a << ' '<< b << ' ' << c << '\n';
    node* cur=nodes.at(a);
    //node* cur2=nodes.find(a);
    // cout << cur->value << endl;
    // if(b!='.'){
      node* leftchild = new node();
      leftchild->left=NULL;
      leftchild->right=NULL;
      nodes.insert({b, leftchild});
      leftchild->value=b;
      cur->left=leftchild;
    // }
    // if(c!='.'){
      node* rightchild = new node();
      rightchild->left=NULL;
      rightchild->right=NULL;
      nodes.insert({c, rightchild});
      rightchild->value=c;
      cur->right=rightchild;
    // }
    // cout<<"printing all\n";
    // for(int i=0;i<nodes.size();i++){
    //   // cout << nodes.at((i+'A')) << endl;
    //   cout << nodes.find(i+'A')->second->value << endl;
    // }
    // cout<<"end\n";
  }

  preorder(root);
  cout<<endl;
  inorder(root);
  cout<<endl;
  postorder(root);

}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // //https://stackoverflow.com/questions/5183203/checking-argv-against-a-string-c
  // std::vector<std::string> args(argv, argv+argc);

  solve();
  return 0;
}