#include"Ball.h"

Textures* Textures::instance = NULL;

void Initialize() 
{
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glEnable(GL_BLEND);
 gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 30.0);

 Textures::GetInstance()->LoadGLTextures();
}

 Ball *newBall = new Ball(0.0, 0.0, 0.0, 0.3);
 Point3D point;

void Draw()
{

	 newBall->Draw();
	 glMatrixMode(GL_MODELVIEW);
}

void specialKey(int key, int x, int y) { 

	switch(key) 
	{
	case GLUT_KEY_RIGHT :
		point = Point3D(0.05, 0, 0);
		break;

	case GLUT_KEY_LEFT :
		point = Point3D(-0.05, 0, 0);
		break;
	}

	glutPostRedisplay();
}

void Timer(int value)
{
	newBall->Translate(point);
	newBall->Rotate(Point3D(15, 0, 0));
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	//textures.LoadGLTextures();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(768, 768);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("BallRun");
	Initialize();
	glutDisplayFunc(Draw);

	glutSpecialFunc(specialKey);
	glutTimerFunc(30, Timer, 0);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}