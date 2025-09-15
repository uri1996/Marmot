#include"mmpch.h"
#include "Application.h"

#include"Log.h"

#include<glad/glad.h>

#include"Input.h"

namespace Marmot
{
	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		MM_CORE_ASSERT(s_instance, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		
		MM_CORE_TRACE(e);

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.GetHandled()) break;
		}
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerStack)
			{
				layer->OnUpdate();
			}
			auto [x, y] = Input::GetMousePosition();

			m_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}
}