#pragma once

#include"Event.h"


namespace Marmot
{
	class MARMOT_API MouseMovedEvent : public Event
	{
		float m_mouseX;
		float m_mouseY;

	public:
		MouseMovedEvent(float x, float y)
			: m_mouseX(x), m_mouseY(y)
		{ }

		inline float GetX() const { return m_mouseX; }
		inline float GetY() const { return m_mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MARMOT_API MouseScrolledEvent : public Event
	{
		float m_xOffset;
		float m_yOffset;

	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_xOffset(xOffset), m_yOffset(yOffset)
		{ }

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MARMOT_API MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(int button) // protected so that we can't create this class
			: m_button(button)
		{ }
		
		int m_button;

	public:
		inline int GetMouseButton() const { return m_button; }
	
		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
	};

	class MARMOT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	}; 

	class MARMOT_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}