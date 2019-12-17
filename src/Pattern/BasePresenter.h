#ifndef BASEPRESENTER_H
#define BASEPRESENTER_H

#include "IMvpPresenter.h"

template <typename T>
class BasePresenter : public IMvpPresenter<T>
{
	//// Свойства
	private:
		T _view;

	//// Методы
	public:
		explicit BasePresenter();
		virtual ~BasePresenter();

		// IMvpPresenter interface
		void attachView(T view) override;
		T view() override;
		void viewIsReady() override;
};


//// Реализация

template<typename T>
BasePresenter<T>::BasePresenter()
{
	// empty
}

template<typename T>
BasePresenter<T>::~BasePresenter()
{
	// empty
}

template<typename T>
void BasePresenter<T>::attachView(T view)
{
	_view = view;
}

template<typename T>
T BasePresenter<T>::view()
{
	return _view;
}

template<typename T>
void BasePresenter<T>::viewIsReady()
{
	// empty, for override
}

#endif // BASEPRESENTER_H
