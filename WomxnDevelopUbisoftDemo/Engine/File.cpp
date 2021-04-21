#include "stdafx.h"
#include <iostream>
#include "File.h"

File::File(const char* fileName){
	this->fileName = fileName;
	this->fileMode = FileMode::NONE;
}

File::~File(){
	if (file.is_open()) {
		file.close();
	}
}

void File::readMode(){
	close();
	file.open(fileName, std::ios::in);
	this->fileMode = FileMode::READ;
}

void File::writeMode(){
	close();
	file.open(fileName, std::ios::out);
	this->fileMode = FileMode::WRITE;
}

void File::close(){
	if (file.is_open()) {
		file.close();
	}
	this->fileMode = FileMode::NONE;
}

void File::getFloat(float* value){
	if (file.is_open() && fileMode == FileMode::READ) {
		std::string string;

		getline(file, string);
		*value = std::stof(string);
	}
	else {
		value = nullptr;
	}
}

void File::getInt(int* value){
	if (file.is_open() && fileMode == FileMode::READ) {
		*value = file.get();
	}
	else {
		value = nullptr;
	}
}

void File::getString(std::string *value){
	if (file.is_open() && fileMode == FileMode::READ) {
		getline(file, *value);
	}
	else {
		value = nullptr;
	}
}
