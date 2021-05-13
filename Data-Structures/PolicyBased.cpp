#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;

indexed_set s;

// Função para inserir o elemento "X"
s.insert(X);

// Função para remoção do elemento "X"
s.erase(X);

// Retorna um iterator para o elemento na posição "X" (0-based indexing)
s.find_by_order(X);

// Retorna a posição do elemento "X", uma outra função é contar a quantidade de elementos estritamente menores que "X"
s.order_of_key(X);


/*

Time Complexity

s.insert(X)         -> O(logn)
s.erase(X)          -> O(logn)
s.find_by_order(X)  -> O(logn)
s.order_of_key(X);  -> O(logn)

Observação: Quando o elemento não existe no indexed_set a função "order_of_key()" retorna a posição que ele DEVERIA ESTAR,
caso existisse, por isso é útil para calcular a quantidade de elementos estritamente menores que "X".

Links:

https://codeforces.com/blog/entry/11080
https://www.geeksforgeeks.org/policy-based-data-structures-g/

*/
