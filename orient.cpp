#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "function.h"

float x = 0.0f, y = 1.75f, z = 15.0f; // posisi awal kamera
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float ratio;
int h, w;

void Reshape(int w1, int h1)
{
	// Fungsi reshape
	if (h1 == 0) h1 = 1;
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f
	);
}

void orientMe(float ang)
{
	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(
		x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f
	);
}

void moveMeFlat(int i)
{
	// Fungsi ini untuk maju mundur kamera
	x = x + i * (lx) * 0.1;
	z = z + i * (lz) * 0.1;
	glLoadIdentity();
	gluLookAt(
		x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f
	);
}

void KameraAtasFix() {
	gluLookAt(
		10.0f, 5.0f, 3.0f,
		x, y, z,
		0.0f, 1.0f, 0.0f
	);
}
