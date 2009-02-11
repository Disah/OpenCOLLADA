/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAYEREDSHADER_H__
#define __MayaDM_LAYEREDSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LayeredShader : public DependNode
{
public:
	struct Inputs{
		float3 color;
		float3 transparency;
		float3 glowColor;
		void write(FILE* file) const
		{
			color.write(file);
			fprintf(file, " ");
			transparency.write(file);
			fprintf(file, " ");
			glowColor.write(file);
		}
	};
public:
	LayeredShader():DependNode(){}
	LayeredShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "layeredShader"){}
	virtual ~LayeredShader(){}
	void setCompositingFlag(unsigned int cf)
	{
		if(cf == 0) return;
		fprintf(mFile,"\tsetAttr \".cf\" %i;\n", cf);

	}
	void setInputs(size_t cs_i,const Inputs& cs)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i]\" ",cs_i);
		cs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor(size_t cs_i,const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i].c\" -type \"float3\" ",cs_i);
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(size_t cs_i,float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cr\" %f;\n", cs_i,cr);

	}
	void setColorG(size_t cs_i,float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cg\" %f;\n", cs_i,cg);

	}
	void setColorB(size_t cs_i,float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cb\" %f;\n", cs_i,cb);

	}
	void setTransparency(size_t cs_i,const float3& t)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i].t\" -type \"float3\" ",cs_i);
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparencyR(size_t cs_i,float tr)
	{
		if(tr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].t.tr\" %f;\n", cs_i,tr);

	}
	void setTransparencyG(size_t cs_i,float tg)
	{
		if(tg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].t.tg\" %f;\n", cs_i,tg);

	}
	void setTransparencyB(size_t cs_i,float tb)
	{
		if(tb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].t.tb\" %f;\n", cs_i,tb);

	}
	void setGlowColor(size_t cs_i,const float3& g)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i].g\" -type \"float3\" ",cs_i);
		g.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlowColorR(size_t cs_i,float gr)
	{
		if(gr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].g.gr\" %f;\n", cs_i,gr);

	}
	void setGlowColorG(size_t cs_i,float gg)
	{
		if(gg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].g.gg\" %f;\n", cs_i,gg);

	}
	void setGlowColorB(size_t cs_i,float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].g.gb\" %f;\n", cs_i,gb);

	}
	void setHardwareColor(const float3& hc)
	{
		fprintf(mFile,"\tsetAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHardwareColorR(float hcr)
	{
		if(hcr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcr\" %f;\n", hcr);

	}
	void setHardwareColorG(float hcg)
	{
		if(hcg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcg\" %f;\n", hcg);

	}
	void setHardwareColorB(float hcb)
	{
		if(hcb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcb\" %f;\n", hcb);

	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"\tsetAttr \".mom\" %i;\n", mom);

	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mog\" %f;\n", mog);

	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"\tsetAttr \".mifm\" %i;\n", mifm);

	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"\tsetAttr \".mis\" %f;\n", mis);

	}
	void setMiAngle(float mia)
	{
		if(mia == 0) return;
		fprintf(mFile,"\tsetAttr \".mia\" %f;\n", mia);

	}
	void setMiSpreadX(float misx)
	{
		if(misx == 10) return;
		fprintf(mFile,"\tsetAttr \".misx\" %f;\n", misx);

	}
	void setMiSpreadY(float misy)
	{
		if(misy == 5) return;
		fprintf(mFile,"\tsetAttr \".misy\" %f;\n", misy);

	}
	void setMiWhiteness(const float3& miwn)
	{
		fprintf(mFile,"\tsetAttr \".miwn\" -type \"float3\" ");
		miwn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiWhitenessR(float miwnr)
	{
		if(miwnr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnr\" %f;\n", miwnr);

	}
	void setMiWhitenessG(float miwng)
	{
		if(miwng == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwng\" %f;\n", miwng);

	}
	void setMiWhitenessB(float miwnb)
	{
		if(miwnb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnb\" %f;\n", miwnb);

	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"\tsetAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscr\" %f;\n", miscr);

	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscg\" %f;\n", miscg);

	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscb\" %f;\n", miscb);

	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mirf\" %f;\n", mirf);

	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"\tsetAttr \".miri\" %f;\n", miri);

	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"\tsetAttr \".mirc\" %i;\n", mirc);

	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"\tsetAttr \".miab\" %i;\n", miab);

	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".midc\" %f;\n", midc);

	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"\tsetAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micr\" %f;\n", micr);

	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micg\" %f;\n", micg);

	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micb\" %f;\n", micb);

	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"\tsetAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitr\" %f;\n", mitr);

	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitg\" %f;\n", mitg);

	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitb\" %f;\n", mitb);

	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"\tsetAttr \".mitc\" %f;\n", mitc);

	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mitf\" %f;\n", mitf);

	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"\tsetAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincx\" %f;\n", mincx);

	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincy\" %f;\n", mincy);

	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincz\" %f;\n", mincz);

	}
	void getCompositingFlag()
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());

	}
	void getInputs(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i]\"",mName.c_str(),cs_i);

	}
	void getColor(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].c\"",mName.c_str(),cs_i);

	}
	void getColorR(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].c.cr\"",mName.c_str(),cs_i);

	}
	void getColorG(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].c.cg\"",mName.c_str(),cs_i);

	}
	void getColorB(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].c.cb\"",mName.c_str(),cs_i);

	}
	void getTransparency(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].t\"",mName.c_str(),cs_i);

	}
	void getTransparencyR(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].t.tr\"",mName.c_str(),cs_i);

	}
	void getTransparencyG(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].t.tg\"",mName.c_str(),cs_i);

	}
	void getTransparencyB(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].t.tb\"",mName.c_str(),cs_i);

	}
	void getGlowColor(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].g\"",mName.c_str(),cs_i);

	}
	void getGlowColorR(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].g.gr\"",mName.c_str(),cs_i);

	}
	void getGlowColorG(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].g.gg\"",mName.c_str(),cs_i);

	}
	void getGlowColorB(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i].g.gb\"",mName.c_str(),cs_i);

	}
	void getHardwareShader()
	{
		fprintf(mFile,"\"%s.hws\"",mName.c_str());

	}
	void getHardwareShaderR()
	{
		fprintf(mFile,"\"%s.hws.hwr\"",mName.c_str());

	}
	void getHardwareShaderG()
	{
		fprintf(mFile,"\"%s.hws.hwg\"",mName.c_str());

	}
	void getHardwareShaderB()
	{
		fprintf(mFile,"\"%s.hws.hwb\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
	void getOutGlowColor()
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());

	}
	void getOutGlowColorR()
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());

	}
	void getOutGlowColorG()
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());

	}
	void getOutGlowColorB()
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());

	}
	void getMatteOpacityMode()
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());

	}
	void getMatteOpacity()
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());

	}
	void getOutMatteOpacity()
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());

	}
	void getOutMatteOpacityR()
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());

	}
	void getOutMatteOpacityG()
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());

	}
	void getOutMatteOpacityB()
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());

	}
	void getMiDeriveFromMaya()
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());

	}
	void getMiShinyness()
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());

	}
	void getMiAngle()
	{
		fprintf(mFile,"\"%s.mia\"",mName.c_str());

	}
	void getMiSpreadX()
	{
		fprintf(mFile,"\"%s.misx\"",mName.c_str());

	}
	void getMiSpreadY()
	{
		fprintf(mFile,"\"%s.misy\"",mName.c_str());

	}
	void getMiWhiteness()
	{
		fprintf(mFile,"\"%s.miwn\"",mName.c_str());

	}
	void getMiWhitenessR()
	{
		fprintf(mFile,"\"%s.miwn.miwnr\"",mName.c_str());

	}
	void getMiWhitenessG()
	{
		fprintf(mFile,"\"%s.miwn.miwng\"",mName.c_str());

	}
	void getMiWhitenessB()
	{
		fprintf(mFile,"\"%s.miwn.miwnb\"",mName.c_str());

	}
	void getMiSpecularColor()
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());

	}
	void getMiSpecularColorR()
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());

	}
	void getMiSpecularColorG()
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());

	}
	void getMiSpecularColorB()
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());

	}
	void getMiReflectivity()
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());

	}
	void getMiRefractiveIndex()
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());

	}
	void getMiRefractions()
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());

	}
	void getMiAbsorbs()
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());

	}
	void getMiDiffuse()
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());

	}
	void getMiColor()
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());

	}
	void getMiColorR()
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());

	}
	void getMiColorG()
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());

	}
	void getMiColorB()
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());

	}
	void getMiTransparency()
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());

	}
	void getMiTransparencyR()
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());

	}
	void getMiTransparencyG()
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());

	}
	void getMiTransparencyB()
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());

	}
	void getMiTranslucence()
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());

	}
	void getMiTranslucenceFocus()
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());

	}
	void getMiNormalCamera()
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());

	}
	void getMiNormalCameraX()
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());

	}
	void getMiNormalCameraY()
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());

	}
	void getMiNormalCameraZ()
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());

	}
protected:
	LayeredShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LAYEREDSHADER_H__
