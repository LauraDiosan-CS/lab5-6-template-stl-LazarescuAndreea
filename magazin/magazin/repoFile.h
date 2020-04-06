#pragma once
#include "repoSTL.h"
template <typename T>
class RepoFile:
	public Repo<T>
{
private:
	const char* fis;
public:
	RepoFile() {};
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
};