Dim lp As Boolean, last As Integer, now As Integer
Private Sub Start_Button_Click()
 On Error Resume Next
 last = 0
 lp = True
    While lp
        DoEvents
            now = ActivePresentation.SlideShowWindow.View.Slide.SlideIndex
            If now <> last Then
                last = now
                
                Dim sFullPathToExecutable As String
                sFullPathToExecutable = "C:\Users\Admin\Desktop\PORT.exe " & now
                Shell sFullPathToExecutable, vbHide
                
            End If
            If last = 7 Then
                lp = False
            End If
    Wend
End Sub
