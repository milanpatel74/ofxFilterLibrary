//
//  Parameter3fv.h
//  ofxFilterLibraryExample
//
//  Created by Matthew Fargo on 2014/06/27.
//
//

#ifndef ofxFilterLibraryExample_Parameter3fv_h
#define ofxFilterLibraryExample_Parameter3fv_h

#include "ParameterV.h"

class Parameter3fv : public ParameterV {
public:
	Parameter3fv(string name, float * value, int numValues) : ParameterV(name, value, numValues) {
        _type = FILTER_PARAMETER_3FV;
    }
	virtual ~Parameter3fv() {}
};

#endif
