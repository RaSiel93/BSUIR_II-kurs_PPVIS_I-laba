#include <iostream>
using std::ostream;
using std::istream;

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
friend ostream &operator<<( ostream &, const MashinTuring* );
friend istream &operator>>( istream &, MashinTuring* );

friend MashinTuring* creatAlgo( const char* );
friend MashinTuring* loadAlgo( const char* );
friend void saveAlgo( MashinTuring*, const char* );
friend MashinTuring* editAlgo( MashinTuring* );
friend void runAlgo( MashinTuring*, bool );

public:
	MashinTuring();
	~MashinTuring();
//�������	
	int getCaretka() const;
	void setCaretka( int );
//�����
	void AddElement( int );
	bool SearchElement( int );
	void DelElement( int );
	void ClearElements();
//�������
	void AddPravilo( int, int, int, int, int );
	Pravila *SearchPravilo( int, int );
	void DelPravilo( int, int );
	void ClearPravila();
//��������������� �������� ��� ����������� ������
	int getHelpScreenPravila() const { return helpScreenPravila; }
	void setHelpScreenPravila( int temp ){ helpScreenPravila = temp; }
	void helpScreenEditPravila( MashinTuring *, int );
//��������������� �������� ��� ����������� �����
	int getHelpScreen() const { return helpScreen; }
	void setHelpScreen( int temp ){ helpScreen = temp; }
	void helpScreenEdit( MashinTuring * );
private:
//����� ����� � ������
	void printStatusAlgo();
	void printPravilo( int, int );
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