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
		if (Marmot::Input::IsKeyPressed(MM_KEY_TAB))
		{
			MM_INFO("Tab key is pressed!");
		}
	}

	void OnEvent(Marmot::Event& event) override
	{
		if (event.GetEventType() == Marmot::EventType::KeyPressed)
		{
			Marmot::KeyPressedEvent& e = (Marmot::KeyPressedEvent&)event;
			MM_TRACE("{0}", (char)e.GetKeyCode());
		}
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