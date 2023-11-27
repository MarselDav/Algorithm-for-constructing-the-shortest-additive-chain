#pragma once
#include <string>
#include "VectorsInfo.h"

class FileUtil
{
public:
	FileUtil(std::string fileName);

	VectorsInfo getVectorsFromFile();
};

