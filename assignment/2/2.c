#include <stdio.h>

int main()
{
	int sum = 0;
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	// a에 대해 switch
	switch (a)
	{
	case 0:
		printf("None\n");
		break;
	case 1:
		printf("Pizza\n");
		sum += 15000;
		break;
	case 2:
		printf("Burger\n");
		sum += 5000;
		break;
	case 3:
		printf("Salad\n");
		sum += 4500;
		break;
	case 4:
		printf("Ice cream\n");

		sum += 800;
		break;
	case 5:
		printf("Beverage\n");
		sum += 500;
		break;
	}

	switch (b)
	{
	case 0:
		printf("None\n");
		break;
	case 1:
		printf("Pizza\n");
		sum += 15000;
		break;
	case 2:
		printf("Burger\n");
		sum += 5000;
		break;
	case 3:
		printf("Salad\n");
		sum += 4500;
		break;
	case 4:
		printf("Ice cream\n");

		sum += 800;
		break;
	case 5:
		printf("Beverage\n");
		sum += 500;
		break;
	}

	switch (c)
	{
	case 0:
		printf("None\n");
		break;
	case 1:
		printf("Pizza\n");
		sum += 15000;
		break;
	case 2:
		printf("Burger\n");
		sum += 5000;
		break;
	case 3:
		printf("Salad\n");
		sum += 4500;
		break;
	case 4:
		printf("Ice cream\n");

		sum += 800;
		break;
	case 5:
		printf("Beverage\n");
		sum += 500;
		break;
	
	}
	printf("Total: %dwon\n", sum);

	return 0;
}