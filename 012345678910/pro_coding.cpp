#include <bits/stdc++.h> 

#define NDEBUG
#define TERRORIST

#ifdef TERRORIST
using namespace std;
using pii = pair<int,int>;
using pil = pair<int,int64_t>;
using pli = pair<int64_t,int>;
using pll = pair<int64_t,int64_t>;
#define M_PI 3.14159265358979323846
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define emp_back emplace_back
#define bitcount(x) __builtin_popcount((x))
#define mbin(val, cap) bitset<64>(val).to_string().substr(64 - cap)
#ifdef NDEBUG
    #define print(x) cout << "[ " << #x << " ]: " << x << "\n";
    #define e_ cout << "\n";
#else
    #define print(x)
    #define e_
#endif

template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v);
template<typename F, typename S> ostream& operator<<(ostream &cout, pair<F, S> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template <typename K, typename V> ostream& operator<<(ostream& cout, const map<K, V>& omp) {
    for(auto& [k, v] : omp){ cout << "(" << k << ": " << v << ")"; if(&v != &omp.rbegin()->second) cout << ", ";} return cout;
}
template<typename T> ostream& operator<<(ostream& cout, const set<T>& ost){
    cout << "{"; for(auto& v : ost){ cout << v; if(v != *ost.rbegin()) cout << ", "; } cout << "}"; return cout;
}
template<typename T, typename Cmp = less<T>>
optional<vector<T>> get_unique(vector<T>& who, bool in_place = true, Cmp compare = Cmp()){
    if(in_place){ sort(all(who), compare); who.erase(unique(all(who)), who.end()); return nullopt;}
    vector<T> ret = who; sort(all(ret), compare); ret.erase(unique(all(ret)), ret.end()); return ret;
}
mt19937_64 _GEN(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
T mrand(T begin, T end) {
    if constexpr (is_integral<T>::value){ uniform_int_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); } 
    else if constexpr (is_floating_point<T>::value) { uniform_real_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); }
}
int fastIO = []{ ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }();
//down0, right1, up2, left3, upleft4, downright5, upright6, downleft7, stay8
constexpr int dx[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
constexpr int dy[9] = {1, 0, -1, 0, -1, 1, -1, 1, 0};
#endif

template <uint64_t mod = 1'000'000'007>
struct Mint {
    uint64_t val;
    Mint() : val(0) {}
    Mint(int64_t _val) {
        _val %= mod;
        if (_val < 0) _val += mod;
        val = _val;
    }
    Mint& operator += (const Mint& other){ val += other.val; if(val >= mod) val -= mod; return *this; }
    Mint& operator -= (const Mint& other){ val += mod - other.val; if(val >= mod) val -= mod; return *this; }
    Mint& operator *= (const Mint& other){ val = (uint64_t)val * other.val % mod; return *this; }
    Mint& operator /= (const Mint& other){ return *this *= other.inv(); }
    Mint operator + (const Mint& other) const { return Mint(*this) += other; }
    Mint operator - (const Mint& other) const { return Mint(*this) -= other; }
    Mint operator * (const Mint& other) const { return Mint(*this) *= other; }
    Mint operator / (const Mint& other) const { return Mint(*this) /= other; }
    Mint pwr(int64_t expo) const {
        Mint res = 1;
        Mint cur = *this;
        while(expo){
            if(expo & 1) res *= cur;
            cur *= cur; expo >>= 1;
        }
        return res;
    }
    Mint inv() const { return pwr(mod - 2); }
    friend ostream& operator << (ostream& os, const Mint& m) { os << m.val; return os; }
    bool operator == (const Mint& other) const { return val == other.val; }
};

const uint64_t MOD = 1'000'000'007; // 8191 // 1e9 + 7 //1'000'000'000'039
using mint = Mint<MOD>;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int nax = 1'000'01;
int mdata[nax][3];

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto dfs = [&](TreeNode* cur, int lvl, int dad, int dir, auto&& dfs) -> void {
            if(!cur) return;
            if(dad != -1){
                auto& now = mdata[cur->val];
                now[0] = dad;
                now[1] = lvl;
                now[2] = dir;
            }
            dfs(cur->left, lvl + 1, cur->val, 0, dfs);
            dfs(cur->right, lvl + 1, cur->val, 1, dfs);
        };
        dfs(root, 0, -1, -1, dfs);
        mdata[root->val][1] = 0;

        int u = startValue;
        int du = mdata[u][1];
        int v = destValue;
        int dv = mdata[v][1];
        string ans1;
        string ans2;
        while(du > dv){
            ans1.push_back('U');
            du--;
            u = mdata[u][0];
        }
        while(dv > du){
            ans2.push_back((!mdata[v][2]) ? 'L' : 'R');
            dv--;
            v = mdata[v][0];
        }
        while(u != v){
            ans1.push_back('U');
            ans2.push_back((!mdata[v][2]) ? 'L' : 'R');
            u = mdata[u][0];
            v = mdata[v][0];
        }

        reverse(all(ans2));
        return ans1 + ans2;
    }
};

struct Timer {
    chrono::_V2::system_clock::time_point start, end;
    chrono::duration<float> duration;
    Timer(){ start = chrono::high_resolution_clock::now(); }
    ~Timer(){
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time taken: " << duration.count() * 1000.0f << " ms\n"; 
    }
};

// #define MAIN_ACTIVE
#ifdef MAIN_ACTIVE
int main() {

    ifstream in("input.txt");
    ofstream out("output.txt", ios::trunc);
    out.close();
    out.open("output.txt", ios::app);
    Timer timer;
    
    return EXIT_SUCCESS;
}
#endif   
