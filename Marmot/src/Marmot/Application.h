#pragma once

#include"Core.h"

#include"Window.h"
#include"Marmot/LayerStack.h"
#include"Events/Event.h"
#include"Events/ApplicationEvent.h"

namespace Marmot
{
	class MARMOT_API Application
	{
		std::unique_ptr<Window> m_window;
		bool m_running = true;
		LayerStack m_layerStack;

		bool OnWindowClose(WindowCloseEvent& e);

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}