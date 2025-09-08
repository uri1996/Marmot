#pragma once

#include"Marmot/Core.h"



namespace Marmot
{
	// Events in Marmot are currently blocking, meaning when an event occurs it
	// immediately get dispatched and must be dealt with right away
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage

	enum class EventType
	{
		None = 0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None                        = 0,
		EventCategoryApplication    = 1 << 0,
		EventCategoryInput          = 1 << 1,
		EventCategoryKeyboard       = 1 << 2,
		EventCategoryMouse          = 1 << 3,
		EventCategoryMouseButton    = 1 << 4
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
                               virtual EventType GetEventType() const override {return GetStaticType();}\
                               virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class MARMOT_API Event
	{
		//friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handled = false;
	};

	class MARMOT_API EventDispatcher
	{
		Event& m_event;

	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{ }

		template<typename T>
		bool Dispatch(std::function<bool(T&)> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	};

	//the fmt library that spdlog uses under the hood looks for format_to() 
	// in order to convert the custom type to text
	inline std::string format_as(const Event& e) { return e.ToString(); }

	// unknown error
	/*inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}*/
}