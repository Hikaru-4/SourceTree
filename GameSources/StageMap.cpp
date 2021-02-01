/*!
@file	StageMap.cpp
@brief ステージマップの実態
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
		// ステージファイルを開く
		std::ifstream ifs(filename, std::ios::binary);
		if (ifs.fail())
		{
			MessageBox(0, L"ステージファイルを開けませんでした", L"failed", 0);
			return; // 失敗していたら強制終了
		}

		// オブジェクトの数をファイルから取得する
		uint32_t numObjects;
		ifs.read((char*)&numObjects, sizeof(numObjects));

		// オブジェクトの数だけ，ポジションを取得してブロックを追加する
		for (int i = 0; i < numObjects; i++)
		{
			// オブジェクトIDを取得する
			uint16_t id;
			ifs.read((char*)&id, sizeof(id));

			// ポジションを取得する
			Vec3 position;
			ifs.read((char*)&position, sizeof(position));

			// ブロックを追加する
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

		// ファイルを閉じる
		ifs.close();
	}

	void StageMap::SaveTextFile(const std::wstring& filename)
	{
		// 保存用ファイルを開く（ファイルが存在しなかったら作成してくれる）
		std::ofstream ofs(filename);
		if (ofs.fail())
		{
			MessageBox(0, L"保存用ファイルを開けませんでした", L"failed", 0);
			return;
		}

		// ステージに追加されているオブジェクトの数だけループ
		for (auto& obj : m_stageObjects)
		{
			// オブジェクトの座標を取得する
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			// 座標をテキストデータで書きだす
			ofs << objPos.x << ", " << objPos.y << ", " << objPos.z << std::endl;
		}

		// 成功メッセージを表示して，ファイルを閉じる
		MessageBox(0, L"ステージ配置を保存しました", L"Text file save succeeded", 0);
		ofs.close();
	}

	void StageMap::SaveBinaryFile(const std::wstring& filename)
	{
		// 保存用ファイルを開く（ファイルが存在しなかったら作成してくれる）
		std::ofstream ofs(filename, std::ios::binary);
		if (ofs.fail())
		{
			MessageBox(0, L"保存用ファイルを開けませんでした", L"failed", 0);
			return; // 開けなかったら強制終了
		}

		// オブジェクトの数を書き込む
		uint32_t numObjects = m_stageObjects.size();
		ofs.write((char*)&numObjects, sizeof(numObjects));

		// オブジェクトの情報を書き込む
		for (auto& obj : m_stageObjects)
		{
			auto objTrans = obj->GetComponent<Transform>();
			auto objPos = objTrans->GetPosition();

			// 文字列をIDに変換する
			uint16_t id = GetObjectIdByName(obj->GetName());
			ofs.write((char*)&id, sizeof(uint16_t)); // IDの取得
			ofs.write((char*)&objPos, sizeof(objPos)); // 座標
		}

		// 成功のメッセージを表示してファイルを閉じる
		MessageBox(0, L"ステージ配置を保存しました", L"Binary file save succeeded", 0);
		ofs.close();
	}

	void StageMap::Clear()
	{
		m_stageObjects.clear();
	}
}