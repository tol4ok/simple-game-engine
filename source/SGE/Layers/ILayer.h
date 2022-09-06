#pragma once

#include "SGE/Core/Defines.h"
#include "SGE/Events/IEvent.h"

namespace sge
{
	class SGE_API ILayer
	{
	public:
		virtual ~ILayer() = default;

		virtual void onUpdate() = 0;
		virtual void onEvent(IEvent& event) = 0;
		virtual void onAttach() = 0;
		virtual void onDetach() = 0;
	};
}