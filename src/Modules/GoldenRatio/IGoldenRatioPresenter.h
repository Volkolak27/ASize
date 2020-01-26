#ifndef IGOLDENRATIOPRESENTER_H
#define IGOLDENRATIOPRESENTER_H

#include "src/Modules/GoldenRatio/IGoldenRatioView.h"
#include "src/Pattern/BasePresenter.h"

class IGoldenRatioPresenter : public BasePresenter<IGoldenRatioView*>
{
	public:
		virtual void sourceValueChanged(const double& newValue) = 0;
		virtual void ratioPartChanged(const GoldenRatioPart& goldenRatioPart) = 0;
};

#endif // IGOLDENRATIOPRESENTER_H
