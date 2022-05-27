#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

void init(void)
{
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Truk Gandeng Isekai");
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardFunc(pressKeyNormal);
	glutDisplayFunc(display);
	glutIdleFunc(display); // Fungsi display-nya dipanggil terus-menerus
	glutReshapeFunc(Reshape);
	lighting();
	init();
	glutMainLoop();
	return(0);
}
