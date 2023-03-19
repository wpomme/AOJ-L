# Queue with ling buffer and round robin
キューの実装

head: キューの先頭を指す
tail: キューの末尾+1を指す

enqueue()
Queue[tail]にxを代入し、tailを一つ増やす

dequeue()
Queue[head]の値を返し、headを一つ増やす
