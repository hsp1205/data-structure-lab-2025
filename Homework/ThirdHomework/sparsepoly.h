#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>

#define MAX_DEGREE 101                 // ���׽��� ó�� ������ �ִ� ���� + 1

class SparsePoly {
	int numTerms;                      // ���׽� ���� ����
	std::vector<int> exponents;        // �� ���� ���� ���� ����
	std::vector<float> coefficients;   // �� ���� ��� ���� ����

public:
	// ������ - ���� ������ 0���� �ʱ�ȭ
	SparsePoly() : numTerms(0) {}

	// ���׽� �Է� �Լ�
	void read() {
		std::cout << "���� ������ �Է��ϼ���: ";
		std::cin >> numTerms;

		float coef; // �Է� ���
		int exp;    // �Է� ����

		for (int i = 0; i < numTerms; ++i) {
			std::cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��: ��� ����): ";
			std::cin >> coef >> exp;

			// ����� 0�� �ƴ� ��쿡�� �Է���
			if (coef != 0) {
				coefficients.push_back(coef);  // �Է¹��� ����� ������ ���Ϳ� ����
				exponents.push_back(exp);
			}
			else {
				--numTerms;
			}
		}
	}

	// ���׽� ��� �Լ�
	void display(const char* str) {
		std::cout << str;   // ���׽� �̸� ���
		for (int i = 0; i < numTerms; ++i) {
			std::cout << coefficients[i] << "x^" << exponents[i];  // �� ���� ���
			if (i != numTerms - 1) std::cout << " + ";             // ������ ���� �ƴϸ� "+" ���
		}
		std::cout << std::endl;
	}

	// ���׽� ���� �Լ�
	void add(SparsePoly a, SparsePoly b) {
		numTerms = 0;         // ��� ���� ���� �ʱ�ȭ
		exponents.clear();    // ���� ������ �ʱ�ȭ
		coefficients.clear();

		int i = 0, j = 0;     // a, b ���׽��� ���� �� ��ġ �ε���

		// a�� b�� �׵��� �ϳ��� ���ϸ鼭 ���� �������� ����
		while (i < a.numTerms && j < b.numTerms) {

			// �� ���� ������ ���� ��� -> ������� ����
			if (a.exponents[i] == b.exponents[j]) {
				float sum = a.coefficients[i] + b.coefficients[j];
				exponents.push_back(a.exponents[i]);
				coefficients.push_back(sum);
				++numTerms;
				++i;
				++j;
			}

			// a�� �� ������ �� ū ��� -> �״�� ����
			else if (a.exponents[i] > b.exponents[j]) {
				exponents.push_back(a.exponents[i]);
				coefficients.push_back(a.coefficients[i]);
				++i;
				++numTerms;
			}

			// b�� �� ������ �� ū ��� -> �״�� ����
			else {
				exponents.push_back(b.exponents[j]);
				coefficients.push_back(b.coefficients[j]);
				++j;
				++numTerms;
			}
		}

		// a�� ���� �׵� �߰�
		while (i < a.numTerms) {
			exponents.push_back(a.exponents[i]);
			coefficients.push_back(a.coefficients[i]);
			++i;
			++numTerms;
		}

		// b�� ���� �׵� �߰�
		while (j < b.numTerms) {
			exponents.push_back(b.exponents[j]);
			coefficients.push_back(b.coefficients[j]);
			++j;
			++numTerms;
		}
	}
};