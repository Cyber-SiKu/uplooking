#include <stdio.h>

int main(void)
{
	int value_height;//valueHeight
	int sum = 0;
	int i;

	do {
		printf("input the number\n");	
		scanf("%d", &value_height);
	}while (value_height <= 0);

	printf("the number is %d\n", value_height);

#if 0
	switch(value_height % 2) {
		case 0:
			statement1;
			break;
		case 1:
			break;
		default:
			break;
	}

#endif

	if (value_height % 2 == 0) {
		printf("偶数\n");
	} else if (value_height > 10) {
		//前n項和
#if 0
		while (value_height > 0) {
			sum += value_height;	
			value_height --;
		}
#endif
		for (i = 1; i <= value_height; i++) {
			sum += i;
		}
		printf("奇数%d的前n和是%d\n", value_height, sum);
			
	}
	


	return 0;
}





