/*
 * DemoWindow.cpp
 *
 *  Created on: 19 апр. 2021 г.
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
	glEnable(GL_DEPTH_TEST);// решение неправильного отображения куба


	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// Угол обзора по вертикали
			double(width()) / double(height()),	// Соотношение сторон
			0.1,								// Расстояние до ближней ПО
			20.0);								// Расстояние до дальней ПО
	glMatrixMode(GL_MODELVIEW);
}

void funcKUB () {  // функция
	glBegin(GL_QUADS);

		glNormal3d(  0.,  0.,  -1.);
		glColor3d(1.0, 0.0, 0.0);		// Нижняя грань, красная
		glVertex3d(  1.,  1., -1.);
		glVertex3d( -1.,  1., -1.);
		glVertex3d( -1., -1., -1.);
		glVertex3d(  1., -1., -1.);

		glNormal3d(  0.,  0., 1.);
		glColor3d(0.0, 1.0, 1.0);		// Верхняя грань, бирюзовая
		glVertex3d( -1.,  1.,  1.);
		glVertex3d(  1.,  1.,  1.);
		glVertex3d(  1., -1.,  1.);
		glVertex3d( -1., -1.,  1.);

		glNormal3d(  1.,  0.,  0.);
		glColor3d(0.0, 1.0, 0.0);		// Боковая грань1, синяя
			glVertex3d(1.0, -1.0,  1.0);
			glVertex3d( 1.0, 1.0,  1.0);
			glVertex3d( 1.0,  1.0,  -1.0);
			glVertex3d(1.0,  -1.0,  -1.0);

			glNormal3d( -1.,  0.,  0.);
			glColor3d(1.0, 0.0, 1.0);		// Боковая грань2, розовая
					glVertex3d(-1.0, 1.0,  1.0);
					glVertex3d( -1.0, -1.0,  1.0);
					glVertex3d( -1.0,  -1.0,  -1.0);
					glVertex3d(-1.0,  1.0,  -1.0);

					glNormal3d(  0.,  1.,  0.);
			glColor3d(1.0, 1.0, 1.0);		// Боковая грань3, белая
					glVertex3d(-1.0, 1.0,  1.0);
					glVertex3d( 1.0, 1.0,  1.0);
					glVertex3d( 1.0,  1.0,  -1.0);
					glVertex3d(-1.0,  1.0,  -1.0);

					glNormal3d(  0., -1.,  0.);
					glColor3d(0.0, 0.0, 0.0);		// Боковая грань4, черная
							glVertex3d(1.0, -1.0,  1.0);
							glVertex3d( -1.0, -1.0,  1.0);
							glVertex3d( -1.0,  -1.0,  -1.0);
							glVertex3d(1.0,  -1.0,  -1.0);
							glEnd();
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистка

	glPushMatrix(); // сохраняем текущие координаты

	gluLookAt(	16.0, 10.0, 6.0,		// Координаты камеры
			   7.0, 0.0, 0.0,		// Координаты центра
				0.0, 0.0, 1.0);		// Направление вверх,	MV = C


	glTranslated(4.0, 0.0, 0.0);		//// сдвигаемся по оси Х на 4.0 (нижний куб 1)
	funcKUB ();							//функция рисования кубика
	glTranslated(4.0, 0.0, 0.0);		//  (нижний куб 2)
	funcKUB ();
	glTranslated(4.0, 0.0, 0.0);		// (нижний куб 3)
	funcKUB ();

	glTranslated(-2.0, 0.0, 2.0);		// (средний куб 1)
	funcKUB ();
	glTranslated(-2.0, 0.0, 2.0);		// (верхний куб 1)
	funcKUB ();
	glTranslated(-2.0, 0.0, -2.0);		// (средний куб 2)
	funcKUB ();


	glPopMatrix(); // возвращаемся к старой системе координат

	/* TODO: задание для самостоятельной работы
		 * - Добавить оставшиеся грани куба
		 * - Выяснить, почему куб в текущем виде отображается неправильно
		 * - Исправить программу, чтобы куб начал правильно отображаться
		 * - Разобраться с основными преобразованиями:
		 * 		~ параллельный перенос;
		 * 		~ поворот;
		 * 		~ масштабирование.
		 * - Разобраться с функциями glPushMatrix() и glPopMatrix()
		 * - Построить из кубиков пирамидку:
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
