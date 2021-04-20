/*
 * DemoWindow.cpp
 *
 *  Created on: 19 ���. 2021 �.
 *      Author: kompU510
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST);// ������� ������������� ����������� ����


	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// ���� ������ �� ���������
			double(width()) / double(height()),	// ����������� ������
			0.1,								// ���������� �� ������� ��
			20.0);								// ���������� �� ������� ��
	glMatrixMode(GL_MODELVIEW);
}

void funcKUB () {  // �������
	glBegin(GL_QUADS);

		glNormal3d(  0.,  0.,  -1.);
		glColor3d(1.0, 0.0, 0.0);		// ������ �����, �������
		glVertex3d(  1.,  1., -1.);
		glVertex3d( -1.,  1., -1.);
		glVertex3d( -1., -1., -1.);
		glVertex3d(  1., -1., -1.);

		glNormal3d(  0.,  0., 1.);
		glColor3d(0.0, 1.0, 1.0);		// ������� �����, ���������
		glVertex3d( -1.,  1.,  1.);
		glVertex3d(  1.,  1.,  1.);
		glVertex3d(  1., -1.,  1.);
		glVertex3d( -1., -1.,  1.);

		glNormal3d(  1.,  0.,  0.);
		glColor3d(0.0, 1.0, 0.0);		// ������� �����1, �����
			glVertex3d(1.0, -1.0,  1.0);
			glVertex3d( 1.0, 1.0,  1.0);
			glVertex3d( 1.0,  1.0,  -1.0);
			glVertex3d(1.0,  -1.0,  -1.0);

			glNormal3d( -1.,  0.,  0.);
			glColor3d(1.0, 0.0, 1.0);		// ������� �����2, �������
					glVertex3d(-1.0, 1.0,  1.0);
					glVertex3d( -1.0, -1.0,  1.0);
					glVertex3d( -1.0,  -1.0,  -1.0);
					glVertex3d(-1.0,  1.0,  -1.0);

					glNormal3d(  0.,  1.,  0.);
			glColor3d(1.0, 1.0, 1.0);		// ������� �����3, �����
					glVertex3d(-1.0, 1.0,  1.0);
					glVertex3d( 1.0, 1.0,  1.0);
					glVertex3d( 1.0,  1.0,  -1.0);
					glVertex3d(-1.0,  1.0,  -1.0);

					glNormal3d(  0., -1.,  0.);
					glColor3d(0.0, 0.0, 0.0);		// ������� �����4, ������
							glVertex3d(1.0, -1.0,  1.0);
							glVertex3d( -1.0, -1.0,  1.0);
							glVertex3d( -1.0,  -1.0,  -1.0);
							glVertex3d(1.0,  -1.0,  -1.0);
							glEnd();
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �������

	glPushMatrix(); // ��������� ������� ����������

	gluLookAt(	16.0, 10.0, 6.0,		// ���������� ������
			   7.0, 0.0, 0.0,		// ���������� ������
				0.0, 0.0, 1.0);		// ����������� �����,	MV = C


	glTranslated(4.0, 0.0, 0.0);		//// ���������� �� ��� � �� 4.0 (������ ��� 1)
	funcKUB ();							//������� ��������� ������
	glTranslated(4.0, 0.0, 0.0);		//  (������ ��� 2)
	funcKUB ();
	glTranslated(4.0, 0.0, 0.0);		// (������ ��� 3)
	funcKUB ();

	glTranslated(-2.0, 0.0, 2.0);		// (������� ��� 1)
	funcKUB ();
	glTranslated(-2.0, 0.0, 2.0);		// (������� ��� 1)
	funcKUB ();
	glTranslated(-2.0, 0.0, -2.0);		// (������� ��� 2)
	funcKUB ();


	glPopMatrix(); // ������������ � ������ ������� ���������

	/* TODO: ������� ��� ��������������� ������
		 * - �������� ���������� ����� ����
		 * - ��������, ������ ��� � ������� ���� ������������ �����������
		 * - ��������� ���������, ����� ��� ����� ��������� ������������
		 * - ����������� � ��������� ����������������:
		 * 		~ ������������ �������;
		 * 		~ �������;
		 * 		~ ���������������.
		 * - ����������� � ��������� glPushMatrix() � glPopMatrix()
		 * - ��������� �� ������� ���������:
		 *          +-+
		 *          |X|
		 *        +-+ +-+
		 *        |X| |X|
		 *      +-+ +-+ +-+
		 *      |X| |X| |X|
		 *      +-+ +-+ +-+
		 */

	glEnd();
}

void DemoWindow::update()
{
	_cube_angle += 0.1;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
