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


struct Node {
	Node * links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}
	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};


void solution() {

        int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie T;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			T.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (T.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (T.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}


int main() {
        fastIO();
        // file() ;
        ll _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}
