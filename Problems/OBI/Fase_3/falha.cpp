#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
vector<string> senhas;
string s;

bool substring(string s1, string s2) {
	int counter = 0; // pointing s2
    	int i = 0;
    for(;i<s1.length();i++)
    {
        if(counter==s2.length())
            break;
        if(s2[counter]==s1[i])
        {
            counter++;
        }
      else
        {
            if(counter > 0)
            {
                i -= counter;
            }
            counter = 0;
        }
    }
    return counter < s2.length()?false:true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		senhas.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (senhas[i].length() > senhas[j].length()) {
				if (substring(senhas[i], senhas[j])) ans++;
			} else if (senhas[i].length() < senhas[j].length()) {
				if (substring(senhas[j], senhas[i])) ans++;
			} else if (senhas[i].length() == senhas[j].length()) {
				if (substring(senhas[i], senhas[j])) ans++;
				if (substring(senhas[j], senhas[i])) ans++;
			}
		}
	}
	cout << ans << "\n";


	return 0;
}