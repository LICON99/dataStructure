#include <stdio.h>

// 보간 탐색 함수 정의
int ISearch(int ar[], int first, int last, int target)
{
	int mid;

	// 배열 범위를 벗어난 경우 탐색 실패
	if (ar[first] > target || ar[last] < target)
		return -1;

	// 보간 탐색 공식으로 예상 위치 계산
	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) *
		   (last - first)) +
		  first;

	if (ar[mid] == target)
		return mid; // 탐색 성공 시 인덱스 반환
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target); // 왼쪽 탐색
	else
		return ISearch(ar, mid + 1, last, target); // 오른쪽 탐색
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("찾은 값의 인덱스: %d\n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("찾은 값의 인덱스: %d\n", idx);

	return 0;
}

/*
int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("찾은 값의 인덱스: %d\n", idx);

	return 0;
}
*/