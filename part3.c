#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hasCommonChar(const char* s1, const char* s2) {
    int mask1 = 0;
    int mask2 = 0;

    for (int i = 0;s1[i] != '\0';i++) {
        char c = s1[i];

        mask1 |= 1u << c - 'a';
    }

    for (int j = 0;s2[j] != '\0';j++) {
        char d = s2[j];

        mask2 |= 1u << d - 'a';
    }

    int res = mask1 & mask2;

    if (res) printf("1");
    else printf("0");

    return 0;
}

int main() {

    char str1[100];
    char str2[100];

    printf("Enter the first string:\n");
    scanf("%99s", str1);
    printf("Enter the second string:\n");
    scanf("%99s", str2);

    const char* s1 = str1;
    const char* s2 = str2;

    hasCommonChar(s1, s2);

    return 0;
}