#include <bits/stdc++.h>

using namespace std;

const long long naoEncontrado = 1e9 + 7;

typedef long long ll;

ll l,n;
map<string, ll> valores;

int main() {
	cin >> l >> n;

	string letras[l][n];
	ll numeros[l][n];
	ll soma_linhas[l];
	ll soma_colunas[n];

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			cin >> letras[i][j];
			numeros[i][j] = naoEncontrado;
			if (valores.count(letras[i][j]) == 0) {
				valores.insert({letras[i][j], naoEncontrado});
			}
		}
		cin >> soma_linhas[i];
	}

	for (int i = 0; i < n; i++) cin >> soma_colunas[i];

	while(true) {
		bool atualizacao = false;
		for (int L = 0; L < l; L++) {
			ll qtd_letras_diferentes = 0;
			ll qtd_letras_iguais = 0;
			string arrayTemporaria[l];
			for (int i = 0; i < n; i++) {
				arrayTemporaria[i] = letras[i][L];
			}
			sort(arrayTemporaria, arrayTemporaria + n);
			string encontrada = "";
			for (int i = 1; i < l - 1; i++) {
				if (arrayTemporaria[i] != arrayTemporaria[i - 1]) qtd_letras_diferentes++;
				if (arrayTemporaria[i] != "z") encontrada = arrayTemporaria[i];
				if (arrayTemporaria[i] == arrayTemporaria[i - 1]) qtd_letras_iguais++;
			}

			if (qtd_letras_diferentes == 1) atualizacao = true;
			

			if (atualizacao) {
				ll soma_numeros = 0;
				for (int i = 0; i < n; i++) {
					if (numeros[L][i] != naoEncontrado) soma_numeros += numeros[L][i];
				}
				ll valor_encontrado = (soma_linhas[L] - soma_numeros) / qtd_letras_diferentes;
				valores[encontrada] = valor_encontrado;

				for (int i = 0; i < l; i++) {
					for (int j = 0; j < n; j++) {
						if (letras[i][j] == encontrada) numeros[i][j] = valor_encontrado;
					}
				}
			}


		}

		//Colunas;
		for (int C = 0; C < n; C++) {
			ll qtd_letras_diferentes = 0;
			string arrayTemporaria[l];
			for (int i = 0; i < l; i++) {
				arrayTemporaria[i] = letras[i][C];
			}
			sort(arrayTemporaria, arrayTemporaria + l);

			for (int i = 1; i < l - 1; i++) {
				if (arrayTemporaria[i] != arrayTemporaria[i - 1]) qtd_letras_diferentes++;
			}
			string encontrada = "";
			if (qtd_letras_diferentes == 1) atualizacao = true;
				if (atualizacao) {
				ll soma_numeros = 0;
				for (int i = 0; i < n; i++) {
					if (numeros[C][i] != naoEncontrado) soma_numeros += numeros[C][i];
				}
				ll valor_encontrado = (soma_linhas[C] - soma_numeros) / qtd_letras_diferentes;
				valores[encontrada] = valor_encontrado;

				for (int i = 0; i < l; i++) {
					for (int j = 0; j < n; j++) {
						if (letras[i][j] == encontrada) numeros[i][j] = valor_encontrado;
					}
				}
			}
		}
		if (atualizacao == false) break;
	}

		for(auto elem : valores) {
 		  cout << elem.first << " " << elem.second << "\n";
		}
	return 0;
}