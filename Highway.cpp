#include "Highway.h"

Highway::Highway(Scene* scene)
	:scene(scene)
{
	lastRoad = new Road(Point3D(0.0, 0.0, 1.0));
	roads.push_back(lastRoad);
	nextCorner = NULL;

	newCurve = new Curve(2);
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
	if(lastRoad && (lastRoad->GetEndPoint() - ball->GetTranslate() ).Magnitude() > 30.0)
	{
		if(rand() % 5 == 0)
		{
			Plant *newPlant;
			if(rand() % 2 == 0)
				newPlant = new Cactus(1, 1, 2, 3);
			else 
				newPlant = new Tree(1, 1, 1, 4);

			if(rand() % 2 == 0)
				newPlant->Translate(ball->GetTranslate() - ball->GetDirection() * (rand() % 6 + 12) + ball->GetDirection().rotateY(90) * (rand() % 3 + 4));
			else
				newPlant->Translate(ball->GetTranslate() - ball->GetDirection() * (rand() % 6 + 12) - ball->GetDirection().rotateY(90) * (rand() % 3 + 4));

			newPlant->Rotate(Point3D(0, rand()%360, 0));

			plants.push_back(newPlant);
		}
	}

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

				delete newCurve;
				newCurve = new Curve(0);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*22);
				newCurve->Rotate(newRoad->GetRotate()*-1+Point3D(0,180,0));

				lastRoad = newRoad;
		   }
		   else if(random == 1) 
		   {
				newRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,false);

				delete newCurve;
				newCurve = new Curve(1);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*18);
				newCurve->Rotate(newRoad->GetRotate()*-1+Point3D(0,180,0));

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

				delete newCurve;
				newCurve = new Curve(2);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*22);
				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,true);
				newCurve->Rotate(otherRoad->GetRotate()*(-1) + Point3D(0.0, -90.0, 0.0));

				lastRoad = NULL;
				leftRoad = newRoad;
				rightRoad = otherRoad;
		   }
		   else
		   {
				newRoad->Translate(lastRoad->GetForward()*40);
				lastRoad = newRoad;
		   }

		    int side = rand() % 2;
			int dist = rand() % 10 + 20;

   		    Mountain *newMountain = new Mountain(rand() % 10 + 10, -rand() % 10 - 10, rand() % 10 + 10);

			if(side == 0)
				newMountain->Translate(newRoad->GetTranslate() + newRoad->GetRight() * dist);
			else 
				newMountain->Translate(newRoad->GetTranslate() - newRoad->GetRight() * dist);
			newMountain->Rotate(Point3D(0, rand() % 360, 0));
			mountains.push_back(newMountain);

			int nr = mountains.size() - 5;
			for(int i = 0; i < nr; i++)
				mountains.erase(mountains.begin());

			nr = plants.size() - 20;
			for(int i = 0; i < nr; i++)
				plants.erase(plants.begin());

			nr = roads.size() - 4;
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
	for(int i=0;i<mountains.size();i++)
	{
		mountains[i]->Draw();
	}
	for(int i=0;i<plants.size();i++)
	{
		plants[i]->Draw();
	}
	newCurve->Draw();
}