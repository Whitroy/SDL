#include "Chapter4.h"
#include"Application4.h"

void SDLChapter4::Play()
{
	SDLChapter4::Application4 application{ 1024,720 };

	bool success = application.Intialize();

	if (success)
	{
		application.RunLoop();
	}

	application.Shutdown();
}
