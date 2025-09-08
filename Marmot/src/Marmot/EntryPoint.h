#pragma once

#ifdef MM_PLATFORM_WINDOWS

extern Marmot::Application* Marmot::CreateApplication();

int main(int argc, char** argv)
{
	Marmot::Log::Init();
	MM_CORE_ERROR("Initialized LOG!");
	MM_CORE_INFO("Initialized LOG!");
	int a = 5;
	MM_TRACE("YEAH!{0}", a);
	MM_WARN("YEAH!");

	auto app = Marmot::CreateApplication();
	app->Run();
	delete app;
}

#endif