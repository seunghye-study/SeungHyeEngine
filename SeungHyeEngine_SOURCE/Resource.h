#pragma once
#include "Entity.h"

namespace Game
{
	class Resource abstract : public Entity// �߻�Ŭ���� ( ����ؼ��� ����Ѵ�, �޸� x)
	{
	public:
		Resource(Game::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // ���� �����Լ�, ���� �޸��Ҵ� x

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const Game::eResourceType mType;
		std::wstring mPath;
	};
}


