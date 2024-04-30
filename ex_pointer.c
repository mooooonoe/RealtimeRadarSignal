#include <stdio.h>

int main() {
    float DOA_2D_storage[10]; // 예를 들어 크기가 10인 배열로 가정합니다.
    int offset = 3; // 예를 들어 3으로 가정합니다.

    // DOA_2D_storage[offset]의 주소를 float 포인터로 변환합니다.
    float* ptr = (float*)&DOA_2D_storage[offset];

    // 변환된 포인터를 사용하여 값에 접근합니다.
    printf("Value at offset %d: %f\n", offset, *ptr);

    printf("\n");

    
    for (int i = 0; i < 10; i++) {
        int *value = (float*)&DOA_2D_storage[i];
        printf("%d\n", value);
    }

    return 0;
}
