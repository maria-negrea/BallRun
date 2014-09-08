#include "Highway.h"

Highway::Highway(void)
{
	lastRoad = new Road(Point3D(0.0, 0.0, 1.0));
	roads.push_back(lastRoad);
	nextCorner = NULL;

}

Highway::~Highway(void)
{
}


void Highway::CheckPossibilities()
{
	if((leftRoad->GetTranslate() - ball->GetTranslate()).Magnitude() < 5.0)
	{
		lastRoad = leftRoad;
	}
	if((rightRoad->GetTranslate() - ball->GetTranslate()).Magnitude() < 5.0)
	{
		lastRoad = rightRoad;
	}
}


bool Highway::CanMoveLeft (Point3D &point)
{
	if(nextCorner == NULL)
		return false;
	if(nextCorner->CanMoveLeft(ball))
	{
		point = nextCorner->GetPoint();

		nextCorner = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

bool Highway::CanMoveRight(Point3D &point)
{
	if(nextCorner == NULL)
		return 0;
	if(nextCorner->CanMoveRight(ball))
	{
		point = nextCorner->GetPoint();

		nextCorner = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

bool Highway::IsOffRoad()
{
	if(nextCorner != NULL)
	{
		GLfloat radius = nextCorner->GetRadius();
		if((nextCorner->GetPoint()-ball->GetDirection()*radius*2 - ball->GetTranslate()).Magnitude() < radius)
		{
			return true;
		}
	}
	return false;
}

void Highway::Follow(Ball* ball)
{
	this->ball = ball;
}

void Highway::Update()
{
	if(lastRoad == NULL)
	{
		CheckPossibilities();
	}
	else
	{
		Point3D endRoad = lastRoad->GetEndPoint();
		if((endRoad - ball->GetTranslate()).Magnitude() < 15.0)
		{
			Road *newRoad = new Road(lastRoad->GetTranslate());
			roads.push_back(newRoad);

			newRoad->Rotate(lastRoad->GetRotate());

			int random = rand() % 7;
			
		   if(random == 0) 
		   {
				newRoad->Rotate(Point3D(0.0, 90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22+lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,false,true);
				lastRoad = newRoad;
		   }
		   else if(random == 1) 
		   {
				newRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,false);
				lastRoad = newRoad;
		   }
		   else if(random == 2)
		   {
				Road *otherRoad = new Road(lastRoad->GetTranslate());
				roads.push_back(otherRoad);
				otherRoad->Rotate(lastRoad->GetRotate());

				otherRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				otherRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				newRoad->Rotate(Point3D(0.0, 90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22+lastRoad->GetRight()*22);
				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,true);

				lastRoad = NULL;
				leftRoad = newRoad;
				rightRoad = otherRoad;
		   }
		   else
		   {
				newRoad->Translate(lastRoad->GetForward()*40);
				lastRoad = newRoad;
		   }

			int nr = roads.size() - 15;
			for(int i = 0; i < nr; i++)
			{
				roads.erase(roads.begin());
			}
		}
	}
}

void Highway::DrawObject()
{
	for(int i=0;i<roads.size();i++)
	{
		roads[i]->Draw();
	}
}