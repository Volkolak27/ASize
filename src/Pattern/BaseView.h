#ifndef BASEVIEW_H
#define BASEVIEW_H

#include "IMvpView.h"

class BaseView : public IMvpView
{
	//// Свойства
	protected:
		bool _isFirstShow;

	//// Методы
	public:
		explicit BaseView();
		virtual ~BaseView();
};

#endif // BASEVIEW_H
