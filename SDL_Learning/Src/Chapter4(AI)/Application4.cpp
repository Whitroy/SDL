#include"Application4.h"
#include"Enemy.h"
#include"Grid.h"
namespace SDLChapter4
{
	Application4::Application4(int width, int height)
		:Game{ width,height }
	{
	}

	Enemy* Application4::GetNearestEnemy(const Vector2& pos)
	{
		Enemy* best = nullptr;

		if (mEnemies.size() > 0)
		{
			best = mEnemies[0];
			// Save the distance squared of first enemy, and test if others are closer
			float bestDistSq = (pos - mEnemies[0]->GetPosition()).LengthSq();
			for (size_t i = 1; i < mEnemies.size(); i++)
			{
				float newDistSq = (pos - mEnemies[i]->GetPosition()).LengthSq();
				if (newDistSq < bestDistSq)
				{
					bestDistSq = newDistSq;
					best = mEnemies[i];
				}
			}
		}

		return best;
	}

	void Application4::LoadData()
	{
		mGrid = new Grid(this);
	}
}