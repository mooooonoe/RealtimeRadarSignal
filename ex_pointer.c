#include <stdio.h>

int main() {
    float DOA_2D_storage[10]; // ���� ��� ũ�Ⱑ 10�� �迭�� �����մϴ�.
    int offset = 3; // ���� ��� 3���� �����մϴ�.

    // DOA_2D_storage[offset]�� �ּҸ� float �����ͷ� ��ȯ�մϴ�.
    float* ptr = (float*)&DOA_2D_storage[offset];

    // ��ȯ�� �����͸� ����Ͽ� ���� �����մϴ�.
    printf("Value at offset %d: %f\n", offset, *ptr);

    printf("\n");

    
    for (int i = 0; i < 10; i++) {
        int *value = (float*)&DOA_2D_storage[i];
        printf("%d\n", value);
    }

    return 0;
}
