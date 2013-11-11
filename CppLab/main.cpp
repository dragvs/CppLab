//
//  main.cpp
//  CppLab
//
//  Created by Vladimir Shishov on 11/8/13.
//  Copyright (c) 2013 Vladimir Shishov. All rights reserved.
//

#include <iostream>

#include "VariadicTemplatesWithFunctions.h"
#include "TypeAlias.h"
#include "TemplateClassStatics.h"
#include "PrivateMemberAccess.h"
#include "OverloadingWithTemplateSpec.h"
#include "OperatorNew.h"


int main(int argc, const char * argv[])
{
	std::cout << "\n- LABS START -\n";
	
	VariadicTemplatesWithFunctions::run();
	TypeAlias::run();
	TemplateClassStatics::run();
	PrivateMemberAccess::run();
	OverloadingWithTemplateSpec::run();
	OperatorNew::run();
	
	std::cout << "\n- LABS END -\n";
	
    return 0;
}

