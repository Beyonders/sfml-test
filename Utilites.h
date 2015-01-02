#ifndef UTILITES_H
#define UTILITES_H

template<class Ti, class Tq>
struct Quantity
{
	Ti item;
	Tq count;

	Quantity() : item(0), count(0)
	{ }

	Quantity(Ti item, Tq count) : item(item), count(count)
	{ }

	Quantity(const Quantity& original) 
		: item(original.item), count(original.count)
	{ }

	Quantity& operator=(const Quantity& rhs)
	{
		return Quantity(rhs);
	}
};

#endif