#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiMatrix3.h"

namespace RE
{
	class MenuOpenCloseEvent;
	class NiControllerSequence;
	class TESObjectREFR;

	// menuDepth = 3
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate
	// context = kLockpicking
	class LockpickingMenu :
		public IMenu,                            // 00
		public MenuEventHandler,                 // 30
		public BSTEventSink<MenuOpenCloseEvent>  // 40
	{
	public:
		inline static constexpr auto      RTTI = RTTI_LockpickingMenu;
		constexpr static std::string_view MENU_NAME = "Lockpicking Menu";

		~LockpickingMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05

		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TESObjectREFR* GetTargetReference();

		// members
		void*                 lockpickShiv;  // 048
		void*                 lockpick;      // 050
		NiMatrix3             unk058;        // 058
		NiPoint3              unk07C;        // 07C
		std::uint64_t         unk088;        // 088
		std::uint64_t         unk090;        // 090
		std::uint64_t         unk098;        // 098
		std::uint64_t         unk0A0;        // 0A0
		std::uint64_t         unk0A8;        // 0A8
		std::uint64_t         unk0B0;        // 0B0
		std::uint64_t         unk0B8;        // 0B8
		NiControllerSequence* unk0C0;        // 0C0
		float                 unk0C8;        // 0C8
		std::uint32_t         unk0CC;        // 0CC
		NiControllerSequence* unk0D0;        // 0D0
		float                 unk0D8;        // 0D8
		std::uint32_t         unk0DC;        // 0DC
		std::uint32_t         unk0E0;        // 0E0
		float                 lockMaxAngle;  // 0E4
		std::uint32_t         unk0E8;        // 0E8
		BSSoundHandle         unk0EC;        // 0EC
		std::uint32_t         unk0F8;        // 0F8
		std::uint32_t         unk0FC;        // 0FC
		std::uint32_t         unk100;        // 100
		std::uint32_t         unk104;        // 104
		std::uint16_t         unk108;        // 108
		std::uint8_t          unk10A;        // 10A
		std::uint8_t          unk10B;        // 10B
		std::uint8_t          unk10C;        // 10C
		std::uint8_t          unk10D;        // 10D
		std::uint8_t          unk10E;        // 10E
		std::uint8_t          pad10F;        // 10F
	};
#ifndef SKYRIMVR
	static_assert(sizeof(LockpickingMenu) == 0x110);
#endif
}
