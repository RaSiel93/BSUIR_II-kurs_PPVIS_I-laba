/// @file mashina.h
/// @author ���������� ��������� ����������
/// @date ������� 2012 ����
///

#ifndef MASHINA_H
#define MASHINA_H

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

/// @class Pravila
///
/// @brief ����� ������������ ����� ������ � ������ ��������.
///
/// @author ���������� ��������� ����������
/// @date ������� 2012 ����
///
class Pravila {
public:
	/// @brief ������ ����� �������.
	///
	Pravila();
	/// @return ����� �������� ��� ���������, �� �������, ��� ���������� �������, ����� ������ �������.
	///
	int getEl() const;
	/// @brief ������ ����� �������� ��� ���������, �� �������, ��� ���������� �������, ����� ������ �������.
	///
	void setEl( int );
	/// @return ����� ������ �������, ��� ���������� �������.
	///	
	int getCar() const;
	/// @brief ������ ����� ������ �������, ��� ���������� �������.
	///
	void setCar( int );
	/// @return ����� ���������� �������.
	///	
	int getGo() const;
	/// @brief ������ ����� ���������� �������.
	///
	void setGo( int );
	/// @return ��������� �� ����� �������.
	///	
	Pravila* getNext() { return this->next; }
	/// @brief ������ ��������� �� ����� �������.
	///	
	void setNext( Pravila *temp ) { this->next = temp; }
	/// @return ����� ������� � �����.
	///	
	int getNum() const { return number; }
	/// @brief ������ ����� ������� � �����.
	///		
	void setNum( int temp ) { number = temp; }
private:
	int actEl;
	int actCar;
	int go;

	int number;
	Pravila *next;
};

/// @class Lenta
///
/// @brief ����� ������������ �����.
///
/// @author ���������� ��������� ����������
/// @date ������� 2012 ����
///
class Lenta {
public:
	/// @return ������� �����
	///
	Lenta* getNext() { return this->next; }
	/// @brief ������ ������� �����
	///
	void setNext( Lenta *temp ) { this->next = temp; }
	/// @return ������ ����� ������� ������� � �����
	///
	int getInfo() { return this->info; }
	/// @brief ������ ����� ������� ������� � �����
	///
	void setInfo( int temp ) { this->info = temp; }
private:
	int info;
	Lenta *next;
};

/// @class MashinTuring
///
/// @brief ����� ��� ������������� ������ ��������.
///
/// @author ���������� ��������� ����������
/// @date ������� 2012 ����
///
class MashinTuring {
	/// @brief ��������� �� ������ stream ����� � �������� ����.
	///
	friend ostream &operator<<( ostream &, const MashinTuring & );
	/// @brief ������� � ����� stream ����� � �������� ����.
	///
	friend istream &operator>>( istream &, MashinTuring & );
	// ������� ������ ������ MashinTuring
	friend MashinTuring &creat( const char*, bool );
	// ��������� ������ ������ MashinTuring
	friend MashinTuring &load( const char*, bool );
	// ��������� ������ ������ MashinTuring
	friend void save( MashinTuring&, const char*, bool );
	// ����������� ������ ������ MashinTuring
	friend MashinTuring &edit( MashinTuring &, bool );
	// ��������� �������� ������� ������ MashinTuring
	friend MashinTuring &run( MashinTuring &, bool );

public:
	bool operator==( const MashinTuring & ) const;
	bool operator!=( const MashinTuring & ) const;
	MashinTuring &operator=( const MashinTuring & );
	// �������� ������� ������
	MashinTuring &operator++();
	// �������� ������� �����
	MashinTuring &operator--();
	// ��������� ������� ������� �� �������� �����
	bool operator[]( int ) const;

	MashinTuring();
	MashinTuring( const MashinTuring & );
	~MashinTuring();
	// ���������� ������� �������	
	int getCaretka() const;
	// ������ ������� �������
	void setCaretka( int );
	// ��������� ������� �� �����
	void AddElement( int );
	// ��������� ������� ������� �� �������� �����
	bool SearchElement( int ) const;
	// �������� �������� �������� �����
	void DelElement( int );
	// �������� ��� �����
	void ClearElements();
	// ��������� �������
	void AddPravilo( int, int, int, int, int );
	// ���������� ������� �� ������
	Pravila *SearchPravilo( int, int ) const;
	// ������� ������� �� ������
	void DelPravilo( int, int );
	// ������� ��� �������
	void ClearPravila();
//��������������� �������� ��� ����������� ������
	int getHelpScreenPravila() const { return helpScreenPravila; }
	void setHelpScreenPravila( int temp ){ helpScreenPravila = temp; }
	void helpScreenEditPravila( MashinTuring &, int );
//��������������� �������� ��� ����������� �����
	int getHelpScreen() const { return helpScreen; }
	void setHelpScreen( int temp ){ helpScreen = temp; }
	void helpScreenEdit( MashinTuring & );
	// ����� ����� �� �������
	void printStatusAlgo();
	// ����� ������ �� �������
	void printPravilo( int, int );
	// ��������� ������� ������� ���������
	int stepGo( int, int );
	// ��������� ������� ��������� ���������
	int searchStop( int, bool );
private:	
//��������������� ������� ��� ����� � ������	
	int helpScreen;
	int helpScreenPravila;
//�������, �����, �������
	int caretka;
	Lenta *lentMassiv;
	Pravila *pravilo[ 2 ];
};

#endif //MASHINA_H