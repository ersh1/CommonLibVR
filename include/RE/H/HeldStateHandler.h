#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class HeldStateHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_HeldStateHandler;
		inline static constexpr auto VTABLE = VTABLE_HeldStateHandler;

		~HeldStateHandler() override;  // 00

		// add
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event);  // 05
		virtual void SetHeldStateActive(bool a_flag);                    // 06 - { heldStateActive = a_flag; }

		// members
		bool          heldStateActive;      // 10
		bool          triggerReleaseEvent;  // 11
		std::uint16_t pad12;                // 12
		std::uint32_t pad14;                // 14
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(HeldStateHandler) == 0x18);
#else
	static_assert(sizeof(HeldStateHandler) == 0x30);
#endif
}
