
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define janela_altura 800
#define janela_largura 1000

float tx = 0.0;
float tiroy = 0.0;
float ty = 0;
int cont = 0;
float tirox;
int nvidas = 3;
double tamanho_vida = 380;
int dispara = 0;
float xStep = 3;
float yStep = 10;
double mov = 1;
int i;
int linha1 = 1;
int linha2 = 4;
int linha3 = 8;
int colocanavsInicio = 0;
char gameover[50];
BOOLEAN ativa1[20] = { true };
BOOLEAN ativa2[20] = { true };
BOOLEAN ativa3[20] = { true };
int navea1[15] = { 0 };
int naveb1[15] = { 0 };
int navea2[15] = { 0 };
int naveb2[15] = { 0 };

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void anima(int valor);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(50, 0); // posicao que surge a janela
	glutCreateWindow("MegaMania"); // cria janela
								   //glutFullScreen();
	glutReshapeFunc(tela); // configura a tela
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard); // chama teclado
	glutTimerFunc(150, anima, 1);
	glutMainLoop(); // redesenhar
	return(0);
}

void barravida() {

	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(-500, -500);
	glVertex2f(500, -500);
	glVertex2f(500, -250);
	glVertex2f(-500, -250);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -20, 0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-120, -330);
	glVertex2f(380, -330);
	glVertex2f(380, -280);
	glVertex2f(-120, -280);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -20, 0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-120, -330);
	glVertex2f(tamanho_vida, -330);
	glVertex2f(tamanho_vida, -280);
	glVertex2f(-120, -280);
	glEnd();
	glPopMatrix();

}

void anima(int valor)
{
	if (!colocanavsInicio) {

		for (linha1 = 0; linha1 < 5; linha1++) {

			ativa1[linha1] = { true };
		}
		for (linha2 = 5; linha2 < 9; linha2++) {

			ativa2[linha2] = { true };
		}
		for (linha3 = 9; linha3 < 14; linha3++) {

			ativa3[linha3] = { true };
		}
		colocanavsInicio = 1;
	}

	if (tamanho_vida <= -120)
	{
		tamanho_vida = -120;
		nvidas--;
		tamanho_vida = 380;
	}
	tamanho_vida -= 1.6;

	if ((tx) > (100) || (tx) < (-100))
	{
		xStep = -xStep;
	}


	tx += xStep;
	glutPostRedisplay();
	glutTimerFunc(15, anima, 1);

}

void desenhaTiro() {

	tiroy += yStep;

	if (tiroy >= 400) {
		tiroy = 0;
		dispara = 0;
		tirox = mov;
	}

	glLineWidth(4);
	glColor3f(0.0, 0.7, 0.0);
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex2f(0 + tirox, -160 + tiroy);
	glVertex2f(0 + tirox, -170 + tiroy);
	glEnd();
	glPopMatrix();

	for (int linha1 = 0; linha1 < 5; linha1++) {
		if (tirox >= navea1[linha1] && tirox <= naveb1[linha1] && tiroy == 240 && ativa1[linha1] == true) {

			dispara = 0;
			tiroy = 0;
			tirox = mov;
			ativa1[linha1] = false;
			cont++;
		}
	}

	for (int linha2 = 5; linha2 < 9; linha2++) {
		if (tirox >= navea2[linha2] && tirox <= naveb2[linha2] && tiroy == 290 && ativa2[linha2] == true) {

			dispara = 0;
			tiroy = 0;
			tirox = mov;
			ativa2[linha2] = false;
			cont++;
		}
	}

	for (int linha3 = 9; linha3 < 14; linha3++) {
		if (tirox >= navea1[linha3] && tirox <= naveb1[linha3] && tiroy == 340 && ativa3[linha3] == true) {

			dispara = 0;
			tiroy = 0;
			tirox = mov;
			ativa3[linha3] = false;
			cont++;
		}
	}

}


void keyboard(unsigned char tecla, int x, int y)
{
	if (tecla == 'd')
	{
		mov += 12;
	}
	if (tecla == 'a')
	{
		mov -= 12;
	}
	if (tecla == 'w')
	{
		dispara = 1;
	}
	if (dispara == 0) {
		tirox = mov;
	}
}

void desenhaNaveInimiga() {
	int pos1;
	int pos2;
	int pos3;
	int dis = 0;
	int dis1 = 0;
	int dis2 = 0;

	for (linha1 = 0; linha1 < 5; linha1++) {

		if (ativa1[linha1] == true) {
			glColor3f(0.0f, 0.7f, 0.0f);
		}
		else {
			glColor3f(0.0f, 0.0f, 0.0f);
		}

		glPushMatrix();
		glTranslatef(tx, 0, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(-280 + dis1, 70);
		glVertex2f(-260 + dis1, 60);
		glVertex2f(-230 + dis1, 60);
		glVertex2f(-210 + dis1, 70);
		glVertex2f(-230 + dis1, 80);
		glVertex2f(-260 + dis1, 80);
		glEnd();
		glPopMatrix();

		pos1 = (-280 + dis1 + tx);
		navea1[linha1] = { pos1 };

		pos2 = (-210 + dis1 + tx);
		naveb1[linha1] = { pos2 };

		dis1 += 100;

	}

	for (linha2 = 5; linha2 < 9; linha2++) {

		if (ativa2[linha2] == true) {
			glColor3f(0.0f, 0.7f, 0.0f);
		}
		else {
			glColor3f(0.0f, 0.0f, 0.0f);
		}

		glPushMatrix();
		glTranslatef(tx, 0, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(-235 + dis2, 120);
		glVertex2f(-215 + dis2, 110);
		glVertex2f(-185 + dis2, 110);
		glVertex2f(-165 + dis2, 120);
		glVertex2f(-185 + dis2, 130);
		glVertex2f(-215 + dis2, 130);
		glEnd();
		glPopMatrix();

		pos1 = (-235 + dis2 + tx);
		navea2[linha2] = { pos1 };

		pos2 = (-165 + dis2 + tx);
		naveb2[linha2] = { pos2 };

		dis2 += 100;

	}

	for (linha3 = 9; linha3 < 14; linha3++) {

		if (ativa3[linha3] == true) {
			glColor3f(0.0f, 0.7f, 0.0f);
		}
		else {
			glColor3f(0.0f, 0.0f, 0.0f);
		}

		glPushMatrix();
		glTranslatef(tx, 0, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(-280 + dis, 170);
		glVertex2f(-260 + dis, 160);
		glVertex2f(-230 + dis, 160);
		glVertex2f(-210 + dis, 170);
		glVertex2f(-230 + dis, 180);
		glVertex2f(-260 + dis, 180);
		glEnd();
		glPopMatrix();

		pos1 = (-280 + dis + tx);
		navea1[linha3] = { pos1 };

		pos2 = (-210 + dis + tx);
		naveb1[linha3] = { pos2 };

		dis += 100;
	}

}

void desenhaVidas() {
	int m = 0;

	for (int i = 1; i <= nvidas; i++)
	{

		glPushMatrix();
		glTranslatef(-400, -150, 0);
		glColor3f(0.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
		glVertex2f(-30 + m, -190);
		glVertex2f(-25 + m, -190);
		glVertex2f(-25 + m, -170);
		glVertex2f(-30 + m, -170);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(30 + m, -190);
		glVertex2f(25 + m, -190);
		glVertex2f(25 + m, -170);
		glVertex2f(30 + m, -170);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(-5 + m, -190);
		glVertex2f(5 + m, -190);
		glVertex2f(5 + m, -160);
		glVertex2f(-5 + m, -160);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(-30 + m, -182);
		glVertex2f(30 + m, -182);
		glVertex2f(30 + m, -175);
		glVertex2f(-30 + m, -175);
		glEnd();
		glPopMatrix();

		m += 70;
	}

	glColor3f(0, 1, 0);
	sprintf_s(gameover, "%s", "Vidas");
	glRasterPos3d(-360, -280, 0);
	for (i = 0; gameover[i] != '\0'; ++i)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameover[i]);

	glColor3f(0, 1, 0);
	sprintf_s(gameover, "%s", "Energia");
	glRasterPos3d(0, -280, 0);
	for (i = 0; gameover[i] != '\0'; ++i)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameover[i]);

}

void desenhaNave() {
	glPushMatrix();
	glColor3f(0.0f, 0.7f, 0.0f);
	glTranslatef(mov, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-30, -190);
	glVertex2f(-25, -190);
	glVertex2f(-25, -170);
	glVertex2f(-30, -170);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(30, -190);
	glVertex2f(25, -190);
	glVertex2f(25, -170);
	glVertex2f(30, -170);
	glEnd();



	glBegin(GL_QUADS);
	glVertex2f(-5, -190);
	glVertex2f(5, -190);
	glVertex2f(5, -160);
	glVertex2f(-5, -160);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-30, -182);
	glVertex2f(30, -182);
	glVertex2f(30, -175);
	glVertex2f(-30, -175);
	glEnd();
	glPopMatrix();
}

void desenhar()
{

	glLoadIdentity();
	glTranslatef((janela_largura) / 2, (janela_altura) / 2, 0); // Especificar o local aonde o desenho acontece: bem no centro da janela

	glColor3f(0.0, 0.7, 0.0);

	desenhaNaveInimiga();
	desenhaNave();
	barravida();
	desenhaVidas();

	if (dispara == 1) {
		desenhaTiro();
	}
	if (nvidas <= 0) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0, 1, 0);
		sprintf_s(gameover, "%s", "Game Over!");
		glRasterPos3d(-4, 0, 0);
		for (i = 0; gameover[i] != '\0'; ++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameover[i]);
	}
	if (cont >= 14) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0, 1, 0);
		sprintf_s(gameover, "%s", "Ganhou");
		glRasterPos3d(-4, 0, 0);
		for (i = 0; gameover[i] != '\0'; ++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameover[i]);
	}
}

void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT);
	// Especificar o local aonde o desenho acontece: bem no centro da janela mais translacao
	//glTranslatef(janela_largura / 2, janela_altura/2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush(); // execute o desenho
}
void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);

}

