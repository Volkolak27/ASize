#ifndef IMVPPRESENTER_H
#define IMVPPRESENTER_H

template <typename T>
class IMvpPresenter
{
	public:
		virtual void attachView(T view) = 0;
		virtual T view() = 0;
		virtual void viewIsReady() = 0;
};

#endif // IMVPPRESENTER_H
