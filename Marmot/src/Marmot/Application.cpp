#include"mmpch.h"
#include "Application.h"

#include"Events/ApplicationEvent.h"
#include"Log.h"

#include<GLFW/glfw3.h>

namespace Marmot
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}
}