#pragma once

#include"mmpch.h"

#include"Marmot/Core.h"
#include"Marmot/Events/Event.h"

namespace Marmot
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Marmot Engine",
			unsigned int width = 1200,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	// Interface representing a desktop system based Window
	class MARMOT_API Window
	{
	public:
		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}