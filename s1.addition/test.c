#include <stdio.h>
#include <string.h>

int main(void) {
    char input[80];
    char copied[80];

    puts("請輸入字串...");
    fgets(input, sizeof(input) / sizeof(input[0]), stdin);

    strcpy(copied, input);
    printf("複製整個字串：%s\n", copied);

    // 重設所有字元為空字元
    memset(copied, '\0', sizeof(copied));

    strncpy(copied, input, 4);
    printf("複製部份字串：%s\n", copied);

    return 0;
}