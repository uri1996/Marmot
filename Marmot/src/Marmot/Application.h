#pragma once

#include"Core.h"
#include"Window.h"

namespace Marmot
{
	class MARMOT_API Application
	{
		std::unique_ptr<Window> m_window;
		bool m_running = true;

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}