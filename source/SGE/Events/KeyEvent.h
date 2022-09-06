#pragma once

#include "IEvent.h"
#include "SGE/Core/KeyCodes.h"

namespace sge
{
	class KeyEvent : public IEvent
	{
	public:
		KeyCode getKeyCode() const { return m_keyCode; }
	protected:
		KeyEvent(const KeyCode keyCode) :
			IEvent(), m_keyCode(keyCode) {}
	private:
		KeyCode m_keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false) :
			KeyEvent(keyCode), m_isRepeat(isRepeat) {}

		std::string toString() const override
		{
			return std::string("KeyEventPressed: code: " +
				std::to_string(getKeyCode()) + ", repeat: " +
				std::to_string(m_isRepeat));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(KeyPressed)
		// ---
	private:
		bool m_isRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keyCode) :
			KeyEvent(keyCode) {}

		std::string toString() const override
		{
			return std::string("KeyEventPressed: code: " +
				std::to_string(getKeyCode()));
		}

		// Only for "sge::KeyEvent::" types!
		SET_EVENT_CLASS_TYPE(KeyReleased)
		// ---
	};
}