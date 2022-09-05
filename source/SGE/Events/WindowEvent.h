#pragma once

#include "IEvent.h"

namespace sge
{
	class WindowResizedEvent : public IEvent
	{
	public:
		WindowResizedEvent(int width, int height) :
			m_width(width), m_height(height) {};
		~WindowResizedEvent() = default;

		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }

		std::string toString() const override
		{
			return std::string("WindowResizedEvent: width: " +
				std::to_string(m_width) + ", height: " +
				std::to_string(m_height));
		}

		SET_EVENT_CLASS_TYPE(WindowResized)
	private:
		int m_width, m_height;
	};

	class WindowClosedEvent : public IEvent
	{
	public:
		WindowClosedEvent() = default;
		~WindowClosedEvent() = default;

		SET_EVENT_CLASS_TYPE(WindowClosed)
	};

}