#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
class multi_indexed_set{

    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
	    tree_order_statistics_node_update> miset;
    unordered_map<T, int> freq;

    public:
	void insert(T x){
	    freq[x]++;
	    miset.insert({x, freq[x]});
	}
	void erase(T x){
	    if(!freq[x]) return;
	    miset.erase({x, freq[x]});
	    freq[x]--;
	}
	int order_of_key(T x){ return miset.order_of_key({x, 0}); }
	int count(T x) { return freq[x]; }
	int size(){ return miset.size(); }

};

multi_indexed_set<int> ms;

// Função para inserir o elemento "X"
ms.insert(X);

// Função para remoção do elemento "X"
ms.erase(X);

// Retorna a posição do elemento "X", uma outra função é contar a quantidade de elementos estritamente menores que "X"
ms.order_of_key(X);

// Retorna a quantidade de elementos iguais a "X"
ms.count(X);

// Retorna a quantidade de elementos no multiset
ms.size();

/*

Time Complexity

ms.insert(X)        -> O(logn)
ms.erase(X)         -> O(logn)
ms.order_of_key(X); -> O(logn)
ms.count(X)         -> O(1) (Average)
ms.size()           -> ??

Observação: Ainda é possivel a implementação da função "find_by_order".

*/