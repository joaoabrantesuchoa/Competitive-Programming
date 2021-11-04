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


int cartas_baralho[4][14];
string baralho;

int main() {
        NeedForSpeed

	cin >> baralho;

	string carta;
	int numeracao;
	for (int i = 0; i < baralho.size(); i++) {
		carta += baralho[i];
		if (carta.size() == 2) { 
			if (carta[0] == '0') {
				numeracao = carta[1] - '0';
			} else {
				numeracao = 10 + (carta[1] - '0');
			}
		} else if (carta.size() == 3) {
			if (carta[2] == 'C') {
				cartas_baralho[0][numeracao]++;
			} else if(carta[2] == 'E') {
				cartas_baralho[1][numeracao]++;
			} else if(carta[2] == 'U') {
				cartas_baralho[2][numeracao]++;
			} else if(carta[2] == 'P') {
				cartas_baralho[3][numeracao]++;
			}
			carta.clear();
		}
	}

	for (int i = 0; i < 4; i++) {
		int soma = 0;
		for (int j = 1; j <= 13; j++) {
			soma += cartas_baralho[i][j];
			if (cartas_baralho[i][j] > 1) {
				cout << "erro" << "\n";
				soma = -1;
				break;
			}
		}
		if (soma != -1) {
			cout << 13 - soma << "\n";
		}
	}

        return 0;
}