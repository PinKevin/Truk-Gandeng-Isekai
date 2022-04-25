#include <GL/glut.h>
#include <stdio.h>
#include "function.h"

void Grid() 
{
	// Fungsi untuk membuat grid di "lantai"
	double i;
	const float Z_MIN = -50, Z_MAX = 50;
	const float X_MIN = -50, X_MAX = 50;
	const float gap = 1.5;
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	for(i = Z_MIN; i < Z_MAX; i+=gap)
	{
		glVertex3f(i, 0, Z_MIN);
		glVertex3f(i, 0, Z_MAX);
	}
	
	for(i = X_MIN; i < X_MAX; i+=gap)
	{
		glVertex3f(X_MIN, 0, i);
		glVertex3f(X_MAX, 0, i);
	}
	glEnd();
}

void Jalan() {
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_QUADS);
			glVertex3f(-4, 0, -20);
			glVertex3f(-4, 0, 4);
			glVertex3f(20, 0, 4);	
			glVertex3f(20, 0, -20);		
		glEnd();
	glPopMatrix();
}

void GarisJalan() {
	glPushMatrix();
		glColor3f(1, 1, 1);
		for (int j = 1; j <= 6; j++) {
			glBegin(GL_QUADS);
				glVertex3f(-4, 0.001, -4.25);
				glVertex3f(-4, 0.001, -3.65);
				glVertex3f(-2, 0.001, -3.65);	
				glVertex3f(-2, 0.001, -4.25);		
			glEnd();
			glTranslatef(4.4, 0, 0);
		}
	glPopMatrix();
	glPushMatrix();
		for (int k = 1; k <= 6; k++) {
			glBegin(GL_QUADS);
				glVertex3f(-4, 0.001, -12.25);
				glVertex3f(-4, 0.001, -11.65);
				glVertex3f(-2, 0.001, -11.65);	
				glVertex3f(-2, 0.001, -12.25);		
			glEnd();
			glTranslatef(4.4, 0, 0);
		}
	glPopMatrix();
}

void JalanTotal() {
	Jalan();
	GarisJalan();
}

void Palang(int N, float red1, float green1, float blue1, float red2, float green2, float blue2) {
	// palang
	glPushMatrix(); 
		glTranslatef(-19, 1, 0);
		glRotatef(90, 0, 1, 0);
		
		for (int j = 1; j <= N; j++) {
			glColor3f(red1, green1, blue1);
			glBegin(GL_QUADS); // merah depan
				glVertex3f(-4.0f, 1.0f, 0.0f);
				glVertex3f(-4.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
			glEnd();
			glBegin(GL_QUADS); // merah belakang
				glVertex3f(-4.0f, 1.0f, -0.5f);
				glVertex3f(-4.0f, 0.0f, -0.5f);
				glVertex3f(-2.0f, 0.0f, -0.5f);
				glVertex3f(-2.0f, 1.0f, -0.5f);
			glEnd();
			if (j == 1) {
				glBegin(GL_QUADS); // merah samping
					glVertex3f(-4.0f, 1.0f, -0.5f);
					glVertex3f(-4.0f, 0.0f, -0.5f);
					glVertex3f(-4.0f, 0.0f, 0.0f);
					glVertex3f(-4.0f, 1.0f, 0.0f);
				glEnd();
			}
			glBegin(GL_QUADS); // merah atas
				glVertex3f(-4.0f, 1.0f, -0.5f);
				glVertex3f(-4.0f, 1.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, -0.5f);
			glEnd();
			glBegin(GL_QUADS); // merah bawah
				glVertex3f(-4.0f, 0.0f, -0.5f);
				glVertex3f(-4.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, -0.5f);
			glEnd();
			
			glColor3f(red2, green2, blue2);
			glBegin(GL_QUADS); // putih depan
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
			glEnd();
			glBegin(GL_QUADS); // putih belakang
				glVertex3f(-2.0f, 0.0f, -0.5f);
				glVertex3f(-2.0f, 1.0f, -0.5f);
				glVertex3f(0.0f, 1.0f, -0.5f);
				glVertex3f(0.0f, 0.0f, -0.5f);
			glEnd();
			if (j == 4) {
				glBegin(GL_QUADS); // putih samping
					glVertex3f(0.0f, 1.0f, -0.5f);
					glVertex3f(0.0f, 0.0f, -0.5f);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 1.0f, 0.0f);
				glEnd();
			}
			glBegin(GL_QUADS); // putih atas
				glVertex3f(-2.0f, 1.0f, -0.5f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(-0.0f, 1.0f, 0.0f);
				glVertex3f(-0.0f, 1.0f, -0.5f);
			glEnd();
			glBegin(GL_QUADS); // putih bawah
				glVertex3f(-2.0f, 0.0f, -0.5f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-0.0f, 0.0f, 0.0f);
				glVertex3f(-0.0f, 0.0f, -0.5f);
			glEnd();
			
			
			glTranslatef(4, 0, 0);
		}
		
	glPopMatrix();
}

void PelengkapPalang(float red1, float green1, float blue1, float Rc, float Gc, float Bc) {
	// apit palang
	glPushMatrix();
		glTranslatef(-18.999, 0, -2);
		glRotatef(90, 0, 1, 0);
		glColor3f(red1, green1, blue1);
		Balok(-4, -3, 2.5, 0, 0.5, 0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-18.999, 0, -2);
		glRotatef(90, 0, 1, 0);
		glColor3f(Rc, Gc, Bc);
		Balok(-4, -3, 3, 2.499, 0.5, 0);
	glPopMatrix();
}

void TiangListrik(float red1, float green1, float blue1, float red2, float green2, float blue2) {
	// tengah
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-3, -2, 7, 0, 0.5, 0);
		glColor3f(red2, green2, blue2);
		Balok(-3, -2, 7, 8, 0.5, 0);
	glPopMatrix();
	// pucuk kanan
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-1, 0, 6, 7, 0.5, 0);
		glColor3f(red2, green2, blue2);
		Balok(-1, 0, 7, 8, 0.5, 0);
	glPopMatrix();
	// pucuk kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-5, -4, 6, 7, 0.5, 0);
		glColor3f(red2, green2, blue2);
		Balok(-5, -4, 7, 8, 0.5, 0);
	glPopMatrix();
	// penghubung kanan
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-2, 0, 5, 6, 0.5, 0);
	glPopMatrix();
	// penghubung kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-5, -3, 5, 6, 0.5, 0);
	glPopMatrix();
}

void KabelListrik(float red1, float green1, float blue1, float JarakTiang) {
	// kabel tengah
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-2.65, -2.35, 7.25, 7.75, 0, JarakTiang);
	glPopMatrix();
	// kabel kanan
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-0.65, -0.35, 7.25, 7.75, 0, JarakTiang);
	glPopMatrix();
	// kabel kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-4.65, -4.35, 7.25, 7.75, 0, JarakTiang);
	glPopMatrix();
} 

void Gedung(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3) {
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-30, 0, 40, 0, 30, 0);
		glColor3f(red2, green2, blue2);
		Balok(-50, -35, 25, 0, 20, 0);
		glColor3f(red3, green3, blue3);
		Balok(-85, -55, 35, 0, 20, 0);
	glPopMatrix();
}

