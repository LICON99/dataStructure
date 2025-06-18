/*용돈 관리 다국어

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	24886	7687	5285	29.394%
문제
현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다. 현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고, 돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 현우는 통장에서 K원을 인출하며, 통장에서 뺀 돈으로 하루를 보낼 수 있으면 그대로 사용하고, 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 다만 현우는 M이라는 숫자를 좋아하기 때문에, 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. 현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.

입력
1번째 줄에는 N과 M이 공백으로 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ M ≤ N)

2번째 줄부터 총 N개의 줄에는 현우가 i번째 날에 이용할 금액이 주어진다. (1 ≤ 금액 ≤ 10000)

출력
첫 번째 줄에 현우가 통장에서 인출해야 할 최소 금액 K를 출력한다.

예제 입력 1
7 5
100
400
300
100
500
101
400
예제 출력 1
500*/
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int money[100002]; // 하루마다 쓸 금액 저장
	int a, sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a; // 최대값
		money[i] = a;
	}
	int result = 0;
	int low, mid, high;
	low = 1;	// 최소값
	high = sum; // 최대값
	int total;	// 현재 남은 금액
	while (low <= high)
	{
		mid = (low + high) / 2; // 인출 금액
		total = mid;			// 인출 금액으로 초기화
		bool pass = true;		// 성립 가능한지
		int cnt = 1;			// 인출 횟수 1로 시작
		for (int i = 0; i < n; i++)
		{
			int day_money = money[i];
			if (day_money > mid)
			{ // 하루쓸 돈이 인출 금액보다 크면 성립x
				pass = false;
				break;
			}
			if (day_money > total)
			{				 // 하루쓸 돈이 남은 돈보다 큰 경우
				total = mid; // 돈을 인출
				cnt++;		 // 인출 횟수 카운트
			}
			total -= day_money; // 하루에 쓸 돈 차감
		}
		if (!pass || cnt > m)
		{				   // 인출 횟수가 많거나 성립x
			low = mid + 1; // 인출 금액 늘려줌
		}
		else
		{
			result = mid;	// 인출 금액 저장
			high = mid - 1; // 인출 금액 낮춰서 탐색
		}
	}

	cout << result << endl; // 출력
	return 0;
}
