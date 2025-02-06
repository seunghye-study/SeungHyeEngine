#pragma once
#include "Entity.h"

namespace Game
{
	class Resource abstract : public Entity// 추상클래스 ( 상속해서만 사용한다, 메모리 x)
	{
	public:
		Resource(Game::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수 가상함수, 실제 메모리할당 x

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const Game::eResourceType mType;
		std::wstring mPath;
	};
}


