//
//  BilateralFilter.h
//  filterSandbox
//
//  Created by Matthew Fargo on 2014/06/24.
//
//

#ifndef __filterSandbox__BilateralFilter__
#define __filterSandbox__BilateralFilter__

#include "AbstractTwoPassFilter.h"

class BilateralFilter : public AbstractTwoPassFilter {
public:
	BilateralFilter(float width, float height, float blurOffset=4.f, float normalization=6.f);
	virtual ~BilateralFilter();

    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() { return "Up and Down change blur offset: " + ofToString(_texelSpacing.x) + "\nLeft and Right to change normalization: " + ofToString(_normalization); }

    
    float           getBlurOffset() { return _texelSpacing.x; }
    void            setBlurOffset(float blurOffset) { _texelSpacing = ofVec2f(blurOffset, blurOffset); }
    
protected:
    virtual void    _setup();
    float           _normalization;

};

#endif /* defined(__filterSandbox__BilateralFilter__) */