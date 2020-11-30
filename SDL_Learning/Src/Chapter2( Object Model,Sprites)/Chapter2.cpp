#include"Application2.h"
#include "Chapter2.h"

void SDLChapter3::Play()
{
	SDLChapter3::Application2 application{ 1024,720 };

	bool success = application.Intialize();

	if (success)
	{
		application.RunLoop();
	}

	application.Shutdown();
}
