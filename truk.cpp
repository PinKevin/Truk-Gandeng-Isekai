#include <math.h>
#include "function.h"
#include <iostream>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int i, j, radius, jumlah_titik, x_tengah, y_tengah;
const double PI = 3.141592653589793;

void Roda(float red1, float green1, float blue1)
{
	// tapak roda
	glPushMatrix();
		for(int j = 0; j <= 360; j++) {
			glPushMatrix();
				glTranslatef(1, 0, -0.5);
				glRotated(90, 1, 0, 0);
				glRotated(j, 0, 1, 0);
				glTranslatef(0, 3, 0.8);
				glColor3f(red1, green1, blue1);
				glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(0.1, 0, 0);
					glVertex3f(0.1, 0.6, 0);
					glVertex3f(0, 0.6, 0);
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();

	// roda bagian depan
	glPushMatrix();
		glTranslatef(0, 0, 3.1);
		glColor3f(red1, green1, blue1);
		glBegin(GL_TRIANGLE_FAN);
			radius = 80;
			jumlah_titik = 100;
			x_tengah = 100;
			y_tengah = 0;
			for (i = 0; i <= 360; i++) {
				float sudut = i * (2 * PI / jumlah_titik);
				float x = x_tengah + radius * cos(sudut);
				float y = y_tengah + radius * sin(sudut);
				glVertex2f(x/100, y/100);
			}
		glEnd();
	glPopMatrix();

	// roda bagian belakang
	glPushMatrix();
		glTranslatef(0, 0, 2.5);
		glRotated(180, 1, 0, 0);
		glColor3f(red1, green1, blue1);
		glBegin(GL_TRIANGLE_FAN);
			radius = 80;
			jumlah_titik = 100;
			x_tengah = 100;
			y_tengah = 0;
			for (i = 0; i <= 360; i++) {
				float sudut = i * (2 * PI / jumlah_titik);
				float x = x_tengah + radius * cos(sudut);
				float y = y_tengah + radius * sin(sudut);
				glVertex2f(x/100, y/100);
			}
		glEnd();
	glPopMatrix();
}

void Sopir(float red1, float green1, float blue1, float red2, float green2, float blue2)
{
	// pintu kiri
	glPushMatrix();
		glTranslatef(0, 2, 3);
		glColor3f(red1, green1, blue1);
		glBegin(GL_QUADS);
			glVertex3f(-1.0f, 2.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, 0.0f);
			glVertex3f(2.0f, -2.0f, 0.0f);
			glVertex3f(2.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0, 2, 3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-3.0f, -2.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, 0.0f);
			glVertex3f(-1.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
		
	// pintu kanan
	glPushMatrix();
		glTranslatef(0, 2, -3);
		glBegin(GL_QUADS);
			glVertex3f(-1.0f, 2.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, 0.0f);
			glVertex3f(2.0f, -2.0f, 0.0f);
			glVertex3f(2.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0, 2, -3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-3.0f, -2.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, 0.0f);
			glVertex3f(-1.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// depan spoiler
	glPushMatrix();
		glTranslatef(-3, 2, 0);
		glRotated(-90, 0, 1, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-3.0f, -2.0f, 0.0f);
			glVertex3f(3.0f, -2.0f, 0.0f);
			glVertex3f(3.0f, 0.0f, 0.0f);
		glEnd();
	glPopMatrix();

	// depan kaca
	glPushMatrix();
		glTranslatef(-3, 2, 0);
		glRotated(-90, 0, 1, 0);
		glRotated(-45, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 2.85f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 2.85f, 0.0f);
		glEnd();
	glPopMatrix();
		
	// bawah sopir
	glPushMatrix();
		glTranslatef(2, 0, 0);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-5.0f, 3.0f, 0.0f);
			glVertex3f(-5.0f, -3.0f, 0.0f);
			glVertex3f(0.0f, -3.0f, 0.0f);
			glVertex3f(0.0f, 3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas sopir
	glPushMatrix();
		glTranslatef(2, 4, 0);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 3.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(0.0f, -3.0f, 0.0f);
			glVertex3f(0.0f, 3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// roda kiri
	glPushMatrix();
		glTranslatef(-1, 0.3, 0.2);
		Roda(red2, green2, blue2);
	glPopMatrix();
	
	// roda kanan
	glPushMatrix();
		glTranslatef(-1, 0.3, -0.2);
		glRotated(180, 1, 0, 0);
		Roda(red2, green2, blue2);
	glPopMatrix();
}

void Kontainer(float red1, float green1, float blue1) 
{
	glEnable(GL_TEXTURE_2D);
	// kiri kontainer
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		glTranslatef(0, 3.5, 3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 2.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, 2.0f, 0.0f);
		glEnd();
		
	glPopMatrix();
	
	// kanan kontainer
	glPushMatrix();
		glTranslatef(0, 3.5, -3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 2.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// depan kontainer
	glPushMatrix();
		glTranslatef(-3, 3.5, 0);
		glRotated(-90, 0, 1, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 2.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(3.0f, -3.0f, 0.0f);
			glVertex3f(3.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang kontainer
	glPushMatrix();
		glTranslatef(5, 3.5, 0);
		glRotated(-90, 0, 1, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 2.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(3.0f, -3.0f, 0.0f);
			glVertex3f(3.0f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();

	// atas kontainer
	glPushMatrix();
		glTranslatef(0, 5.5, 0);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 3.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, 3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
}

void bawahKontainer(float red1, float green1, float blue1, float red2, float green2, float blue2) 
{
	// kiri kontainer
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		glTranslatef(0, 3.5, 3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(-3.0f, -3.5f, 0.0f);
			glVertex3f(5.0f, -3.5f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan kontainer
	glPushMatrix();
		glTranslatef(0, 3.5, -3);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(-3.0f, -3.5f, 0.0f);
			glVertex3f(5.0f, -3.5f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// depan kontainer
	glPushMatrix();
		glTranslatef(-3, 3.5, 0);
		glRotated(-90, 0, 1, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(-3.0f, -3.5f, 0.0f);
			glVertex3f(3.0f, -3.5f, 0.0f);
			glVertex3f(3.0f, -3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang kontainer
	glPushMatrix();
		glTranslatef(5, 3.5, 0);
		glRotated(-90, 0, 1, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(-3.0f, -3.5f, 0.0f);
			glVertex3f(3.0f, -3.5f, 0.0f);
			glVertex3f(3.0f, -3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas bawah kontainer
	glPushMatrix();
		glTranslatef(0, 0.5, 0);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 3.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, 3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// bawah bawah kontainer
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 3.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, -3.0f, 0.0f);
			glVertex3f(5.0f, 3.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// roda kiri
	glPushMatrix();
		glTranslatef(2, 0.3, 0.2);
		Roda(red2, green2, blue2);
	glPopMatrix();
	
	// roda kanan
	glPushMatrix();
		glTranslatef(2, 0.3, -0.2);
		glRotated(180, 1, 0, 0);
		Roda(red2, green2, blue2);
	glPopMatrix();
}

void Kait(float red1, float green1, float blue1) 
{	
	// bawah kait
	glPushMatrix();
		glTranslatef(0, 0, 0.5);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 1.0f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas kait
	glPushMatrix();
		glTranslatef(0, 0.5, 0.5);
		glRotated(-90, 1, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, 1.0f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri kait
	glPushMatrix();
		glTranslatef(0, 0.5, 0.5);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -0.5f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 0.0f, 0.0f);
			glVertex3f(-1.5f, -0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan kait
	glPushMatrix();
		glTranslatef(0, 0.5, -0.5);
		glBegin(GL_QUADS);
			glVertex3f(-3.0f, -0.5f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(-1.5f, 0.0f, 0.0f);
			glVertex3f(-1.5f, -0.5f, 0.0f);
		glEnd();
	glPopMatrix();
}

void RodaKontainer2(float red2, float green2, float blue2)
{
	// roda kiri
	glPushMatrix();
		glTranslatef(-2, 0.3, 0.2);
		Roda(red2, green2, blue2);
	glPopMatrix();
			
	// roda kanan
	glPushMatrix();
		glTranslatef(-2, 0.3, -0.2);
		glRotated(180, 1, 0, 0);
		Roda(red2, green2, blue2);
	glPopMatrix();
}

void TrukTotal(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3) 
{
	glPushMatrix();
		glTranslatef(0, 0.5, 0);
		Sopir(red1, green1, blue1, red3, green3, blue3);
		glPushMatrix();
			glTranslatef(5, 0, 0);
			Kontainer(red2, green2, blue2);
			bawahKontainer(red3, green3, blue3, red3, green3, blue3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(13, 0, 0);
			Kait(0.1, 0.1, 0.1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(14.5, 0, 0);
			Kontainer(red2, green2, blue2);
			bawahKontainer(red3, green3, blue3, red3, green3, blue3);
			RodaKontainer2(red3, green3, blue3);
		glPopMatrix();
	glPopMatrix();
}
