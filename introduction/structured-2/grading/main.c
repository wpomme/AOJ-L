#include <stdio.h>

char judge(int m, int f, int r) {
    int score = m + f;
    if (m == -1 || f == -1) return 'F';
    if (score >= 80) return 'A';
    if (score >= 65 && score < 80) return 'B';
    if (score >= 50 && score < 65) return 'C';
    if (score >= 30 && score < 50) {
        if (r >= 50) {
            return 'C';
        } else {
            return 'D';
        }
    }
    return 'F';
}

int main() {
    int middleExam, finalExam, reExam;
    while (1) {
        scanf("%d %d %d", &middleExam, &finalExam, &reExam);
        if (middleExam == -1 && finalExam == -1 && reExam == -1) break;
        printf("%c\n", judge(middleExam, finalExam, reExam));
    }
}
