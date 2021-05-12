﻿#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
void putpixel(GLfloat x, GLfloat y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void bred(float x1, float x2, float y1, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float d = -2 * dy + dx;
	float dtren = -2 * dy + 2 * dx;
	float dduoi = -2 * dy;
	float x, y;
	x = x1;
	y = y1;
	while (x < x2) {
		if (d > 0) {
			x++;
			d = d + dduoi;
		}
		else {
			x++;
			y++;
			d = d + dtren;
		}
		putpixel(x/10, y/10);
	}
}
void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(20);
	/*glBegin(GL_LINES);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();*/
	//putpixel(0, 0.5);
	bred(3,13,1,9);
	glFlush();
}
void init() {
	glClearColor(1,1,1,1);

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	init();
	glClearColor(0.0, 0.0, 0.0, 1.0);   //GL 상태변수 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}