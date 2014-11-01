///////////////////////////////////////////////////////////
//  CUserInterface.cpp
//  Implementation of the Class CUserInterface
//  Created on:      30-Okt-2014 21:35:35
//  Original author: AbdulM
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "iostream"
#include "UserInterface.h"
#include "Control.h"
#include "string"
#include "vector"
#include <conio.h>
using namespace std;

CUserInterface::CUserInterface(){
	CControl control;
	int opt_check;
	
	std::cout << "Projektarbeit Scrambler: " << endl;
	std::cout << "Druecken Sie fuer Datei kodieren die Nummer 1 und druecken Sie Enter:" << endl;
	std::cout << "Druecken Sie fuer Datei dekodieren die Nummer 2 und druecken Sie Enter:" << endl;
	std::cin >> opt_check;
	if (opt_check == 1)
	{
		std::cout << "Waehlen Sie die zu verschluesselnde Datei aus:" << endl;
		//std::cout << "Geben Sie den Verzeichnispfad ein und druecken Sie Enter:" << endl;
		//std::cout << "!!Hinweis Verzeichnispfad darf keine leerzeichen enthalten!!" << endl;
		// Die Funktion Ask() ermöglicht Pfad extraction durch einfügen per Drag & Drop
		Ask();
		//std::cin >> path;
		std::cout << "Geben Sie den Schluessel an ein druecken Sie Enter:" << endl;
		std::cin >> key;

		control.encryptFile(path, key);
		std::cout << "Die Datei liegt im Pfad:" << path << endl;
	}
	else if (opt_check==2)
	{
		std::cout << "Waehlen Sie die zu entschluesselnde Datei aus : " << endl;
		//std::cout << "!!Hinweis Verzeichnispfad darf keine leerzeichen enthalten!!" << endl;
		// Die Funktion Ask() ermöglicht Pfad extraction durch einfügen per Drag & Drop
		Ask();
		std::cout << "Geben Sie den Schluessel ein und druecken Sie Enter:" << endl;
		std::cin >> key;

		control.decryptFile(path, key);
		std::cout << "Die Datei liegt im Pfad:" << path << endl;
		
	}


}


CUserInterface::~CUserInterface(){

}


void CUserInterface::Ask(){
	std::cout << "Bitte Datei per Drag & Drop in die Konsole ziehen. (Beenden mit [Enter].)\n";

	std::vector< std::string > files;

	for (int ch = _getch(); ch != '\r'; ch = _getch()) {

		std::string file_name;

		if (ch == '\"') {  // path containing spaces. read till next '"' ...

			while ((ch = _getch()) != '\"')
				file_name += ch;

		}
		else {  // path not containing spaces ... read as long as characters are coming rapidly ...

			file_name += ch;

			while (_kbhit())
				file_name += _getch();
		}

		files.push_back(file_name);
	}

	std::cout << "Sie haben folgende Dateien in das Konsolenfenster gezogen:\n";

	for (auto & i : files)
	{
		path = i;
		std::cout << i << '\n';
	}
	
}


void Print(string ret_val){

}