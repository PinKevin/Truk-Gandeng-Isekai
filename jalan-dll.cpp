#include <GL/glut.h>
#include <stdio.h>
#include "function.h"

void Jalan() {
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_QUADS);
			glVertex3f(-4, 0, -24);
			glVertex3f(-4, 0, 8);
			glVertex3f(20, 0, 9);	
			glVertex3f(20, 0, -24);		
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
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(-4, 0.001, -20.25);
			glVertex3f(-4, 0.001, -19.65);
			glVertex3f(20, 0.001, -19.65);	
			glVertex3f(20, 0.001, -20.25);	
		glEnd();
		glTranslatef(0, 0, 24);
		glBegin(GL_QUADS);
			glVertex3f(-4, 0.001, -20.25);
			glVertex3f(-4, 0.001, -19.65);
			glVertex3f(20, 0.001, -19.65);	
			glVertex3f(20, 0.001, -20.25);	
		glEnd();
	glPopMatrix();
}

void JalanTotal() {
	Jalan();
	GarisJalan();
}

void Trotoar(int N, float red1, float green1, float blue1, float red2, float green2, float blue2) {
	for (int j = 1; j <= N; j++) {
			glColor3f(red1, green1, blue1);
			glBegin(GL_QUADS); 
				glVertex3f(-4.0f, 1.0f, 0.0f);
				glVertex3f(-4.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
			glEnd();
			glBegin(GL_QUADS); 
				glVertex3f(-4.0f, 1.0f, -2.0f);
				glVertex3f(-4.0f, 0.0f, -2.0f);
				glVertex3f(-2.0f, 0.0f, -2.0f);
				glVertex3f(-2.0f, 1.0f, -2.0f);
			glEnd();
			if (j == 1) {
				glBegin(GL_QUADS); 
					glVertex3f(-4.0f, 1.0f, -2.0f);
					glVertex3f(-4.0f, 0.0f, -2.0f);
					glVertex3f(-4.0f, 0.0f, 0.0f);
					glVertex3f(-4.0f, 1.0f, 0.0f);
				glEnd();
			}
			glBegin(GL_QUADS); 
				glVertex3f(-4.0f, 1.0f, -2.0f);
				glVertex3f(-4.0f, 1.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, -2.0f);
			glEnd();
			glBegin(GL_QUADS); 
				glVertex3f(-4.0f, 0.0f, -2.0f);
				glVertex3f(-4.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 0.0f, -2.0f);
			glEnd();
			
			glColor3f(red2, green2, blue2);
			glBegin(GL_QUADS); 
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
			glEnd();
			glBegin(GL_QUADS); 
				glVertex3f(-2.0f, 0.0f, -2.0f);
				glVertex3f(-2.0f, 1.0f, -2.0f);
				glVertex3f(0.0f, 1.0f, -2.0f);
				glVertex3f(0.0f, 0.0f, -2.0f);
			glEnd();
			if (j == N) {
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 1.0f, -2.0f);
					glVertex3f(0.0f, 0.0f, -2.0f);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 1.0f, 0.0f);
				glEnd();
			}
			glBegin(GL_QUADS); 
				glVertex3f(-2.0f, 1.0f, -2.0f);
				glVertex3f(-2.0f, 1.0f, 0.0f);
				glVertex3f(-0.0f, 1.0f, 0.0f);
				glVertex3f(-0.0f, 1.0f, -2.0f);
			glEnd();
			glBegin(GL_QUADS); 
				glVertex3f(-2.0f, 0.0f, -2.0f);
				glVertex3f(-2.0f, 0.0f, 0.0f);
				glVertex3f(-0.0f, 0.0f, 0.0f);
				glVertex3f(-0.0f, 0.0f, -2.0f);
			glEnd();
			
			
			glTranslatef(4, 0, 0);
		}
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
			if (j == N) {
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

void TiangListrik(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3) {
	// tengah
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-3.5, -2.5, 14, 1, 0.5, 0);
		glColor3f(red2, green2, blue2);
		Balok(-3.5, -2.5, 14, 15, 0.5, 0);
	glPopMatrix();
	// pucuk kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-5.5, -4.5, 13, 14, 0.5, 0);
		glColor3f(red2, green2, blue2);
		Balok(-5.5, -4.5, 14, 15, 0.5, 0);
	glPopMatrix();
	// penghubung kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-5.5, -3.5, 12, 13, 0.5, 0);
	glPopMatrix();
	glPushMatrix();
		Balok(-2.5, 8, 12, 13, 0.5, 0);
		glColor3f(red3, green3, blue3);
		Balok(6, 8, 11, 12, 0.5, 0);
	glPopMatrix();
	
}

void KabelListrik(float red1, float green1, float blue1, float JarakTiang) {
	// kabel tengah
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-3.15, -2.85, 14.25, 14.75, 0, JarakTiang);
	glPopMatrix();
	// kabel kiri
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-5.25, -4.85, 14.25, 14.75, 0, JarakTiang);
	glPopMatrix();
} 

void Gedung3(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3) {
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-30, 0, 40, 0, 30, 0);
		glColor3f(red2, green2, blue2);
		Balok(-50, -30.1, 25, 0, 30, 0);
		glColor3f(red3, green3, blue3);
		Balok(-85, -50.1, 35, 0, 30, 0);
	glPopMatrix();
}

void Gedung2(float red1, float green1, float blue1, float red2, float green2, float blue2) {
	glPushMatrix();
		glColor3f(red1, green1, blue1);
		Balok(-30, 0, 40, 0, 30, 0);
		glColor3f(red2, green2, blue2);
		Balok(-50, -30.1, 25, 0, 30, 0);
	glPopMatrix();
}

