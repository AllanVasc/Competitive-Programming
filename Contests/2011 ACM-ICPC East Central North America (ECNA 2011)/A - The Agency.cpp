#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct BIT{
    vector<int> bit;
    int n;
    BIT(int n) : n(n){
        bit.assign(n + 1, 0);
    }
    void update(int idx, int add){
        for(++idx; idx < n; idx += idx & -idx) bit[idx] += add;
    }
    int pref(int idx){
        int answ = 0;
        for(++idx; idx > 0; idx -= idx & -idx) answ += bit[idx];
        return answ;
    }
    int range_query(int l, int r){
        if(l == 0) return pref(r);
        return pref(r) - pref(l - 1);
    }
};

const int maxCost = 1e6 + 10;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    int cnt = 1;
    while(cin >> n){
        if(n == 0) break;

        string start, end;
        cin >> start >> end;

        vector<int> costs(n);
        for(int i = 0; i < n; i++) cin >> costs[i];

        BIT conj0to1(maxCost), conj1to0(maxCost),
            sum0to1(maxCost), sum1to0(maxCost);

        int hamDist = 0;
        int sumOnesUp = 0;
        int curr_answ = 0;
        int answ = INF;
        vector<int> cost1to0, cost0to1, cost1keep1;
        
        // Dividindo nos 3 conjuntos
        for(int i = 0; i < n; i++){
            if(start[i] != end[i]){
                hamDist++;
                if(start[i] == '1'){    // 1 -> 0
                    conj1to0.update(costs[i], 1);
                    sum1to0.update(costs[i], costs[i]);
                    cost1to0.push_back(costs[i]);
                }
                else{
                    // 0 -> 1
                    conj0to1.update(costs[i], 1);
                    sum0to1.update(costs[i], costs[i]);
                    cost0to1.push_back(costs[i]);
                }
            }
            else if(start[i] == '1' && end[i] == '1'){
                // posso dropar e dps levantar
                sumOnesUp += costs[i];
                cost1keep1.push_back(costs[i]);
            }
        }

        sort(cost1to0.begin(), cost1to0.end(), greater<int>());
        sort(cost0to1.begin(), cost0to1.end());
        sort(cost1keep1.begin(), cost1keep1.end(), greater<int>());

        // Calculo da primeira resposta
        curr_answ = 0;
        // 1 -> 0
        for(int i = 0; i < cost1to0.size(); i++){
            curr_answ += i * cost1to0[i];
        }
        // 0 -> 1
        for(int i = 0; i < cost0to1.size(); i++){
            int qtd = cost0to1.size();
            curr_answ += (qtd - i) * cost0to1[i];
        }
        // 1 keep 1
        for(int i = 0; i < cost1keep1.size(); i++){
            curr_answ += hamDist * cost1keep1[i];
        }

        answ = min(answ, curr_answ);
        // cout << "first answer = " << answ << '\n';

        // Vou analisar agora as novas respostas: 1 -> 0 e dps 0 -> 1
        for(int i = 0; i < cost1keep1.size(); i++){
            int val = cost1keep1[i];
            int delta = 0;

            // Tiro a contrib de val dos "1 keep 1"
            delta -= val * hamDist;
            
            // 1 -> 0
            int qtdMaiores1to0 = conj1to0.range_query(0, maxCost - 1) - conj1to0.range_query(0, val);
            delta += val * qtdMaiores1to0;

            // somo todo mundo que é menor que eu pois vao esperar mais uma rodada
            delta += sum1to0.range_query(0, val);
            
            // 0 -> 1
            int qtdMaiores0to1 = conj0to1.range_query(0, maxCost - 1) - conj0to1.range_query(0, val) + 1;
            delta += val * qtdMaiores0to1;

            // Somo todo mundo que é menor do que eu no conjunto 0 -> 1 pois vao aparecer por mais uma rodada
            delta += sum0to1.range_query(0, val);

            // Contribuição dos que permanecem levantados
            delta += 2 * (sumOnesUp - val);

            // atualizando os valores
            hamDist += 2;
            // cout << val << ": delta = " << delta << " answ = " << answ << '\n';
            curr_answ = curr_answ + delta;
            answ = min(answ, curr_answ);
            sumOnesUp -= val;
            
            sum1to0.update(val, val);
            sum0to1.update(val, val);
            conj1to0.update(val, 1);
            conj0to1.update(val, 1);
            
        }

        cout << "Case " << cnt++ << ": " << answ << '\n';
    }
    return 0;
}