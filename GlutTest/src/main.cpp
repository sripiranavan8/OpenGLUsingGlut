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
#include "Shapes/TestEllipse.h"

#include "Lines/Bresenham.h"
#include "Lines/DDA.h"

#include "Curves/Bezier.h"

Position start, finish;
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

static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
static float f = 0.0f;
static int counter = 0;
static const char *shapes[] = { "Line","Triangle","Quads","Square","Circle","Ellipse","Circle1","DDA","Bresenham" };
static const char *selectedItem = NULL;
static bool clear_window = false;

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui::Begin("Window");

	if (ImGui::BeginCombo("Select the Shape", selectedItem, ImGuiComboFlags_HeightRegular))
	{
		for (int n = 0; n < IM_ARRAYSIZE(shapes); n++)
		{
			bool is_selected = (selectedItem == shapes[n]);
			if (ImGui::Selectable(shapes[n], is_selected))
			{
				selectedItem = shapes[n];
			}
			if (is_selected)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
	ImGui::Checkbox("Clear Window", &clear_window);
	if (selectedItem)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		double w = glutGet(GLUT_WINDOW_WIDTH);
		double h = glutGet(GLUT_WINDOW_HEIGHT);
		glOrtho(0, w, h, 0, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		ImGui::ColorEdit3("clear color", (float*)&clear_color);
		glColor4f(clear_color.x, clear_color.y, clear_color.z, clear_color.w);

		if (selectedItem == "Line")
		{
			Line line;
			line.DrawLine(start, finish);
		}
		else if (selectedItem == "Triangle")
		{
			Triangle triangle;
			triangle.DrawTriangle(start, finish);
		}
		else if (selectedItem == "Quads")
		{
			Quads quads;
			quads.DrawQuads(start, finish);
		}
		else if (selectedItem == "Square")
		{
			Square square;
			square.DrawSquare(start, finish);
		}
		else if (selectedItem == "Circle")
		{
			Circle circle;
			circle.DrawCircle(start, finish);
		}
		else if (selectedItem == "Ellipse")
		{
			TestEllipse ellip;
			ellip.DrawEllipse(start, finish);
		}
		else if (selectedItem == "Circle1")
		{
			TestEllipse ellip1;
			ellip1.DrawCircle(start, finish);
		}
		else if (selectedItem == "Bresenham")
		{
			Bresenham bresen;
			bresen.bresenham_spoke(start, finish);
		}
		else if (selectedItem == "DDA")
		{
			DDA dda;
			dda.dda_star_draw(start, finish);
		}
	}
	ImGui::End();
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT");
	//createMenu();
	glutDisplayFunc(glut_display_func);


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