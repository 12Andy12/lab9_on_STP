#pragma once
#include <set>

using namespace std;

template<class T>
class MegaSet
{
private:
	set<T> data;
public:
	MegaSet() {};
	MegaSet(set<T> newData);
	void insert(T a);
	void remove(T a);
	void clear();
	bool isEmpty();
	bool isCount(T a);
	MegaSet<T> add(MegaSet<T> a);
	MegaSet<T> dif(MegaSet<T> a);
	MegaSet<T> mul(MegaSet<T> a);
	T operator[](int i);
	int size();
};

template<class T>
inline int MegaSet<T>::size()
{
	return data.size();
}


template<class T>
inline MegaSet<T>::MegaSet(set<T> newData):data(newData)
{

}

template<class T>
inline void MegaSet<T>::insert(T a)
{
	data.insert(a);
}

template<class T>
inline void MegaSet<T>::remove(T a)
{
	data.erase(a);
}

template<class T>
inline void MegaSet<T>::clear()
{
	data.clear();
}

template<class T>
inline  MegaSet<T> MegaSet<T>::add(MegaSet<T> a)
{
	MegaSet<T> res(data);
	for (int i =0; i < a.size();++i)
	{
		res.insert(a[i]);
	}
	return res;
}

template<class T>
inline  MegaSet<T> MegaSet<T>::dif(MegaSet<T> a)
{
	MegaSet<T> res;
	for (auto i : data)
	{
		if (!a.isCount(i))
			res.insert(i);
	}
	return res;
}

template<class T>
inline  MegaSet<T> MegaSet<T>::mul(MegaSet<T> a)
{
	MegaSet<T> res;
	for (auto i : data)
	{
		if (a.isCount(i))
			res.insert(i);
	}
	return res;
}

template<class T>
inline T MegaSet<T>::operator[](int id)
{
	int i = 0;
	for (auto t : data) 
	{
		if (id == i)
			return t;
		++i;
	}
	throw "index out of range";
}

template<class T>
inline bool MegaSet<T>::isEmpty()
{
	return data.empty();
}

template<class T>
inline bool MegaSet<T>::isCount(T a)
{
	return data.count(a);
}








