#include <stdio.h>
#include "struct.h"

int main() {
    // ����ü ���� ���� �� �ʱ�ȭ
    struct Person person1 = { "John", 25 };
    struct Person* personPtr = &person1;

    // . �����ڸ� ����Ͽ� ����ü ����� ����
    printf("Using . operator:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    // -> �����ڸ� ����Ͽ� ����ü �����ͷ� ����� ����
    printf("\nUsing -> operator:\n");
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);

    return 0;
}
