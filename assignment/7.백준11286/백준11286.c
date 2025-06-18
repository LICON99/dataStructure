#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 최대 힙 크기 정의
#define MAX_SIZE 100001

int heap[MAX_SIZE];
int heapSize = 0;

// 사용자 정의 비교 함수
int compare(int a, int b) {
    int absA = abs(a), absB = abs(b);
    
    if (absA == absB)
        return a > b;

    return absA > absB;
    // 절대값이 같으면 더 작은 수를 우선, 절대값 기준으로 정렬
}

// 최소 힙에 값 삽입
void push(int x) {
    int i = ++heapSize;

    while (i != 1 && compare(heap[i / 2], x)) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    
    heap[i] = x;
    // 삽입 후 부모 노드와 비교하여 위로 올리는 힙 연산
}

// 최소 힙에서 값 추출
int pop() {
    if (heapSize == 0) return 0;

    int top = heap[1];
    int temp = heap[heapSize--];

    int parent = 1, child = 2;

    while (child <= heapSize) {
        if (child + 1 <= heapSize && compare(heap[child], heap[child + 1]))
            child++;

        if (!compare(temp, heap[child]))
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
    return top;
    // 힙의 루트 삭제 후 재정렬하여 최소 힙 유지
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);

        if (x == 0) {
            printf("%d\n", pop());
        } else {
            push(x);
        }
    }

    return 0;
    // 명령에 따라 힙에서 삽입 또는 추출 수행
}