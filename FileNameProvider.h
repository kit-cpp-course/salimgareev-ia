/*
 *FileNameProvider.h
 */
#pragma once
#include <vector>
#include <string>
/*
 *����� ��� ������ � ����������� ��������� ������
 */
class FileNameProvider
{
private:
	/*
	 *������ � ������� �������� ��������� �� ��������� ������
	 */
	std::vector<std::string> _args;
public:
	/*
	 *����������� ��������� ��������� ��������� ������
	 */
	FileNameProvider(int argc, char * argv[])
		: _args(argv, argv + argc) {}
	/*
	 *������� ������� ���������� �������� �������� �����
	 */
	std::string GetInputFileName() const;
	/*
	 *������� ������� ���������� �������� ��������� �����
	 */
	std::string GetOutputFileName() const;
};
