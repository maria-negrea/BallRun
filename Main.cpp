//random comment
#include"Ball.h"
#include"Plant.h"
Textures textures;

void Initialize() 
{
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glEnable(GL_BLEND);
 gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 30.0);
}

void Draw()
{
	glMatrixMode(GL_MODELVIEW);
	/*
	 Ball *newBall = new Ball();
	 newBall->Draw(); */ 
	 Plant *newPlant=new Plant();
	 newPlant->Draw();
}

void main()
{
	//textures.LoadGLTextures();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(768, 768);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("BallRun");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop(); 
}