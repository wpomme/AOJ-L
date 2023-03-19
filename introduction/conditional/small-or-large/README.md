# insertion sort
挿入ソート

疑似コード
```
insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
  for i が 1 から N-1 まで
    v = A[i]
    j = i - 1
    while j >= 0 かつ A[j] > v
      A[j+1] = A[j]
      j--
    A[j+1] = v
```
