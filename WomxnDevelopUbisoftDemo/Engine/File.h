#pragma once

#include <string>
#include <fstream>

enum class FileMode {
	READ,
	WRITE,
	NONE
};

class File{

public :
	File(const char* fileName);
	~File();

	void readMode();
	void writeMode();
	void close();

	void getFloat(float *value);

private :
	std::fstream file;
	const char* fileName;
	FileMode fileMode;

};

