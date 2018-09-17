/*
 * BuildMetaInfo.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: bfarnham
 */
#include "BuildMetaInfo.h"
#include "../generated/BuildMetaInfoGenerated.h"

using std::string;

string BuildMetaInfo::getBuildTime()
{
	return GEND_BUILD_TIME;
}

string BuildMetaInfo::getBuildHost()
{
	return GEND_BUILD_HOST;
}

string BuildMetaInfo::getToolkitLibs()
{
	return GEND_TOOLKIT_LIBS;
}
