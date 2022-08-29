#pragma once

#include "Core.h"

namespace sge
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	private:

	};

	Application* CreateApplication();
}
