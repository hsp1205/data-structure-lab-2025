#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>

#define MAX_DEGREE 101                 // 다항식의 처리 가능한 최대 차수 + 1

class SparsePoly {
	int numTerms;                      // 다항식 항의 개수
	std::vector<int> exponents;        // 각 항의 차수 저장 벡터
	std::vector<float> coefficients;   // 각 항의 계수 저장 벡터

public:
	// 생성자 - 항의 개수를 0으로 초기화
	SparsePoly() : numTerms(0) {}

	// 다항식 입력 함수
	void read() {
		std::cout << "항의 개수를 입력하세요: ";
		std::cin >> numTerms;

		float coef; // 입력 계수
		int exp;    // 입력 차수

		for (int i = 0; i < numTerms; ++i) {
			std::cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ";
			std::cin >> coef >> exp;

			// 계수가 0이 아닌 경우에만 입력함
			if (coef != 0) {
				coefficients.push_back(coef);  // 입력받은 계수와 차수를 벡터에 저장
				exponents.push_back(exp);
			}
			else {
				--numTerms;
			}
		}
	}

	// 다항식 출력 함수
	void display(const char* str) {
		std::cout << str;   // 다항식 이름 출력
		for (int i = 0; i < numTerms; ++i) {
			std::cout << coefficients[i] << "x^" << exponents[i];  // 각 항을 출력
			if (i != numTerms - 1) std::cout << " + ";             // 마지막 항이 아니면 "+" 출력
		}
		std::cout << std::endl;
	}

	// 다항식 덧셈 함수
	void add(SparsePoly a, SparsePoly b) {
		numTerms = 0;         // 결과 항의 개수 초기화
		exponents.clear();    // 기존 데이터 초기화
		coefficients.clear();

		int i = 0, j = 0;     // a, b 다항식의 현재 항 위치 인덱스

		// a와 b의 항들을 하나씩 비교하면서 차수 기준으로 병합
		while (i < a.numTerms && j < b.numTerms) {

			// 두 항의 차수가 같은 경우 -> 계수끼리 더함
			if (a.exponents[i] == b.exponents[j]) {
				float sum = a.coefficients[i] + b.coefficients[j];
				exponents.push_back(a.exponents[i]);
				coefficients.push_back(sum);
				++numTerms;
				++i;
				++j;
			}

			// a의 항 차수가 더 큰 경우 -> 그대로 복사
			else if (a.exponents[i] > b.exponents[j]) {
				exponents.push_back(a.exponents[i]);
				coefficients.push_back(a.coefficients[i]);
				++i;
				++numTerms;
			}

			// b의 항 차수가 더 큰 경우 -> 그대로 복사
			else {
				exponents.push_back(b.exponents[j]);
				coefficients.push_back(b.coefficients[j]);
				++j;
				++numTerms;
			}
		}

		// a에 남은 항들 추가
		while (i < a.numTerms) {
			exponents.push_back(a.exponents[i]);
			coefficients.push_back(a.coefficients[i]);
			++i;
			++numTerms;
		}

		// b에 남은 항들 추가
		while (j < b.numTerms) {
			exponents.push_back(b.exponents[j]);
			coefficients.push_back(b.coefficients[j]);
			++j;
			++numTerms;
		}
	}
};