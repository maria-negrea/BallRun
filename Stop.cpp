#include "Stop.h"
#include "Point2D.h"
#include <vector>

using namespace std;

Stop::Stop(void)
{
}

Stop::~Stop(void)
{
}

int getComb(int n, int i)
{
	if (n == i || i == 0)
		return 1;
	return (n * getComb(n - 1, i - 1)) / i;

}

double Bezier(int n, int i, double t)
{
	return (double)getComb(n, i) * pow(t, i) * pow((1 - t), (n - i));
}


void ComputeBezier(std::vector<Point2D>controlPoints, std::vector<Point2D> &bladePoints)
{
	for (double t = 0; t <= 1; t += 0.01)
	{
		Point2D s = Point2D(0., 0.);
		for(int i = 0; i < controlPoints.size(); i++)
		{
			double coef = Bezier(controlPoints.size() - 1, i, t);
			s.x += controlPoints[i].x * coef;
			s.y += controlPoints[i].y * coef;
		}
		bladePoints.push_back(s);
	}
}

void drawCurve(Point2D a, Point2D b, Point2D c, vector<Point2D> &top1, vector<Point2D> &r1) {
	top1.push_back(a);
	top1.push_back(b);
	top1.push_back(c);
	ComputeBezier(top1, r1);

	for(int i=0; i < r1.size()-1; i++) {
		glBegin(GL_LINES);
			glVertex3f( r1[i].x, r1[i].y,  -4.0);
			glVertex3f( r1[i+1].x, r1[i+1].y, -4.0);
		glEnd();
	}
}

void Stop::DrawObject() {
	/*
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f( 0.0, 0.0, -5.0);
		glTexCoord2f(1, 0); glVertex3f( 1.0, 0.0, -5.0);
		glTexCoord2f(1, 1); glVertex3f( 1.0, 1.0, -5.0);
		glTexCoord2f(0, 1); glVertex3f( 0.0, 1.0, -5.0);
	glEnd();*/
	/*glColor3f (0.0, 0.0, 0.0);*/
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[7]);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex3f( 0.5*3, 0.0*3,  -4.0);
		glVertex3f( 0.3*3, 1.0*3,  -4.0);
		glVertex3f( 0.2*3, 0.75*3, -4.0);
		glVertex3f( 0.8*3, 0.75*3, -4.0);
		glVertex3f( 0.7*3, 1.0*3,  -4.0);
		glVertex3f( 0.5*3, 1.0*3,  -4.0);

		glVertex3f( 0.2*3, 0.4*3,  -4.0);
		glVertex3f( 0.8*3, 0.4*3,  -4.0);
	glEnd();
	vector<Point2D> top1, top2, top3, r1, r2, r3, top4, r4, top5, r5, top6, r6;
	
	drawCurve(Point2D(0.3*3, 1.0*3), Point2D(0.4*3, 0.9*3), Point2D(0.5*3, 1.0*3), top1, r1);

	drawCurve(Point2D(0.5*3, 1.0*3), Point2D(0.6*3, 0.9*3), Point2D(0.7*3, 1.0*3), top2, r2);

	drawCurve(Point2D(0.2*3, 0.75*3), Point2D(0.3*3, 0.6*3), Point2D(0.2*3, 0.5*3), top3, r3);

	drawCurve(Point2D(0.8*3, 0.75*3), Point2D(0.7*3, 0.6*3), Point2D(0.8*3, 0.5*3), top4, r4);

	drawCurve(Point2D(0.2*3, 0.5*3), Point2D(0.35*3, 0.3*3), Point2D(0.5*3, 0.0*3), top5, r5);

	drawCurve(Point2D(0.8*3, 0.5*3), Point2D(0.65*3, 0.3*3), Point2D(0.5*3, 0.0*3), top6, r6);



	glBegin(GL_LINES);
		glVertex3f( 0.3*3, 1.0*3,  -4.0);
		glVertex3f( 0.2*3, 0.75*3, -4.0);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f( 0.8*3, 0.75*3, -4.0);
		glVertex3f( 0.7*3, 1.0*3,  -4.0);
	glEnd();
	
}
