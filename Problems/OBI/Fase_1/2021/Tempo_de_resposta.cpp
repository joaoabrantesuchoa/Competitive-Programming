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

int n;
char tipo[25];
int valor[25];

pair<int,int> amigo_tempo_mensagens[102];
bool existe[102];

void aumentar_valores(int adicao) {
	for (int i = 1; i <= 100; i++) {
		if (existe[i] && amigo_tempo_mensagens[i].second != 0) {
			amigo_tempo_mensagens[i].first += adicao;
		}
	}
}

int main() {
        NeedForSpeed

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tipo[i] >> valor[i];
	}

	for (int i = 0; i < n; i++) {
		if (tipo[i] == 'R') {
			amigo_tempo_mensagens[valor[i]].second++;
			existe[valor[i]] = true;
		} else if (tipo[i] == 'E') {
			amigo_tempo_mensagens[valor[i]].second--;
		} else if (tipo[i] == 'T') {
			continue;
		}
		if (tipo[i + 1] == 'T') {
			aumentar_valores(valor[i + 1]);
		} else {
			aumentar_valores(1);
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (existe[i]) {
			if (amigo_tempo_mensagens[i].second == 0) {
				cout << i << " " << amigo_tempo_mensagens[i].first << "\n";
			} else {
				cout << i << " " << -1 << "\n";
			}
		}
	}

        return 0;
}