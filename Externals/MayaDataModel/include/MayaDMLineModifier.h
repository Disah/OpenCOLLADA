/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LINEMODIFIER_H__
#define __MayaDM_LINEMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class LineModifier : public Shape
{
public:
	struct Dropoff{
		float dropoff_Position;
		float dropoff_FloatValue;
		unsigned int dropoff_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", dropoff_Position);
			fprintf(file,"%f ", dropoff_FloatValue);
			fprintf(file,"%i", dropoff_Interp);
		}
	};
public:
	LineModifier():Shape(){}
	LineModifier(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "lineModifier"){}
	virtual ~LineModifier(){}
	void setShape(unsigned int shp)
	{
		if(shp == 0) return;
		fprintf(mFile,"\tsetAttr \".shp\" %i;\n", shp);

	}
	void setWidthScale(double wsc)
	{
		if(wsc == 5.0) return;
		fprintf(mFile,"\tsetAttr \".wsc\" %f;\n", wsc);

	}
	void setWidthOffset(double wof)
	{
		if(wof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wof\" %f;\n", wof);

	}
	void setOpacityScale(double osc)
	{
		if(osc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".osc\" %f;\n", osc);

	}
	void setOpacityOffset(double oof)
	{
		if(oof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".oof\" %f;\n", oof);

	}
	void setSurfaceOffset(double sof)
	{
		if(sof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sof\" %f;\n", sof);

	}
	void setLineExtend(double lex)
	{
		if(lex == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lex\" %f;\n", lex);

	}
	void setModifyColor(bool mcl)
	{
		if(mcl == false) return;
		fprintf(mFile,"\tsetAttr \".mcl\" %i;\n", mcl);

	}
	void setColor(const float3& clr)
	{
		fprintf(mFile,"\tsetAttr \".clr\" -type \"float3\" ");
		clr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float crr)
	{
		if(crr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".clr.crr\" %f;\n", crr);

	}
	void setColorG(float crg)
	{
		if(crg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr.crg\" %f;\n", crg);

	}
	void setColorB(float crb)
	{
		if(crb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr.crb\" %f;\n", crb);

	}
	void setTubeScale(double tus)
	{
		if(tus == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tus\" %f;\n", tus);

	}
	void setTubeDropout(double tud)
	{
		if(tud == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tud\" %f;\n", tud);

	}
	void setBranchDropout(double bdp)
	{
		if(bdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bdp\" %f;\n", bdp);

	}
	void setTwigDropout(double tdp)
	{
		if(tdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tdp\" %f;\n", tdp);

	}
	void setLeafDropout(double ldp)
	{
		if(ldp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ldp\" %f;\n", ldp);

	}
	void setFlowerDropout(double fdp)
	{
		if(fdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fdp\" %f;\n", fdp);

	}
	void setLeafScale(double lsc)
	{
		if(lsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lsc\" %f;\n", lsc);

	}
	void setFlowerScale(double fsc)
	{
		if(fsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fsc\" %f;\n", fsc);

	}
	void setForce(double frc)
	{
		if(frc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".frc\" %f;\n", frc);

	}
	void setDirectionalForce(double dfc)
	{
		if(dfc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dfc\" %f;\n", dfc);

	}
	void setDisplacement(double dsp)
	{
		if(dsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsp\" %f;\n", dsp);

	}
	void setDirectionalDisplacement(double ddc)
	{
		if(ddc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ddc\" %f;\n", ddc);

	}
	void setDropoffNoise(double don)
	{
		if(don == 0.0) return;
		fprintf(mFile,"\tsetAttr \".don\" %f;\n", don);

	}
	void setNoiseFrequency(double nfr)
	{
		if(nfr == 0.2) return;
		fprintf(mFile,"\tsetAttr \".nfr\" %f;\n", nfr);

	}
	void setDropoff(size_t drp_i,const Dropoff& drp)
	{
		fprintf(mFile,"\tsetAttr \".drp[%i]\" ",drp_i);
		drp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDropoff_Position(size_t drp_i,float drpp)
	{
		if(drpp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".drp[%i].drpp\" %f;\n", drp_i,drpp);

	}
	void setDropoff_FloatValue(size_t drp_i,float drpfv)
	{
		if(drpfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".drp[%i].drpfv\" %f;\n", drp_i,drpfv);

	}
	void setDropoff_Interp(size_t drp_i,unsigned int drpi)
	{
		if(drpi == 0) return;
		fprintf(mFile,"\tsetAttr \".drp[%i].drpi\" %i;\n", drp_i,drpi);

	}
	void getShape()
	{
		fprintf(mFile,"\"%s.shp\"",mName.c_str());

	}
	void getWidthScale()
	{
		fprintf(mFile,"\"%s.wsc\"",mName.c_str());

	}
	void getWidthOffset()
	{
		fprintf(mFile,"\"%s.wof\"",mName.c_str());

	}
	void getOpacityScale()
	{
		fprintf(mFile,"\"%s.osc\"",mName.c_str());

	}
	void getOpacityOffset()
	{
		fprintf(mFile,"\"%s.oof\"",mName.c_str());

	}
	void getSurfaceOffset()
	{
		fprintf(mFile,"\"%s.sof\"",mName.c_str());

	}
	void getLineExtend()
	{
		fprintf(mFile,"\"%s.lex\"",mName.c_str());

	}
	void getModifyColor()
	{
		fprintf(mFile,"\"%s.mcl\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.clr\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.clr.crr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.clr.crg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.clr.crb\"",mName.c_str());

	}
	void getTubeScale()
	{
		fprintf(mFile,"\"%s.tus\"",mName.c_str());

	}
	void getTubeDropout()
	{
		fprintf(mFile,"\"%s.tud\"",mName.c_str());

	}
	void getBranchDropout()
	{
		fprintf(mFile,"\"%s.bdp\"",mName.c_str());

	}
	void getTwigDropout()
	{
		fprintf(mFile,"\"%s.tdp\"",mName.c_str());

	}
	void getLeafDropout()
	{
		fprintf(mFile,"\"%s.ldp\"",mName.c_str());

	}
	void getFlowerDropout()
	{
		fprintf(mFile,"\"%s.fdp\"",mName.c_str());

	}
	void getLeafScale()
	{
		fprintf(mFile,"\"%s.lsc\"",mName.c_str());

	}
	void getFlowerScale()
	{
		fprintf(mFile,"\"%s.fsc\"",mName.c_str());

	}
	void getForce()
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());

	}
	void getDirectionalForce()
	{
		fprintf(mFile,"\"%s.dfc\"",mName.c_str());

	}
	void getDisplacement()
	{
		fprintf(mFile,"\"%s.dsp\"",mName.c_str());

	}
	void getDirectionalDisplacement()
	{
		fprintf(mFile,"\"%s.ddc\"",mName.c_str());

	}
	void getDropoffNoise()
	{
		fprintf(mFile,"\"%s.don\"",mName.c_str());

	}
	void getNoiseFrequency()
	{
		fprintf(mFile,"\"%s.nfr\"",mName.c_str());

	}
	void getDropoff(size_t drp_i)
	{
		fprintf(mFile,"\"%s.drp[%i]\"",mName.c_str(),drp_i);

	}
	void getDropoff_Position(size_t drp_i)
	{
		fprintf(mFile,"\"%s.drp[%i].drpp\"",mName.c_str(),drp_i);

	}
	void getDropoff_FloatValue(size_t drp_i)
	{
		fprintf(mFile,"\"%s.drp[%i].drpfv\"",mName.c_str(),drp_i);

	}
	void getDropoff_Interp(size_t drp_i)
	{
		fprintf(mFile,"\"%s.drp[%i].drpi\"",mName.c_str(),drp_i);

	}
	void getOutLineModifier(size_t olm_i)
	{
		fprintf(mFile,"\"%s.olm[%i]\"",mName.c_str(),olm_i);

	}
protected:
	LineModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LINEMODIFIER_H__
