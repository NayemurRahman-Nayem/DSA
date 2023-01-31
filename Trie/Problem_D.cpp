//      BISMILLAH-IR-RAHMAN-IR-RAHIM


#include <bits/stdc++.h>
#include<unordered_map>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<ll> vl ;
typedef vector<vl> vvl ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define el << '\n'
#define pb push_bachk
#define PI 3.14159265358979323
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
ll bin_expo(ll base, ll pow, ll m ){
        if (pow == 0) return 1 ;
        ll ret = bin_expo(base, pow / 2, m) % m ;
        if (pow & 1)return (ret % m * ret % m * base % m) % m ;
        else return (ret % m * ret % m) % m;
}
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
ll dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1000000000000000002 ;
const ll mod2 = 1e9 + 9 ;
const ll mx = 1e6 + 123 ;
const double eps = 1e-7 ;

// forever-striver

struct Node
{
        Node *links[26];
        int cntEndWith = 0;
        int cntPrefix = 0;
        bool containsKey(char ch)
        {
                return (links[ch - 'a'] != NULL);
        }
        Node *get(char ch)
        {
                return links[ch - 'a'];
        }
        void put(char ch, Node *node)
        {
                links[ch - 'a'] = node;
        }
        void increaseEnd()
        {
                cntEndWith++;
        }
        void increasePrefix()
        {
                cntPrefix++;
        }
        void deleteEnd()
        {
                cntEndWith--;
        }
        void reducePrefix()
        {
                cntPrefix--;
        }
        int getEnd()
        {
                return cntEndWith;
        }
        int getPrefix()
        {
                return cntPrefix;
        }
};

class Trie
{
private:
        Node *root;

public:
        /** Initialize your data structure here. */
        Trie()
        {
                root = new Node();
        }
        /** Inserts a word into the trie. */
        void insert(string word)
        {
                Node *node = root;
                for (int i = 0; i < word.length(); i++)
                {
                        if (!node->containsKey(word[i]))
                        {
                                node->put(word[i], new Node());
                        }
                        node = node->get(word[i]);
                        node->increasePrefix();
                }
                node->increaseEnd();
        }
        int countWordsEqualTo(string &word)
        {
                Node *node = root;
                for (int i = 0; i < word.length(); i++)
                {
                        if (node->containsKey(word[i]))
                        {
                                node = node->get(word[i]);
                        }
                        else
                        {
                                return 0;
                        }
                }
                return node->getEnd();
        }
        int countWordsStartingWith(string &word)
        {
                Node *node = root;
                for (int i = 0; i < word.length(); i++)
                {
                        if (node->containsKey(word[i]))
                        {
                                node = node->get(word[i]);
                        }
                        else
                        {
                                return 0;
                        }
                }
                return node->getPrefix();
        }
        void erase(string &word)
        {
                Node *node = root;
                for (int i = 0; i < word.length(); i++)
                {
                        if (node->containsKey(word[i]))
                        {
                                node = node->get(word[i]);
                                node->reducePrefix();
                        }
                        else
                        {
                                return;
                        }
                }
                node->deleteEnd();
        }
};

void solution()
{

        Trie T;
        T.insert("apple");
        T.insert("apple");
        T.insert("apps");
        T.insert("apps");
        string word1 = "apps";
        cout << "Count Words Equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
        string word2 = "abc";
        cout << "Count Words Equal to " << word2 << " " << T.countWordsEqualTo(word2) << endl;
        string word3 = "ap";
        cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3)
             << endl;
        string word4 = "appl";
        cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4)
             << endl;
        T.erase(word1);
        cout << "Count Words equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
}

int main()
{
        fastIO();
        // file() ;
        ll _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}
