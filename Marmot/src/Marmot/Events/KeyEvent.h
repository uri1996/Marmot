#pragma once

#include"Event.h"



namespace Marmot
{
	class MARMOT_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) : m_keyCode(keycode){}
		int m_keyCode;
	};

	class MARMOT_API KeyPressedEvent : public KeyEvent
	{
		int m_repeatedCount;

	public:
		KeyPressedEvent(int keycode, int repeatedCount)
			: KeyEvent(keycode), m_repeatedCount(repeatedCount)
		{ }

		inline int GetRepeatCount() const { return m_repeatedCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatedCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		// instead of 
		//static EventType GetStaticType() {return EventType::KeyPressed;}
		//virtual EventType GetEventType() const override {return GetStaticType();}
		//virtual const char* GetName() const override {return "KeyPressed";}
	};

	class MARMOT_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}