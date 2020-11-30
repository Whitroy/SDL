#include"Application1.h"
#include"PingPong.h"
namespace SDLChapter1
{
	void Play()
	{
		Application1 application{ 1024,720 };

		bool success = application.Intialize();

		if (success)
		{
			application.RunLoop();
		}

		application.Shutdown();
	}
}
