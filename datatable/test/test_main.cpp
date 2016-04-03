#include <gtest/gtest.h>


int main(int argc, char **argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtSetBreakAlloc(316743);
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}