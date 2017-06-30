#include <stdio.h>

#define STUDENTNR 50	

int main(void)
{
	int score_c[STUDENTNR] = {1,2,3,4,5};						
	int i = 0;
	int score_o[25][2];

	for (i = 0; i < STUDENTNR; i++)
		printf("%d ", score_c[i]);

	printf("\n");

	printf("score_c:%p\n", score_c);//int *P = score_c;
	printf("score_c+1:%p\n", score_c+1);

	printf("&score_c:%p\n", &score_c);//int (*p)[50] = &score_c
	printf("&score_c+1:%p\n", &score_c+1);


	return 0;
}



