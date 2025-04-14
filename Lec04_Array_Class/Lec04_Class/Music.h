#pragma once
#include <iostream> // �Է� ��� ���� ���̺귯��
#include <string>   // ���ڿ�
#include <vector>   // STL vector

using namespace std;  // Namespace

class Music {

private:
	string title;
	string artist;
	string album;
	int year;

public:  // ������
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;

	}
	
	string getTitle() {
		return title;
	}
	string getArtist() {
		return artist;
	}
	string getAlbum() {
		return album;
	}
	int getYear() {
		return year;
	}
};

class MusicStreamingService{
	
private:
	string service_name;
	vector<Music> music_list;

public:
	//������
	MusicStreamingService(string service_name) {
		this->service_name = service_name;
	}
	//���� �߰� ���
	void addMusic(string title, string artist, string album, int year) {
		Music new_music(title, artist, album, year);
		music_list.push_back(new_music);
		cout << title << " by " << artist << "added to " << service_name << endl;
	}
	// ���� ã���ִ� ���� (Title)
	Music* searchByTitle(string title) {  // * = �ּҰ� ����
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getTitle() == title) {
				return &music_list[i];  // �迭 �ּҰ� ��ȯ(&���̱�) &music_list[i] = music_list+i
			}
		}
		return NULL;
	}

	// ���� ã���ִ� ���� (Artist)
	vector<Music*> searchByArtist(string artist) {
		vector<Music*> result;  // vector �ϳ��ϳ��� Music*�� *�� �ּҰ�
		for (int i = 0; i < music_list.size(); i++) {  // .size �Լ� = vertor ũ�� �Լ�
			if (music_list[i].getArtist() == artist) {
				result.push_back(&music_list[i]);   // &�������� Music* �̹Ƿ�
			}
		}

		return result;
	}

};