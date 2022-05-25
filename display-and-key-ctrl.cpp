#include <GL/glut.h>
#include <stdio.h>
#include "function.h"


float l[] = { 0.0, 20.0, 10.0 }; // koordinat sumber cahaya
float n[] = { 0.0, -20.0, 0.0 };
float e[] = { 0.0, 0.002, 0.0 };

float angle = 0.0, deltaAngle = 0.0;
int deltaMove = 0 ;

float posTrukX = 0.0, posTrukZ = 0.0;
int hadapTruk = 0, cekHadapTruk = 0;

float rotPalang = 0.0;
int cekPalang = 0, PlgRc = 1, PlgGc = 0, PlgBc = 0;

int nLstrk = 14;
int nGdg = 6;
int loopJalan = 20;

void display() 
{
	// Kalau move dan angle tidak nol, gerakkan kamera...
	if (deltaMove)
	moveMeFlat(deltaMove);
	
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.53f, 0.8f, 0.92f, 1.0f);
	glDisable(GL_CULL_FACE);
	
	glEnable(GL_LIGHTING);
	// Gambar Jalan
	glPushMatrix();
		for (int k = 1; k <= loopJalan; k++) {
			JalanTotal();
			glTranslatef(-24, 0, 0);
		}
	glPopMatrix();
	
	// Trotoar Kiri
	glPushMatrix();
		glTranslatef(0, 0, 10);
		for (int k = 1; k <= loopJalan; k++) {
			Trotoar(6, 1, 1, 1, 0, 0, 0);
			glTranslatef(-48, 0, 0);
		}
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 0, 20);
		for (int k = 1; k <= loopJalan; k++) {
			Trotoar(6, 0, 0, 0, 1, 1, 1);
			glTranslatef(-48, 0, 0);
		}
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-14, 0, 20);
		Trotoar(2, 0, 0, 0, 1, 1, 1);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-14, 0, -458);
		Trotoar(2, 1, 1, 1, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glEnable(GL_TEXTURE_2D);
		for (int k = 1; k <= loopJalan; k++) {
			if (k == 1) {
				Balok(-4, 18, 1, 0, 10, 18);	
				glTranslatef(-24, 0, 0);
			} else if (k == loopJalan) {
				Balok(-2, 22, 1, 0, 10, 18);	
				glTranslatef(-24, 0, 0);
			} else {
				Balok(-4, 22, 1, 0, 10, 18);	
				glTranslatef(-24, 0, 0);	
			}
		}
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	// Trotoar Kanan
	glPushMatrix();
		glTranslatef(0, 0, -24);
		for (int k = 1; k <= loopJalan; k++) {
			Trotoar(6, 0, 0, 0, 1, 1, 1);
			glTranslatef(-48, 0, 0);
		}
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 0, -34);
		for (int k = 1; k <= loopJalan; k++) {
			Trotoar(6, 1, 1, 1, 0, 0, 0);
			glTranslatef(-48, 0, 0);
		}
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(30, 0, 20);
		Trotoar(2, 0, 0, 0, 1, 1, 1);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(30, 0, -458);
		Trotoar(2, 1, 1, 1, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		for (int k = 1; k <= loopJalan; k++) {
			if (k == 1) {
				Balok(-4, 18, 1, 0, -26, -34);	
				glTranslatef(-24, 0, 0);
			} else if (k == loopJalan) {
				Balok(-2, 22, 1, 0, -26, -34);	
				glTranslatef(-24, 0, 0);
			} else {
				Balok(-4, 22, 1, 0, -26, -34);	
				glTranslatef(-24, 0, 0);	
			}
		}
	glPopMatrix();
	
	
	//gambar aseli cuy 
	glPushMatrix();
		glPushMatrix();
			glTranslatef(-50.5, 2.3, 5);
			glRotatef(rotPalang, 1, 0, 0);
			glTranslatef(0.0, -2, -2);
			Palang(7, 1, 0, 0, 1, 1, 1);	
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-50.5, 0, 3);
			PelengkapPalang(0.6, 0.6, 0.6, PlgRc, PlgGc, PlgBc);
			glTranslatef(-0.999, 0, 0);
			PelengkapPalang(0.6, 0.6, 0.6, PlgRc, PlgGc, PlgBc);
		glPopMatrix();
		// halang rintang
		glPushMatrix();
			glColor3f(0.64, 0.46, 0.31);
			Balok(-150, -155, 5, 0, 3, -3);
			Balok(-190, -195, 5, 0, -13, -19);
			Balok(-230, -235, 5, 0, -5, -11);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(posTrukX, 0, posTrukZ);
			glRotatef(hadapTruk, 0, 1, 0);
			TrukTotal(
				0, 1, 0,
				1, 1, 0,
				0.1, 0.1, 0.1
			);
		glPopMatrix();
		// tiang kiri
		glPushMatrix();
			glTranslatef(14.75, 0, 6);
			glRotatef(90, 0, 1, 0);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.6, 0.6, 0.6, 0.2, 0.2, 0.2, 1, 1, 0);
				if (i < nLstrk) {
					KabelListrik(0.1, 0.1, 0.1, -36);
				}
				glTranslatef(0, 0, -36);	
			}
		glPopMatrix();
		// tiang kanan
		glPushMatrix();
			glRotatef(270, 0, 1, 0);
			glTranslatef(-22, 0, 452.75);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.6, 0.6, 0.6, 0.2, 0.2, 0.2, 1, 1, 0);
				if (i < nLstrk) {
					KabelListrik(0.1, 0.1, 0.1, -36);
				}
				glTranslatef(0, 0, -36);	
			}
		glPopMatrix();
		// gedung kiri
		glPushMatrix();
			glTranslatef(16, 0, 20.001);
			for (int k = 1; k <= nGdg; k++) {
				if (k == nGdg) {
					Gedung2(0, 0.1, 1.0, 0, 1, 0);
					break;
				}
				Gedung3(0, 0.1, 1.0, 0, 1, 0, 1, 0, 0);
				glTranslatef(-85.1, 0, 0);
			}
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			Balok(16, 20, 40, 0, 50, 20);
		glPopMatrix();
		// gedung kanan
		glPushMatrix();
			glRotatef(180, 0, 1, 0);
			glTranslatef(460, 0, 36.001);
			for (int k = 1; k <= nGdg; k++) {
				if (k == nGdg) {
					Gedung2(0, 0.1, 1.0, 0, 1, 0);
					break;
				}
				Gedung3(0, 0.1, 1.0, 0, 1, 0, 1, 0, 0);
				glTranslatef(-85.1, 0, 0);
			}
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(0, 0, -86);
			Balok(15.4001, 20, 40, 0, 50, 20);
		glPopMatrix();
		// gedung blkg truk
		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(50, 0, 20.001);
			Gedung3(1, 1, 1, 0, 1, 1, 1, 1, 0);
		glPopMatrix();
		// gedung ujung
		glPushMatrix();
			glRotatef(270, 0, 1, 0);
			glTranslatef(30, 0, 460.001);
			Gedung3(1, 1, 1, 0, 1, 1, 1, 1, 0);
		glPopMatrix();
	glPopMatrix();
	
	
	// gambar shadow
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glShadowProjection(l, e, n);
		glPushMatrix();
			glTranslatef(-50.5, 2.3, 5);
			glRotatef(rotPalang, 1, 0, 0);
			glTranslatef(0.0, -2, -2);
			Palang(7, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);	
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-50.5, 0, 3);
			PelengkapPalang(0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
			glTranslatef(-0.999, 0, 0);
			PelengkapPalang(0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
		glPopMatrix();
		// halang rintang
		glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			Balok(-150, -155, 5, 0, 3, -3);
			Balok(-190, -195, 5, 0, -13, -19);
			Balok(-230, -235, 5, 0, -5, -11);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(posTrukX, 0, posTrukZ);
			glRotatef(hadapTruk, 0, 1, 0);
			TrukTotal(
				0.2, 0.2, 0.2,
				0.2, 0.2, 0.2,
				0.2, 0.2, 0.2
			);
		glPopMatrix();
		// tiang kiri
		glPushMatrix();
			glTranslatef(14.75, 0, 6);
			glRotatef(90, 0, 1, 0);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				if (i < nLstrk) {
					KabelListrik(0.2, 0.2, 0.2, -36);
				}
				glTranslatef(0, 0, -36);	
			}
		glPopMatrix();
		// tiang kanan
		glPushMatrix();
			glTranslatef(-22, 0, 452.75);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				if (i < nLstrk) {
					KabelListrik(0.2, 0.2, 0.2, -36);
				}
				glTranslatef(0, 0, -36);	
			}
		glPopMatrix();
		// gedung kiri
		glPushMatrix();
			glTranslatef(16, 0, 20.001);
			for (int k = 1; k <= nGdg; k++) {
				if (k == nGdg) {
					Gedung2(0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
					break;
				}
				Gedung3(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				glTranslatef(-85.1, 0, 0);
			}
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			Balok(16, 20, 40, 0, 50, 20);
		glPopMatrix();
		// gedung kanan
		glPushMatrix();
			glRotatef(180, 0, 1, 0);
			glTranslatef(460, 0, 36.001);
			for (int k = 1; k <= nGdg; k++) {
				if (k == nGdg) {
					Gedung2(0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
					break;
				}
				Gedung3(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				glTranslatef(-85.1, 0, 0);
			}
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(0, 0, -86);
			Balok(15.4001, 20, 40, 0, 50, 20);
		glPopMatrix();
		// gedung blkg truk
		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(50, 0, 20.001);
			Gedung3(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
		glPopMatrix();
		// gedung ujung
		glPushMatrix();
			glRotatef(270, 0, 1, 0);
			glTranslatef(30, 0, 460.001);
			Gedung3(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
		glPopMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}

void pressKey(int key, int x, int y) 
{
	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.015f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.015f; break;
		case GLUT_KEY_UP : deltaMove = 5; break;
		case GLUT_KEY_DOWN : deltaMove = -5; break;
	}
}

void releaseKey(int key, int x, int y) 
{
	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
	// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
	switch (key) {
		case GLUT_KEY_LEFT :
			if (deltaAngle < 0.0f)
				deltaAngle = 0.0f;
				break;
		case GLUT_KEY_RIGHT : 
			if (deltaAngle > 0.0f)
				deltaAngle = 0.0f;
				break;
		case GLUT_KEY_UP : if (deltaMove > 0)
			deltaMove = 0;
			break;
		case GLUT_KEY_DOWN : if (deltaMove < 0)
			deltaMove = 0;
			break;
	}
}

void pressKeyNormal(unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
		case 'r':
			posTrukX = 0;
			posTrukZ = 0;
			break;
			
		// gerakan truk
		case 'w' :
			if (posTrukX > -457) {
				posTrukX -= 1;
			} else {
				posTrukX = -457;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-65.5, -90.5, 1, -17) == 1)  {
					posTrukX = -65.5;
				}
			}
			
			if (CekTabrak(-146, -175, 1, -8) == 1)  {
					posTrukX = -146;
			} else if (CekTabrak(-186, -215, -8, -17) == 1)  {
					posTrukX = -186;
			} else if (CekTabrak(-226, -255, -7, -9) == 1)  {
					posTrukX = -226;
			}
				
			printf("posTrukX = %f\n", posTrukX);
			break;
			
		case 's':
			if (posTrukX < 0) {
				posTrukX += 1;
			} else {
				posTrukX = 0;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-65.5, -90.5, 1, -17) == 1)  {
					posTrukX = -90.5;
				}	
			} 
			
			if (CekTabrak(-146, -175, 1, -8) == 1)  {
					posTrukX = -175;
			} else if (CekTabrak(-186, -215, -8, -17) == 1)  {
					posTrukX = -215;
			} else if (CekTabrak(-226, -255, -7, -9) == 1)  {
					posTrukX = -255;
			}
			
			printf("posTrukX = %f\n", posTrukX);
			break;
			
		case 'a':
			if (posTrukZ < 0) {
				posTrukZ += 8;	
			}
			
			if (CekTabrak(-146, -175, 1, -8) == 1)  {
					posTrukZ = -8;
			} else if (CekTabrak(-226, -255, -7, -9) == 1)  {
					posTrukZ = -16;
			}
			
			printf("posTrukZ = %f\n", posTrukZ);
			break;
			
		case 'd':
			if (posTrukZ > -16) {
				posTrukZ -= 8;	
			}
			
 			if (CekTabrak(-186, -215, -8, -17) == 1)  {
					posTrukZ = -8;
			} else if (CekTabrak(-226, -255, -7, -9) == 1)  {
					posTrukZ = 0;
			}
			
			printf("posTrukZ = %f\n", posTrukZ);
			break;

		// gerakan palang
		case 'z':
			if (rotPalang >= 0 && rotPalang < 90) {
				rotPalang += 3;	
			} else {
				rotPalang = 90;
			}
			
			if (rotPalang == 90) {
				cekPalang = 1;
				PlgRc = 0, PlgGc = 1, PlgBc = 0;
			} else {
				cekPalang = 0;
				PlgRc = 1, PlgGc = 0, PlgBc = 0;
			}
			
			printf("rotPalang = %f\n", rotPalang);
			break;
		case 'x':
			if (rotPalang > 0 && rotPalang <= 90) {
				rotPalang -= 3;	
			} else {
				rotPalang = 0;
			}
			
			if (rotPalang == 90) {
				cekPalang = 0;
				PlgRc = 1, PlgGc = 0, PlgBc = 0;
			} else {
				cekPalang = 0;
				PlgRc = 1, PlgGc = 0, PlgBc = 0;
			}
			
			printf("rotPalang = %f\n", rotPalang);
			break;
	}
}

int CekTabrak(float depanB, float blkgB, float kiriB, float kananB) {
	if ((posTrukX < depanB && posTrukX > blkgB) && (posTrukZ < kiriB && posTrukZ > kananB)) { // cek maju
		return 1;
	} else {
		return 0;
	}
}
