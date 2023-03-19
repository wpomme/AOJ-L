# Binary search
二分探索

疑似コード
```
binarySearch()
    left = 0
    right = n
    while left < right
        mid = (left + right) / 2
        if A[mid] == key
            return mid
        else if key < A[mid]
            right = mid
        else
            left = mid + 1
    return NOT_FOUND
```

`left = mid + 1`に注意!!
C言語で二分探索を作成した。breakにするべきところをcontinueにしていた...。
