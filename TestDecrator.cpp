#include <iostream>
using namespace std;

class Widget 
{
public:
	virtual void Draw() = 0;
	virtual ~Widget()
	{
		cout << "run ~Widget()\n"; 
	}
};

class TextField : public Widget
{
public:
	TextField(const int w, const int h):
		m_width(w),
		m_height(h)
	{

	}

	void Draw()
	{
		cout << "Text Field width[" << m_width << "], height[" << m_height <<"]\n";
	}

private:
	int m_width;
	int m_height;
};

class Decorator: public Widget
{
public:
	Decorator(Widget* widget):
		m_widget(widget)
	{

	}

	void Draw()
	{
		m_widget->Draw();
	}

	~Decorator()
	{
		delete m_widget;
	}
private:
	Widget* m_widget;
};

class BorderDecrator: public Decorator
{
public:
	BorderDecrator(Widget* widget):Decorator(widget)
	{

	}

	void Draw()
	{
		Decorator::Draw();
		cout << "BorderDecrator \n";
	}
};

class ScrollDecrator: public Decorator
{
public:
	ScrollDecrator(Widget* widget): Decorator(widget)
	{

	}
	void Draw()
	{
		Decorator::Draw();
		cout << "ScrollDecorator \n";
	}
};

int main()
{
	Widget* widget = new BorderDecrator(
			new BorderDecrator(
				new ScrollDecrator(
				new TextField(80, 24))
			)
		);

	widget->Draw();

	delete widget;
	return 0;
}