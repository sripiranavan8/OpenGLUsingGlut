#include <GL/glut.h>
#include <iostream>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glut.h"
#include "imgui/imgui_impl_opengl2.h"

#include "Shapes/Quads.h"
#include "Shapes/Triangle.h"
#include "Shapes/Line.h"
#include "Shapes/Circle.h"
#include "Shapes/Square.h"

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}
void createMenu(void) {
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Quads", 2);
	glutAddMenuEntry("Triangle", 3);
	glutAddMenuEntry("Circle", 4);
	glutAddMenuEntry("Square", 5);
	glutAddMenuEntry("Line", 6);
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("Draw", submenu_id);
	glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

Position start, finish;
static bool show_demo_window = true;
static bool Quards = false;
static bool show_another_window = false;
static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		start.x = finish.x = x;
		start.y = finish.y = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		finish.x = x;
		finish.y = y;
	}
	glutPostRedisplay();
}
void TestMouse(int glut_button, int state, int x, int y)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);
	int button = -1;
	if (glut_button == GLUT_LEFT_BUTTON) button = 0;
	if (glut_button == GLUT_RIGHT_BUTTON) button = 1;
	if (glut_button == GLUT_MIDDLE_BUTTON) button = 2;
	if (button != -1 && state == GLUT_DOWN)
		io.MouseDown[button] = true;
	if (button != -1 && state == GLUT_UP)
		io.MouseDown[button] = false;

	if (glut_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		start.x = finish.x = x;
		start.y = finish.y = y;
	}
	if (glut_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		finish.x = x;
		finish.y = y;
	}
}
void TestMotion(int x, int y)
{
	finish.x = x;
	finish.y = y;
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);
}

void motion(int x, int y)
{
	finish.x = x;
	finish.y = y;
	glutPostRedisplay();
}
static float f = 0.0f;
static int counter = 0;

void display()
{

	ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
	ImGui::Checkbox("Draw Quads", &Quards);
	if (Quards)
	{
		glBegin(GL_TRIANGLES);

		glColor3f(0.5, 0, 0);

		glVertex2f(300.0, 210.0);
		glVertex2f(340.0, 215.0);
		glVertex2f(320.0, 250.0);

		glEnd();

		glFlush();
		std::cout << "Quads True" << std::endl;
		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		double w = glutGet(GLUT_WINDOW_WIDTH);
		double h = glutGet(GLUT_WINDOW_HEIGHT);
		glOrtho(0, w, h, 0, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glColor3f(1, 1, 1);

		Quads quads;
		quads.DrawQuads(start, finish);

		glPopMatrix();

		glutPostRedisplay();*/
	}
	ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
	ImGui::Checkbox("Another Window", &show_another_window);

	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui::End();

	/*
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);
	glOrtho(0, w, h, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glColor3f(1, 1, 1);

	if (value == 1) {
		glutPostRedisplay();
	}
	else if (value == 2) {
		Quads quads;
		quads.DrawQuads(start, finish);
	}
	else if (value == 3) {
		Triangle triangle;
		triangle.DrawTriangle(start, finish);
	}
	else if (value == 4) {
		Circle circle;
		circle.DrawCircle(start, finish);
	}
	else if (value == 5) {
		Square square;
		square.DrawSquare(start, finish);
	}
	else if (value == 6)
	{
		Line line;
		line.DrawLine(start, finish);
	}
	glFlush();

	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();*/
}

void glut_display_func()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	display();

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);

	//glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}
void displayI1()
{
	

	ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
	ImGui::Checkbox("Draw Quads", &Quards);
	if (Quards)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		double w = glutGet(GLUT_WINDOW_WIDTH);
		double h = glutGet(GLUT_WINDOW_HEIGHT);
		glOrtho(0, w, h, 0, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glColor3f(1, 1, 1);

		Quads quads;
		quads.DrawQuads(start, finish);

		glPopMatrix();



		std::cout << start.x << " , " << finish.x << std::endl;
	}
	ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
	ImGui::Checkbox("Another Window", &show_another_window);

	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color


	ImGui::End();
	
}
void displayI() {  // Display function will draw the image.
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	displayI1();

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);

	//glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT");
	//createMenu();
	glutDisplayFunc(displayI);


	// Setup Dear ImGui context
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	// Setup Dear ImGui style
	//ImGui::StyleColorsDark();
	ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGLUT_Init();
	ImGui_ImplGLUT_InstallFuncs();
	glutMotionFunc(TestMotion);
	glutMouseFunc(TestMouse);
	ImGui_ImplOpenGL2_Init();
	glutMainLoop();

	//Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();

	return 0;
}