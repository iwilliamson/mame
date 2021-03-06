// license:BSD-3-Clause
// copyright-holders:R. Belmont, Tomasz Slanina, David Haywood
#ifndef MAME_SOUND_ST0016_H
#define MAME_SOUND_ST0016_H

#pragma once


//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> st0016_device

class st0016_device : public device_t, public device_sound_interface
{
public:
	st0016_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	auto ram_read() { return m_ram_read_cb.bind(); }

	uint8_t snd_r(offs_t offset);
	void snd_w(offs_t offset, uint8_t data);

protected:
	// device-level overrides
	virtual void device_start() override;

	// sound stream update overrides
	virtual void sound_stream_update(sound_stream &stream, std::vector<read_stream_view> const &inputs, std::vector<write_stream_view> &outputs) override;

private:
	sound_stream *m_stream;
	devcb_read8 m_ram_read_cb;
	int m_vpos[8];
	int m_frac[8];
	int m_lponce[8];
	uint8_t m_regs[0x100];
};

DECLARE_DEVICE_TYPE(ST0016, st0016_device)

#endif // MAME_SOUND_ST0016_H
