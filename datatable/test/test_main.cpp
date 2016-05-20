#include <gtest/gtest.h>


int main(int argc, char **argv)
{
#if defined(_DEBUG) && defined(_WIN32)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif // DEBUG && WIN32
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}