#include "FileUtil.h"

FileUtil::FileUtil(std::string fileName)
{
	//������� ������� ����
	readStream.open(fileName);
	if (!readStream.is_open())
	{
		std::cout << "Cannot open file!\n";
	}
}

VectorsInfo FileUtil::getVectorsFromFile()
{
	VectorsInfo vec;
	try
	{
		if (!readStream)
		{
			throw "Trying to get vectors from non-existing file!";
		}
		
		std::string line;
		while(std::getline(readStream,line)) //���� ���� ������, ������� ����� ���������
		{
			std::vector<int> tempVector; //������ ��� �������� � ������ ������ � vec

			//��������� ������
			int i = 1, j  =0; // i - ����� �����; j - ������ �����
			while (line[i-1] != 0 and line[i-1] != '\n')
			{
				if (line[i] == ',' or line[i] == '\n' or line[i] == 0)
				{
					tempVector.push_back(std::stoi(line.substr(j, i))); //������ ���� �� �����������
					j = i + 1;
				}
				i++;
			}

			//������ � vec ������
			vec.vectors.push_back(tempVector);
			vec.count = tempVector.size();
			tempVector.clear();
		}

	}
	catch (const char* err_message)
	{
		std::cout << err_message << '\n';
	}
	return vec;
}