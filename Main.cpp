#include"Ball.h"
#include"Camera.h"

Textures* Textures::instance = NULL;

void Initialize() 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_BLEND);
	gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 100.0);

	Textures::GetInstance()->LoadGLTextures();
}

Camera *mainCamera = new Camera();
Point3D point;
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.01, 0.3);

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mainCamera->Follow(*newBall);
	mainCamera->Perspective();

	newBall->Draw();
	glMatrixMode(GL_MODELVIEW);

	glFlush();
}

void specialKey(int key, int x, int y) { 

	switch(key) 
	{
		case GLUT_KEY_RIGHT :
			newBall->MoveRight();
			break;

		case GLUT_KEY_LEFT :
			newBall->MoveLeft();
			break;
	}

	glutPostRedisplay();
}

void Timer(int value)
{
	newBall->MoveForward();
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