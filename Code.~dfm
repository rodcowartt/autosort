object Form1: TForm1
  Left = 835
  Top = 379
  Width = 278
  Height = 161
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 56
    Width = 6
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object FileListBox1: TFileListBox
    Left = 40
    Top = 8
    Width = 33
    Height = 17
    ItemHeight = 13
    TabOrder = 0
    Visible = False
  end
  object DriveComboBox1: TDriveComboBox
    Left = 8
    Top = 8
    Width = 33
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 1
    Visible = False
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 8
    Top = 32
    Width = 41
    Height = 17
    FileList = FileListBox1
    ItemHeight = 16
    TabOrder = 2
    Visible = False
  end
  object Button5: TButton
    Left = 80
    Top = 8
    Width = 97
    Height = 33
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button5Click
  end
  object IdHTTP1: TIdHTTP
    HandleRedirects = True
    Request.Accept = 'text/html, */*'
    Request.ContentLength = 0
    Request.ContentRangeEnd = 0
    Request.ContentRangeStart = 0
    Request.ProxyPort = 0
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Left = 208
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 184
    Top = 8
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About'
        OnClick = About1Click
      end
    end
  end
  object IdAntiFreeze1: TIdAntiFreeze
    IdleTimeOut = 35
    Left = 208
    Top = 40
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 128
    Top = 56
  end
end
