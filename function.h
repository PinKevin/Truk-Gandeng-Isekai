#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

// base bentuk
void Balok(float Lx, float Rx, float Ty, float Bty, float Fz, float Bz);

// buat truk
void Roda(float red1, float green1, float blue1);
void Sopir(float red1, float green1, float blue1, float red2, float green2, float blue2);
void Kontainer(float red1, float green1, float blue1);
void bawahKontainer(float red1, float green1, float blue1, float red2, float green2, float blue2);
void Kait(float red1, float green1, float blue1);
void RodaKontainer2(float red2, float green2, float blue2);
void TrukTotal(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3);

// pemandangan
void Grid(); 
void Jalan();
void GarisJalan();
void JalanTotal();
void Trotoar(int N, float red1, float green1, float blue1, float red2, float green2, float blue2);
void Palang(int N, float red1, float green1, float blue1, float red2, float green2, float blue2);
void PelengkapPalang(float red1, float green1, float blue1, float Rc, float Gc, float Bc);
void TiangListrik(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3);
void KabelListrik(float red1, float green1, float blue1, float JarakTiang);
void Gedung3(float red1, float green1, float blue1, float red2, float green2, float blue2, float red3, float green3, float blue3);
void Gedung2(float red1, float green1, float blue1, float red2, float green2, float blue2); 

// environment
void lighting();
void glShadowProjection(float * l, float * e, float * n);

// display
void display();

// keyboard
void pressKey(int key, int x, int y);
void releaseKey(int key, int x, int y);
void pressKeyNormal(unsigned char key, int x, int y);

// kamera
void Reshape(int w1, int h1);
void orientMe(float ang);
void moveMeFlat(int i); 
void KameraAtasFix();


// cek
int CekTabrak(float depanB, float blkgB, float kiriB, float kananB);
#endif
