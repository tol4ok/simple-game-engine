#pragma once

#ifdef SGE_PLATFORM_WINDOWS

extern sge::Application* sge::CreateApplication();

int main(int argc, char** argv)
{
	sge::Application* app = sge::CreateApplication();
	app->run();
	delete app;

	return 0;
}

#endif