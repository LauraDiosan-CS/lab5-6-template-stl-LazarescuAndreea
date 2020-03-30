#include "magazin.h"
#include "repoSTL.h"
#include <assert.h>

void testRepo()
{
	Repo repo;
	assert(repo.get_size() == 0);
}