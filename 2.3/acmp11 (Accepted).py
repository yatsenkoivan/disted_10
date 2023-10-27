k, n = [int(i) for i in input().split()]
arr = [0]*n
arr[0] = 1
s = arr[0]
for i in range(1,k):
    arr[i] = s+1
    s += arr[i]

for i in range(k, n):
    arr[i] = s
    s -= arr[i-k]
    s += arr[i]
    
print(arr[n-1])