#include <stdio.h>
#include "struct.h"

int main() {
    // 구조체 변수 선언 및 초기화
    struct Person person1 = { "John", 25 };
    struct Person* personPtr = &person1;

    // . 연산자를 사용하여 구조체 멤버에 접근
    printf("Using . operator:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    // -> 연산자를 사용하여 구조체 포인터로 멤버에 접근
    printf("\nUsing -> operator:\n");
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);

    return 0;
}
