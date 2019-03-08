///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

com_win::com_win( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	menubar = new wxMenuBar( 0 );
	m_menu_help = new wxMenu();
	wxMenuItem* m_menuItem_homPage;
	m_menuItem_homPage = new wxMenuItem( m_menu_help, wxID_ANY, wxString( wxT("Home Page") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_help->Append( m_menuItem_homPage );

	wxMenuItem* m_menuItem_about;
	m_menuItem_about = new wxMenuItem( m_menu_help, wxID_ANY, wxString( wxT("About Author") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_help->Append( m_menuItem_about );

	menubar->Append( m_menu_help, wxT("Help") );

	this->SetMenuBar( menubar );

	wxBoxSizer* win_sizer;
	win_sizer = new wxBoxSizer( wxVERTICAL );

	wxWrapSizer* receive_win;
	receive_win = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

	m_staticText_receive = new wxStaticText( this, wxID_ANY, wxT("Receive:"), wxDefaultPosition, wxSize( 400,25 ), 0 );
	m_staticText_receive->Wrap( -1 );
	m_staticText_receive->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial Narrow") ) );
	m_staticText_receive->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_staticText_receive->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	receive_win->Add( m_staticText_receive, 0, wxALL, 5 );

	wxString m_choice_plotChoices[] = { wxT("Plot_On"), wxT("Plot_Off") };
	int m_choice_plotNChoices = sizeof( m_choice_plotChoices ) / sizeof( wxString );
	m_choice_plot = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 100,20 ), m_choice_plotNChoices, m_choice_plotChoices, 0 );
	m_choice_plot->SetSelection( 0 );
	receive_win->Add( m_choice_plot, 0, wxALL, 5 );

	wxString m_choice_lineChoices[] = { wxT("Line#1"), wxT("Line#2") };
	int m_choice_lineNChoices = sizeof( m_choice_lineChoices ) / sizeof( wxString );
	m_choice_line = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,20 ), m_choice_lineNChoices, m_choice_lineChoices, 0 );
	m_choice_line->SetSelection( 0 );
	receive_win->Add( m_choice_line, 0, wxALL, 5 );

	m_staticText_recvFormat = new wxStaticText( this, wxID_ANY, wxT("Format:"), wxDefaultPosition, wxSize( 50,15 ), 0 );
	m_staticText_recvFormat->Wrap( -1 );
	m_staticText_recvFormat->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	receive_win->Add( m_staticText_recvFormat, 0, wxALL, 5 );

	wxString m_choice_recvFormatChoices[] = { wxT("Char"), wxEmptyString, wxT("Hex") };
	int m_choice_recvFormatNChoices = sizeof( m_choice_recvFormatChoices ) / sizeof( wxString );
	m_choice_recvFormat = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 50,20 ), m_choice_recvFormatNChoices, m_choice_recvFormatChoices, 0 );
	m_choice_recvFormat->SetSelection( 0 );
	receive_win->Add( m_choice_recvFormat, 0, wxALL, 5 );

	m_staticText_null1 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 380,20 ), 0 );
	m_staticText_null1->Wrap( -1 );
	receive_win->Add( m_staticText_null1, 0, wxALL, 5 );

	m_button_server = new wxButton( this, wxID_ANY, wxT("Server"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	receive_win->Add( m_button_server, 0, wxALL, 5 );

	m_button_recvClear = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxSize( 50,30 ), 0 );
	m_button_recvClear->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	receive_win->Add( m_button_recvClear, 0, wxALL, 5 );

	m_textCtrl_recv = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 700,180 ), wxTE_MULTILINE );
	m_textCtrl_recv->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	receive_win->Add( m_textCtrl_recv, 0, wxALL, 5 );


	win_sizer->Add( receive_win, 1, wxEXPAND, 5 );

	wxGridSizer* edit_win;
	edit_win = new wxGridSizer( 0, 2, 0, 0 );

	wxWrapSizer* setting_win;
	setting_win = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

	m_staticText_settings = new wxStaticText( this, wxID_ANY, wxT("Settings:"), wxDefaultPosition, wxSize( 350,25 ), 0 );
	m_staticText_settings->Wrap( -1 );
	m_staticText_settings->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial Narrow") ) );
	m_staticText_settings->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_staticText_settings->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	setting_win->Add( m_staticText_settings, 0, wxALL, 5 );

	m_staticText_comPort = new wxStaticText( this, wxID_ANY, wxT("Com Port:"), wxDefaultPosition, wxSize( 150,15 ), wxALIGN_RIGHT );
	m_staticText_comPort->Wrap( -1 );
	m_staticText_comPort->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	setting_win->Add( m_staticText_comPort, 0, wxALL, 5 );

	wxArrayString m_choice_comPortChoices;
	m_choice_comPort = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 120,20 ), m_choice_comPortChoices, 0 );
	m_choice_comPort->SetSelection( 0 );
	setting_win->Add( m_choice_comPort, 0, wxALL, 5 );

	m_staticText_baudrate = new wxStaticText( this, wxID_ANY, wxT("Baud Rate:"), wxDefaultPosition, wxSize( 150,15 ), wxALIGN_RIGHT );
	m_staticText_baudrate->Wrap( -1 );
	m_staticText_baudrate->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	setting_win->Add( m_staticText_baudrate, 0, wxALL, 5 );

	wxString m_choice_baudrateChoices[] = { wxT("256000"), wxT("128000"), wxT("115200"), wxT("57600"), wxT("38400"), wxT("19200"), wxT("9600"), wxT("4800") };
	int m_choice_baudrateNChoices = sizeof( m_choice_baudrateChoices ) / sizeof( wxString );
	m_choice_baudrate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 120,20 ), m_choice_baudrateNChoices, m_choice_baudrateChoices, 0 );
	m_choice_baudrate->SetSelection( 2 );
	m_choice_baudrate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	setting_win->Add( m_choice_baudrate, 0, wxALL, 5 );

	m_staticText_dataBits = new wxStaticText( this, wxID_ANY, wxT("Data Bits:"), wxDefaultPosition, wxSize( 150,15 ), wxALIGN_RIGHT );
	m_staticText_dataBits->Wrap( -1 );
	m_staticText_dataBits->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	setting_win->Add( m_staticText_dataBits, 0, wxALL, 5 );

	wxString m_choice_dataBitsChoices[] = { wxT("8"), wxT("7"), wxT("6"), wxT("5") };
	int m_choice_dataBitsNChoices = sizeof( m_choice_dataBitsChoices ) / sizeof( wxString );
	m_choice_dataBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 120,20 ), m_choice_dataBitsNChoices, m_choice_dataBitsChoices, 0 );
	m_choice_dataBits->SetSelection( 0 );
	setting_win->Add( m_choice_dataBits, 0, wxALL, 5 );

	m_staticText_stopBits = new wxStaticText( this, wxID_ANY, wxT("Stop Bits:"), wxDefaultPosition, wxSize( 150,15 ), wxALIGN_RIGHT );
	m_staticText_stopBits->Wrap( -1 );
	m_staticText_stopBits->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	setting_win->Add( m_staticText_stopBits, 0, wxALL, 5 );

	wxString m_choice_stopBitsChoices[] = { wxT("1"), wxT("1.5"), wxT("2") };
	int m_choice_stopBitsNChoices = sizeof( m_choice_stopBitsChoices ) / sizeof( wxString );
	m_choice_stopBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 120,20 ), m_choice_stopBitsNChoices, m_choice_stopBitsChoices, 0 );
	m_choice_stopBits->SetSelection( 0 );
	setting_win->Add( m_choice_stopBits, 0, wxALL, 5 );

	m_staticText_parityBits = new wxStaticText( this, wxID_ANY, wxT("Parity Bits"), wxDefaultPosition, wxSize( 150,15 ), wxALIGN_RIGHT );
	m_staticText_parityBits->Wrap( -1 );
	m_staticText_parityBits->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	setting_win->Add( m_staticText_parityBits, 0, wxALL, 5 );

	wxString m_choice_parityBitsChoices[] = { wxT("None"), wxT("Odd"), wxT("Even"), wxT("Mark"), wxT("Space") };
	int m_choice_parityBitsNChoices = sizeof( m_choice_parityBitsChoices ) / sizeof( wxString );
	m_choice_parityBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 120,20 ), m_choice_parityBitsNChoices, m_choice_parityBitsChoices, 0 );
	m_choice_parityBits->SetSelection( 0 );
	setting_win->Add( m_choice_parityBits, 0, wxALL, 5 );

	m_staticText_null2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,15 ), 0 );
	m_staticText_null2->Wrap( -1 );
	setting_win->Add( m_staticText_null2, 0, wxALL, 5 );

	m_bitmap_led = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	setting_win->Add( m_bitmap_led, 0, wxALL, 5 );

	m_button_openClose = new wxButton( this, wxID_ANY, wxT("Open"), wxDefaultPosition, wxSize( 80,40 ), 0 );
	m_button_openClose->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	setting_win->Add( m_button_openClose, 0, wxALL, 5 );


	edit_win->Add( setting_win, 1, wxEXPAND, 5 );

	wxWrapSizer* send_win;
	send_win = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

	m_staticText_send = new wxStaticText( this, wxID_ANY, wxT("Send:"), wxDefaultPosition, wxSize( 350,25 ), 0 );
	m_staticText_send->Wrap( -1 );
	m_staticText_send->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial Narrow") ) );
	m_staticText_send->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	send_win->Add( m_staticText_send, 0, wxALL, 5 );

	m_staticText_sendFormat = new wxStaticText( this, wxID_ANY, wxT("Format:"), wxDefaultPosition, wxSize( 50,15 ), 0 );
	m_staticText_sendFormat->Wrap( -1 );
	m_staticText_sendFormat->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	send_win->Add( m_staticText_sendFormat, 0, wxALL, 5 );

	wxString m_choice_sendFormatChoices[] = { wxT("Char"), wxT("Hex") };
	int m_choice_sendFormatNChoices = sizeof( m_choice_sendFormatChoices ) / sizeof( wxString );
	m_choice_sendFormat = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 50,20 ), m_choice_sendFormatNChoices, m_choice_sendFormatChoices, 0 );
	m_choice_sendFormat->SetSelection( 0 );
	send_win->Add( m_choice_sendFormat, 0, wxALL, 5 );

	m_staticText_null3 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), 0 );
	m_staticText_null3->Wrap( -1 );
	send_win->Add( m_staticText_null3, 0, wxALL, 5 );

	m_button_sendClear = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxSize( 50,30 ), 0 );
	m_button_sendClear->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	send_win->Add( m_button_sendClear, 0, wxALL, 5 );

	m_textCtrl_send = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,105 ), wxTE_MULTILINE );
	m_textCtrl_send->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	send_win->Add( m_textCtrl_send, 0, wxALL, 5 );

	m_staticText_null4 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,15 ), 0 );
	m_staticText_null4->Wrap( -1 );
	send_win->Add( m_staticText_null4, 0, wxALL, 5 );

	m_button_send = new wxButton( this, wxID_ANY, wxT("Send"), wxDefaultPosition, wxSize( 80,40 ), 0 );
	m_button_send->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	send_win->Add( m_button_send, 0, wxALL, 5 );


	edit_win->Add( send_win, 1, wxEXPAND, 5 );


	win_sizer->Add( edit_win, 1, wxEXPAND, 5 );


	this->SetSizer( win_sizer );
	this->Layout();
	statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_menu_help->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( com_win::showHomepageMessage ), this, m_menuItem_homPage->GetId());
	m_menu_help->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( com_win::showAboutMessage ), this, m_menuItem_about->GetId());
	m_choice_plot->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setPlotState ), NULL, this );
	m_choice_line->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::changeAnaline ), NULL, this );
	m_choice_recvFormat->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setRecvFormat ), NULL, this );
	m_button_server->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::OpenServer ), NULL, this );
	m_button_recvClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::clearRecvDisplay ), NULL, this );
	m_choice_comPort->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( com_win::refreshComPort ), NULL, this );
	m_button_openClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::openClosePort ), NULL, this );
	m_choice_sendFormat->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setSendFormat ), NULL, this );
	m_button_sendClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::clearSendDisplay ), NULL, this );
	m_button_send->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::sendData ), NULL, this );
}

com_win::~com_win()
{
	// Disconnect Events
	m_choice_plot->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setPlotState ), NULL, this );
	m_choice_line->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::changeAnaline ), NULL, this );
	m_choice_recvFormat->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setRecvFormat ), NULL, this );
	m_button_server->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::OpenServer ), NULL, this );
	m_button_recvClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::clearRecvDisplay ), NULL, this );
	m_choice_comPort->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( com_win::refreshComPort ), NULL, this );
	m_button_openClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::openClosePort ), NULL, this );
	m_choice_sendFormat->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( com_win::setSendFormat ), NULL, this );
	m_button_sendClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::clearSendDisplay ), NULL, this );
	m_button_send->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( com_win::sendData ), NULL, this );

}
