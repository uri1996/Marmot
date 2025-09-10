#include<Marmot.h>

class ExampleLayer : public Marmot::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		MM_INFO("ExampleLayer::Update");
	}

	void OnEvent(Marmot::Event& event) override
	{
		MM_TRACE("{0}", event);
	}
};

class Sandbox : public Marmot::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Marmot::ImguiLayer());
	}

	~Sandbox()
	{

	}
};

Marmot::Application* Marmot::CreateApplication()
{
	return new Sandbox();
}