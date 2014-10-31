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
using namespace std;

CUserInterface::CUserInterface(){
	CControl control;
	int opt_check;
	std::cout << "Projektarbeit Scrambler: "<< endl;
	std::cout << "Druecken Sie fuer Datei kodieren die Nummer 1:" << endl;
	std::cout << "Druecken Sie fuer Datei dekodieren die Nummer 2:" << endl;
	std::cin >> opt_check;
	if (opt_check == 1)
	{
		std::cout << "Geben Sie verzeichnis Pfad an und druecken Sie Enter:" << endl;
		std::cin >> path;
		std::cout << "Rueckgabe Pfad an:"<< path << endl;
	}
}


CUserInterface::~CUserInterface(){

}


void CUserInterface::Ask(){

}


void Print(string ret_val){

}