/*!
@file Grass.cpp
@brief ƒuƒƒbƒN‚ÌÀ‘Ì
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void Grass::OnCreate()
	{
		auto drawComp = AddComponent<PNTStaticDraw>();
		drawComp->SetMeshResource(L"DEFAULT_CUBE");
		drawComp->SetTextureResource(L"grass");
	}
}