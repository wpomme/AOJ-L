# template
c ローカル環境のテンプレート

## main.cpp
main関数と#include <stdio.h>はほぼ必須なので記載してある

## Makefile
コマンド一覧

- make
ソースコードのコンパイル

- make test
test.txtを読み込んでコードを実行

- make clean
main.oを消去

- make copy
main.cをクリップボードにコピーする(Macのみ)

## test.txt
`make test`でファイルの内容をインプットできる
競プロで使う
