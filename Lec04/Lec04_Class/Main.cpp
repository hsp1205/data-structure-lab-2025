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

	//music streaming service�� ����
	MusicStreamingService my_service("spotify");  // f9 = ���ٱ����� ����� f10 = ������

	// add music to music streaming service
	my_service.addMusic("Pola", "roid", "Love", 2022);  //  ctrl+d = �ٺ���, f12 = �� �Լ��� �̵�
	my_service.addMusic("Ditto", "Newjeans", "ALBUM", 2023);
	my_service.addMusic("Cake", "ITZY", "ALBUM", 2024);
	// add by user
	// music ��ü ���� --> ����� �Է¹ޱ� (cin ���)
	// �Է¹��� ���� ������ music��ü��������� �ϳ��� ä���
	// ���������� music��ü my_service�� music_list�� push_back()

	//  search music by title
	string music_title;
	cout << "Enter the Music Title: "; // ȭ�鿡 Enter the Music Title: �� ������
	cin >> music_title;  // �Է¹޴°�
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {  // �Է��� NULL�� �ƴϸ�(�Է¹����� �迭�� ������)
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else {  // ������
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