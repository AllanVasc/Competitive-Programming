class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l < r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[mid+1]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};

/*

Precisamos analisar 3 corner cases:

1º Temos todos os valores em ordem crescente. Logo temos um pico no indice n-1.
2º Temos todos os valores em ordem decrescente. Logo temos um pico no indice 0.
3º Temos um pico em algum lugar do array, como iremos achar?

Método baseado na Busca Binária:
    - Pegamos o elemento central do array, 
        - Se ele for maior do que o lado direito: Temos uma possível solução para a esquerda (com o mid inserido!)
        - Se não, ele é menor do que o lado direito, podemos excluir toda a parte esquerda, inclusive o mid
        - Quando l == r temos a nossa resposta

Time Complexity: O(log2 N)
Space Complexity: O(1)

*/