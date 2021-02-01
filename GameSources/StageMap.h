/*!
@file StageMap.h
@brief �X�e�[�W�}�b�v
*/

#pragma once
#include "stdafx.h"
#include "StageObject.h"

namespace basecross {
	// �X�e�[�W�̔z�u���Ǘ����邽�߂̃N���X
	class StageMap : public GameObject
	{
		std::vector<std::shared_ptr<StageObject>> m_stageObjects;
		std::map<std::wstring, uint16_t> m_objectTypeList;

	public:
		StageMap(const std::shared_ptr<Stage>& stage)
			:GameObject(stage)
		{
			int i = 0;
			m_objectTypeList[L"block"] = i++;
			m_objectTypeList[L"grass"] = i++;
		}


		void OnDraw() override;

		template<class T>
		void AddStageObject(const Vec3& position)
		{
			auto object = ObjectFactory::Create<T>(GetStage());
			auto objectTrans = object->GetComponent<Transform>();
			objectTrans->SetPosition(position);

			m_stageObjects.push_back(object);
		}

		void Load(const std::wstring& filename);
		void SaveTextFile(const std::wstring& filename);
		void SaveBinaryFile(const std::wstring& filename);
		void Clear();

		uint16_t GetObjectIdByName(const std::wstring& objectName) const
		{
			return m_objectTypeList.at(objectName);
		}
	};

}