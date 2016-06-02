//Oras(denumire, judet)
#include "TestPom.h"
#include "TestOras.h"
#include "TestRepo.h"
#include "TestController.h"
#include "UI.h"
int main()
{
	testPom();
	testOras();
	testRepoIntreg();
	testrepoOras();
	testrepoPom();
	testController();
	UI u;
	u.menu();
}