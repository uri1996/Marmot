#include<Marmot.h>

class Sandbox : public Marmot::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Marmot::Application* Marmot::CreateApplication()
{
	return new Sandbox();
}