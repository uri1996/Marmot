#pragma once

#ifdef MM_PLATFORM_WINDOWS

extern Marmot::Application* Marmot::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Marmot::CreateApplication();
	app->Run();
	delete app;
}

#endif