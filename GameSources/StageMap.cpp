#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void StageMap::OnDraw()
	{
		for(auto& obj : m_stageObject)
		{
			obj->OnDraw();
		}
	}
}