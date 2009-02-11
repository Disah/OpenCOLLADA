/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMFUNC_H__
#define __MayaDM_DEFORMFUNC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class DeformFunc : public Shape
{
public:
public:
	DeformFunc():Shape(){}
	DeformFunc(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "deformFunc"){}
	virtual ~DeformFunc(){}
	void setDeformerData(const doubleArray& dd)
	{
		if(dd.size == 0) return;
		fprintf(mFile,"\tsetAttr \".dd\" -type \"doubleArray\" ");
		dd.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHandleWidth(double hw)
	{
		if(hw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hw\" %f;\n", hw);

	}
	void getDeformerData()
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());

	}
	void getHandleWidth()
	{
		fprintf(mFile,"\"%s.hw\"",mName.c_str());

	}
protected:
	DeformFunc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMFUNC_H__
