#include "conio.h"
#include <windows.h>

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include <fstream>
#include <string>
#include <fstream>

using namespace std;

class Pravila {
public:
	Pravila();
//�������� ��� ���������
	int getEl() const;
	void setEl( int );
//�������� ��� ��������	
	int getCar() const;
	void setCar( int );
//������� � ����
	int getGo() const;
	void setGo( int );
//��������� �� ��������� �������
	Pravila* getNext() { return this->next; }
	void setNext( Pravila *temp ) { this->next = temp; }
//����� ������� � ���������
	int getNum() const { return number; }
	void setNum( int temp ) { number = temp; }
private:
//��������
	int actEl;
	int actCar;
	int go;
//������� � �����
	int number;
	Pravila *next;
};

class Lenta {
public:
//��������� �� ��������� ��������� ������
	Lenta* getNext() { return this->next; }
	void setNext( Lenta *temp ) { this->next = temp; }
//����� ��������� ������
	int getInfo() { return this->info; }
	void setInfo( int temp ) { this->info = temp; }

private:
	int info;
	Lenta *next;
};

class MashinTuring {
friend ostream &operator<<( ostream &, const MashinTuring & );
friend istream &operator>>( istream &, MashinTuring & );

friend MashinTuring &creatAlgo( const char* );
friend MashinTuring &loadAlgo( const char* );
friend void saveAlgo( MashinTuring&, const char* );
friend MashinTuring &editAlgo( MashinTuring & );
friend void runAlgo( MashinTuring&, bool );

public:
	bool operator==( const MashinTuring & ) const;
	bool operator!=( const MashinTuring & ) const;
	MashinTuring &operator=( const MashinTuring & );
	MashinTuring &operator++();
	MashinTuring &operator--();
	bool operator[]( int ) const;

	MashinTuring();
	MashinTuring( const MashinTuring & );
	~MashinTuring();
//�������	
	int getCaretka() const;
	void setCaretka( int );
//�����
	void AddElement( int );
	bool SearchElement( int ) const;
	void DelElement( int );
	void ClearElements();
//�������
	void AddPravilo( int, int, int, int, int );
	Pravila *SearchPravilo( int, int ) const;
	void DelPravilo( int, int );
	void ClearPravila();
//��������������� �������� ��� ����������� ������
	int getHelpScreenPravila() const { return helpScreenPravila; }
	void setHelpScreenPravila( int temp ){ helpScreenPravila = temp; }
	void helpScreenEditPravila( MashinTuring &, int );
//��������������� �������� ��� ����������� �����
	int getHelpScreen() const { return helpScreen; }
	void setHelpScreen( int temp ){ helpScreen = temp; }
	void helpScreenEdit( MashinTuring & );
//����� ����� � ������
	void printStatusAlgo();
	void printPravilo( int, int );
private:
//���� ��������� � �������� �� ���������
	int stepGo( int, int );
	int searchStop( int );	
//��������������� ������� ��� ����� � ������	
	int helpScreen;
	int helpScreenPravila;
//�������, �����, �������
	int caretka;
	Lenta *lentMassiv;
	Pravila *pravilo[ 2 ];
};