#include <GL/glut.h>
#include <stdio.h>
#include "function.h"

void Balok(float Lx, float Rx, float Ty, float Bty, float Fz, float Bz) {
	glBegin(GL_QUADS); // belakang
		glVertex3f(Lx, Ty, Bz);
		glVertex3f(Lx, Bty, Bz);
		glVertex3f(Rx, Bty, Bz);
		glVertex3f(Rx, Ty, Bz);
	glEnd();
	glBegin(GL_QUADS); // depan
		glVertex3f(Lx, Ty, Fz);
		glVertex3f(Lx, Bty, Fz);
		glVertex3f(Rx, Bty, Fz);
		glVertex3f(Rx, Ty, Fz);
	glEnd();
	glBegin(GL_QUADS); // samping kiri
		glVertex3f(Lx, Ty, Bz);
		glVertex3f(Lx, Bty, Bz);
		glVertex3f(Lx, Bty, Fz);
		glVertex3f(Lx, Ty, Fz);
	glEnd();
	glBegin(GL_QUADS); // samping kanan
		glVertex3f(Rx, Ty, Bz);
		glVertex3f(Rx, Bty, Bz);
		glVertex3f(Rx, Bty, Fz);
		glVertex3f(Rx, Ty, Fz);
	glEnd();
	glBegin(GL_QUADS); // atas
		glVertex3f(Lx, Ty, Fz);
		glVertex3f(Lx, Ty, Bz);
		glVertex3f(Rx, Ty, Bz);
		glVertex3f(Rx, Ty, Fz);
	glEnd();
	glBegin(GL_QUADS); // bawah
		glVertex3f(Lx, Bty, Fz);
		glVertex3f(Lx, Bty, Bz);
		glVertex3f(Rx, Bty, Bz);
		glVertex3f(Rx, Bty, Fz);
	glEnd();
}
