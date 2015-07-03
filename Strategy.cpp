#include <iostream>
using namespace std;

class StrategyInterface
{
public:
	virtual void Execute() = 0;
};

class ConcreteStrategyA : public StrategyInterface
{
public:
	virtual void Execute()
	{
		cout << "Called ConcreteStrategyA excute method\n";
	}
};

class ConcreteStrategyB : public StrategyInterface
{
public:
	virtual void Execute()
	{
		cout << "Called ConcreteStrategyB excute method\n";
	}
};

class ContreteStrategyC: public StrategyInterface
{
public:
	virtual void Execute()
	{
		cout << "Called ContreteStrategyC excute method\n";
	}
};

class Context
{
private:
	StrategyInterface* m_strategy;
public:
	Context(StrategyInterface * strategy):
		m_strategy(strategy)
	{

	}

	void Execute()
	{
		m_strategy->Execute();
	}

	void SetStrategy(StrategyInterface* strategy)
	{
		m_strategy = strategy;
	}
};

int main()
{
	ConcreteStrategyA concreteStrategyA;
	ConcreteStrategyB concreteStrategyB;
	ContreteStrategyC concreteStrategyC;

	Context contextA(&concreteStrategyA);
	Context contextB(&concreteStrategyB);
	Context contextC(&concreteStrategyC);

	contextA.Execute();
	contextB.Execute();
	contextC.Execute();

	contextA.SetStrategy(&concreteStrategyB);
	contextA.Execute();
	contextA.SetStrategy(&concreteStrategyC);
	contextA.Execute();
	return 0;
}