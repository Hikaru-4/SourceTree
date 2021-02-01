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
			MessageBox(0, L"保存用ファイルを開けませんでした", L"failed", 0);
			return;
		}

		for (auto& obj : m_stageObjects)
		{
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			ofs << objPos.x << "," << objPos.y << L"," << objPos.z << std::endl;
		}

		MessageBox(0, L"ステージ配置を保存しました", L"succeeded", 0);
		ofs.close();
	}

}