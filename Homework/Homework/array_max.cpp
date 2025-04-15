#include <stdio.h>

int main()
{
	int input, max; // 입력값, 최대값
	int array[5];   // 배열 크기 5

	printf("5개의 숫자를 입력하세요: ");

	// 5개의 숫자를 입력받아 배열에 저장
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &input);
		array[i] = input;
	}

	max = array[0];                // 최대값을 배열의 첫번째 값으로 설정

	// 최대값 찾기
	for (int i = 0; i < 5; i++) {
		if (max < array[i]) {      // 현재 최대값보다 큰 값이 있으면 
			max = array[i];        // 그 값을 최대값으로 저장
		}
	}

	printf("최대값: %d", max);

	return 0;
}