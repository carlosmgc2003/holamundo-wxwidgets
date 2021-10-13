/*
Facultad de Ingeniería del Ejercito
Paradigmas de Programación III
¡Hola Mundo! de WxWidgets
*/


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Facultad de Ingeniería del Ejército", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Menú Archivo
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hola...\tCtrl-H", "Ayuda para este item de menu");
    menuFile->Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    menuFile->Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    // Menú Ayuda
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuHelp->Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    // Barra de menús
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Archivo");
    menuBar->Append(menuHelp, "&Ayuda");
    SetMenuBar(menuBar);
    // Barra de estado
    CreateStatusBar();
    SetStatusText("¡Bienvenidos a Paradigmas III!");

    /*Agregar sizer y panel al frame*/
    wxBoxSizer* frame_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxPanel* main_panel = new wxPanel(this);
    frame_sizer->Add(main_panel, 1, wxEXPAND);
    wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);
    main_panel->SetSizer(topsizer);
    // Cartek de nombre
    wxStaticText* autor = new wxStaticText(this, wxID_ANY, "CT CARLOS MACEIRA", wxDefaultPosition);
    wxFont font = autor->GetFont();
    font.SetPointSize(30);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    autor->SetFont(font);

    topsizer->Add(autor, wxSizerFlags(0).Align(wxALIGN_CENTER));

    SetSizer(frame_sizer);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Este es un ejemplo de Hola Mundo de WxWidgets",
        "Acerca de Hola Mundo", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("¡Hola Mundo!");
}