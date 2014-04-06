
#include <Arc/MemoryTracker.h>

#include "Defines.h"
#include "Game.h"
#include "Tests.h"

#if defined(_WOE_DIRECTX)

#define NOGDI

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#endif

using Arc::MemoryTracker;

#if defined(_WOE_DIRECTX)

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{

#elif defined(_WOE_OPENGL)

int main( int argc, char* argv[] )
{

#endif

#if defined(_WOE_DEBUG)

	Arc::Arc_InitMemoryTracker();

#endif

	Log::AddInfoOutput("stdout");
	Log::AddErrorOutput("stderr");

	Log::AddInfoOutput("info.log", false);
	Log::AddErrorOutput("error.log", false);

#if defined(WOE_UNIT_TESTS)

	WOE_RunTests();

#endif

	Game::Instance()->start();

	Game::Destroy();

#if defined(_WOE_DEBUG)

	if (Arc::Arc_GetMemoryAllocationCount() > 0)
	{
		Arc::Arc_PrintMemoryAllocations();

		system("PAUSE");
	}

#endif

	return 0;
}