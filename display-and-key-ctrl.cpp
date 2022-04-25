#include <GL/glut.h>
#include <stdio.h>
#include "function.h"

float l[] = { 0.0, 20.0, 10.0 }; // koordinat sumber cahaya
float n[] = { 0.0, -40.0, 0.0 };
float e[] = { 0.0, 0.0, 0.0 };

float angle = 0.0, deltaAngle = 0.0;
int deltaMove = 0 ;

float posTrukX = 0.0, posTrukZ = 0.0;
int hadapTruk = 0, cekHadapTruk = 0;

float rotPalang = 0.0;
int cekPalang = 0, PlgRc = 1, PlgGc = 0, PlgBc = 0;

int nLstrk = 10;
int nGdg = 10;

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
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_CULL_FACE);
	// Gambar grid
	Grid();
	glPushMatrix();
		for (int k = 1; k <= 20; k++) {
			JalanTotal();
			glTranslatef(-18, 0, 0);
		}
	glPopMatrix();
	
	
	//gambar aseli cuy 
	glPushMatrix();
		glPushMatrix();
			glTranslatef(0.0, 2.3, 2);
			glRotatef(rotPalang, 1, 0, 0);
			glTranslatef(0.0, -2, -2);
			Palang(4, 1, 0, 0, 1, 1, 1);	
		glPopMatrix();
		glPushMatrix();
			PelengkapPalang(0.6, 0.6, 0.6, PlgRc, PlgGc, PlgBc);
			glTranslatef(-0.999, 0, 0);
			PelengkapPalang(0.6, 0.6, 0.6, PlgRc, PlgGc, PlgBc);
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
		glPushMatrix();
			glTranslatef(-20, 0, 6);
			glRotatef(90, 0, 1, 0);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.6, 0.6, 0.6, 0.2, 0.2, 0.2);
				if (i < nLstrk) {
					KabelListrik(0.1, 0.1, 0.1, -30);
				}
				glTranslatef(0, 0, -30);	
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 0, 30);
			for (int k = 1; k <= nGdg; k++) {
				Gedung(0, 0.1, 1.0, 0, 1, 0, 1, 0, 0);
				glTranslatef(-90, 0, 0);
			}
		glPopMatrix();
	glPopMatrix();
	
	// gambar shadow
	glPushMatrix();
		glShadowProjection(l, e, n);
		glColor3f(0.4, 0.4, 0.4);
		glPushMatrix();
			glTranslatef(0.0, 2, 2);
			glRotatef(rotPalang, 1, 0, 0);
			glTranslatef(0.0, -2, -2);
			Palang(4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4);	
		glPopMatrix();
		glPushMatrix();
			PelengkapPalang(0.4, 0.4, 0.4, 0.4, 0.4, 0.4);
			glTranslatef(-0.999, 0, 0);
			PelengkapPalang(0.4, 0.4, 0.4, 0.4, 0.4, 0.4);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(posTrukX, 0, posTrukZ);
			glRotatef(hadapTruk, 0, 1, 0);
//			TrukTotal(
//				0.2, 0.2, 0.2,
//				0.2, 0.2, 0.2,
//				0.2, 0.2, 0.2
//			);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-20, 0, 6);
			glRotatef(90, 0, 1, 0);
			for (int i = 1; i <= nLstrk; i++) {
				TiangListrik(0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				if (i < nLstrk) {
					KabelListrik(0.2, 0.2, 0.2, -30);
				}
				glTranslatef(0, 0, -30);	
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 0, 30);
			for (int k = 1; k <= nGdg; k++) {
				Gedung(0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
				glTranslatef(-90, 0, 0);
			}
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
		case GLUT_KEY_UP : deltaMove = 3; break;
		case GLUT_KEY_DOWN : deltaMove = -3; break;
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
			
		case 'p' :
			KameraAtasFix();
			break;
		// gerakan truk
		case 'w' :
			if (cekHadapTruk == 0) {
				posTrukX -= 1;
			} else {
				posTrukX += 1;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-15.5, -39.5, 7.5, -15.5) == 1)  {
					posTrukX = -15.5;
				}	
			} else if (cekPalang == 1) {
				if (CekTabrak(-15.5, -39.5, 5.5, -2.5) == 1)  {
					posTrukX = -15.5;
				}
			}		
				
			printf("posTrukX = %f\n", posTrukX);
			break;
		case 's':
			if (cekHadapTruk == 0) {
				posTrukX += 0.5;
			} else {
				posTrukX -= 0.5;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-15.5, -39.5, 7.5, -15.5) == 1)  {
					posTrukX = -39.5;
				}	
			} else if (cekPalang == 1) {
				if (CekTabrak(-15.5, -39.5, 5.5, -2.5) == 1)  {
					posTrukX = -39.5;
				}
			}
			
			printf("posTrukX = %f\n", posTrukX);
			break;
		case 'a':
			if (cekHadapTruk == 0) {
				posTrukZ += 8;
			} else {
				posTrukZ -= 8;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-15.5, -39.5, 7.5, -15.5) == 1)  {
					posTrukZ = -15.5;
				}	
			} else if (cekPalang == 1) {
				if (CekTabrak(-15.5, -39.5, 5.5, -2.5) == 1)  {
					posTrukZ = -2.5;
				}
			}
			
			printf("posTrukZ = %f\n", posTrukZ);
			break;
		case 'd':
			if (cekHadapTruk == 0) {
				posTrukZ -= 8;
			} else {
				posTrukZ += 8;
			}
			
			if (cekPalang == 0) {
				if (CekTabrak(-15.5, -39.5, 7.5, -15.5) == 1)  {
					posTrukZ = 7.5;
				}	
			} else if (cekPalang == 1) {
				if (CekTabrak(-15.5, -39.5, 5.5, -2.5) == 1)  {
					posTrukZ = 5.5;
				}
			}
			
			printf("posTrukZ = %f\n", posTrukZ);
			break;
		case 'l':
			hadapTruk = 180;
			cekHadapTruk = 1;
			break;
		case 'k':
			hadapTruk = 0;
			cekHadapTruk = 0;
			break;
			
		// gerakan barang
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




//int CekTabrakMundur() {
//	if ((posTrukX < -16 && posTrukX > -40.5) && (posTrukZ < 4.5 && posTrukZ > -4.5)) { // cek mundur
//		return 1;
//	}
//}
