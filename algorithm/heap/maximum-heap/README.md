# Maximum Heap
ヒープ

子要素が親要素より常に大きいか、小さいという条件を持つ完全二分木をヒープと呼ぶ。
この問題では子要素が親要素より常に小さい場合を扱う。これをMaxヒープと呼ぶ。

maxHeapifyは節点iを根とする部分木がMaxヒープとなるようHeap[i]の値をMaxヒープの葉へ向かって降下させる。
Hはヒープサイズとする。

maxHeapify(heap, i)
    l = left(i)
    r = right(i)

    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if l ≤ H and heap[l] > heap[i]
        largest = l
    else 
        largest = i
    if r ≤ H and heap[r] > heap[largest]
        largest = r

    if largest ≠ i
        heap[i] と heap[largest] を交換
        maxHeapify(heap, largest)
