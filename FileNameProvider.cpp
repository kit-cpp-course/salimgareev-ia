/*
 *FileNameProvider.cpp
 */
#include "FileNameProvider.h"

std::string FileNameProvider::GetInputFileName() const
{
	if (_args.size() >= 2)
	{
		return std::string{ _args[1] };
	}
	else
	{
		return "ExampleInputData.txt";
	}
}
std::string FileNameProvider::GetOutputFileName() const
{
	if (_args.size() >= 3)
	{
		return std::string{ _args[2] };
	}
	else
	{
		return "ExampleOutputData.txt";
	}
}