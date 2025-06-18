/*예산

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	71401	27736	20275	37.666%
문제
국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다. 국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다. 그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정한다.

모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.
예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다.

여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

입력
첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다. 다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다. 그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N 이상 1,000,000,000 이하이다.

출력
첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다.

예제 입력 1
4
120 110 140 150
485
예제 출력 1
127
예제 입력 2
5
70 80 30 40 100
450
예제 출력 2
100*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N;	// 지방의 수
long M; // 총 예산
long *required;
long sum = 0;
int i;

bool isPossible(long quantity)
{
	sum = 0;

	for (i = 0; i < N; i++)
	{
		if (required[i] < quantity)
		{
			sum += required[i];
		}
		else
		{
			sum += quantity;
		}
		if (sum > M)
		{
			return false;
		}
	}
	return true;
}

// data : 탐색할 오름차순으로 정렬된 정수 배열
// n : 정수 배열의 크기
// key : 찾고자하는 값
long solve(long max)
{
	int low, high;
	int mid;
	int res = 0;

	low = 0;
	high = max;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (isPossible(mid))
		{
			res = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return res;
}

int main()
{
	long max = 0;

	scanf("%d", &N);
	required = malloc(sizeof(long) * N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &required[i]);

		if (max < required[i])
		{
			max = required[i];
		}
	}
	scanf("%d", &M);

	printf("%d\n", solve(max));
}