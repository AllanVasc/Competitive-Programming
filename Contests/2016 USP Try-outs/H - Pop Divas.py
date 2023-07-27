
def main():
    aux = input()

    n, m = aux.split()

    taylor = list(map(int,input().split()))
    katy = list(map(int,input().split()))

    n = int(n)
    m = int(m)

    taylorOps = dict()
    for msk in range(1, 1<<n):
        aux = 1
        for i in range(0, n):
            if(msk & (1 << i)):
                aux = aux * taylor[i]
        
        taylorOps[aux] = msk

    for msk in range(1, 1<<n):
        aux = 1
        for i in range(0, n):
            if(msk & (1 << i)):
                aux = aux * taylor[i]
        
        taylorOps[aux] = msk

    for msk in range(1, 1 << m):
        aux = 1
        for i in range(0, m):
            if(msk & (1 << i)):
                aux = aux * katy[i]
        
        if(aux in taylorOps):
            print("Y")
            taylorAns = list()
            katyAns = list()
            ans = taylorOps[aux]

            for i in range(0, n):
                if(ans & (1 << i)):
                    taylorAns.append(taylor[i])
            for i in range(0, m):
                if(msk & (1 << i)):
                    katyAns.append(katy[i])

            print(str(len(taylorAns)) + " " + str(len(katyAns)))
            
            for i in taylorAns:
                print(str(i), end=' ')
            
            print()
            for i in katyAns:
                print(str(i), end=' ')

            return
    
    print("N")

main()
