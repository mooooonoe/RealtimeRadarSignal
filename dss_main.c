#define _CRT_SECURE_NO_WARNINGS /

#include <stdio.h>

int main() {
    FILE* file;
    char line[256];
    file = fopen("frameComplex.txt", "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); 
    }
    else {
        printf("���Ͽ� ������ �����ϴ�.\n");
    }

    fclose(file);

    return 0;
}
