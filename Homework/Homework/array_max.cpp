#include <stdio.h>

int main()
{
	int input, max; // �Է°�, �ִ밪
	int array[5];   // �迭 ũ�� 5

	printf("5���� ���ڸ� �Է��ϼ���: ");

	// 5���� ���ڸ� �Է¹޾� �迭�� ����
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &input);
		array[i] = input;
	}

	max = array[0];                // �ִ밪�� �迭�� ù��° ������ ����

	// �ִ밪 ã��
	for (int i = 0; i < 5; i++) {
		if (max < array[i]) {      // ���� �ִ밪���� ū ���� ������ 
			max = array[i];        // �� ���� �ִ밪���� ����
		}
	}

	printf("�ִ밪: %d", max);

	return 0;
}