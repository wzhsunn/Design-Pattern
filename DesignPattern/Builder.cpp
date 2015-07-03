#include "stdafx.h"

#include <string>
#include <iostream>
using namespace std;


class Pizza
{
public:
	void SetDough(const string& dough)
	{
		m_dough = dough;
	}

	void SetSauce(const string& sauce)
	{
		m_sauce = sauce;
	}

	void SetTopping(const string& topping)
	{
		m_topping = topping;
	}

	void open()const
	{
		cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and " << m_topping << " topping. Mmm" << endl;
	}
private:
	string m_dough;
	string m_sauce;
	string m_topping;
};

class PizzaBuilder
{
public:
	virtual ~PizzaBuilder(){}

	Pizza* GetPizza()
	{
		return m_pizza;
	}

	void CreateNewPizzaProduct()
	{
		m_pizza = new Pizza();
	}

	virtual void BuildDough() = 0;
	virtual void BuildSauce() = 0;
	virtual void BuildTopping() = 0;
protected:
	Pizza* m_pizza;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
public: 
	virtual ~HawaiianPizzaBuilder(){}
	
	virtual void BuildDough()
	{
		m_pizza->SetDough("cross");
	}

	virtual void BuildSauce()
	{
		m_pizza->SetSauce("mild");
	}

	virtual void BuildTopping()
	{
		m_pizza->SetTopping("hmm+pineapple");
	}
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~SpicyPizzaBuilder(){}

	virtual void BuildDough()
	{
		m_pizza->SetDough("pan baked");
	}

	virtual void BuildSauce()
	{
		m_pizza->SetSauce("hot");
	}
	virtual void BuildTopping()
	{
		m_pizza->SetTopping("pepperoni+salami");
	}
};


class Cook
{
public:
	void SetPizzaBuilder(PizzaBuilder* pb)
	{
		m_builder = pb;
	}

	Pizza* GetPizza()
	{
		return m_builder->GetPizza();
	}

	void ConstructPizza()
	{
		m_builder->CreateNewPizzaProduct();
		m_builder->BuildDough();
		m_builder->BuildSauce();
		m_builder->BuildTopping();
	}
private:
	PizzaBuilder * m_builder;
};

void CookPizza()
{
	Cook cook;
	PizzaBuilder* hawaiianPizzaBuilder = new HawaiianPizzaBuilder();
	PizzaBuilder* spicyPizzaBuilder = new SpicyPizzaBuilder();

	cook.SetPizzaBuilder(hawaiianPizzaBuilder);
	cook.ConstructPizza();

	Pizza* hawaiian = cook.GetPizza();
	hawaiian->open();

	cook.SetPizzaBuilder(spicyPizzaBuilder);
	cook.ConstructPizza();

	Pizza* spicy = cook.GetPizza();
	spicy->open();

	delete hawaiianPizzaBuilder;
	delete spicyPizzaBuilder;
	delete hawaiian;
	delete spicy;
}