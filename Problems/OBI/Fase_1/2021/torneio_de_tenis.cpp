#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef priority_queue<pii, vector<pii>, greater<pii>> priority_queue_easy;
typedef priority_queue<iii, vector<iii>, greater<iii>> priority_queue_grids;
typedef vector<vii> graph_dj;


#define preencher_negativo(memo) memset(memo, -1, sizeof memo) 
#define preencher_zero(arr) memset(arr, 0, sizeof arr)
#define sz(x) (int)x.size()
#define nl '\n'
#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define arredondar_para_cima(d) (int)((double)d + 0.5)
#define all(a) a.begin(), a.end()
#define EdgeList vector<pair<int,ii>>

char resultado;
int vitorias,derrotas;

int main() {
        NeedForSpeed

	for (int i = 0; i < 6; i++) {
		cin >> resultado;

		if (resultado == 'V') vitorias++;
		if (resultado == 'P') derrotas++;
	}

	if (vitorias == 5 || vitorias == 6) {
		cout << 1 << "\n";
	} else if (vitorias == 3 || vitorias == 4) {
		cout << 2 << "\n";
	} else if (vitorias == 1 || vitorias == 2) {
		cout << 3 << "\n";
	} else {
		cout << -1 << "\n";
	}

        return 0;
}