//
// EPITECH PROJECT, 2018
// ex00.hpp
// File description:
// ex00.hpp
//

template <typename X>
void swap(X &a, X &b)
{
	X tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename X>
X min(X const a, X const b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename X>
X max(X const a, X const b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename X>
X add(X const a, X const b)
{
	return a + b;
}
