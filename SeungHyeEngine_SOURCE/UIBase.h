#pragma once
#include "Entity.h"

namespace Game
{
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		// ui 로드(초기화)
		void Initialize();

		// ui 활성시 호출
		void Active();

		// ui 비활성시 호출
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		// ui가 사라질 때 호출
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		eUIType mType;
		bool mbFullScreen; 
		bool mbEnabled;
	};
}


