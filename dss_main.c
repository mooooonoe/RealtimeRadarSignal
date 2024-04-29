#define _CRT_SECURE_NO_WARNINGS /

#include <stdio.h>

int main() {
    FILE* file;
    char line[256];
    file = fopen("frameComplex.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); 
    }
    else {
        printf("파일에 내용이 없습니다.\n");
    }

    fclose(file);

    return 0;
}
