/*Libreria usada solo en Windows - debe ir antes que las demás librerias*/
#include<windows.h>

/*Libreria del OpenGL*/
#include<GL/glut.h>
#include <math.h>
#include <iostream>



void draw(void)

{

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);

	/*Estas variables son usadas para generar la Linea con DDA
	Algunas pueden llegar a ser usadas igual en el algoritmo de Bresenham
	*/

	double Xini;
	double Xfin;
	double Yini;
	double Yfin;



	/*Se les otorga un valor a cada variable a través de consola*/


	std::cout << "Ingresar X inicial: ";
	std::cin >> Xini;
	std::cout << "Ingresar Y inicial: ";
	std::cin >> Yini;
	std::cout << "Ingresar X final: ";
	std::cin >> Xfin;
	std::cout << "Ingresar Y final: ";
	std::cin >> Yfin;

	/*Estas variables son usadas para generar la linea don Bresenham*/

	int i = 0;
	int e = 0;
	int XiniB = Xini;
	int YiniB = Yini;
	int XfinB = Xfin;
	int YfinB = Yfin;
	int Dx = abs(XfinB - XiniB);
	int Dy = abs(YfinB - YiniB);
	int x = 0;
	int y = 0;
	int end = 0;
	int P = 2 * Dy - Dx;
	/*Este es el proceso algoritmico*/

	/*Este es el delta para DDA*/
	
	float dx = Xfin - Xini;
	float dy = Yfin - Yini;


	
	float m = dy / dx;
	float Steps = 0;
	
	if (dx > dy) {
		Steps = dx;
	}
	else {
		Steps = dy;
	}

	double Xinc = dx / Steps;
	double Yinc = dy / Steps;

		glColor3f(0, 0, 255);
		glPointSize(5);
		glVertex2i(Xini+50, Yini);
		
		glColor3f(0, 0, 255);
		glPointSize(5);
		glVertex2i(Xfin, Yfin);
		


	for (int i = 0; i < Steps; i++) {
		Xini = Xini + Xinc;
		Yini = Yini + Yinc;
		glColor3f(0, 0, 255);
		glPointSize(5);
		glVertex2i(Xini, Yini);
		
	}
 
	/*Este es el proceso para Bresenham*/

	if (XiniB > XfinB) {
		x = XfinB;
		y = YfinB;
		end = XiniB;
	}
	else {
		x = XiniB;
		y = YiniB;
		end = XfinB;
	}
	glColor3f(255, 0, 0);
	glVertex2i(x+10, y);

	while (x <= end)
	{
		if (P < 0)
		{
			x++;
			P = P + 2 * Dy;
		}
		else
		{
			x++;
			y++;
			P = P + 2 * (Dy - Dx);
		}
		glColor3f(255, 0, 0);
		glVertex2i(x+10, y);	
	}

/*	int incx = 0;
	int incy = 0;
	int inc1 = 0;
	int inc2 = 0;
	if (Dx < 0) {
		Dx = -Dx;
	}
	if (Dy < 0) {
		Dx = -Dx;
	}
	incy = 1;

	

	if (XfinB < XiniB) {
		incx = -1;
		
	}
	incy = 1;
	if (YfinB < YiniB) {
		incy = -1;
	}
	x = XiniB;
	y = YiniB;


	if (Dx > Dy) {
		glColor3f(255, 0, 0);
		glVertex2i(x, y);

		e = 2 * Dy - Dx;
		inc1 = 2 * (Dy - Dx);
		inc2 = 2 * Dy;
		for (i = 0; i < Dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else {
				e += inc2;

			}
			x += incx;
			glColor3f(255, 0, 0);
			glVertex2i(x, y);

		}
	}
	else {
		glColor3f(255, 0, 0);
		glVertex2i(x, y);
		
		e = 2 * Dx - Dy;
		inc1 = 2 * (Dx - Dy);
		inc2 = 2 * Dx;
		for (i = 0; i < Dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else {
				e += inc2;
			}
			y += incy;
			glColor3f(255, 0,0 );
			glVertex2i(x, y);
		}
	}
	*/

	glEnd();

	glFlush();

}

int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(800, 800);

	glutInitWindowPosition(300, 100);

	glutCreateWindow("Generando una linea con DDA y Bresenham");

	glClearColor(1.0,1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0, 800, 0, 800);

	glutDisplayFunc(draw);

	glutMainLoop();

	
}