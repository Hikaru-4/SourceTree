#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void StageMap::OnDraw()
	{
		for(auto& obj : m_stageObjects)
		{
			obj->OnDraw();
		}
	}

	void StageMap::Load(const std::wstring& filename)
	{

	}
	void StageMap::Save(const std::wstring& filename)
	{
		std::ofstream ofs(filename);
		if (ofs.fail()) {
			return;
		}

		for (auto& obj : m_stageObjects)
		{
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			ofs << objPos.x << L"," << objPos.y << L"," << objPos.z << std::endl;
		}
		ofs.close();
	}

}