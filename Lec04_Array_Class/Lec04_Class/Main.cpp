//#include "Complex.h"
//#include"SportsCar.h"
#include "Music.h"


int main()
{
	//Complex a, b, c;
	//a.read("A =");
	//a.print(" A = ");
	
	//Car myCar;
	//Car momsCar(10, "K5", 2);
	//SportsCar mySecondCar;

	//myCar.whereAmI();
	//momsCar.whereAmI();
	//myCar.changeGear(3);
	//momsCar.speedUp();
	//momsCar.display();

	//mySecondCar.setTurbo(true);

	//music streaming service를 생성
	MusicStreamingService my_service("spotify");  // f9 = 그줄까지만 디버깅 f10 = 다음줄

	// add music to music streaming service
	my_service.addMusic("Pola", "roid", "Love", 2022);  //  ctrl+d = 줄복사, f12 = 그 함수로 이동
	my_service.addMusic("Ditto", "Newjeans", "ALBUM", 2023);
	my_service.addMusic("Cake", "ITZY", "ALBUM", 2024);
	// add by user
	// music 객체 선언 --> 사용자 입력받기 (cin 사용)
	// 입력받은 값을 선언한 music객체멤버변수에 하나씩 채우기
	// 마지막으로 music객체 my_service의 music_list에 push_back()

	//  search music by title
	string music_title;
	cout << "Enter the Music Title: "; // 화면에 Enter the Music Title: 를 보여줌
	cin >> music_title;  // 입력받는거
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {  // 입력이 NULL이 아니면(입력받은게 배열에 있으면)
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else {  // 없으면
		cout << "not found" << endl;
	}

	//  search music by artist
	string artist_name;
	cout << "Enter the Artist Name: ";
	cin >> artist_name;
	vector<Music*> artist_result = my_service.searchByArtist(artist_name);
	if (artist_result.size() > 0) {
		cout << "Found " << artist_result.size() << "songs by " << artist_name << " : " << endl;
		for (int i = 0; i < artist_result.size(); i++) {
			cout << artist_result[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;

}