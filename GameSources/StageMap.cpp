/*!
@file	StageMap.cpp
@brief �X�e�[�W�}�b�v�̎���
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void StageMap::OnDraw()
	{
		for (auto& obj : m_stageObjects)
		{
			obj->OnDraw();
		}
	}

	void StageMap::Load(const std::wstring& filename)
	{
		// �X�e�[�W�t�@�C�����J��
		std::ifstream ifs(filename, std::ios::binary);
		if (ifs.fail())
		{
			MessageBox(0, L"�X�e�[�W�t�@�C�����J���܂���ł���", L"failed", 0);
			return; // ���s���Ă����狭���I��
		}

		// �I�u�W�F�N�g�̐����t�@�C������擾����
		uint32_t numObjects;
		ifs.read((char*)&numObjects, sizeof(numObjects));

		// �I�u�W�F�N�g�̐������C�|�W�V�������擾���ău���b�N��ǉ�����
		for (int i = 0; i < numObjects; i++)
		{
			// �I�u�W�F�N�gID���擾����
			uint16_t id;
			ifs.read((char*)&id, sizeof(id));

			// �|�W�V�������擾����
			Vec3 position;
			ifs.read((char*)&position, sizeof(position));

			// �u���b�N��ǉ�����
			switch (id)
			{
			case StageObject::Type::Block:
				AddStageObject<Block>(position);
				break;
			case StageObject::Type::Grass:
				AddStageObject<Grass>(position);
				break;
			}
		}

		// �t�@�C�������
		ifs.close();
	}

	void StageMap::SaveTextFile(const std::wstring& filename)
	{
		// �ۑ��p�t�@�C�����J���i�t�@�C�������݂��Ȃ�������쐬���Ă����j
		std::ofstream ofs(filename);
		if (ofs.fail())
		{
			MessageBox(0, L"�ۑ��p�t�@�C�����J���܂���ł���", L"failed", 0);
			return;
		}

		// �X�e�[�W�ɒǉ�����Ă���I�u�W�F�N�g�̐��������[�v
		for (auto& obj : m_stageObjects)
		{
			// �I�u�W�F�N�g�̍��W���擾����
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			// ���W���e�L�X�g�f�[�^�ŏ�������
			ofs << objPos.x << ", " << objPos.y << ", " << objPos.z << std::endl;
		}

		// �������b�Z�[�W��\�����āC�t�@�C�������
		MessageBox(0, L"�X�e�[�W�z�u��ۑ����܂���", L"Text file save succeeded", 0);
		ofs.close();
	}

	void StageMap::SaveBinaryFile(const std::wstring& filename)
	{
		// �ۑ��p�t�@�C�����J���i�t�@�C�������݂��Ȃ�������쐬���Ă����j
		std::ofstream ofs(filename, std::ios::binary);
		if (ofs.fail())
		{
			MessageBox(0, L"�ۑ��p�t�@�C�����J���܂���ł���", L"failed", 0);
			return; // �J���Ȃ������狭���I��
		}

		// �I�u�W�F�N�g�̐�����������
		uint32_t numObjects = m_stageObjects.size();
		ofs.write((char*)&numObjects, sizeof(numObjects));

		// �I�u�W�F�N�g�̏�����������
		for (auto& obj : m_stageObjects)
		{
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			// �������ID�ɕϊ�����
			uint16_t id = GetObjectIdByName(obj->GetName());
			ofs.write((char*)&id, sizeof(uint16_t)); // ID�̎擾
			ofs.write((char*)&objPos, sizeof(objPos)); // ���W
		}

		// �����̃��b�Z�[�W��\�����ăt�@�C�������
		MessageBox(0, L"�X�e�[�W�z�u��ۑ����܂���", L"Binary file save succeeded", 0);
		ofs.close();
	}

	void StageMap::Clear()
	{
		m_stageObjects.clear();
	}
}