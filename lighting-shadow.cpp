#include <GL/glut.h>
#include "function.h"

// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting() 
{
	// Fungsi mengaktifkan pencahayaan
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);	
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void glShadowProjection(float * l, float * e, float * n)
{
	float d, c;
	float mat[16];
	d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
	c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;
	mat[0] = l[0]*n[0]+c; // membuat matrik. OpenGL menggunakan kolom matrik
	mat[4] = n[1]*l[0];
	mat[8] = n[2]*l[0];
	mat[12] = -l[0]*c-l[0]*d;
	mat[1] = n[0]*l[1];
	mat[5] = l[1]*n[1]+c;
	mat[9] = n[2]*l[1];
	mat[13] = -l[1]*c-l[1]*d;
	mat[2] = n[0]*l[2];
	mat[6] = n[1]*l[2];
	mat[10] = l[2]*n[2]+c;
	mat[14] = -l[2]*c-l[2]*d;
	mat[3] = n[0];
	mat[7] = n[1];
	mat[11] = n[2];
	mat[15] = -d;
	glMultMatrixf(mat); // kalikan matrik
}
