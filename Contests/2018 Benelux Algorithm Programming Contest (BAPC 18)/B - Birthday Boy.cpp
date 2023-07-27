#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> dates;
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(28, 0));
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(30, 0));
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(30, 0));
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(30, 0));
    dates.push_back(vector<int>(31, 0));
    dates.push_back(vector<int>(30, 0));
    dates.push_back(vector<int>(31, 0));
    pair<int, int> last {0, 0};
    for(int i = 0; i < n; i++){
        string name; cin >> name;
        string dat; cin >> dat;
        // cout << dat << '\n';
        int mes = (dat[0] - '0') * 10 + (dat[1] - '0');
        int day = (dat[3] - '0') * 10 + (dat[4] - '0');
        // cout << "mes = " << mes << '\n';
        // cout << "day = " << day << '\n';
        mes--;
        day--;
        pair<int,int> aux = {mes, day};
        if(aux > last){
            last = aux;
        }
        dates[mes][day]++;
    }
    // for(int i = 0; i < 12; i++){
    //     cout << "mes = " << i + 1 << ": ";
    //     for(int j = 0; j < dates[i].size(); j++){
    //         cout << dates[i][j] << " "; 
    //     }
    //     cout << '\n';
    // }

    int answ = 0;
    int distAnsw = 500;
    int cnt = 0;
    pair<int,int> birth = {0, 0};
    int total = 0;
    int reference = 300; // precisa calcular
    int offset = 65;

    for(int i = 0; i < dates.size(); i++){
        for(int j = 0; j < dates[i].size(); j++){
            total++;
            if(dates[i][j]){
                // cout << "deu merda, cnt era " << cnt << '\n';
                cnt = 0;
            }
            else{
                cnt++;
                if(cnt >= answ){
                    if(cnt == answ){
                        // preciso botar mais perto do 27 october
                        int currDist = 0;
                        if(total <= reference){
                            currDist = offset + total;
                        }
                        else{
                            currDist = total - reference;
                        }
                        if(distAnsw > currDist){
                            // tem prioridade
                            distAnsw = currDist;
                            answ = cnt;
                            birth = {i, j};
                        }
                    }
                    else{
                        // eh maior a sequencia
                        int currDist = 0;
                        if(total <= reference){
                            currDist = offset + total;
                        }
                        else{
                            currDist = total - reference;
                        }
                        distAnsw = currDist;
                        answ = cnt;
                        birth = {i, j};
                    }
                }
            }
        }
    }
    // cout << "ate agora " << '\n';
    // cout << birth.first + 1 << " " << birth.second + 1 << '\n';
    // cout << "dist = " << distAnsw << '\n';
    // cout << "answ = " << answ << '\n';
    // preciso verificar o overlap do ultimo 
    total = 0;
    cnt = 0;
    // cout << "last = " << last.first << " " << last.second << '\n';
    for(int i = last.first; i < dates.size(); i++){
        // cout << "i = " << i << '\n';
        for(int j = (i == last.first ? last.second + 1 : 0); j < dates[i].size(); j++){
            // cout << " j = " << j << '\n';
            cnt++;
        }
    }
    // agora volto do inicio ate o primeiro conflito
    bool found = false;
    total = 0;
    // cout << cnt << '\n';
    for(int i = 0; i < dates.size() && !found; i++){
        for(int j = 0; j < dates[i].size() && !found; j++){
            total++;
            if(dates[i][j]){
                // achei o primeiro
                found = true;
            }
            else{
                cnt++;
                // cout << cnt << '\n';
                if(cnt >= answ){
                    // cout << "cnt = " << cnt << '\n';
                    if(cnt == answ){
                        // preciso botar mais perto do 27 october
                        // cout << "to em " << i << " " << j << '\n';
                        int currDist = 0;
                        if(total <= reference){
                            currDist = offset + total;
                        }
                        else{
                            currDist = total - reference;
                        }
                        if(distAnsw > currDist){
                            // tem prioridade
                            distAnsw = currDist;
                            answ = cnt;
                            birth = {i, j};
                        }
                    }
                    else{
                        // eh maior a sequencia
                        int currDist = 0;
                        if(total <= reference){
                            currDist = offset + total;
                        }
                        else{
                            currDist = total - reference;
                        }
                        distAnsw = currDist;
                        answ = cnt;
                        birth = {i, j};
                    }
                }
            }
        }
    }
    if(birth.first >= 9){
        cout << birth.first + 1 << "-";
    }
    else{
        cout << 0 << birth.first + 1 << "-";
    }
    if(birth.second >= 9){
        cout << birth.second + 1 << '\n';
    }
    else{
        cout << 0 << birth.second + 1 << '\n';
    }
    return 0;
}