#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
	setlocale(0, "");
	int n;
	cin >> n;
	vector <vector <int> > G(n + 1);
	vector <int> v;
	int a, b;

	for (int i = 0; i < n; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		bool B = true;
		bool A = true;
		for (int j = 0; j < v.size(); j++){
			if (v[j] == a) A = false;
			if (v[j] == b) B = false;
		}
		if (B) v.push_back(b);
		if (A) v.push_back(a);
	}
	bool g = true;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++){
			bool s = false;
			if (i != j){
				for (int k = 0; k < G[v[i]].size(); k++){
                    if (G[v[i]][k] == v[j])
                        s = true;
                    break;
				}
				if (!s)
                    if (G[v[i]].size() + G[v[j]].size() < v.size())
                        g = false;
			}
		}
	if (!g) cout << "Нет решений\n" << endl;
	else{
		vector <int> gam = v;
		gam.push_back(v[0]);
		for (int i = 0; i < gam.size(); i++)
			for (int j = 0; j < gam.size(); j++){
				bool s = false;
				if (i != j){
					for (int k = 0; k < G[gam[i]].size(); k++){
						if (G[gam[i]][k] == gam[j])
                            s = true;
                            break;
					}
					if (!s){
						if ((i - j == 1) || (j - i == 1)){
							if (i - j == 1)
								i = i + j - (j = i);
							for (int k = 0; k < gam.size(); k++){
								if (k != i){
									for (int p = 0; p < G[gam[i]].size(); p++){
										if ((G[gam[i]][p] == gam[k]) && (G[gam[i + 1]][p] == gam[k + 1])){
											vector <int> g;
											if (i + 1 > k)
												i = i + k - (k = (i + 1));
											for (int x = i + 1; x < k + 1; x++)
                                                g.push_back(gam[x]);
											for (int y = i + 1; y < k + 1; y++)
												gam[y] = g[g.size() + i - y];
										}
									}
								}
							}
						}
					}
				}
			}
		cout << "Гамильтонов цикл:\n";
		for (int m = 0; m < gam.size() - 1; m++)
			cout << gam[m] << " ";
		cout << gam[gam.size() - 1] << endl;
	}
	system("pause");
	return 0;
}
