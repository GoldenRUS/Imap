Dim lp As Boolean, last As Integer, now As Integer, sFullPathToExecutable As String
Private Sub Start_Button_Click()
 On Error Resume Next
 last = 0
 lp = True
    While lp
        DoEvents
            now = ActivePresentation.SlideShowWindow.View.Slide.SlideIndex
            If now <> last Then
                last = now
                
                sFullPathToExecutable = ActivePresentation.Path & "\PORT.exe " & now
                Shell sFullPathToExecutable, vbHide
                
            End If
            If last = 7 Then
                lp = False
            End If
    Wend
End Sub
