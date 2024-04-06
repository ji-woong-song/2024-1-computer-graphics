#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <iostream>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "..\usr\include\imgui\imgui.h"
#include "..\usr\include\imgui\imgui_impl_glfw.h"
#include "..\usr\include\imgui\imgui_impl_opengl3.h"
#include "..\usr\include\GL\glew.h"
#include "..\usr\include\glfw\glfw3.h" // Will drag system OpenGL headers

#include "imgui_graphics.h"

#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// �ܺ� ���̺귯�� ��ũ
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "..\\usr\\lib\\glfw3.lib")
#pragma comment(lib, "..\\usr\\lib\\glew32.lib")

/*! 
*	\class	ImGuiManager
*	\brief	GLFW + OpenGL3.0 ����� ImGui �������α׷� ������ ���� �Ŵ��� �̱���(singleton) Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	2024-03-04
*/
class ImGuiManager
{
public:
	/*! \biref	���� ������ ������ */
	GLFWwindow* m_Window;

private:
	/*! \biref ������ */
	ImGuiManager();

	/*! \biref �Ҹ��� */
	~ImGuiManager();

public:
	/*! 
	*	\biref	Ŭ���� ��ü�� ��ȯ�Ѵ�.
	* 
	*	\return Ŭ���� ��ü�� ��ȯ�Ѵ�.
	*/
	static ImGuiManager& Instance()
	{
		static ImGuiManager _inst;
		return _inst;
	}

	/*! \biref	GLFW �����츦 �����ϰ� ImGui�� �ʱ�ȭ �Ѵ�.	*/
	bool Init();

	/*! \biref	���ο� �������� �����Ѵ�.	*/
	void Begin();

	/*! \biref	�������� ������ �������Ѵ�. */
	void End();

	/*! \biref	������ ������� ImGui�� �����Ѵ�. */
	void CleanUp();
};
