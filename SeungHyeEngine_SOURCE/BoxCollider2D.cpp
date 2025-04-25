#include "BoxCollider2D.h"
#include "Transform.h"
#include "GameObject.h"
#include "Camera.h"
#include "Renderer.h"

namespace Game
{
	BoxCollider2D::BoxCollider2D() : Collider(eColliderType::Rect2D)
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Vector2 worldPos = tr->GetPosition() + GetOffset(); // 월드 좌표 기준 위치 계산
		Vector2 screenPos = mainCamera->CalculatePosition(worldPos); // 화면 위치로 변환

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);
		Rectangle(hdc,
			screenPos.x,
			screenPos.y,
			screenPos.x + 100 * GetSize().x, screenPos.y + 100 * GetSize().y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}