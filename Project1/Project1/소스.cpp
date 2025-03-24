#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void) {
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		char ymd[10];
		scanf("%s", ymd);

//		printf("%s\n", ymd);

		char year[10], month[10], day[10];
		int i;
		for (i = 0; i < 4; i++) {
			year[i] = ymd[i];
		}
		year[4] = '\0';
		for (i = 0; i < 2; i++) {
			day[i] = ymd[i + 6];
		}
		day[2] = '\0';
		printf("%s  %s  %s\n", year, month, day);
	}
	return 0;
}