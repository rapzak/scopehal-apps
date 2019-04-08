/***********************************************************************************************************************
*                                                                                                                      *
* ANTIKERNEL v0.1                                                                                                      *
*                                                                                                                      *
* Copyright (c) 2012-2019 Andrew D. Zonenberg                                                                          *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

/**
	@file
	@author Andrew D. Zonenberg
	@brief Dialog for configuring protocol decoders
 */

#ifndef ProtocolDecoderDialog_h
#define ProtocolDecoderDialog_h

#include "../scopehal/Oscilloscope.h"
#include "WaveformArea.h"
#include "WaveformGroup.h"

class ChannelSelectorRow
{
public:
	ChannelSelectorRow()
	{
		m_box.pack_start(m_label, Gtk::PACK_EXPAND_WIDGET);
		m_box.pack_start(m_chans, Gtk::PACK_EXPAND_WIDGET);
		m_label.set_size_request(100, 1);
		m_label.set_halign(Gtk::ALIGN_END);
		m_chans.set_size_request(100, 1);
	}

	Gtk::HBox m_box;
		Gtk::Label			m_label;
		Gtk::ComboBoxText	m_chans;

	std::map<std::string, OscilloscopeChannel*> m_chanptrs;
};

/**
	@brief Main application window class for an oscilloscope
 */
class ProtocolDecoderDialog	: public Gtk::Dialog
{
public:
	ProtocolDecoderDialog(OscilloscopeWindow* parent, ProtocolDecoder* decoder, OscilloscopeChannel* chan);
	virtual ~ProtocolDecoderDialog();

	void ConfigureDecoder();

protected:
	ProtocolDecoder* m_decoder;

	std::vector<ChannelSelectorRow*> m_rows;

};

#endif
