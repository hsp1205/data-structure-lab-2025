#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	// �̹����� Grayscale�� �ҷ�����
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

	int maxBrightness = 0;  // �ִ� ��� ���� ������ �ʱⰪ = 0

	// �̹����� ��� �ȼ��� ���� �ִ� ��� ã��
	for (int y = 0; y < img.rows; y++) {      // ��-����
		for (int x = 0; x < img.cols; x++) {  // ��-����
			int pixel = img.at<uchar>(y, x);  // y,x �ȼ��� ��Ⱚ ������ pixel�� ����
			if (maxBrightness < pixel) {      // ���� �ִ� ��Ⱚ���� ���Ⱚ�� ũ��
				maxBrightness = pixel;        // ���Ⱚ�� �ִ� ��Ⱚ���� ����
			}
		}
	}

	cv::imshow("lenna window", img);  //�̹����� ȭ�鿡 ���
	printf("\n\n\n�ִ� ȭ�� ���: %d", maxBrightness);
	cv::waitKey(0);

}