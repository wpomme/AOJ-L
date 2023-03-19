#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1046527
#define L 14
#define NOT_FOUND 0 

char hashTable[MOD][L];

int getChar(char ch){
  switch (ch) {
    case 'A':
      return 1;
    case 'C':
      return 2;
    case 'G':
      return 3;
    case 'T':
      return 4;
  }
  printf("Error: ch is not 'ACGT'.");
  exit(1);
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1;
  for (long long i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) {
    return key % MOD;
}

int h2(int key) {
    return 1 + (key % (MOD - 1));
}

int hash(int key, int i) {
    return (h1(key) + i * h2(key)) % MOD;
}

int find(char str[]){
    int i = 0;
    while (1) {
        int j = hash(getKey(str), i);
        if (strcmp(hashTable[j], str) == 0) {
            return j;
        } else if (hashTable[j][0] == '\0' || i >= MOD) {
            return NOT_FOUND;
        } else {
            i++;
        }
    }
}

int insert(char str[]){
    for (int i = 0; ; i++) {
        int j = hash(getKey(str), i);
        if (strcmp(hashTable[j], str) == 0) {
            return 1;
        } else if (strlen(hashTable[j]) == 0) {
            strcpy(hashTable[j], str);
            return 0;
        }
    }
}

int main() {
    int n;
    char str[L], command[9];
    for (int i = 0; i < MOD; i++ ) hashTable[i][0] = '\0';
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++ ) {
        scanf("%s %s", command, str);
        
        if ( command[0] == 'i' ){
            insert(str);
        } else {
            if (find(str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}
