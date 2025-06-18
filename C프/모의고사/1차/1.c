#include <stdio.h>

int main()
{
	double a, b, c, d, e;
	double m;

	scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

	m = ((a + b + c + d + e)) / 5;
	int cnt = 0;
	if(a>100||a<0||b>100||b<0||c>100||c<0||d>100||d<0||e>100||e<0)
	{
		printf("Invalid\n");
		return 0;
	}
	if (a < 40)
		cnt++;
	if (b < 40)
		cnt++;
	if (c < 40)
		cnt++;
	if (d < 40)
		cnt++;
	if (e < 40)
		cnt++;

	if (cnt >= 3)
		printf("F\n");
	else if (m >= 90)
		printf("A+\n");
	else if (m >= 75)
		printf("A\n");
	else if (m >= 65)
		printf("B+\n");
	else if (m >= 50)
		printf("B\n");
	else
		printf("F\n");
	double min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	if (min > e)
		min = e;
	printf("avg=%.2lf min=%d", m, (int)min);
	return 0;
}