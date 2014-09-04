//random comment
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

void Draw()
{
	 Ball *newBall = new Ball();
	 newBall->Draw();
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(768, 768);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("BallRun");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop(); 
}