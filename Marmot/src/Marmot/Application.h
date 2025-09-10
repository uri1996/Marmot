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
		static Application* s_instance;

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

		static Application& Get() { return *s_instance; }
		inline Window& GetWindow() { return *m_window; }
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}