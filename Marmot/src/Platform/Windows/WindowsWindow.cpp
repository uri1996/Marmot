#include"mmpch.h"
#include"WindowsWindow.h"

namespace Marmot
{
	static bool s_GLFWInitiated = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		this->Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		this->Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		MM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitiated)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			MM_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitiated = true;
		}

		m_window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_Data);
		this->SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else		 glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}