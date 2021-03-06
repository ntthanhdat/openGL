
#include<Windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <iostream>
using namespace std;
int spin = 0;




void draw() {
	glEnable(GL_LIGHTING);


	glEnable(GL_DEPTH_TEST);

	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	//vẽ trục tọa độ
	gluLookAt(0.0, 10.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//DrawCoordinate();

	//glLoadIdentity();
	GLfloat light_pos0[] = { 1.0, 0.0, 0.0, 0.0 };  //Vị trí thứ 0 ánh sáng chiếu vào
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);
	GLfloat light_ambient0[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse0[] = { 0.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular0[] = { 0.0, 1.0, 1.0, 1.0 };
	GLfloat light_position0[] = { 0.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	GLfloat light_pos1[] = { 1.0, 0.0, 0.0, 0.0 };  //Vị trí thứ 1 ánh sáng chiếu vào
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	//hai cái ấm to
	glPushMatrix();  //push
	glEnable(GL_LIGHT0);
	glTranslatef(-4, 0, 0);
	glRotatef(spin, 0, 1, 0);
	glutSolidTeapot(2.0);
	glLoadIdentity();
	glDisable(GL_LIGHT0);
	glPopMatrix();   //pop

	glPushMatrix();  //push
	glEnable(GL_LIGHT1);
	glTranslatef(4, 0, 0);
	glRotatef(spin, 0, -1, 0);
	glutSolidTeapot(2.0);
	glDisable(GL_LIGHT1);
	glPopMatrix(); //pop

//hai cái ấm bé

	//GLfloat light_diffuse2[] = { 0.0, 1.0, 0.0, 1.0 };
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
	//GLfloat light_diffuse3[] = { 0.0, 0.0, 1.0, 1.0 };
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse3);

	glPushMatrix();  //push
	glEnable(GL_LIGHT0);
	glTranslatef(4, -5, 0);
	glRotatef(spin, 0, 1, 0);
	glutSolidTeapot(2.0);
	glDisable(GL_LIGHT0);
	glPopMatrix();   //pop

	glPushMatrix();  //push
	glEnable(GL_LIGHT1);
	glTranslatef(-4, -5, 0);
	glRotatef(spin, 0, -1, 0);
	glutSolidTeapot(2.0);
	glDisable(GL_LIGHT1);
	glPopMatrix();   //pop
	spin += 1;
	if (spin > 360)
	{
		spin = spin - 360;
	}

	glutSwapBuffers();
	glutPostRedisplay();



	glFlush();
}



void ReShape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)w / (float)h;
	gluPerspective(45.0, ratio, 1, 100.0);
	//glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Thuc-hanh-1");


	glutDisplayFunc(draw);
	glutReshapeFunc(ReShape);
	glutMainLoop();
}