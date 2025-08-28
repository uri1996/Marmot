#pragma once

#include"Core.h"

namespace Marmot
{
	class MARMOT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}