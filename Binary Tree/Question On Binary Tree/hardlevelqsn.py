def fun(n, k, arr):
    ans = 0
    if min(arr) < k:
        ans = 1
    for i in range(n - 1):
        for j in range(i + 1, n):
            if sum(arr[i:j]) < k:
                ans = max(ans, j - i)
            else:
                break
    return ans


n, k = map(int, input().split())
arr = list(map(int, input().split()))
print(fun(n, k, arr))