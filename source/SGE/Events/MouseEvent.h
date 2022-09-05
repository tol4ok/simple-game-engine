#pragma once

#include "IEvent.h"

namespace sge
{
	class MouseMovedEvent : public IEvent
	{
	public:
		MouseMovedEvent(float xCoord, float yCoord) :
			IEvent(), m_xCoord(xCoord), m_yCoord(yCoord) {}

		float getX() const { return m_xCoord; };
		float getY() const { return m_yCoord; };

		std::string toString() const override
		{
			return std::string("MouseMovedEvent: x: " +
				std::to_string(m_xCoord) + ", y: " +
				std::to_string(m_yCoord));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(MouseMoved)
		// ---
	private:
		float m_xCoord, m_yCoord;
	};

	class MouseScrolledEvent : public IEvent
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) :
			IEvent(), m_xOffset(xOffset), m_yOffset(yOffset) {}

		std::string toString() const override
		{
			return std::string("MouseButtonPressedEvent: x offset: " +
				std::to_string(m_xOffset) + ", y offset: " +
				std::to_string(m_yOffset));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(MouseScrolled)
		// ---
	private:
		float m_xOffset, m_yOffset;
	};

	class MouseButtonEvent : public IEvent
	{
	public:
		uint32_t getButtonCode() const { return m_buttonCode; }
	protected:
		MouseButtonEvent(uint32_t buttonCode) :
			IEvent(), m_buttonCode(buttonCode) {}
	private:
		uint32_t m_buttonCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(uint32_t buttonCode) :
			MouseButtonEvent(buttonCode) {}

		std::string toString() const override
		{
			return std::string("MouseButtonPressedEvent: button code: " +
				std::to_string(getButtonCode()));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(MouseButtonPressed)
		// ---
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(uint32_t buttonCode) :
			MouseButtonEvent(buttonCode) {}

		std::string toString() const override
		{
			return std::string("MouseButtonReleasedEvent: button code: " +
				std::to_string(getButtonCode()));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(MouseButtonReleased)
		// ---
	};
}