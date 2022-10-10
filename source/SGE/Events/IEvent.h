#pragma once
#include "sgepch.h"

namespace sge
{
	enum class EventType
	{
		None = 0,
		WindowResized, WindowMoved, WindowFocus, WindowLostFocus, WindowClosed,
		KeyPressed, KeyReleased,
		MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased,
	};

	#define SET_EVENT_CLASS_TYPE(type)\
		static EventType getStaticEventType() { return EventType::type; }\
		virtual EventType getEventType() const { return getStaticEventType(); }\
		virtual const char* getName() const { return #type; }

	class IEvent
	{
	public:
		virtual ~IEvent() = default;

		bool isHandled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual std::string toString() const { return getName(); };
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(IEvent& _event) : m_event(_event) {}

		template<typename T, typename F>
		bool dispatch(const F& func)
		{
			if (m_event.getEventType() == T::getStaticEventType())
			{
				m_event.isHandled = func(static_cast<T&>(m_event));
				return true;
			}

			return false;
		}

	private:
		IEvent& m_event;
	};
}
