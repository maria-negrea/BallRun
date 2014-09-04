//random comment
#include"Ball.h"

Textures textures;

void Initialize() 
{
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glEnable(GL_BLEND);
 glOrtho(0.0, 1.0, 0.0, 1.0, -5.0, 5.0);
 gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 30.0);
}

void Draw()
{
	 Ball *newBall = new Ball(0.0, 0.0, 0.0, 0.3);
	 newBall->Draw();
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
	glutMainLoop(); 

	return 0;
}