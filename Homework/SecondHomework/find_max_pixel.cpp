#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	// 이미지를 Grayscale로 불러오기
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

	int maxBrightness = 0;  // 최대 밝기 저장 변수의 초기값 = 0

	// 이미지의 모든 픽셀을 돌며 최대 밝기 찾기
	for (int y = 0; y < img.rows; y++) {      // 행-세로
		for (int x = 0; x < img.cols; x++) {  // 열-가로
			int pixel = img.at<uchar>(y, x);  // y,x 픽셀의 밝기값 추출후 pixel에 저장
			if (maxBrightness < pixel) {      // 현재 최대 밝기값보다 추출값이 크면
				maxBrightness = pixel;        // 추출값을 최대 밝기값으로 저장
			}
		}
	}

	cv::imshow("lenna window", img);  //이미지를 화면에 출력
	printf("\n\n\n최대 화소 밝기: %d", maxBrightness);
	cv::waitKey(0);

}