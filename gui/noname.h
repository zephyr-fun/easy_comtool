///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/wrapsizer.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class com_win
///////////////////////////////////////////////////////////////////////////////
class com_win : public wxFrame
{
	private:

	protected:
		wxMenuBar* menubar;
		wxMenu* m_menu_help;
		wxStaticText* m_staticText_receive;
		wxChoice* m_choice_plot;
		wxChoice* m_choice_line;
		wxStaticText* m_staticText_recvFormat;
		wxChoice* m_choice_recvFormat;
		wxStaticText* m_staticText_null1;
		wxButton* m_button_server;
		wxButton* m_button_recvClear;
		wxTextCtrl* m_textCtrl_recv;
		wxStaticText* m_staticText_settings;
		wxStaticText* m_staticText_comPort;
		wxChoice* m_choice_comPort;
		wxStaticText* m_staticText_baudrate;
		wxChoice* m_choice_baudrate;
		wxStaticText* m_staticText_dataBits;
		wxChoice* m_choice_dataBits;
		wxStaticText* m_staticText_stopBits;
		wxChoice* m_choice_stopBits;
		wxStaticText* m_staticText_parityBits;
		wxChoice* m_choice_parityBits;
		wxStaticText* m_staticText_null2;
		wxStaticBitmap* m_bitmap_led;
		wxButton* m_button_openClose;
		wxStaticText* m_staticText_send;
		wxStaticText* m_staticText_sendFormat;
		wxChoice* m_choice_sendFormat;
		wxStaticText* m_staticText_null3;
		wxButton* m_button_sendClear;
		wxTextCtrl* m_textCtrl_send;
		wxStaticText* m_staticText_null4;
		wxButton* m_button_send;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void showHomepageMessage( wxCommandEvent& event ) { event.Skip(); }
		virtual void showAboutMessage( wxCommandEvent& event ) { event.Skip(); }
		virtual void setPlotState( wxCommandEvent& event ) { event.Skip(); }
		virtual void changeAnaline( wxCommandEvent& event ) { event.Skip(); }
		virtual void setRecvFormat( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenServer( wxCommandEvent& event ) { event.Skip(); }
		virtual void clearRecvDisplay( wxCommandEvent& event ) { event.Skip(); }
		virtual void refreshComPort( wxMouseEvent& event ) { event.Skip(); }
		virtual void openClosePort( wxCommandEvent& event ) { event.Skip(); }
		virtual void setSendFormat( wxCommandEvent& event ) { event.Skip(); }
		virtual void clearSendDisplay( wxCommandEvent& event ) { event.Skip(); }
		virtual void sendData( wxCommandEvent& event ) { event.Skip(); }


	public:

		com_win( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("JaysPyCOM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,598 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~com_win();

};

